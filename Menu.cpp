//
// Created by seraf on 28.03.2021.
//

#include "Menu.h"
Menu::Menu(std::vector<Reminder> R, std::vector<ShoppingList> S, std::vector<ToDoList> T, std::vector<Alarm> A): rList(R), sList(S), tdList(T), aList(A) {}
void Menu::listAlarms(){

    for(int i = 0; i<aList.size(); ++i){
        std::cout << aList[i];
    }
    menuAlarms();
}

void Menu::listReminders(){
    for(int i = 0; i<rList.size(); ++i){
        std::cout << rList[i];
    }
    menuReminders();
}

void Menu::menuAlarms(){
    std::cout << "1. List alarms\n" <<"2. Add alarm\n" << "3. Delete alarm\n" << "4. Back to main menu\n";
    int n, hour, min, i;
    bool recurrent;
    std::string in;
    std::cin >> n;
    switch(n){
        case 1:
            listAlarms();
            break;
        case 2:
            std::cout <<"\nTime in format HH MM: ";
            std::cin >> hour >> min;
            std::cout <<"\nMessage: ";
            std::cin >> in;
            std::cout<<"\nRecurrent alarm?(1 for yes, 0 for no): ";
            std::cin >> recurrent;
            aList.push_back(Alarm( hour,min, in, recurrent));
            menuAlarms();
            break;
        case 3:
            //listAlarms();
            std::cout << "\nEnter index: ";
            std::cin >> i;
            aList.erase(aList.begin() + i - 1);
            menuAlarms();
            break;
        default:
            menu();
    }
}

void Menu::menuReminders(){
    std::cout << "1. List reminders\n" <<"2. Add reminder\n" << "3. Delete reminder\n" << "4. Back to main menu\n";
    int n, i;
    bool recurrent;
    DateTime time;
    std::string in;
    std::cin >> n;
    switch(n){
        case 1:
            listReminders();
            break;
        case 2:
            std::cout <<"\nTime in format DD MM YYYY HH MM: ";
            std::cin >> time;
            std::cout <<"\nMessage: ";
            std::cin >> in;
            std::cout<<"\nImportant reminder?(1 for yes, 0 for no): ";
            std::cin >> recurrent;
            rList.push_back(Reminder( in,time,recurrent));
            menuReminders();
            break;
        case 3:
            //listReminders();
            std::cout << "\nEnter index: ";
            std::cin >> i;
            rList.erase(rList.begin() + i - 1);
            menuReminders();
            break;
        default:
            menu();
    }
}

void Menu::listSLists(){
    for(int i = 0; i<sList.size(); ++i){
        sList[i].printList(std::cout);
    }
    menuSLists();
}

void Menu::menuSLists(){
    std::cout << "1. Print shopping lists\n" <<"2. Add shopping list\n" << "3. Delete shopping list\n" << "4. Back to main menu\n";
    int n, i;
    bool recurrent;
    DateTime time;
    std::string in;
    std::cin >> n;
    switch(n){
        case 1:
            listSLists();
            break;
        case 2: {
            std::cout << "\nList name: ";
            std::cin >> in;
            std::cout << "\nNo of items: ";
            std::cin >> i;
            ShoppingList aux(in);
            std::cout << "\nEnter items: ";
            for (int j = 0; j < i; ++j) {
                std::cin >> in;
                aux.addItem(in);
            }
            sList.push_back(aux);
            menuSLists();
            break;
        }
        case 3:
            //listSLists();
            std::cout << "\nEnter index: ";
            std::cin >> i;
            sList.erase(sList.begin() + i - 1);
            menuSLists();
            break;
        default:
            menu();
    }
}

void Menu::listTDLists(){
    for(int i = 0; i<tdList.size(); ++i)
        std::cout <<i+1<<". " << tdList[i];
    menuTDLists();
}

void Menu::menuTDLists(){
    std::cout << "1. Print ToDos\n" <<"2. Add ToDo\n" << "3. Delete ToDo\n" <<"4. Mark task completed\n"<<"5. Print completed tasks\n"<< "6. Back to main menu\n";
    int n, i, j;
    bool recurrent;
    DateTime time;
    std::string in;
    std::cin >> n;
    switch(n){
        case 1:
            listTDLists();
            break;
        case 2: {
            std::cout << "\nToDo name: ";
            std::cin >> in;
            std::cout << "\nNo of tasks: ";
            std::cin >> i;
            ToDoList aux(in);
            std::cout << "\nEnter tasks: ";
            for (int j = 0; j < i; ++j) {
                std::cout << "\nTask name: ";
                std::cin >> in;
                std::cout << "\nDeadline in format DD MM YYYY HH MM: ";
                std::cin >> time;
                aux.addTask(in, time);
            }
            tdList.push_back(aux);
            menuTDLists();
            break;
        }
        case 3:
            //listTDLists();
            std::cout << "Enter index: ";
            std::cin >> i;
            tdList.erase(tdList.begin() + i - 1);
            menuTDLists();
            break;
        case 4:
            //listTDLists();
            std::cout << "Which list?";
            std::cin >> i;
            std::cout << "\nWhich index?";
            std::cin >> j;
            tdList[i].completedTask(j);
            menuTDLists();
            break;
        case 5:
            std::cout <<"\nFrom which list?";
            std::cin >> i;
            tdList[i].printCompleted(std::cout);
            menuTDLists();
            break;
        default:
            menu();
    }
}

void Menu::menu(){
    std::cout << "1. Alarms\n" << "2. Reminders\n" << "3. Shopping lists\n" << "4. ToDo lists\n" << "5. Exit\n";
    int n;
    std::cin >> n;
    switch(n){
        case 1:
            menuAlarms();
            break;
        case 2:
            menuReminders();
            break;
        case 3:
            menuSLists();
            break;
        case 4:
            menuTDLists();
            break;
        default:
            return ;

    }
}