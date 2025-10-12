#include "helperFunctions.h"
#include "titleScreen.h"


int main() {
    // Pre window drawing
    gameParameters params;

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

    // Objects controlling the different states
    TitleScreen titleScreen(window, event, arial, params);
    titleScreen.declareTitleScreenObjects();


    // Set the state
    State machine = State::TITLE;

    // Keep the window open
    while  (window.isOpen()){
        
        // Process all events sent to the window in the last frame
        while (window.pollEvent(event)) {
            
            // Stuff that needs to happen no matter what state we are on
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }


            // Draw what is needed for the current state
            switch (machine) {
                case State::TITLE: {
                    titleScreen.updateTitleScreen();
                    
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                        machine = State::COUNTDOWN;
                    }
                    break;
                }
                case State::COUNTDOWN: {
                    
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
