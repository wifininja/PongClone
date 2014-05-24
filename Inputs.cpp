#include "Classes.h"

Inputs::Inputs()
{
	current = false;
	previous = false;
}

bool Inputs::down()
{
	return current;
}

bool Inputs::pressed()
{
	return (current && !previous);
}

bool Inputs::released()
{
	return (!current && previous);
}