#include "bucket.hpp"
bucket::bucket(std::vector<sf::Texture> t, sf::Sprite* b, sf::Vector2u* winS)
{
  this->buck = b;
  this->texts = t;
  this->winSize = winS;
}
void bucket::draw(sf::RenderWindow* w)
{
  w->draw(*this->buck);
}

