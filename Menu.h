//
// Created by seraf on 28.03.2021.
//

#ifndef PROIECTOOP_MENU_H
#define PROIECTOOP_MENU_H


#include <memory>
#include "Reminder.h"
#include "ShoppingList.h"
#include "ToDoList.h"
#include "Alarm.h"

class Menu {
    std::vector<std::unique_ptr<Reminder>> rList;
    std::vector<ShoppingList> sList;
    std::vector<ToDoList> tdList;
    std::vector<Alarm> aList;
public:
    Menu(std::vector<std::unique_ptr<Reminder>> R, std::vector<ShoppingList> S, std::vector<ToDoList> T, std::vector<Alarm> A);
    void menuAlarms();
    void menu();
    void listAlarms();
    void menuReminders();
    void listReminders();
    void menuSLists();
    void menuTDLists();
    void listSLists();
    void listTDLists();
};


#endif //PROIECTOOP_MENU_H
