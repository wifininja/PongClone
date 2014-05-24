#include "Classes.h"

Events::Events()
{
	quit = false;
}

Events::~Events()
{
	keys.clear();
}

void Events::update()
{
	for (std::map<unsigned, Inputs>::iterator i = keys.begin(); i != keys.end(); i++)
	{
		i->second.previous = i->second.current;
	}
	int sym;
	while (SDL_PollEvent(&queue))
	{
		sym = queue.key.keysym.sym;
		switch (queue.type)
		{
		case SDL_QUIT:
			quit = true; 
			break;

		case SDL_KEYDOWN:
			if (supported_keys.count(sym) < 1)
				break;
			keys[sym].current = true;
			break;
		case SDL_KEYUP:
			if (supported_keys.count(sym) < 1)
				break;
			keys[sym].current = false;
			break;
		}
	}
}

bool Events::key_down(int sym)
{
	if (keys.count(sym) < 1)
	{
		return false;
	}
	return keys[sym].down();
}

bool Events::key_pressed(int sym)
{
	if (keys.count(sym) < 1)
	{
		return false;
	}
	return keys[sym].pressed();
}

bool Events::key_released(int sym)
{
	if (keys.count(sym) < 1)
	{
		return false;
	}
	return keys[sym].released();
}