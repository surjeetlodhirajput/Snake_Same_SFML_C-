#include"Game.h"
#include<ctime>
int main()
{
	srand(time(NULL));
	Game game;
	game.run();
	return 0;
}