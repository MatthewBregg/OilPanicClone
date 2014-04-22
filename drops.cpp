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
  //std::cout << bucketO.y << " and " << temp.y << std::endl;
  if ( (abs(bucketO.y - temp.y)) > 25 )
    {
      return false;
    }
  sf::FloatRect bucketBoundBox = bucket->getGlobalBounds();
  sf::FloatRect dropBoundBox = droplet->getGlobalBounds();
  if ( bucketBoundBox.intersects(dropBoundBox))
    {
      std::cout << "Caught" << std::endl;
      return true;
    }
  return false;
  
}
void drop::move(int x)
{
 
  droplet->setOrigin(-x,droplet->getOrigin().y);


}
//droplets here
droplets::droplets(sf::Texture* T, class Bucket* b, sf::Vector2u* winS)
{
  srand (time(NULL));
 
  this->t = T;
  this->winSize=winS;
  this->buck = b;
  this->bucket = buck->getBucket();
  this->spawnAmount = 1;
  this->spawnRate = sf::seconds(5);
  return;
 
  
}
void droplets::addDrop()
{
  drop temp = drop(t);
  
  temp.move(rand()%winSize->x);
  this->drops.push_back(temp);
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
	this->drops.at(i)=drops.at(drops.size()-1);
	this->drops.pop_back();
      }
    else if ( drops.at(i).hitBucket(bucket))
	 {
	   buck->hitDrop();
	   this->drops.at(i)=drops.at(drops.size()-1);
	   this->drops.pop_back();
	   return;
	
	 }
    else{
	 drops.at(i).update();
    }
  }
  if ( pacer.getElapsedTime() > spawnRate )
    {
      spawnRate -= sf::seconds(1);
      if ( spawnRate < sf::seconds(1))
	{
	  spawnRate = sf::seconds(5);
	}
      pacer.restart();
  	  this->addDrop();

    }
}
