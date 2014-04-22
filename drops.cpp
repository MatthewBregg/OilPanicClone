#include "drops.hpp"
drop::drop(sf::Texture* T)
{
  this->t = T;
  T->setSmooth(true);
  droplet = new sf::Sprite();
  droplet->setTexture(*T);
  
}
void drop::draw(sf::RenderWindow* w)
{
  w->draw(*droplet);
  return;
}
void drop::update()
{
       sf::Vector2f tempDrop = this->droplet->getOrigin();
       sf::Vector2f temp2(0,pacer.getElapsedTime().asSeconds()*100); 
       tempDrop -= temp2;
       pacer.restart();     
       droplet->setOrigin(tempDrop);
       return;
}
