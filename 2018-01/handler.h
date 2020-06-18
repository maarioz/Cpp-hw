#ifndef HANDLER_H
#define HANDLER_H

#include "rsystem.h"
#include <iostream>
#include <string>

class Handler {
private:
	ReservationSystem rSystem;

	void printIntro() const;

	bool addRoom();

	bool addCourse();

	bool addReservation();

	bool getOccupation() const;

	const std::string getInput() const;

public:
	void handle();
};

#endif
