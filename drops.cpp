#include "drops.hpp"
//Drop here
drop::drop(sf::Texture* T)
{
  this->t = T;
  T->setSmooth(true);
  droplet = new sf::Sprite();
  droplet->setTexture(*T);
  sf::FloatRect dropletSize = droplet->getLocalBounds();
  droplet->move(dropletSize.width/2, dropletSize.height/2);
  //std::cout << "Demensions are " << dropletSize.width << " and "  << dropletSize.height << std::endl;
  
  
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
bool drop::outOfBounds(sf::Vector2u* wSize)
{
  sf::Vector2f temp = this->droplet->getOrigin();
  //std::cout << temp.y  << " and " << -(signed)wSize->y << std::endl;
  if ( temp.y > -(signed)wSize->y /*&& temp.y < 0*/ )
    {

      return false;
    }

  return true;
}
bool drop::hitBucket(sf::Sprite* bucket)
{
  sf::Vector2f temp = this->droplet->getOrigin();
  sf::Vector2f bucketO = bucket->getOrigin();
  std::cout << bucketO.y << " and " << temp.y << std::endl;
  if ( (abs(bucketO.y - temp.y)) > 25 )
    {
      return false;
    }
  sf::FloatRect bucketBoundBox = bucket->getGlobalBounds();
  sf::FloatRect dropBoundBox = droplet->getGlobalBounds();
  if ( bucketBoundBox.intersects(dropBoundBox))
    {
      return true;
    }
  return false;
  
}
//droplets here
droplets::droplets(sf::Texture* T, sf::Sprite* b, sf::Vector2u* winS)
{
  this->t = T;
  this->winSize=winS;
  this->bucket = b;
  
}
void droplets::addDrop()
{
  this->drops.push_back(drop(t));
  return;

}
void droplets::draw(sf::RenderWindow* w)
{
  for (unsigned int i = 0; i < this->drops.size(); ++i)
  {
   	 drops.at(i).draw(w); 
  }
}
void droplets::update()
{

  for (unsigned int i = 0; i < this->drops.size(); ++i)
  {
    if (drops.at(i).outOfBounds(winSize) )
      {
	std::cout << "Out" << std::endl;
      }
    if ( drops.at(i).hitBucket(bucket))
	 {
	std::cout << "Bucket Hit" << std::endl;
	
	 }
	 drops.at(i).update();
  }
}
