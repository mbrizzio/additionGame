#pragma once
#include "helperFunctions.h"

class FinalGuess {
  public:
    FinalGuess(sf::RenderWindow &Window, sf::Event &Event, sf::Font &Font, gameParameters &Params) : 
        window(Window), event(Event), font(Font), params(Params) {};
  
    void declareObjects();
    void drawObjects();
    void updateCountdown(float countdown);
    void handleUserInput();
    void stateTransition();

  private:
    sf::Text userGuess;
    sf::Text explanation;
    sf::Text displayContdown;
    sf::Text resultScreen;

    sf::RenderWindow &window; 
    sf::Event &event; 
    sf::Font &font;
    gameParameters &params;
};