#include <iostream>
#include <SFML/Graphics.hpp>
#include "carte.cpp"
#include "personnage.cpp"

int main() {


  Personnage p1 = Personnage();
  Carte map = Carte();

  sf::RenderWindow window(sf::VideoMode(200, 200), "Surival Game!");




  while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
          switch (event.type) {
              // window closed
              case sf::Event::Closed:
                window.close();
                break;
              default:
                break;
          }

      }




      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
      { p1.moveLeft();
        map.moveLeft(); }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
      { p1.moveRight();
        map.moveRight();}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
      { p1.moveUp();
        map.moveUp(); }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
      { p1.moveDown();
        map.moveDown(); }
      if (!(sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ||
           sf::Keyboard::isKeyPressed(sf::Keyboard::Down))) {
             p1.stop();
      }





      window.clear();
      window.draw(map.getSprite(p1.getx(), p1.gety()));
      window.draw(p1.getSprite());
      window.display();
      sf::sleep(sf::seconds(0.005f));

  }

  return 0;
}
