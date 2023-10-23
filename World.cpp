#include "World.h"

void world::initVariable(int height, int width)
{
	if (this->texture.loadFromFile("Textures/grass.png"))
		std::cout << "ERROR IN LOADING THE BACKGROUND" << std::endl;
	this->sprite.setTexture(texture);
	this->sprite.setScale(1, 1);
}
world::world(int height,int width)
{
	this->initVariable( height, width);
	
}
world::~world() {

}
void world::update()
{

}
void world::render(sf::RenderTarget& target)
{
	target.draw(this->sprite);
}
