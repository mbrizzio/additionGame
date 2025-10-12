#include "finalGuess.h"

void FinalGuess::declareObjects() {
  // User guess, which is constantly updated
  userGuess.setFillColor(sf::Color::White);
  userGuess.setFont(font);
  userGuess.setCharacterSize(100);
  userGuess.setString("0");

  centerOrigin(&userGuess);

  userGuess.setPosition(1280/2, 720/2);



  explanation.setFillColor(sf::Color::White);
  explanation.setFont(font);
  explanation.setCharacterSize(48);
  explanation.setString("What do you think the sum is? Write your best guess!");

  centerOrigin(&explanation);

  explanation.setPosition(1280/2, 720/2 - 100);


  // Put a little pressure on them
  displayContdown.setFillColor(sf::Color::White);
  displayContdown.setFont(font);
  displayContdown.setCharacterSize(12);
  displayContdown.setString("15.00");

  displayContdown.setPosition(0, 0);



  // Final result
  resultScreen.setFillColor(sf::Color::White);
  resultScreen.setFont(font);
  resultScreen.setCharacterSize(48);
  resultScreen.setString("Good luck");

  centerOrigin(&resultScreen);

  resultScreen.setPosition(1280/2, 720/2 - 100);
}

void FinalGuess::updateCountdown(float countdown) {
  ostringstream dummy;
  dummy << fixed << setprecision(2) << countdown;

  displayContdown.setString(dummy.str());
}

void FinalGuess::updateResult() {
  if (params.guess == params.sum){
    resultScreen.setString("Congratulations! The correct sum indeed was " + to_string(params.guess));
    cout << "winner!" << endl;
  }
  else {
    resultScreen.setString("Tough luck! \nThe correct answer was " + to_string(params.sum) + " \nwhile you guessed " + to_string(params.guess));
    cout << "loser!" << endl;
  }

  centerOrigin(&resultScreen);
  resultScreen.setPosition(1280/2, 720/2);
}

void FinalGuess::drawResult() {
  window.draw(resultScreen);
}

void FinalGuess::drawObjects() {
  window.draw(userGuess);
  window.draw(explanation);
  window.draw(displayContdown);
}

void FinalGuess::stateTransition() {
  params.guess = stoi(userGuess.getString().toAnsiString());

  updateResult();
}

void FinalGuess::handleUserInput() {
   // If we detect a backspace, delete the last character
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::BackSpace) {
        string value = userGuess.getString().toAnsiString();
        
        if (!value.empty()) {
            value.pop_back();
            userGuess.setString(value);

            if (value.empty()) userGuess.setString("0");

            centerOrigin(&userGuess);

            cout << value << endl;
        }
    }
    
    // If we detect a keypress, add it to the current string
    else if (event.type == sf::Event::TextEntered && 
            ranges::find(params.validUnicode, 
                            static_cast<char>(event.text.unicode)) != params.validUnicode.end()){
        
        string value = userGuess.getString().toAnsiString();
        
        if (value[0] == '0') value.pop_back();

        if (value.size() < 10) {
            value += static_cast<char>(event.text.unicode);

            userGuess.setString(value);
            centerOrigin(&userGuess);

            cout << value << endl;
        }
    }
}