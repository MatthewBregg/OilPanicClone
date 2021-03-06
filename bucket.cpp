#include "bucket.hpp"
Bucket::Bucket(std::vector<sf::Texture> t, sf::Sprite* b, sf::Vector2u* winS)
{
  this->score = 0;
  this->buck = b;
  this->texts = t;
  this->winSize = winS;
  buck->setTexture(texts.at(0));
  bucketX = -(signed)winSize->x/2; 
  bucketY = -(signed)winSize->y + 200;
  buck->setOrigin(sf::Vector2f(bucketX,bucketY));
  this->overflow = 0;
  this->fillStatus = 0;
}
void Bucket::draw(sf::RenderWindow* w)
{

  w->draw(*this->buck);
}
int Bucket::getOverFlows()
{
  return overflow;
}
void Bucket::update()
{
  if (fillStatus == (signed)texts.size()-1 || fillStatus == (signed)texts.size()-2)
    {
      if ( timer.getElapsedTime() > sf::seconds(1))
	{
	  fillStatus = 0;
	  buck->setTexture(texts.at(0));
	}
    }
}
void Bucket::emptyBucket(sf::Sprite* A)
{
  sf::FloatRect collectorBounds = A->getGlobalBounds();
  sf::FloatRect bucketBounds = buck->getLocalBounds();
  sf::Vector2f point = sf::Vector2f(-(signed)buck->getOrigin().x+bucketBounds.width/2,-(signed)A->getOrigin().y);

  if ( collectorBounds.contains(point) && fillStatus > 0)
    {

  buck->setTexture(texts.at(texts.size()-2));
  score+=fillStatus;
  fillStatus=texts.size()-2;
  timer.restart();
    }
  
}
void Bucket::move(int A)
{
  if ( (bucketX > -(signed)winSize->x+50 && A < 0 ) || ( bucketX < 50 && A > 0) )
    {
      bucketX += 15*A;
      // std::cout << " Position is X " << bucketS.getPosition().x << " Origin is " << bucketS.getOrigin().x << std::endl;
      // std::cout << " Position is Y " << bucketS.getPosition().y << " Origin is " << bucketS.getOrigin().y << std::endl;
      buck->setOrigin(sf::Vector2f(bucketX,bucketY));


    }
  // 	std::cout << "wheel movement: " << event.mouseWheel.delta << std::endl;
  // 	std::cout << "mouse x: " << event.mouseWheel.x << std::endl;
  // 	std::cout << "mouse y: " << event.mouseWheel.y << std::endl;
}

sf::Sprite* Bucket::getBucket()
{
  return buck;
}
void Bucket::hitDrop()
{
  //Check if the bucket is full

  if (  fillStatus > (signed)texts.size() -4 )
    {
      overflow++;
      fillStatus = texts.size()-1;
      timer.restart();
    }
  else{
    fillStatus++;
    score++;
  }
  std::cout << "Fill is " << fillStatus<< std::endl;

  buck->setTexture(texts.at(fillStatus));

  
}
int Bucket::getScore()
{
  return score;
}
