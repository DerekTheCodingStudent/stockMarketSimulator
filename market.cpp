#include "market.h"
#include "stock.h"

// file is used to simulate the market

map<string, double> stockMarket;


// Should bring up a couple of stocks in the market
void callMarket() {
    for(auto m : stockMarket) {
        cout << "Stock name: " << m.first << ", Price: " << m.second << endl;
    }

    printf("\n");
}

void addStocksToMarket() {
    ifstream file("stocks.txt");
    
    string stockName = "";
    double price = 0.0;

    while(file >> stockName >> price) {
        stockMarket[stockName] = price;
    }


    file.close();

    callMarket();
}


