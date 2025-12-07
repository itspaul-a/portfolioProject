#include "Pong.hpp"
#include <iostream>

Pong::Pong()
{
	if(!music.openFromFile("8-bit3.mp3"))
	{
		std::cout << "error loading success" << std::endl;
	}
	if(!smash.openFromFile("8-bit4.mp3"))
	{
		std::cout << "error loading smash" << std::endl;
	}
}

void Pong::run()
{
	sf::RenderWindow window(sf::VideoMode({800,600}), "window");
	window.setFramerateLimit(60);

	Paddle paddle({20, 100}, {0, 0}, 400);
	Paddle paddle2({20, 100}, {800, 0}, 400);

	Ball ball(10, {400, 300}, 300);
	Scoreboard score;

	sf::Clock clock;

	while(window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
	{
		float dt = clock.restart().asSeconds();
		while(const std::optional event = window.pollEvent())
		{
			if(event->is<sf::Event::Closed>())
			{
				window.close();
			}
		}

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) paddle.moveUp();
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) paddle.moveDown();
		else paddle.resetMovement();

		if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)) paddle2.moveUp();
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)) paddle2.moveDown();
		else paddle2.resetMovement();

		auto bound = ball.getBounds();
		float ballTop = bound.position.y;
		float ballBottom = bound.position.y + bound.size.y;
		if(ballTop < 0 || ballBottom > 600)
		{
			ball.bounceY();
		}

		if(intersect(ball.getBounds(), paddle.getBounds()) ||
		   intersect(ball.getBounds(), paddle2.getBounds()))
		{
			smash.play();
			ball.bounceX();
		}

		sf::Vector2f pos = ball.getPosition();
		if(pos.x < 0)
		{
			score.addRight();
			ball.resetPosition({800.f / 2, 600.f / 2});
		}
		else if(pos.x > 800)
		{
			score.addLeft();
			ball.resetPosition({800.f / 2, 600.f / 2});
		}

		std::ostringstream ss;
		ss <<  std::setw(5) << score.getScoreLeft() << std::setw(15) << score.getScoreRight() << std::setw(5);
		score.setScoreText(ss.str());

		if(score.getScoreLeft() == 5 || score.getScoreRight() == 5)
		{
			music.play();
			sf::sleep(sf::seconds(3));
			window.close();
		}

		paddle.update(dt, window.getSize().y);
		paddle2.update(dt, window.getSize().y);
		ball.update(dt);

		window.clear(sf::Color::Black);
		window.draw(paddle);
		window.draw(paddle2);
		window.draw(ball);
		window.draw(score.getScoreText());
		window.display();
	}
}

bool Pong::intersect(const sf::FloatRect& a, const sf::FloatRect& b) const 
{
	return !(a.position.x + a.size.x < b.position.x || b.position.x + b.size.x < a.position.x ||
			 a.position.y + b.size.y < b.position.y || b.position.y + b.size.y < a.position.y);
}

