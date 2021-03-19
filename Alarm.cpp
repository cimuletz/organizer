//
// Created by seraf on 18.03.2021.
//

#include "Alarm.h"
Alarm::Alarm(int hour, int min,  std::string msg, bool recurrent){
    DateTime currentTime;
    DateTime aux(hour, min, currentTime.getYear(), currentTime.getMon(), currentTime.getDay());
    if( (hour < currentTime.getHour()) || (hour == currentTime.getHour() && min < currentTime.getMinute()) )
        aux.addDay();
    time = aux;
    message = msg;
    this -> recurrent = recurrent;
}
Alarm::Alarm(const Alarm& A){
    this -> time = A.time;
    this -> message = A.message;
    this -> recurrent = A.recurrent;
}
Alarm::Alarm(DateTime time, std::string msg, bool recurrent): time(time), message(msg), recurrent(recurrent){}
/*Alarm& recurringAlarm(){
    DateTime nextAlarm = time;
    nextAlarm.addDay();
    Alarm aux(nextAlarm, this -> message, this -> recurrent);
    return aux;
}*/
bool Alarm::isRecurrent(){
    return recurrent;
}
void Alarm::setMessage(std::string message){
    this -> message = message;
}
void Alarm::setRecurrence(bool recurrence){
    recurrent = recurrence;
}
std::ostream &operator<<(std::ostream& out, Alarm &A){
    out << A.message << "\n";
    A.time.printHour();
    return out;
}
DateTime Alarm::getTime(){
    return this -> time;
}