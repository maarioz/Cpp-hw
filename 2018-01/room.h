#ifndef ROOM_H
#define ROOM_H

#include <array>
#include <iostream>
#include <string>

class Room {

private:
	std::array<bool, 24> room;

public:
	const std::string name;

	Room(const std::string &name)
	    : name(name) { room.fill(false); }

	bool isFree(int from, int to) const {
		if (from < 0 || from > 24 || to <= 0 || to > 24 || from >= to) {
			return false;
		}
		for (int i = from; i < to; i++) {
			if (room[i]) {
				return false;
			}
		}
		return true;
	}

	int isFreeFor(int duration) const {
		if (duration <= 0 || duration > 24) {
			return -1;
		}
		for (int i = 0; i < static_cast<int>(room.size()); i++) {
			if (!room[i] && isFree(i, duration + i)) {
				return i;
			}
		}
		return -1;
	}

	bool occupy(int from, int to) {
		if (!isFree(from, to)) {
			return false;
		}
		for (int i = from; i < to; i++) {
			room[i] = true;
		}
		return true;
	}

	void print() const {
        std::cout << "Room: " + name + '\n';
    }

	void schedule() const {
		for (const bool &elem : room) {
			std::cout << (elem ? 'X' : '_');
		}
		std::cout << '\n';
	}
};

#endif
