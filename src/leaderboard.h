#pragma once
#include "helperFunctions.h"

struct Entry {
  double points;
  string name;

  gameParameters settings;
};

class Leaderboard {
  public:
    Leaderboard(string saved, sf::RenderWindow &Window, sf::Font Font) : directory(saved), window(Window), font(Font){
      string holder;
      ifstream file(directory);

      if (file.is_open()) {
        while (getline(file, holder)) {
          cout << holder << endl;
          stringstream toParse;
          toParse << holder;

          Entry current;
          toParse >> current.points >> current.name >> current.settings.numNumbers 
                  >> current.settings.timePerNumber >> current.settings.timeBetweenNumbers
                  >> current.settings.lowBound >> current.settings.upperBound;
          
          double points = current.points;
          rankings[points] = current;
        } // rankings processing  while loop
      }
    };  

    void addEntry(gameParameters settings, string name);
    void saveLeaderboard();
    void drawLeaderboard();

    void drawObjects();
    void declareObjects();

    gameParameters getFirstSettings();

  private:
    map<double, Entry> rankings;

    string directory;
    sf::Text header;
    vector<sf::Text> displayRankngs;

    sf::Font font;
    sf::RenderWindow &window;
};

class SaveName {
  public:
    SaveName(sf::RenderWindow &Window, sf::Event &Event, sf::Font &Font, gameParameters &Params) : 
          window(Window), event(Event), font(Font), params(Params) {};

    void declareObjects();
    void drawObjects();
    void handleUserInput();
    string getName();
  
  private:
    sf::Text username;
    sf::Text explanation;

    sf::RenderWindow &window; 
    sf::Event &event; 
    sf::Font &font;
    gameParameters &params; 
};