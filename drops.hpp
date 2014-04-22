#ifndef _DROPS_H_
#define _DROPS_H_
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>
#include "bucket.hpp"
class drop
{
public:
  drop(sf::Texture* T);
  void draw(sf::RenderWindow* w);
  void update();
  bool outOfBounds(sf::Vector2u* wSize);
  bool hitBucket(sf::Sprite* bucket);
private:
  sf::Texture* t;
  sf::Sprite* droplet;
  sf::Clock pacer;
};
class droplets
{
public:
  droplets(sf::Texture* T, Bucket* b, sf::Vector2u* winS);
  void draw(sf::RenderWindow* w);
  void addDrop();
  void update();
private:
  std::vector<drop> drops;
  sf::Texture* t;
  sf::Vector2u* winSize;
  Bucket* buck; 
  sf::Sprite* bucket;

};
  

#endif /* _DROPS_H_ */
