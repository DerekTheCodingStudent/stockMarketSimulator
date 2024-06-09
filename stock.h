#ifndef STOCK_MAIN
#define STOCK_MAIN



class stock {
    private:
        double quantity;
        double price;

    public:

        stock(double price) {
            this->price = price;
        }

        double getQuantity() {
            return quantity;
        }

        double getPrice() {
            return price;
        }

        void addStock(double quantity) {
            this->quantity += quantity;
        }
};


#endif