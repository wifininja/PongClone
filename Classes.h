#ifndef CLASSES_H
#define CLASSES_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <map>
#include <unordered_set>

const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 720;

class Inputs
{
public:
	Inputs();
	bool down();
	bool pressed();
	bool released();
	bool current;
	bool previous;
};

class Events
{
public:
	SDL_Event queue;
	std::map<unsigned, Inputs> keys;
	bool quit;

	Events();
	~Events();
	void update();
	bool key_down(int);
	bool key_pressed(int);
	bool key_released(int);
	std::unordered_set <unsigned> supported_keys;
};

class Render
{
public:
	Render();
	~Render();

	bool load(const char *, SDL_Renderer *);
	void draw(SDL_Renderer *, unsigned, unsigned, unsigned, unsigned);
	void draw(SDL_Renderer *, SDL_Rect);

	SDL_Texture *texture;
	SDL_Rect rect;
};

class PongClone
{
public:
	PongClone();
	~PongClone();
	bool start();
	void draw();
	bool update();
	bool init;
	
	SDL_Window *window;
	SDL_Renderer *renderer;
	Render *background;
	Render *paddle;
	Render *ball;
	Events queue;
};

class Paddle
{
public:
	Paddle();

	void move(int offset);
	void action(int direction);
	int y;

};
#endif