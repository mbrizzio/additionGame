#include "helperFunctions.h"

void gameParameters::calculatePoints() {
    double range = pow(log10(upperBound - lowBound), 3);
    double quantity = pow(numNumbers - 1, 1.5);
    double timeOnScreen = 50.f / (double)timePerNumber;
    double timeBetween = 25.f / (double)timeBetweenNumbers;

    points = range * quantity * timeOnScreen * timeBetween;

    cout << points << endl;
}