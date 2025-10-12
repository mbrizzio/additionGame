#include "helperFunctions.h"

void gameParameters::calculatePoints() {
    double range = pow(log10(upperBound - lowBound), 3);
    double quantity = pow(numNumbers - 1, 1.5);
    double timeOnScreen = 50.f / (double)timePerNumber;
    double timeBetween = 25.f / (double)timeBetweenNumbers;

    points = range * quantity * timeOnScreen * timeBetween;

    cout << points << endl;
}

void gameParameters::chooseNums() {
    // First we want to define a random object from today's date
    auto now = chrono::sys_seconds::duration().count();
    cout << now << endl;
    mt19937 rng(now);

    uniform_int_distribution<int> range(lowBound, upperBound);

    for (int i = 0; i < numNumbers; ++i) {
        nums.push_back(range(rng));
    }

}