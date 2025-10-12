#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <optional>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <ranges>
#include <math.h>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

enum State {
    TITLE,
    COUNTDOWN,
    SHOWNUM,
    BETWEENNUM,
    GUESS,
    RESULT,
    LEADERBOARD
};

struct gameParameters {
  int numNumbers = 3;
  int timePerNumber = 100;
  int timeBetweenNumbers = 50;

  int lowBound = 0;
  int upperBound = 100;

  double points;
  void calculatePoints();

  vector<int> nums;
  int currentNum;
  int sum = 0;
  void chooseNums();

  int guess;
  
  const std::vector<char> validUnicode = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
};


template <typename T>
concept HasOrigin = requires(T t, float x, float y) {
    {t.getLocalBounds()};
    {t.setOrigin(x, y)};
};

template <HasOrigin T>
void centerOrigin(T *object) {
    sf::FloatRect boundingBox = object->getLocalBounds(); 

    object->setOrigin(boundingBox.left + boundingBox.width / 2.f, boundingBox.top + boundingBox.height / 2.f);
}