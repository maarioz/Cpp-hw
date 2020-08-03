#ifndef RSYSTEM_H
#define RSYSTEM_H

#include "course.h"
#include "reservation.h"
#include "room.h"
#include <iostream>
#include <string>
#include <vector>

class ReservationSystem {

private:
    std::vector<Room> rooms;
    std::vector<Course> courses;
    std::vector<Reservation> reservations;

public:
    const std::vector<Room> &getRooms() const {
        return rooms;
    }

    const std::vector<Course> &getCourses() const {
        return courses;
    }

    const std::vector<Reservation> &getReservations() const {
	return reservations;
    }

    bool addRoom(const std::string &name);

    bool hasRoom(const std::string &name) const;

    const Room &getRoom(const std::string &name) const;

    bool addCourse(const std::string &code, const std::string &teacher);

    bool hasCourse(const std::string &code) const;

    const Course &getCourse(const std::string &code) const;

    bool makeAnyReservation(const std::string &course_code, int duration);

    bool makeReservation(const std::string &course_code, const std::string &room_name, int from, int to);
};

#endif
