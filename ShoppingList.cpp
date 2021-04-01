//
// Created by seraf on 18.03.2021.
//

#include "ShoppingList.h"
    ShoppingList::ShoppingList(std::string name): name(name){}
    ShoppingList::~ShoppingList(){}
    std::ostream& operator<<( std::ostream& out, const ShoppingList& lista ){
        out << lista.name <<":\n";
        for(int i = 0; i < lista.items.size(); ++i){
            out << lista.items[i] << "\n";
        }
        return out;
    }

    void ShoppingList::addItem(std::string item){
        items.push_back(item);
        std::cout << "Item added.\n";
    }
    void ShoppingList::deleteItem(const int i){
        std::string removed = items[i-1];
        items.erase(items.begin() + i - 1);
        std::cout << "Removed item " << removed << "\n";
    }
    void ShoppingList::printList(std::ostream& os){
        if(items.empty()){
            std::cout << "Empty list!" << "\n";
        }
        else std::cout << *this;
    }