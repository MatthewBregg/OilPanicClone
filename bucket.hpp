#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <vector>

#ifndef _BUCKET_H_
#define _BUCKET_H_
class Bucket
{
public:
  Bucket(std::vector<sf::Texture> t, sf::Sprite* b, sf::Vector2u* winS);
  void draw(sf::RenderWindow* w);
  void update();
  void move(int A);
  sf::Sprite* getBucket();
  void hitDrop();
  int getOverFlows();
  int getScore();
private:
  int score;
  sf::Sprite* buck;
  std::vector<sf::Texture> texts; 
  sf::Vector2u* winSize;
  int bucketX;
  int bucketY;
  int overflow;
  int fillStatus;
  sf::Clock timer;
};


#endif /* _BUCKET_H_ */
