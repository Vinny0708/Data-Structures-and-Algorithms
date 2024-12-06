#include <iostream> 
#include <vector>
//Items represents the item and their cost
struct Items {
    std::string name;
    float price;
};
// calculateTotalCost Function:
float calculateTotalCost(const std::vector<Items>&cart) {
// Starts with a totalCost of 0.
    float totalCost = 0.0;
    for (const auto & Items : cart) {
        totalCost += Items.price;
    }
    return totalCost;
}

int main() {

    std::vector<Items> cart = {
        {"Spaghetti_na_maikli", 89},
        {"Sinabawang_Carbonara", 150.7},
        {"Pinakuluang_Rebisco", 37}
    };

    float totalCost = calculateTotalCost(cart);

    std::cout << "Total cost of the items in the cart: " << totalCost << std::endl;

    return 0;
}