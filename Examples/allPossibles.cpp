#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Item {
public:
   string itemName;  // Name of item
   int priceDollars; // Price of item
};

const unsigned int MAX_ITEMS_IN_SHOPPING_BAG = 3; // Max num items

/* Output every combination of items that fit
   in a shopping bag. Each recursive call moves
   one item into the shopping bag.
*/
void ShoppingBagCombinations(vector<Item> currBag,          // Bag contents
                             vector<Item> remainingItems) { // Available items
   int bagValue;        // Cost of items in shopping bag
   Item tmpGroceryItem; // Grocery item to add to bag
   unsigned int i;      // Loop index
   
   if (currBag.size() == MAX_ITEMS_IN_SHOPPING_BAG) { // Base case: Shopping bag full
      bagValue = 0;
      for (i = 0; i < currBag.size(); ++i) {
         bagValue += currBag.at(i).priceDollars;
         cout << currBag.at(i).itemName << "  ";
      }
      cout << "= $" << bagValue << endl;
   }
   else {                                              // Recursive case: move one
      for (i = 0; i < remainingItems.size(); ++i) {     // item to bag
         // Move item into bag
         tmpGroceryItem = remainingItems.at(i);
         remainingItems.erase(remainingItems.begin() + i);
         currBag.push_back(tmpGroceryItem);
         
         ShoppingBagCombinations(currBag, remainingItems);
         
         // Take item out of bag
         remainingItems.insert(remainingItems.begin() + i,tmpGroceryItem);
         currBag.pop_back();
      }
   }
}

int main() {
   vector<Item> possibleItems(0); // Possible shopping items
   vector<Item> shoppingBag(0);   // Current shopping bag
   Item tmpGroceryItem;           // Temp item
   
   // Populate grocery with different items
   tmpGroceryItem.itemName = "Milk";
   tmpGroceryItem.priceDollars = 2;
   possibleItems.push_back(tmpGroceryItem);
   
   tmpGroceryItem.itemName = "Belt";
   tmpGroceryItem.priceDollars = 24;
   possibleItems.push_back(tmpGroceryItem);
   
   tmpGroceryItem.itemName = "Toys";
   tmpGroceryItem.priceDollars = 19;
   possibleItems.push_back(tmpGroceryItem);
   
   tmpGroceryItem.itemName = "Cups";
   tmpGroceryItem.priceDollars = 12;
   possibleItems.push_back(tmpGroceryItem);
   
   // Try different combinations of three items
   ShoppingBagCombinations(shoppingBag, possibleItems);
   
   return 0;
}