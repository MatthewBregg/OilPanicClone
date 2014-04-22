#ifndef _DROPS_H_
#define _DROPS_H_
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
class drop
{
public:
  drop(sf::Texture* T);
  void draw(sf::RenderWindow* w);
  void update();
private:
  sf::Texture* t;
  sf::Sprite* droplet;
  sf::Clock pacer;
};

#endif /* _DROPS_H_ */
