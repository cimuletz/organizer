//
// Created by seraf on 28.03.2021.
//

#include <memory>
#include "App.h"
#include "Menu.h"
#include "Bill.h"
#include "Birthday.h"

App::App():rList(), sList(), tdList(), aList(){}

DateTime readDate(std::string in){
    int j = 0, day, min, yr, hour, mon;
    day = min = yr = hour = mon = 0;
    while(in[j] != ' '){
        day = day * 10 + (in[j] - '0');
        j++;
    }
    j++;
    while(in[j] != ' '){
        mon = mon * 10 + (in[j] - '0');
        j++;
    }
    j++;
    while(in[j] != ' '){
        yr = yr * 10 + (in[j] - '0');
        j++;
    }
    j++;
    while(in[j] != ' '){
        hour = hour * 10 + (in[j] - '0');
        j++;
    }
    j++;
    int m = in.size();
    while(j < m){
        min = min * 10 + (in[j] - '0');
        j++;
    }
    j++;
    //importance = input[++index][0] - '0';
    DateTime aux(hour, min, day, mon, yr);
    return  aux;
}

std::istream& operator>>(std::istream& rd, App& A){
    std::string in;
    std::string name;
    std::vector<std::string> input;
    DateTime time, timeAux;
    bool importance;
    int n, m, hour, min,j, index, age;
    double value;
    std::ifstream t("intrare.in");
    std::string str((std::istreambuf_iterator<char>(t)),std::istreambuf_iterator<char>());
    std::stringstream check1(str);
    std::string intermediate;
    while(getline(check1, intermediate, '\n')){
        input.push_back(intermediate);
    }
    ///read reminders
    n = stoi(input[0]);
    index = 1;
    for(int i = 0; i<n; ++i){
        in = input[index++];
        timeAux = readDate(input[index++]);
        A.rList.push_back(std::make_unique <Reminder>(in, timeAux, importance));
    }
    ///read bills
    n = stoi(input[index++]);
    for(int i = 0; i<n; ++i){
        name = input[index++];
        in = input[index++];
        timeAux = readDate(input[index++]);
        value = stod(input[index++]);
        A.rList.emplace_back(std::make_unique <Bill>(value, name, in, timeAux));
    }
    ///read birthdays
    n = stoi(input[index++]);
    for(int i = 0; i<n; ++i){
        name = input[index++];
        in = input[index++];
        timeAux = readDate(input[index++]);
        age = stoi(input[index++]);
        A.rList.push_back(std::make_unique <Birthday>(name, age, in, timeAux));
    }
    ///read shopping lists
    n = stoi(input[index]);
    for(int i = 0; i<n; ++i){
        index++;
        in = input[index];
        ShoppingList aux(in);
        index++;
        m = stoi(input[index]);
        for(int j = 0; j<m; ++j){
            index++;
            in = input[index];
            aux.addItem(in);
        }
        A.sList.push_back(aux);
    }
    ///read todo lists
    index++;
    n = stoi(input[index++]);
    for(int i = 0; i<n; ++i){
        in = input[index++];
        ToDoList aux(in);
        m = stoi(input[index++]);
        for(int k = 0; k<m; ++k){
            in = input[index++];
            timeAux = readDate(input[index++]);
            aux.addTask(in, timeAux);
        }
        A.tdList.push_back(aux);
    }
    ///read alarms
    n = stoi(input[index++]);
    for(int i = 0; i<n; ++i) {
        in = input[index++];
        j = 0;
        hour = min = 0;
        while(input[index][j] != ' '){
            hour = hour * 10 + (input[index][j] - '0');
            j++;
        }
        j++;
        int m = input[index].size();
        while(j < m){
            min = min * 10 + (input[index][j] - '0');
            j++;
        }
        index++;
        A.aList.push_back(Alarm( hour,min, in, importance));
    }
    return rd;
}
void App::launch(){
    Menu M(std::move(rList), sList, tdList, aList);
    M.menu();
}