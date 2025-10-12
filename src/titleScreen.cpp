#include "titleScreen.h"
#include "helperFunctions.h"



void TitleScreen::declareTitleScreenObjects() {
    // Declare the main title
    mainTitle.setFont(font);
    mainTitle.setCharacterSize(48);
    mainTitle.setFillColor(sf::Color::White);
    mainTitle.setString("The Addition Game! Potential Score: ");

    centerOrigin(&mainTitle);
    mainTitle.setPosition(1280/2, 100);



    // How many points you are looking to win
    params.calculatePoints();
    pointsToWin.setFont(font);
    pointsToWin.setCharacterSize(48);
    pointsToWin.setFillColor(sf::Color::White);
    ostringstream dummy;
    dummy << fixed << setprecision(2) << params.points;
    pointsToWin.setString(dummy.str());
    
    pointsToWin.setOrigin(0, pointsToWin.getLocalBounds().top + pointsToWin.getLocalBounds().height/2.f);
    pointsToWin.setPosition(mainTitle.getPosition().x + mainTitle.getLocalBounds().width/2.f, mainTitle.getPosition().y);



    // Give player guidance
    instructions.setFont(font);
    instructions.setCharacterSize(18);
    instructions.setFillColor(sf::Color::White);
    instructions.setString("Click on the boxes and type to change parameters. Press 'enter' when you are ready!");

    centerOrigin(&instructions);
    instructions.setPosition(1280/2, 700);

    // Declare the numNumbers string. This is what the user edits
    numNumbers.setFont(font);
    numNumbers.setCharacterSize(24);
    numNumbers.setFillColor(sf::Color::White);
    numNumbers.setString(to_string(params.numNumbers));

    centerOrigin(&numNumbers);
    numNumbers.setPosition(1280/2, 200);

    // Declare the numNumbers explanation, so the user knows what's going on
    explainNumNumbers.setFont(font);
    explainNumNumbers.setCharacterSize(24);
    explainNumNumbers.setFillColor(sf::Color::White);
    explainNumNumbers.setString("How many numbers to you want to add up?");

    centerOrigin(&explainNumNumbers);
    explainNumNumbers.setPosition(1280/2, 170);

    // Bounding box for numNumbers
    sf::FloatRect dimentionsHelperNumNumbers = numNumbers.getLocalBounds();
    boxNumNumbers.setSize(sf::Vector2f(700, dimentionsHelperNumNumbers.height+10));
    boxNumNumbers.setOutlineThickness(1.f);
    boxNumNumbers.setOutlineColor(sf::Color::White);
    boxNumNumbers.setFillColor(sf::Color::Transparent);

    centerOrigin(&boxNumNumbers);
    boxNumNumbers.setPosition(1280/2, 200);



    // Declare the secondsPerNumber string. This is what the user edits
    timePerNumber.setFont(font);
    timePerNumber.setCharacterSize(24);
    timePerNumber.setFillColor(sf::Color::White);
    timePerNumber.setString(to_string(params.timePerNumber));

    centerOrigin(&timePerNumber);
    timePerNumber.setPosition(1280/2, 300);

    // Declare the explanation for timePerNumber
    explainTimePerNumber.setFont(font);
    explainTimePerNumber.setCharacterSize(24);
    explainTimePerNumber.setFillColor(sf::Color::White);
    explainTimePerNumber.setString("How may centiseconds do you want the numbers to last on screen?");

    centerOrigin(&explainTimePerNumber);
    explainTimePerNumber.setPosition(1280/2, 270);

    // Declare the box for timePerNumber
    sf::FloatRect dimentionsHelperSecondsPerNumber = timePerNumber.getLocalBounds();
    boxTimePerNumber.setSize(sf::Vector2f(700, dimentionsHelperSecondsPerNumber.height+10));
    boxTimePerNumber.setOutlineThickness(1.f);
    boxTimePerNumber.setOutlineColor(sf::Color::White);
    boxTimePerNumber.setFillColor(sf::Color::Transparent);

    centerOrigin(&boxTimePerNumber);
    boxTimePerNumber.setPosition(1280/2, 300);



    // Declare the timeBetweenNumbers string. This is what the user edits
    timeBetweenNumbers.setFont(font);
    timeBetweenNumbers.setCharacterSize(24);
    timeBetweenNumbers.setFillColor(sf::Color::White);
    timeBetweenNumbers.setString(to_string(params.timeBetweenNumbers));

    centerOrigin(&timeBetweenNumbers);
    timeBetweenNumbers.setPosition(1280/2, 400);

    // Declare the explanation for timeBetweenNumbers
    explainTimeBetweenNumbers.setFont(font);
    explainTimeBetweenNumbers.setCharacterSize(24);
    explainTimeBetweenNumbers.setFillColor(sf::Color::White);
    explainTimeBetweenNumbers.setString("How many centiseconds between numbers do you want?");

    centerOrigin(&explainTimeBetweenNumbers);
    explainTimeBetweenNumbers.setPosition(1280/2, 370);

    // Declare the box for timeBetweenNumbers
    sf::FloatRect dimentionsHelperSecondsBetweenNumbers = timeBetweenNumbers.getLocalBounds();
    boxTimeBetweenNumbers.setSize(sf::Vector2f(700, dimentionsHelperSecondsBetweenNumbers.height+10));
    boxTimeBetweenNumbers.setOutlineThickness(1.f);
    boxTimeBetweenNumbers.setOutlineColor(sf::Color::White);
    boxTimeBetweenNumbers.setFillColor(sf::Color::Transparent);

    centerOrigin(&boxTimeBetweenNumbers);
    boxTimeBetweenNumbers.setPosition(1280/2, 400);



    // Declare the lowBound string. This is what the user edits
    lowBound.setFont(font);
    lowBound.setCharacterSize(24);
    lowBound.setFillColor(sf::Color::White);
    lowBound.setString(to_string(params.lowBound));

    centerOrigin(&lowBound);
    lowBound.setPosition(1280/2, 500);

    // Declare the explanation for lowBound
    explainLowBound.setFont(font);
    explainLowBound.setCharacterSize(24);
    explainLowBound.setFillColor(sf::Color::White);
    explainLowBound.setString("What is the lower bound for the numbers?");

    centerOrigin(&explainLowBound);
    explainLowBound.setPosition(1280/2, 470);

    // Declare the box for lowBound
    sf::FloatRect dimentionsHelperLowBound = lowBound.getLocalBounds();
    boxLowBound.setSize(sf::Vector2f(700, dimentionsHelperLowBound.height+10));
    boxLowBound.setOutlineThickness(1.f);
    boxLowBound.setOutlineColor(sf::Color::White);
    boxLowBound.setFillColor(sf::Color::Transparent);

    centerOrigin(&boxLowBound);
    boxLowBound.setPosition(1280/2, 500);



    // Declare the upperBound string. This is what the user edits
    upperBound.setFont(font);
    upperBound.setCharacterSize(24);
    upperBound.setFillColor(sf::Color::White);
    upperBound.setString(to_string(params.upperBound));

    centerOrigin(&upperBound);
    upperBound.setPosition(1280/2, 600);

    // Declare the explanation for upperBound
    explainUpperBound.setFont(font);
    explainUpperBound.setCharacterSize(24);
    explainUpperBound.setFillColor(sf::Color::White);
    explainUpperBound.setString("What is the upper bound for the numbers?");

    centerOrigin(&explainUpperBound);
    explainUpperBound.setPosition(1280/2, 570);

    // Declare the box for upperBound
    sf::FloatRect dimentionsHelperUpperBound = upperBound.getLocalBounds();
    boxUpperBound.setSize(sf::Vector2f(700, dimentionsHelperUpperBound.height+10));
    boxUpperBound.setOutlineThickness(1.f);
    boxUpperBound.setOutlineColor(sf::Color::White);
    boxUpperBound.setFillColor(sf::Color::Transparent);

    centerOrigin(&boxUpperBound);
    boxUpperBound.setPosition(1280/2, 600);
}

void TitleScreen::drawObjects() {
    window.draw(mainTitle);
    window.draw(instructions);

    ostringstream dummy;
    dummy << fixed << setprecision(2) << params.points;
    pointsToWin.setString(dummy.str());
    window.draw(pointsToWin);

    window.draw(numNumbers);
    window.draw(explainNumNumbers);
    window.draw(boxNumNumbers);

    window.draw(timePerNumber);
    window.draw(explainTimePerNumber);
    window.draw(boxTimePerNumber);

    window.draw(timeBetweenNumbers);
    window.draw(explainTimeBetweenNumbers);
    window.draw(boxTimeBetweenNumbers);

    window.draw(lowBound);
    window.draw(explainLowBound);
    window.draw(boxLowBound);

    window.draw(upperBound);
    window.draw(explainUpperBound);
    window.draw(boxUpperBound);
}

void TitleScreen::getActiveObject() {
    sf::Vector2i position = sf::Mouse::getPosition(window);

    // All the bounding boxes are in the same horizontal position, so we can get this check out of the way
    if (position.x < boxNumNumbers.getPosition().x - boxNumNumbers.getLocalBounds().width/2.f ||
        position.x > boxNumNumbers.getPosition().x + boxNumNumbers.getLocalBounds().width/2.f){

        active = nullptr;
        return;
    }

    if (position.y < boxNumNumbers.getPosition().y + boxNumNumbers.getLocalBounds().height/2.f && 
        position.y > boxNumNumbers.getPosition().y - boxNumNumbers.getLocalBounds().height/2.f){

        active = &numNumbers;
        cout << "num numbers active" << endl;

        return;
    }

    if (position.y < boxTimePerNumber.getPosition().y + boxTimePerNumber.getLocalBounds().height/2.f && 
        position.y > boxTimePerNumber.getPosition().y - boxTimePerNumber.getLocalBounds().height/2.f){

        active = &timePerNumber;
        cout << "seconds per num active" << endl;

        return;
    }

    if (position.y < boxTimeBetweenNumbers.getPosition().y + boxTimeBetweenNumbers.getLocalBounds().height/2.f && 
        position.y > boxTimeBetweenNumbers.getPosition().y - boxTimeBetweenNumbers.getLocalBounds().height/2.f){

        active = &timeBetweenNumbers;
        cout << "seconds between nums active" << endl;

        return;
    }

    if (position.y < boxLowBound.getPosition().y + boxLowBound.getLocalBounds().height/2.f && 
        position.y > boxLowBound.getPosition().y - boxLowBound.getLocalBounds().height/2.f){

        active = &lowBound;
        cout << "low bound active" << endl;

        return;
    }


    if (position.y < boxUpperBound.getPosition().y + boxUpperBound.getLocalBounds().height/2.f && 
        position.y > boxUpperBound.getPosition().y - boxUpperBound.getLocalBounds().height/2.f){

        active = &upperBound;
        cout << "upper bound active" << endl;

        return;
    }


    active = nullptr;
}

void TitleScreen::handleTitleScreenInputs() {
    if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Button::Left) {
        getActiveObject();
    }

    // If no bounding box is active, there is nothing to be done so we must move on
    if (!active) return;
    
    // If we detect a backspace, delete the last character
    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::BackSpace) {
        string value = active->getString().toAnsiString();
        
        if (!value.empty()) {
            value.pop_back();
            active->setString(value);

            if (value.empty()) active->setString("0");

            centerOrigin(active);

            cout << value << endl;
        }
    }
    
    // If we detect a keypress, add it to the current string
    else if (event.type == sf::Event::TextEntered && 
            ranges::find(params.validUnicode, 
                            static_cast<char>(event.text.unicode)) != params.validUnicode.end()){
        
        string value = active->getString().toAnsiString();
        
        if (value[0] == '0') value.pop_back();

        if (value.size() < 10) {
            value += static_cast<char>(event.text.unicode);

            active->setString(value);
            centerOrigin(active);

            cout << value << endl;
        }
    }

    // Update the params to the new values
    params.numNumbers = stoi(numNumbers.getString().toAnsiString());
    params.timePerNumber = stoi(timePerNumber.getString().toAnsiString());
    params.timeBetweenNumbers = stoi(timeBetweenNumbers.getString().toAnsiString());
    params.lowBound = stoi(lowBound.getString().toAnsiString());
    params.upperBound = stoi(upperBound.getString().toAnsiString());

    // Preventing bad scenarios
    if (params.lowBound > params.upperBound){
        params.lowBound = params.upperBound;
        lowBound.setString(upperBound.getString());
    }

    params.calculatePoints();

}