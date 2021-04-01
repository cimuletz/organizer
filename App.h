//
// Created by seraf on 28.03.2021.
//

#ifndef PROIECTOOP_APP_H
#define PROIECTOOP_APP_H

#include <fstream>
#include <vector>
#include <sstream>
#include "Reminder.h"
#include "ShoppingList.h"
#include "ToDoList.h"
#include "Alarm.h"

class App {
    std::vector<Reminder> rList;
    std::vector<ShoppingList> sList;
    std::vector<ToDoList> tdList;
    std::vector<Alarm> aList;
public:
    friend std::istream& operator>>(std::istream& rd, App& A);
    void launch();
};


#endif //PROIECTOOP_APP_H