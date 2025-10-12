#pragma once
#include "helperFunctions.h"


class TitleScreen {
  public:  
    TitleScreen(sf::RenderWindow &Window, sf::Event &Event, sf::Font &Font, gameParameters &Params) : 
        window(Window), event(Event), font(Font), params(Params) {};
    
    void declareTitleScreenObjects();
    void drawObjects();
    void handleTitleScreenInputs();
    

  private:
    sf::Text* active = nullptr;
    void getActiveObject();
  
    sf::Text mainTitle; 
    sf::Text pointsToWin;
    sf::Text instructions;

    sf::Text numNumbers;
    sf::Text explainNumNumbers; 
    sf::RectangleShape boxNumNumbers;

    sf::Text timePerNumber;
    sf::Text explainTimePerNumber;
    sf::RectangleShape boxTimePerNumber;

    sf::Text timeBetweenNumbers;
    sf::Text explainTimeBetweenNumbers;
    sf::RectangleShape boxTimeBetweenNumbers;

    sf::Text lowBound;
    sf::Text explainLowBound;
    sf::RectangleShape boxLowBound;

    sf::Text upperBound;
    sf::Text explainUpperBound;
    sf::RectangleShape boxUpperBound;

    sf::RenderWindow &window; 
    sf::Event &event; 
    sf::Font &font;
    gameParameters &params;
};
