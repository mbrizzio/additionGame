#include "showNums.h"


void NumberHandler::declareObjects(){
  displayNumber.setFillColor(sf::Color::White);
  displayNumber.setFont(font);
  displayNumber.setCharacterSize(100);
  displayNumber.setString("0");

  centerOrigin(&displayNumber);

  // Experiment to make text right alligned
  displayNumber.setOrigin(displayNumber.getLocalBounds().width, displayNumber.getOrigin().y);

  displayNumber.setPosition(1280/2, 720/2);
}

void NumberHandler::drawObjects() {
  window.draw(displayNumber);
}

State NumberHandler::pickNum() {
  if (params.nums.empty()) return State::GUESS;

  params.currentNum = params.nums.back();
  params.nums.pop_back();

  params.sum += params.currentNum;

  displayNumber.setString(to_string(params.currentNum));

  displayNumber.setFillColor(sf::Color::White);

  return State::SHOWNUM;
}

void NumberHandler::updateObjects(float countdown) {
  float alpha = 255 * (400*countdown) / params.timePerNumber;
  
  if (alpha < 255) {
    cout << alpha << endl;

    displayNumber.setFillColor(sf::Color(255, 255, 255, (sf::Uint8)max((int)alpha, 0)));
  }
}