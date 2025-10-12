#include "helperFunctions.h"

void gameParameters::calculatePoints() {
    double range = pow(log10(upperBound - lowBound), 3);
    double quantity = pow(numNumbers - 1, 1.5);
    double timeOnScreen = 50.f / (double)timePerNumber;
    double timeBetween = sqrt(25.f / (double)timeBetweenNumbers);

    points = range * quantity * timeOnScreen * timeBetween;

    cout << points << endl;
}

void gameParameters::chooseNums() {
    auto now = chrono::high_resolution_clock::now();
    auto seed = chrono::duration_cast<chrono::seconds>(now.time_since_epoch());

    std::cout << "Seed: " << seed.count() << endl;

    mt19937 rng(seed.count());

    uniform_int_distribution<int> range(lowBound, upperBound);

    for (int i = 0; i < numNumbers; ++i) {
        nums.push_back(range(rng));
        cout << nums.back() << endl;
    }

}