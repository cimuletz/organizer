//
// Created by seraf on 28.03.2021.
//

#ifndef PROIECTOOP_APP_H
#define PROIECTOOP_APP_H

#include <fstream>
#include <vector>
#include <sstream>
#include <memory>
#include "Reminder.h"
#include "ShoppingList.h"
#include "ToDoList.h"
#include "Alarm.h"

class App {
    static App* app;
    std::vector<std::unique_ptr<Reminder>> rList;
    std::vector<ShoppingList> sList;
    std::vector<ToDoList> tdList;
    std::vector<Alarm> aList;
    App();
public:
    static App* getApp(){
        if(app == 0){
            app = new App;
        }
        return app;
    }
    void setVectors();
    void launch();
};


#endif //PROIECTOOP_APP_H