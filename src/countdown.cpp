#include "countdown.h"

void CountdownScreen::declareObjects() {
  displayCountdown.setFillColor(sf::Color::White);
  displayCountdown.setFont(font);
  displayCountdown.setCharacterSize(100);
  displayCountdown.setString("3.00");

  centerOrigin(&displayCountdown);
  displayCountdown.setPosition(1280/2, 720/2);
}

void CountdownScreen::updateObjects(float countdown) {
  ostringstream dummy;
  dummy << fixed << setprecision(2) << countdown;

  displayCountdown.setString(dummy.str());
  centerOrigin(&displayCountdown);
  displayCountdown.setPosition(1280/2, 720/2);

  if (countdown < 1) {
      displayCountdown.setFillColor(sf::Color(255, 255, 255, 255 * countdown));
  }
}

void CountdownScreen::drawObjects() {
  window.draw(displayCountdown);
}