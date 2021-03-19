//
// Created by seraf on 17.03.2021.
//

#include "ToDoList.h"

    ToDoList::ToDoList(std::string name): name(name) {}
    ToDoList::~ToDoList(){}
    ToDoList::ToDoList(const ToDoList &A){
        this -> name = A.name;
        this -> tasks = A.tasks;
        this -> completed = A.completed;
    }
    std::ostream& operator<<(std::ostream& out, ToDoList& lista){
        out << lista.name << "\n";
        for(int i = 0; i < lista.tasks.size(); ++i){
            out << lista.tasks[i].getMessage() << "\nDeadline: " << lista.tasks[i].getDate() << "\n";
        }
        return out;
    }
    void ToDoList::addTask(std::string message, DateTime time){
        tasks.push_back(Reminder(message, time));
        std::cout<< "Task added succesfully!" << "\n" ;
    }
    void ToDoList::removeTask(int i){
        Reminder R = tasks[i - 1];
        tasks.erase(tasks.begin() + i - 1);
        std::cout << "Removed task: " << R.getMessage() << "\n";
    }
    void ToDoList::nextTasks(DateTime time){
        for(int i = 0; i < tasks.size(); ++i){
            if( tasks[i].getDate() > time )
                std::cout << tasks[i];
        }
    }
    void ToDoList::missedTasks() {
        DateTime time;
        for (int i = 0; i < tasks.size(); ++i) {
            if (time > tasks[i].getDate())
                std::cout << "You missed a task!" << "\n" << tasks[i];
        }
    }
    void ToDoList::completedTask(int i){
        Reminder R = tasks[i-1];
        this->removeTask(i);
        completed.push_back(R);
        std::cout << "Completed task: " << R.getMessage() << "\n";
    }
    void ToDoList::printCompleted(){
        std::cout << "Completed tasks: " << "\n";
        for(int i = 0; i < completed.size(); ++i){
            std::cout << completed[i].getMessage() << "\n";
        }
    }