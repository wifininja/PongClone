#include "Classes.h"

unsigned int fullscreen = 0;
Paddle p1Paddle;
Paddle p2Paddle;

PongClone::PongClone()
{
	init = (SDL_Init(SDL_INIT_EVERYTHING) == 0);

	if (!init)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Init Error", "Init failed", NULL);
	}
}

PongClone::~PongClone()
{
	if (background != NULL)
		delete background;
	if (paddle != NULL)
		delete paddle;
	if (ball != NULL)
		delete ball;
	if (renderer != NULL)
		SDL_DestroyRenderer(renderer);
	if (window != NULL)
		SDL_DestroyWindow(window);
	SDL_Quit();
}

bool PongClone::start()
{
	window = SDL_CreateWindow("Pong Clone", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (window == nullptr)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Window Fail", "Your window is failed to be made", window);
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Renderer Failed", "Renderer Broke", window);
	}

	background = new Render;
	paddle = new Render;
	ball = new Render;
	if (background == nullptr || paddle == nullptr || ball == nullptr)
		return false;
	if (background->load("pbackground.png", renderer) == false)
		return false;
	if (paddle->load("paddle.png", renderer) == false)
		return false;
	if (ball->load("ball.png", renderer) == false)
		return false;

	//setup keyboard support
	queue.supported_keys.insert(SDLK_ESCAPE);
	queue.supported_keys.insert(SDLK_w);
	queue.supported_keys.insert(SDLK_s);
	queue.supported_keys.insert(SDLK_UP);
	queue.supported_keys.insert(SDLK_DOWN);
	queue.supported_keys.insert(SDLK_F4);
	return true;
}

void PongClone::draw()
{
	SDL_RenderClear(renderer);
	background->draw(renderer, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	paddle->draw(renderer, 25, p1Paddle.y, paddle->rect.w, paddle->rect.h);
	paddle->draw(renderer, 1205, p2Paddle.y, paddle->rect.w, paddle->rect.h);
	SDL_RenderPresent(renderer);

}

bool PongClone::update()
{
	queue.update();
	if (queue.quit) return false;
	if (queue.key_pressed(SDLK_ESCAPE)) return false;
	if (queue.key_down(SDLK_w))
	{
		p1Paddle.action(-1);
	}
	if (queue.key_down(SDLK_s))
	{
		p1Paddle.action(1);
	}
	if (queue.key_down(SDLK_UP))
	{
		p2Paddle.action(-1);
	}
	if (queue.key_down(SDLK_DOWN))
	{
		p2Paddle.action(1);
	}
	if (queue.key_down(SDLK_F4))
	{
		fullscreen = !fullscreen;
		SDL_SetWindowFullscreen(window, fullscreen);
	}
	draw();
	return true;
}