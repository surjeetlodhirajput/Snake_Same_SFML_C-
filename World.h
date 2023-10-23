#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<iostream>
//#include"WIndow.h"
#ifndef WORLD_H
#pragma once

class world
{
private:
		sf::Texture texture;
		sf::Sprite sprite;
		void initVariable(int height, int width);
public:
	world(int height, int width);
	~world();
	void update();
	void render(sf::RenderTarget& target);

};
#endif // !WORLD_H
