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
  Entry rank = {round(params.points * 100.0) / 100.0, name, params};
  rankings[params.points] = rank;
}

void Leaderboard::declareObjects() {
  header.setFont(font);
  header.setFillColor(sf::Color::Red);
  header.setCharacterSize(24);
  header.setString("Player          Points         ");

  //centerOrigin(&header);
  header.setPosition(600, 100);

  for (auto c = rankings.rbegin(); c != rankings.rend(); ++c) {
    sf::Text current;
    current.setFont(font);
    current.setFillColor(sf::Color::White);
    current.setCharacterSize(24);
    
    string display = c->second.name;
    display.append(16 - display.size(), ' ');

    double value = round(c->second.points * 100.0) / 100.0;
    ostringstream out;
    out << fixed << setprecision(2) << value;
    string s = out.str();
    display.append(s);

    current.setString(display);
    //centerOrigin(&current);

    displayRankngs.push_back(current);
  }
}

void Leaderboard::drawLeaderboard() {
  float y = 50;

  for (int i = 0; i < displayRankngs.size(); ++i) {
    if (i == 0) displayRankngs[i].setFillColor(sf::Color::Yellow);
    
    displayRankngs[i].setPosition(600, 150 + y*i);

    window.draw(displayRankngs[i]);
  }
}

void Leaderboard::drawObjects() {
  
  window.draw(header);
  drawLeaderboard();
  window.draw(header);
}

void Leaderboard::saveLeaderboard() {
  ofstream file(directory);

  if (!file.is_open()) exit(1);

  for (auto i : rankings) {
    const Entry &relevant = i.second;
    const gameParameters &params = relevant.settings;

    file << to_string(relevant.points) << " " << relevant.name << " " << params.numNumbers 
         << " " << params.timePerNumber << " " << params.timeBetweenNumbers << " " << params.lowBound 
         << " " << params.upperBound << endl;
  }
}