#include "rsystem.h"
#include <iostream>
#include <string>
#include <vector>

bool ReservationSystem::hasRoom(const std::string &name) const {
    for (const Room &room : rooms) {
        if (room.name == name) {
            return true;
        }
    }
    return false;
}

bool ReservationSystem::addRoom(const std::string &name) {
    if (hasRoom(name)) {
        return false;
    }
    rooms.emplace_back(Room{ name });
    return true;
}

const Room &ReservationSystem::getRoom(const std::string &name) const {
    for (const Room &room : rooms) {
        if (room.name == name) {
            return room;
        }
    }
    throw std::runtime_error("Room not found.");
}

bool ReservationSystem::hasCourse(const std::string &code) const {
    for (const Course &course : courses) {
        if (course.code == code) {
            return true;
        }
    }
    return false;
}

bool ReservationSystem::addCourse(const std::string &code,
    const std::string &teacher) {
        if (hasCourse(code)) {
            return false;
        }
    courses.emplace_back(Course{ code, teacher });
    return true;
}

const Course &ReservationSystem::getCourse(const std::string &code) const {
    for (const Course &course : courses) {
        if (course.code == code) {
            return course;
        }
    }
    throw std::runtime_error("Course not found.");
}

bool ReservationSystem::makeAnyReservation(const std::string &course_code,
    int duration) {
    if (duration <= 0 || duration > 24 || !hasCourse(course_code)) {
        return false;
    }
    for (Room &room : rooms) {
        const int from = room.isFreeFor(duration);
    	if (from != -1) {
            const int to = from + duration;
            room.occupy(from, to);
            reservations.emplace_back(Reservation{ room.name, course_code, from, to });
            return true;
        }
    }
    return false;
}

bool ReservationSystem::makeReservation(const std::string &course_code,
    const std::string &room_name, int from, int to) {
    if (!hasRoom(room_name) || !hasCourse(course_code)) {
        return false;
    }
    for (Room &room : rooms) {
        if (room.name == room_name && !room.occupy(from, to)) {
            return false;
        }
    }
    reservations.emplace_back(Reservation{ room_name, course_code, from, to });
    return true;
}
