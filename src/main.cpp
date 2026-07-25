#include <iostream>
#include "Order.h"


int main() {
    
    Order order(
        1,
        Side::Buy,
        10.0,
        100
    );

    std::cout << "Order ID: " << order.getId() << std::endl;
    
    std::cout << "Remaining Quantity: " << order.getRemainingQuantity() << std::endl;

    order.reduceQuantity(40);

    std::cout << "After trade: " << order.getRemainingQuantity() << std::endl;



    return 0;
}