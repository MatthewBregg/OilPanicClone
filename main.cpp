#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "drops.hpp"
#include <vector>
// If something has an origin of (x, y) then it's as if you take the (x, y)th pixel of the image and treat that as the origin of the image. So your top corner is now offset by -x, -y.

// Basically it gets the final coordinate of the top left of the image by doing position - origin

int main()
{

  
  //Declare the window and initiliaze size/title
  sf::RenderWindow window(sf::VideoMode(800,600),"Oil Panic!!!!!!");

  
  //Texture and Sprite stuff
  //Load the texture and make the sprite
  sf::Texture bucketT;
  sf::Texture dropletT;

  if (!bucketT.loadFromFile("Images/simpleBucket.png"))
    {
      std::cout << "Bucket texture failed to laod" << std::endl;
      bucketT.setSmooth(true);

      //Make that bucket smooth and aliased
    }

  if (!dropletT.loadFromFile("Images/drop.png"))
    {
      std::cout << "Droplet texture failed to laod" << std::endl;
      dropletT.setSmooth(true);

      //Make that droplet smooth and aliased
    }
  //Bucket sprite
  sf::Sprite bucketS;
  bucketS.setTexture(bucketT);
  //Set the bucket to a resonable size
   sf::Vector2u winSize = window.getSize();
  
  sf::FloatRect bucketBoundBox = bucketS.getGlobalBounds();

  int bucketX = -(signed)winSize.x/2; 
  const int bucketY = -(signed)winSize.y + 200;
  bucketS.setOrigin(sf::Vector2f(bucketX,bucketY));
 //Droplet sprite
  droplets drops(&dropletT,&bucketS, &winSize);  
  drops.addDrop();
  
  //Begin all the window stuff

  while (window.isOpen())
    {
      // check all the window's events that were triggered since the last iteration of the loop
      sf::Event event;
      //handle window events
      while (window.pollEvent(event))
        {
	  // "close requested" event: we close the window
	  if (event.type == sf::Event::Closed)
	    window.close();
	  if ( event.type == sf::Event::LostFocus)
	    {

	      std::cout << "Lost focus" << std::endl;
	    }
	  if ( event.type == sf::Event::GainedFocus)
	    {
	      std::cout << "Gained Focus" << std::endl;
	    }
	  if (event.type == sf::Event::MouseWheelMoved)
	    {
	      
	     
	      if ( (bucketX > -(signed)winSize.x+50 && event.mouseWheel.delta < 0 ) || ( bucketX < 50 && event.mouseWheel.delta > 0) )
		{
		  bucketX += 15*event.mouseWheel.delta;
		  // std::cout << " Position is X " << bucketS.getPosition().x << " Origin is " << bucketS.getOrigin().x << std::endl;
		  // std::cout << " Position is Y " << bucketS.getPosition().y << " Origin is " << bucketS.getOrigin().y << std::endl;
		  bucketS.setOrigin(sf::Vector2f(bucketX,bucketY));
		  bucketBoundBox = bucketS.getGlobalBounds();

		}
	      // 	std::cout << "wheel movement: " << event.mouseWheel.delta << std::endl;
	      // 	std::cout << "mouse x: " << event.mouseWheel.x << std::endl;
	      // 	std::cout << "mouse y: " << event.mouseWheel.y << std::endl;
	    }
        }
 
      //Draw shit
      window.clear(sf::Color(255,255,255));
      window.draw(bucketS);
      //Draw,update, and etc all the drops.
      drops.update();
      drops.draw(&window);
      window.display();
      winSize = window.getSize();

    }

  return 0;

}
