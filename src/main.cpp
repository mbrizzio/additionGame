#pragma once
#include "helperFunctions.h"

using namespace std;

enum State {
    TITLE
};


int main() {
    // Pre window drawing
    const vector<char> validUnicode = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    string numNumbers = "";
    
    // Window drawing
    sf::RenderWindow window(sf::VideoMode(1280, 720), "Addition Game");
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(144);

    // Be able to capture events happening in the window
    sf::Event event;

    // Load the font for later use
    sf::Font arial;
    if (!arial.loadFromFile("../src/assets/arial.ttf")) {
        cerr << "Font file not found" << endl;
        exit(1);
    }


    // Set the state
    State machine = State::TITLE;

    // Keep the window open
    while  (window.isOpen()){
        
        // Process all events sent to the window in the last frame
        while (window.pollEvent(event)) {
            
            // Stuff that needs to happen no matter what state we are on
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Draw what is needed for the current state
            switch (machine) {
                case State::TITLE: {
                    window.clear(sf::Color::Black);
                    
                    // Declare the main title
                    sf::Text displayMainTitle;
                    displayMainTitle.setFont(arial);
                    displayMainTitle.setCharacterSize(48);
                    displayMainTitle.setFillColor(sf::Color::White);
                    displayMainTitle.setString("The Addition Game");

                    centerOrigin(displayMainTitle);
                    displayMainTitle.setPosition(1280/2, 100);

                    // Declare the numNumbers string
                    sf::Text displayNumNumbers;
                    displayNumNumbers.setFont(arial);
                    displayNumNumbers.setCharacterSize(24);
                    displayNumNumbers.setFillColor(sf::Color::White);
                    displayNumNumbers.setString(numNumbers);

                    centerOrigin(displayNumNumbers);
                    displayNumNumbers.setPosition(1280/2, 300);
                    
                    
                    // If we detect a backspace, delete the last character
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::BackSpace) {
                        if (!numNumbers.empty()) numNumbers.pop_back();
                        cout << numNumbers << endl;
                    }
                    
                    // If we detect a keypress, add it to the current string
                    else if (event.type == sf::Event::TextEntered && 
                             ranges::find(validUnicode, static_cast<char>(event.text.unicode)) != validUnicode.end()){
                        
                        numNumbers += static_cast<char>(event.text.unicode);
                        cout << numNumbers << endl;
                    }

                    // Draw all the text. Do this at the end so all the postprocessing is done!

                    window.draw(displayMainTitle);
                    window.draw(displayNumNumbers);

                    break;
                }
                default: {
                    window.clear(sf::Color::Black);    
                    break;
                }
        }
          
        }   

        

        // Display what you drew this frame
        window.display();
    }
    
    return 0;
}
