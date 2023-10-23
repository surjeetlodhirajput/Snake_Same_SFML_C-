#include"Game.h"
void Game::initVariable()
{
	sf::VideoMode video(H*SIZE ,W*SIZE/1.f);
	
	std::string str = "snake game";
	this->window.create(video, str,sf::Style::Default);
	this->World =new world(SIZE * H, SIZE * W);
	this->snake = new Snake(this->window);
	this->fruit = new Fruit(this->window);
	this->window.setFramerateLimit(13);
	this->sound.loadFromFile("crash.wav");
	so.setBuffer(sound);
	fone.loadFromFile("fonts/PixellettersFull.ttf");
	this->text.setFont(fone);
	this->text.setString("Game Over");
	this->text.setCharacterSize(50);
	this->text.setPosition(window.getSize().x / 2-100, window.getSize().y / 2);
	this->scores.setFont(this->fone);
	this->scores.setCharacterSize(20);
	this->scores.setFillColor(sf::Color::White);
	this->scores.setString("Score:- 0");
	this->scores.setPosition(10,10);
}
Game::Game()
{	
	this->initVariable();

}
Game:: ~Game()
{
	delete this-> World;
	delete this->snake;
	delete this->fruit;
}
void Game::run()
{
	while (this->window.isOpen())
	{
		float timer = clock.getElapsedTime().asSeconds();
		time += timer;
		clock.restart();
		this->handelEvents();
		if(!gameOver)
		this->update();

		this->render();
	}
}
void Game::update()
{
	this->updateSnake();
	if (time > delay) {
		this->snake->updatePosition();
		this->snake->increaseLength(value);
		this->eat();
		this->snake->saveCollision(this->window);
		this->snake->checkTail(gameOver);
	}
}
void Game::eat()
{	
	f = this->fruit->posF();
	s = this->snake->getGlobalBOunds();
	if (s.x==f.x&&f.y==s.y)
	{
		this->score += 10;
		std::stringstream ss;
		ss << "Scores:- " << this->score;
		this->scores.setString(ss.str());
		so.play();
		int i = 0;
		while (i < 50)i++;
		this->fruit = new Fruit(window);
		this->snake->increaen();
		
	}
}
void Game::updateSnake()
{

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)||sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		value = UP;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		value = DOWN;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		value = LEFT;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		value = RIGHT;
	}
//	else value = NONE;
}

void Game::render()
{
	this->window.clear(sf::Color::Black);//clearing the window

	this->World->render(this->window);
	this->window.draw(this->scores);
	this->snake->render(this->window);
	this->fruit->render(this->window);
	if (this->gameOver)
	this->window.draw(text);
	this->window.display();

}
void Game::handelEvents()
{
	while (this->window.pollEvent(event))
	{
		if (sf::Keyboard::Escape == event.key.code)
			window.close();
		else if (sf::Event::Closed == event.type)
			this->window.close();
	}
}