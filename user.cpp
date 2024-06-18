#include "user.h"
#include "stock.h"

// file is used to simulate a person

/* Adds a stock the Player's portfolio.
*
*
*
*
*
*/
void addStockToPortfolio(user *Player, string name, double price, int quantity) {
    Player->portfolio.addStock(name, quantity, price);
}

// Bring up the Player's portfolio
void lookAtPortfolio(user *Player) {
    Player->portfolio.lookAtPortfolio();
}
