#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "drops.hpp"
#include <vector>
#include "bucket.hpp"
// If something has an origin of (x, y) then it's as if you take the (x, y)th pixel of the image and treat that as the origin of the image. So your top corner is now offset by -x, -y.

// Basically it gets the final coordinate of the top left of the image by doing position - origin

int main()
{

  
  //Declare the window and initiliaze size/title
  sf::RenderWindow window(sf::VideoMode(800,600),"Oil Panic!!!!!!");

  
  //Texture and Sprite stuff
  //Load the texture and make the sprite
  sf::Texture dropletT;
  std::vector<sf::Texture> textures;
for (int i = 0; i < 5; ++i)
  {
    textures.push_back(sf::Texture()); 
  
    if (!textures.at(i).loadFromFile("Images/simpleBucket"+std::to_string(i)+".png"))
    {
      std::cout << "Bucket texture failed to laod" << std::endl;
      textures.at(i).setSmooth(true);

      //Make that bucket smooth and aliased
    }
  }

  if (!dropletT.loadFromFile("Images/drop.png"))
    {
      std::cout << "Droplet texture failed to laod" << std::endl;
      dropletT.setSmooth(true);

      //Make that droplet smooth and aliased
    }
  //Bucket sprite
  sf::Sprite bucketS;

   sf::Vector2u winSize = window.getSize();
   Bucket buck = Bucket(textures, &bucketS, &winSize); 
  


 //Droplet sprite
  droplets drops(&dropletT,&buck, &winSize);  
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
	      int a = event.mouseWheel.delta; 
	      buck.move(a);
	     
	    }
        }
 
      //Draw shit
      window.clear(sf::Color(255,255,255));
     
      //Draw,update, and etc all the drops.
      drops.update();
      drops.draw(&window);
      buck.draw(&window);
      window.display();
      winSize = window.getSize();

    }

  return 0;

}
