#pragma once
#include "helperFunctions.h"

class CountdownScreen {
  public:
    CountdownScreen(sf::RenderWindow &Window, sf::Event &Event, sf::Font &Font) :
      window(Window), event(Event), font(Font) {};
    
      void declareObjects();
      void updateObjects(float countdown);
      void drawObjects();

  private:
    sf::RenderWindow &window; 
    sf::Event &event; 
    sf::Font &font; 

    sf::Text displayCountdown;
};