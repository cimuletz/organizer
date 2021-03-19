//
// Created by seraf on 17.03.2021.
//

#ifndef PROIECTOOP_TODOLIST_H
#define PROIECTOOP_TODOLIST_H


#include <string>
#include <vector>
#include "Reminder.h"

class ToDoList {
    std::string name;
    std::vector<Reminder> tasks;
    std::vector<Reminder> completed;

public:

    ToDoList(std::string name);
    ~ToDoList();
    ToDoList(const ToDoList &A);
    friend std::ostream& operator<<(std::ostream& out, ToDoList& lista);
    void addTask(std::string message, DateTime time);
    void removeTask(int i);
    void nextTasks(DateTime time);
    void missedTasks();
    void completedTask(int i);
    void printCompleted();

};


#endif //PROIECTOOP_TODOLIST_H
