#include<SFML/Graphics.hpp>
#pragma once
struct S
{
	float x, y;

};
enum dir 
{UP=0,DOWN,LEFT,RIGHT,NONE};
class Snake
{

private:
	 struct S s[100];
	sf::RectangleShape head;
	sf::RectangleShape body;
	 int num = 1;
	void initVariable(sf::RenderTarget& target);
public:
	Snake();
	Snake(sf::RenderTarget& target);
	~Snake();
	void update();
	void render(sf::RenderTarget& target);
	void updatePosition();
	void checkTail(bool &game);
	void increaseLength(enum dir value);
	void saveCollision(sf::RenderTarget& target);
	struct S getGlobalBOunds();
	 void increaen();
};