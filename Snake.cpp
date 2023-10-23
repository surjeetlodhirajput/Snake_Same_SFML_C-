#include"Snake.h"
void Snake::initVariable(sf::RenderTarget &target)
{
	this->head.setSize(sf::Vector2f(30.f, 30.f));
	
	this->head.setFillColor(sf::Color::Red);
	
	this->head.setPosition(rand() % target.getSize().x , rand() % target.getSize().y );
	this->head.setOutlineColor(sf::Color::Black);
	this->head.setOutlineThickness(1);
}
Snake::Snake()
{
	
}
Snake::Snake(sf::RenderTarget& target)
{
	this->initVariable(target);
}
Snake::~Snake()
{

}
void Snake::update()
{
	
	
}

void Snake::updatePosition()
{
	for (int i=num; i > 0; i--)
	{
		s[i].x = s[i - 1].x; s[i].y = s[i - 1].y;
	}
}
void Snake::checkTail(bool& game)
{
	for (int i = 1; i < num; i++)
	{
		if (s[0].x == s[i].x && s[0].y == s[i].y)game=true;
	}
}
void Snake::saveCollision(sf::RenderTarget& target)
{
	//if (s[0].x > target.getSize().x) s[0].x = 900;  //
	if (s[0].x < 0) s[0].x =29;
	//if (s[0].y > target.getSize().y) s[0].y =0;  
	else	if (s[0].y < 0) s[0].y = 14;
	else if (s[0].x > 29)s[0].x =0;
	else if (s[0].y > 14)s[0].y = 0;
	
}
void Snake::increaseLength(enum dir value)
{
	if (value == UP)s[0].y -= 1;
	if (value == LEFT)s[0].x -= 1;
	if (value == RIGHT)s[0].x += 1;
	if (value == DOWN)s[0].y += 1;
}
struct S Snake::getGlobalBOunds()
{
	
	return s[0];
	
}
void Snake::increaen()
{
	num++;
}
void Snake::render(sf::RenderTarget& target)
{	
	for (int i = 0; i < num; i++)
	{
		if (i == 0)
			head.setFillColor(sf::Color::Red);
		else
			head.setFillColor(sf::Color::Green);
		this->head.setPosition(s[i].x * 30, s[i].y * 30); target.draw(this->head);
	}
}