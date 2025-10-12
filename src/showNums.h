#pragma once
#include "helperFunctions.h"

class NumberHandler {
  public:
    NumberHandler(sf::RenderWindow &Window, sf::Event &Event, sf::Font &Font, gameParameters &Params) : 
        window(Window), event(Event), font(Font), params(Params) {};
  
    void declareObjects();
    void drawObjects();
    void updateObjects(float countdown);
    State pickNum();

  private:
    sf::Text displayNumber;

    sf::RenderWindow &window; 
    sf::Event &event; 
    sf::Font &font;
    gameParameters &params;
};