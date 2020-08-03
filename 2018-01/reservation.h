#ifndef RESERVATION_H
#define RESERVATION_H

#include <iostream>
#include <string>

class Reservation {

public:
    const std::string room_name;
    const std::string course_code;
    const int start_time;
    const int end_time;

    Reservation(const std::string &room_name, const std::string &course_code,
        int start_time, int end_time)
        : room_name(room_name)
        , course_code(course_code)
        , start_time(start_time)
        , end_time(end_time) {}

   void print() const {
        std::cout << "Reservation for Course " << course_code << " in Room " 
             << room_name << " [" << start_time << '-' << end_time << "]\n";
    }
};

#endif
