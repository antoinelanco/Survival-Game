#include <SFML/Graphics.hpp>
#include <iostream>

class Carte {
private:
  sf::Texture texture;
    sf::Sprite sprite;
public:
    Carte() {
      texture.loadFromFile("img/map.png", sf::IntRect(0, 0, 500, 500));

    }

    void moveLeft(){
      sprite.move(1.f, 0.f);
    }

    void moveRight(){
      sprite.move(-1.f, 0.f);
    }
    void moveUp(){
      sprite.move(0.f, 1.f);
    }
    void moveDown(){
      sprite.move(0.f, -1.f);
    }

    sf::Sprite getSprite(int x, int y){

      sprite.setTexture(texture);

      return sprite;

    }

};
