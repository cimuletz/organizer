//
// Created by seraf on 18.03.2021.
//

#ifndef PROIECTOOP_SHOPPINGLIST_H
#define PROIECTOOP_SHOPPINGLIST_H

#include <vector>
#include <string>
#include <iostream>

class ShoppingList {
    std::vector<std::string> items;
    std::string name;

public:

    ShoppingList(std::string name);
    ~ShoppingList();
    friend std::ostream& operator<<( std::ostream& out, const ShoppingList& lista );
    void addItem(std::string item);
    void deleteItem(const int i);
    void printList(std::ostream& os);
};


#endif //PROIECTOOP_SHOPPINGLIST_H
