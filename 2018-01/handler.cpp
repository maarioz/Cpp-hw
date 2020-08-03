#include "handler.h"

void Handler::printIntro() const {
    std::cout << "--- Reservation System ---\n";
    std::cout << "0. End program\n";
    std::cout << "1. Add room\n";
    std::cout << "2. Add course\n";
    std::cout << "3. Add reservation\n";
    std::cout << "4. Print all rooms\n";
    std::cout << "5. Print all courses\n";
    std::cout << "6. Print all reservations\n";
    std::cout << "7. Print rooms' occupation\n";
}

bool Handler::addRoom() {
    std::string roomName;
    while (roomName.empty()) {
        std::cout << "Room name:\n";
        std::getline(std::cin, roomName);
        if (roomName.empty()) {
	    std::cerr << "Room name cannot be empty.\n";
        }
    }
    if (!rSystem.addRoom(roomName)) {
        std::cerr << "Room of that name already exists.\n";
        return false;
    }
    return true;
}

bool Handler::addCourse() {
    std::string courseCode;
    std::string courseTeacher;
    while (courseCode.empty()) {
        std::cout << "Course code:\n";
        std::getline(std::cin, courseCode);
        if (courseCode.empty()) {
            std::cerr << "Course code cannot be empty.\n";
        }
    }
    std::cout << "Teacher:\n";
    std::getline(std::cin, courseTeacher);
    if (!rSystem.addCourse(courseCode, courseTeacher)) {
        std::cerr << "Course with that code already exists.\n";
        return false;
    }
    return true;
}

const std::string Handler::getInput() const {
    std::string result;
    std::cin >> result;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return result;
}

bool Handler::addReservation() {
    std::string roomName;
    std::string courseCode;
    std::string durationOnly;
    bool success = true;

    std::cout << "Course code:\n";
    std::getline(std::cin, courseCode);

    while (durationOnly != "yes" || durationOnly != "no") {
        std::cout << "Duration only? (yes/no):\n";
        std::getline(std::cin, durationOnly);

        if (durationOnly == "yes") {
            std::cout << "Duration:\n";
            std::string duration = getInput();
            success = rSystem.makeAnyReservation(courseCode, stoi(duration));
        } else if (durationOnly == "no") {
            std::cout << "Room name:\n";
            roomName = getInput();
            std::cout << "Starting time:\n";
            std::string startingTime = getInput();
            std::cout << "Finishing time:\n";
            std::string finishingTime = getInput();
            success = rSystem.makeReservation(courseCode, roomName, stoi(startingTime), stoi(finishingTime));
        } else {
            std::cerr << "Use only yes/no\n";
            continue;
        }
        break;
    }
    if (!success) {
        std::cerr << "Reservation unsuccesfull.\n";
    }
    return success;
}

bool Handler::getOccupation() const {
    std::string roomName;
    std::cout << "Room name:\n";
    std::getline(std::cin, roomName);
    if (rSystem.hasRoom(roomName)) {
        rSystem.getRoom(roomName).schedule();
        return true;
    }
    std::cerr << "Room does not exist!\n";
    return false;
}

void Handler::handle() {
    while (true) {
        printIntro();
        int intPut = stoi(getInput());

        switch (intPut) {
            case 0:
                std::cout << "Termination request registered!\n";
                std::cout << "OK\n";
                return;
            case 1:
                if (addRoom()) {
                    break;
                }
                continue;
            case 2:
                if (addCourse()) {
                    break;
                }
                continue;
            case 3:
                if (addReservation()) {
                    break;
                }
                continue;
            case 4:
                std::cout << "Rooms:\n";
                for (const Room &room : rSystem.getRooms()) {
                    room.print();
                }
                break;
            case 5:
                std::cout << "Courses:\n";
                for (const Course &course : rSystem.getCourses()) {
                    course.print();
                }
                break;
            case 6:
                std::cout << "Reservations:\n";
                for (const Reservation &reservation : rSystem.getReservations()) {
                    reservation.print();
                }
                break;
            case 7:
                if (getOccupation()) {
                    break;
                }
                continue;
            default:
                std::cerr << "Wrong action; try again.\n";
                continue;
        }
        std::cout << "OK\n";
    }
}
