#include "Classes.h"

Render::Render()
{
	texture = nullptr;
}

Render::~Render()
{
	if (texture != NULL)
		SDL_DestroyTexture(texture);
}

bool Render::load(const char *filename, SDL_Renderer *context)
{
	//Load the image
	texture = IMG_LoadTexture(context, filename);

	//If loading went ok, convert to texture and return
	if (texture == nullptr)
	{
		SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_ERROR, "Texture load fail", "You failed to load the texture", NULL);
		return false;
	}

	SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

	return true;
}

void Render::draw(SDL_Renderer * ren, SDL_Rect dest)
{
	SDL_RenderCopy(ren, texture, &rect, &dest);
}

void Render::draw(SDL_Renderer * ren, unsigned x, unsigned y, unsigned w, unsigned h)
{
	//Setup the dest rectangle where we want
	SDL_Rect dest = { x, y, w, h };
	draw(ren, dest);

}