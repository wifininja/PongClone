#include "Classes.h"

int main(int argc, char **argv)
{
	PongClone pongclone;

	if (!pongclone.init)
		return 0;
	if (!pongclone.start())
		return 0;

	while (1)
	{
		if (!pongclone.update())
			break;
	}

	return 0;
}