#include <SFML/Graphics.hpp>
#include <iostream> 
#include <sstream>
#include <cassert>
#include <string>
using namespace sf;
using namespace std;
void menu(RenderWindow & window);

int main()
{
	
	bool isMove = false;
	float dX = 0, bX = 0;
	float dY = 0, bY = 0;
	float bX1 = 0, bX2 = 0, bX3 = 0;
	float bY1 = 0, bY2 = 20, bY3 = 40;

	sf::Text text;

	RenderWindow window(sf::VideoMode(600, 450), "Darts");
	Texture herotexture;
	Texture maptexture;
	Texture arrowtexture;
	Texture backgroundtexture;
	Texture atempttexture;
	Texture listtexture;
	Texture gameOvertexture;

	listtexture.loadFromFile("images/list.png");
	atempttexture.loadFromFile("images/atempt.png");
	backgroundtexture.loadFromFile("images/t.png");
	arrowtexture.loadFromFile("images/arrow.png");
	maptexture.loadFromFile("images/map.png");
	herotexture.loadFromFile("images/hero.png");
	gameOvertexture.loadFromFile("images/gameOver.png");

	
	Sprite herosprite;
	Sprite mapsprite;
	Sprite arrowsprite;
	Sprite backgroundsprite;
	Sprite atemptsprite;
	Sprite listsprite;
	Sprite gameOversprite;

	gameOversprite.setTexture(gameOvertexture);
	gameOversprite.setPosition(0, 0);

	backgroundsprite.setTexture(backgroundtexture);
	backgroundsprite.setPosition(205, 91);

	listsprite.setTexture(listtexture);
	listsprite.setPosition(-10, 350);
		
	mapsprite.setTexture(maptexture);
	mapsprite.setPosition(0, 0);

	arrowsprite.setTexture(arrowtexture);

	bool isSelect;
	Image image = backgroundtexture.copyToImage();
	int score1 = 0, score3 = 0,score2 = 0;
	float CurrentFrame = 0;
	Clock clock;

	sf::Font font;
	sf::Font overFont;
	font.loadFromFile("Font/RabbitsApril.ttf");
	overFont.loadFromFile("Font/Grid.ttf");



	
		menu(window);
		int atempt = 3;
	while (window.isOpen())
	{				
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time = time / 800;
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);
	
		sf::Event event;

		while (window.pollEvent(event))
		{
			text.setFont(font);
			text.setCharacterSize(50);
			text.setPosition(5, 5);
			text.setStyle(sf::Text::Italic | sf::Text::Underlined);
			text.setFillColor(sf::Color::Cyan);
			text.setPosition(203, 300);


				if (event.type == Event::MouseMoved)
				{					
					window.setMouseCursorVisible(false);
					herosprite.setTexture(herotexture);
					herosprite.setPosition(pos.x, pos.y);

				}
				if (event.type == sf::Event::Closed)
					window.close();

				if (event.type == Event::MouseButtonPressed)
					if (event.key.code == Mouse::Left)
						if (backgroundsprite.getGlobalBounds().contains(pos.x, pos.y))
						{
							
							atemptsprite.setTexture(atempttexture);

							dX = pos.x - backgroundsprite.getPosition().x;
							dY = pos.y - backgroundsprite.getPosition().y;

							bX = pos.x - mapsprite.getPosition().x;
							bY = pos.y - mapsprite.getPosition().y;

							if (atempt == 3)
							{
								bX1 = bX;
								bY1 = bY;
							}

							if (atempt == 2)
							{
								bX2 = bX;
								bY2 = bY;
							}

							if (atempt == 1)
							{
								bX3 = bX;
								bY3 = bY;
							}

							isMove = true;

							Color pixel = image.getPixel(dX, dY);

							score1 = 0;

							if ((pixel.r == 237) && (pixel.g == 28) && (pixel.b == 36))
								score1 = 10;
							if ((pixel.r == 34) && (pixel.g == 177) && (pixel.b == 76))
								score1 = 9;
							if ((pixel.r == 63) && (pixel.g == 72) && (pixel.b == 204))
								score1 = 8;
							if ((pixel.r == 163) && (pixel.g == 73) && (pixel.b == 164))
								score1 = 7;
							if ((pixel.r == 255) && (pixel.g == 174) && (pixel.b == 201))
								score1 = 6;
							if ((pixel.r == 181) && (pixel.g == 230) && (pixel.b == 29))
								score1 = 5;
							if ((pixel.r == 136) && (pixel.g == 0) && (pixel.b == 21))
								score1 = 4;
							if ((pixel.r == 255) && (pixel.g == 201) && (pixel.b == 14))
								score1 = 3;
							if ((pixel.r == 185) && (pixel.g == 122) && (pixel.b == 87))
								score1 = 2;
							if ((pixel.r == 200) && (pixel.g == 191) && (pixel.b == 231))
								score1 = 1;

							if(atempt>0)
							score2 = score1 + score2;

							atempt--;
						}

				if (event.type == Event::MouseButtonReleased)
					if (event.key.code == Mouse::Left)
						isMove = false;
			

		}
		
		window.clear();		
		window.draw(backgroundsprite);
		window.draw(mapsprite);
		
		window.draw(listsprite);

		if (atempt == 3)
		{		
			arrowsprite.setPosition(-10, 350);
			window.draw(arrowsprite);
			arrowsprite.setPosition(-10, 375);
			window.draw(arrowsprite);
			arrowsprite.setPosition(-10, 400);
			window.draw(arrowsprite);
		}

		if (atempt == 2)
		{
			arrowsprite.setPosition(-10, 375);
			window.draw(arrowsprite);
			arrowsprite.setPosition(-10, 400);
			window.draw(arrowsprite);
		}			
		if (atempt == 1)
		{		
			arrowsprite.setPosition(-10, 400);
			window.draw(arrowsprite);
		}		
		
		atemptsprite.setPosition(bX1, bY1);
		window.draw(atemptsprite);
		atemptsprite.setPosition(bX2, bY2);
		window.draw(atemptsprite);
		atemptsprite.setPosition(bX3, bY3);
		
		window.draw(atemptsprite);
		
		

		std::ostringstream ss;

		ss << score2;
		text.setString("Score " + ss.str());

		window.draw(text);
		window.draw(herosprite);
		if (atempt == -1)
		{
			window.draw(gameOversprite);
			window.setMouseCursorVisible(true);
			
			text.setFont(overFont);

			text.setCharacterSize(70);
			text.setString(ss.str());
			text.setStyle(sf::Text::Italic);
			text.setFillColor(sf::Color(255, 0, 0, 175));
			text.setPosition(432, 95);

			window.draw(text);
			bX1 = 0, bX2 = 0, bX3 = 0;
			bY1 = 0, bY2 = 20, bY3 = 40;

			if (event.type == Event::KeyReleased)
				if (event.key.code == Keyboard::Space || event.key.code == Keyboard::Return)
					atempt--;

		}


		if (atempt == -2)
		{
			window.clear();
			menu(window);
			score2 = 0;
			atempt = 3;
			
			bX = 0;
			bY = 0;

		}

		
		window.display();
	}
	return 0;
}



void menu(RenderWindow & window) 
{
	
	Texture menuTexture1, menuTexture3, aboutTexture, menuBackground;

	menuTexture1.loadFromFile("images/111.png");
	menuTexture3.loadFromFile("images/333.png");
	menuBackground.loadFromFile("images/COLOURBOX.png");

	Sprite menu1(menuTexture1), menu3(menuTexture3), about(aboutTexture), menuBg(menuBackground);

	bool isMenu = 1;
	int menuNum = 0;

	menu1.setPosition(30, 300);
	menu3.setPosition(450, 300);
	menuBg.setPosition(0, 0);

	while (isMenu)
	{
		menu1.setColor(Color::White);
		menu3.setColor(Color::White);
		menuNum = 0;
		window.clear(Color(129, 181, 221));
		window.setMouseCursorVisible(true);

		if (IntRect(30, 300, 130, 48).contains(Mouse::getPosition(window))) 
		{ 
			menu1.setColor(Color::Blue); menuNum = 1; 
		}

		if (IntRect(450, 300, 100, 100).contains(Mouse::getPosition(window))) 
		{
			menu3.setColor(Color::White); menuNum = 3; 
		}

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (menuNum == 1) isMenu = false;//game start
			if (menuNum == 3) { window.close(); isMenu = false; }

		}

		window.draw(menuBg);
		window.draw(menu1);
		window.draw(menu3);

		window.display();
	}
}