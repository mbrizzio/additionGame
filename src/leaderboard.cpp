#include "leaderboard.h"

void SaveName::declareObjects() {
  username.setFillColor(sf::Color::White);
  username.setFont(font);
  username.setCharacterSize(100);
  username.setString("");

  centerOrigin(&username);

  username.setPosition(1280/2, 720/2);


  explanation.setFillColor(sf::Color::White);
  explanation.setFont(font);
  explanation.setCharacterSize(48);
  explanation.setString("Write your name to save your score!");

  centerOrigin(&explanation);

  explanation.setPosition(1280/2, 720/2 - 100);
}

void SaveName::drawObjects() {
  window.draw(username);
  window.draw(explanation);
}

void SaveName::handleUserInput() {
   // If we detect a backspace, delete the last character
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::BackSpace) {
        string value = username.getString().toAnsiString();
        
        if (!value.empty()) {
            value.pop_back();
            username.setString(value);

            centerOrigin(&username);

            cout << value << endl;
        }
    }
    
    // If we detect a keypress, add it to the current string
    if (event.type == sf::Event::TextEntered && 
              event.text.unicode >= 32 && event.text.unicode < 127){
        
        string value = username.getString().toAnsiString();
        
        if (value.size() < 15) {
            value += static_cast<char>(event.text.unicode);

            username.setString(value);
            centerOrigin(&username);

            cout << value << endl;
        }
    }
} // HandleUserInput

string SaveName::getName() {
  return username.getString().toAnsiString();
}

gameParameters Leaderboard::getFirstSettings() {
  return (*rankings.rbegin()).second.settings;
}

void Leaderboard::addEntry(gameParameters params, string name) {                       
  Entry rank = {params.points, name, params};
  rankings[params.points] = rank;
}