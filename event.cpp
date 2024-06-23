#include "event.h"

// file is used to simulate why a stock decreased/increased

extern map<string, double> stockMarket;

// merge the two functions
void callEvent(int min, int max) {
    random_device r;
    mt19937 gen(r());
    uniform_int_distribution<> boomer(0, 100);

    int random = boomer(gen);

    if(random%2 == 0) {
        min += 1;
        max += 20;
    } else {
        min -= 20;
        max -= 1;
    }

    uniform_real_distribution<> distrib(min, max);

    double ran = distrib(gen) / 100;
    
    cout << "The market will be change by " << ran << "%" << endl;

    for(auto pair : stockMarket) {
        stockMarket[pair.first] *= ran;
    }

    
}

