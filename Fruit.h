#include<SFML/Graphics.hpp>
#pragma once
struct fruit
{
	int x, y;
};
class Fruit
{
private:
	struct fruit f;
	sf::Texture texture;
	sf::Sprite sprite;
	void initVariable(sf::RenderTarget&  traget);
public:
	Fruit();
	Fruit(sf::RenderTarget& target);
	~Fruit();
	struct fruit posF();
	void update();
	void render(sf::RenderTarget& target);
	sf::FloatRect getGlobalBounds();
};

