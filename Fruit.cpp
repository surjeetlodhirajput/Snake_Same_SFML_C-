#include "Fruit.h"
void Fruit::initVariable(sf::RenderTarget& target)
{
	this->texture.loadFromFile("Textures/food.png");
	this->sprite.setTexture(this->texture);
	f.x = rand() % 30; f.y = rand() % 15;
}
Fruit::Fruit()
{
}
Fruit::Fruit(sf::RenderTarget& target)
{
	this->initVariable(target);
}
Fruit::~Fruit()
{

}
struct fruit Fruit::posF()
{
	return f;
}
sf::FloatRect Fruit::getGlobalBounds()
{
	return this->sprite.getGlobalBounds();
}
void Fruit::update()
{

}
void Fruit::render(sf::RenderTarget &target)
{	
	sprite.setPosition(f.x *30, f.y * 30);
	target.draw(this->sprite);
}