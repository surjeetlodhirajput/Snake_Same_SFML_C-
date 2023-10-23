#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<sstream>
//#include"WIndow.h"
#include"World.h"
#include"Snake.h"
#include"Fruit.h"
#include<string>
#ifndef GAME_H
#define GAME_H
class  Game
{		private:
	sf::RenderWindow window;
	void initVariable();
	sf::Event event;
	int H = 30;
	int W = 15;
	sf::SoundBuffer sound;
	sf::Sound so;
	int score = 0;
	int SIZE = 30;
	sf::Text scores;
	world *World;
	Snake *snake;
	Fruit *fruit;
	enum dir value = NONE;
	sf::Clock clock;
	float time=0.f;
	float delay=0.3;
	sf::Font fone;
	struct S s;
	struct fruit f;
	bool gameOver=false; sf::Text text;
public:
	Game();
	virtual	~Game();
	void run();
	void update();
	void render();
	void handelEvents();
	void updateSnake();
	void eat();
};

#endif // !GAME_H
