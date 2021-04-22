//
// Created by seraf on 18.03.2021.
//

#include "Alarm.h"
DateTime getAlarmDate(int hour, int min){
    DateTime currentTime;
    DateTime aux(hour, min, currentTime.getYear(), currentTime.getMon(), currentTime.getDay());
    if( (hour < currentTime.getHour()) || (hour == currentTime.getHour() && min < currentTime.getMinute()) )
        aux.addDay();
    return aux;
}
Alarm::Alarm(int hour, int min,  std::string msg, bool recurrent): time(getAlarmDate(hour, min)), message(msg), recurrent(recurrent){}
Alarm::Alarm(const Alarm& A): time(A.time), message(A.message), recurrent(A.recurrent){}
Alarm::Alarm(DateTime time, std::string msg, bool recurrent): time(time), message(msg), recurrent(recurrent){}

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
    out << A.message << "\n" ;
    A.time.printHour(std::cout);
    return out;
}
DateTime Alarm::getTime(){
    return this -> time;
}