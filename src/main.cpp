#include "helperFunctions.h"
#include "titleScreen.h"
#include "countdown.h"


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

    // Countdown state
    CountdownScreen countdownScreen(window, event, arial);
    countdownScreen.declareObjects();
    

    sf::Clock clock;
    float countdown;
    
    // Set the state
    State machine = State::TITLE;

    // Keep the window open
    while  (window.isOpen()){
        
        //////////////////////////////// INPUT PROCESSING /////////////////////////////////////////
        // Process all events sent to the window in the last frame
        while (window.pollEvent(event)) {
            // Stuff that needs to happen no matter what state we are on
            if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                window.close();
            }


            // Draw what is needed for the current state
            switch (machine) {
                case State::TITLE: {
                    titleScreen.handleTitleScreenInputs();
                    
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                        machine = State::COUNTDOWN;
                        countdown = 3.0f;
                        clock.restart();
                    }
                    break;
                }

                case State::COUNTDOWN: {
                    // No inputs to process here

                    break;
                }

                default: {
                    window.clear(sf::Color::Black);    
                    break;
                }
            } // Input handler state machine
          
        } // poll event loop
        //////////////////////////////// INPUT PROCESSING END ////////////////////////////////////
        
        
        ////////////////////////////// DRAWING //////////////////////////////////////////////////
        window.clear(sf::Color::Black);
        switch (machine) {
            case State::TITLE: {
                titleScreen.drawObjects();

                break;
            }

            case State::COUNTDOWN: {
                if (countdown <= 0.1) {
                    machine = State::SHOWNUM;
                    continue;
                }

                countdown -= clock.restart().asSeconds();
                cout << countdown << endl;

                
                countdownScreen.updateObjects(countdown);
                countdownScreen.drawObjects();
                break;
            }

            case State::SHOWNUM: {
                window.close();

                break;
            }

            default: {
                window.clear(sf::Color::Black);    
                break;
            }
        } // Drawing logic state machine

        
        // Display what you drew this frame
        window.display();

        //////////////////////////////// DRAWING END /////////////////////////////////
    }
    
    return 0;
}
