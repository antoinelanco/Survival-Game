#include <SFML/Graphics.hpp>
#include <iostream>

class Personnage {
private:
  int vie;
  sf::Texture texture[4][11];
  sf::Sprite sprite;
  int orientation;
  int iter;
  int counter;
  int x;
  int y;
public:
    Personnage() {
      vie = 100;
      counter = 0;
      orientation = 0;
      iter = 0;
      x = 0;
      y = 0;
      // texture.setRepeated(true);
      sprite.scale(sf::Vector2f(0.5f, 0.5f));
      sprite.setPosition(100, 100);

      for (size_t i = 0; i < 4; i++) {
        texture[i][0].loadFromFile("img/zelda.png", sf::IntRect(0, (i*129), 119, 129));
        for (size_t j = 1; j < 11; j++) {
          texture[i][j].loadFromFile("img/zelda.png", sf::IntRect(119*(j-1), 516+(i*129), 119, 129));

        }
      }
    }


    int getVie(){
      return vie;
    }

    int getx(){return x;}
    int gety(){return y;}

    void moveLeft(){
      orientation=1;
      // sprite.move(-1.f, 0.f);
      x--;
      // std::cout << "x" << x << "y" << y << '\n';
    }

    void moveRight(){
      orientation=3;
      // sprite.move(1.f, 0.f);
      x++;
      // std::cout << "x" << x << "y" << y << '\n';

    }
    void moveUp(){
      orientation=2;
      // sprite.move(0.f, -1.f);
      y--;
      // std::cout << "x" << x << "y" << y << '\n';

    }
    void moveDown(){
      orientation=0;
      // sprite.move(0.f, 1.f);
      y++;
      // std::cout << "x" << x << "y" << y << '\n';

    }

    void stop(){
      iter = 0;
    }

    sf::Sprite getSprite(){

      sprite.setTexture(texture[orientation][iter]);

      if (counter > 50){
        iter = ((iter +1 )%10) +1;
        counter = 0;
      }
      counter++;
      return sprite;

    }
};
