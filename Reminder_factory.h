/* Student Serafim Alex-Mihai - 151
   Tutore laborator Marius Micluta-Campeanu
   gcc 10.2.0
 */


#ifndef SHOPPINGLIST_CPP_REMINDER_FACTORY_H
#define SHOPPINGLIST_CPP_REMINDER_FACTORY_H


#include "DateTime.h"
#include "Reminder.h"
#include "Bill.h"
#include "Birthday.h"

class Reminder_factory {
public:
    static std::unique_ptr<Reminder> reminder_important(){
        Reminder r("test", DateTime(14,53,02,06,2021), 1);
        return std::make_unique<Reminder>(r);
    }
    static std::unique_ptr<Reminder> reminder_normal(){
        Reminder r("test normal", DateTime(17,15,03,06,2021));
        return std::make_unique<Reminder>(r);
    }
    static std::unique_ptr<Bill> bill(){
        Bill b(14.5, "Companie Test", "Mesaj test", DateTime(16,0,04,8,2021));
        return std::make_unique<Bill>(b);
    }
    static std::unique_ptr<Birthday> birthday(){
        Birthday b( "nume test ", 19, "mesaj test", DateTime(19,0,10,7,2021) );
        return std::make_unique<Birthday>(b);
    }
};


#endif //SHOPPINGLIST_CPP_REMINDER_FACTORY_H
