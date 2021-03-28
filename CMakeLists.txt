cmake_minimum_required(VERSION 3.17)
project(ProiectOOP)

set(CMAKE_CXX_STANDARD 14)

add_compile_options(-Wall -Wextra -pedantic -Weffc++)

add_executable(ProiectOOP main.cpp Reminder.cpp Reminder.h DateTime.cpp DateTime.h ToDoList.cpp ToDoList.h ShoppingList.cpp ShoppingList.h Alarm.cpp Alarm.h App.cpp App.h Menu.cpp Menu.h)