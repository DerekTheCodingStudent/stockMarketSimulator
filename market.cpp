#include "market.h"
#include "stock.h"
#include "json11.hpp"

// file is used to simulate the market

map<string, double> stockMarket;


// Should bring up a couple of stocks in the market
void callMarket() {
    for(auto m : stockMarket) {
        cout << "Stock name: " << m.first << ", Price: " << m.second << endl;
    }

    printf("\n");
}

void openMarket() {
    ifstream file("stockdata.json");
    string jsonContent((istreambuf_iterator<char>(file)), 
                        istreambuf_iterator<char>());

    string stock = "";
    const auto j = json11::Json::parse(jsonContent, stock);
    

    for(auto& item : j.array_items()) {
        string sym = item["symbol"].string_value();
        double price = stod(item["price"].string_value());
        stockMarket[sym] = price;
    }

    file.close();
}


