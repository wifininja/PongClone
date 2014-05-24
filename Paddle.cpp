#include "Classes.h"

Paddle::Paddle()
{
	y = 300;
}



void Paddle::move(int offset)
{
	y += offset;
}

void Paddle::action(int direction)
{
	move(10 * direction);
}

//test::update()
//{
//	// blah
//	if (queue.key_pressed(SDLK_up)) game.do_this(-1);
//	if (queue.key_pressed(SDLK_down))game.do_this(1);
//}