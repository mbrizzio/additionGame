#include "helperFunctions.h"
#include "titleScreen.h"
#include "countdown.h"
#include "showNums.h"
#include "finalGuess.h"

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

    // Show the numbers and wait a bit 
    NumberHandler numberHandler(window, event, arial, params);
    numberHandler.declareObjects();

    // Guess from the User
    FinalGuess finalGuess(window, event, arial, params);
    finalGuess.declareObjects();    

    sf::Clock clock;
    float countdown, betweenCountdown, numCountdown, guessCountdown, resultCountdown;
    guessCountdown = 15.f;
    resultCountdown = 3.f;
    
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
                        countdown = 2.0f;
                        clock.restart();

                        params.chooseNums();
                    }
                    break;
                }

                case State::COUNTDOWN: {
                    // No inputs to process here

                    break;
                }

                case State::BETWEENNUM: {
                    // No inputs to process here

                    break;
                }

                case State::SHOWNUM: {
                    // No inputs to process here

                    break;
                }

                case State::GUESS: {
                    finalGuess.handleUserInput();

                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                        machine = State::RESULT;
                        clock.restart();

                        finalGuess.stateTransition();

                        cout << "switching to results due to user input" << endl;
                    }
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
                if (countdown <= 0.02) {
                    machine = State::BETWEENNUM;
                    betweenCountdown = params.timeBetweenNumbers / 100.f;

                    clock.restart();

                    cout << "Switching to between nums" << endl;

                    continue;
                }

                countdown -= clock.restart().asSeconds();
                
                countdownScreen.updateObjects(countdown);
                countdownScreen.drawObjects();
                break;
            }

            case State::SHOWNUM: {
                if (numCountdown <= 0) {
                    machine = State::BETWEENNUM;
                    betweenCountdown = params.timeBetweenNumbers / 100.f;

                    clock.restart();

                    cout << "Switching to between nums" << endl;

                    continue;
                }

                numCountdown -= clock.restart().asSeconds();

                cout << "numCountdown: " << numCountdown << endl;

                numberHandler.updateObjects(numCountdown);
                numberHandler.drawObjects();

                break;
            }

            case State::BETWEENNUM: {
                if (betweenCountdown <= 0) {
                    machine = numberHandler.pickNum();
                    numCountdown = params.timePerNumber / 100.f;

                    clock.restart();

                    cout << "Switching to next num " << numCountdown << endl;

                    continue;
                }

                betweenCountdown -= clock.restart().asSeconds();

                cout << "Between clock: " << betweenCountdown << endl;

                break;
            }

            case State::GUESS: {
                if (guessCountdown <= 0) {
                    clock.restart();

                    cout << "Switching to result " << endl;

                    finalGuess.stateTransition();
                    machine = State::RESULT;

                    continue;
                }

                guessCountdown -= clock.restart().asSeconds();

                finalGuess.updateCountdown(guessCountdown);
                finalGuess.drawObjects();

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
