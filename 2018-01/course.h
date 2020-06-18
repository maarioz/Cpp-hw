#ifndef COURSE_H
#define COURSE_H

#include <array>
#include <iostream>
#include <string>

class Course {

public:
	const std::string code;
	const std::string teacher;

	Course(const std::string& code, const std::string& teacher)
	    : code(code)
	    , teacher(teacher) {}

	void print() const {
		if (teacher.empty()) {
			std::cout << "Course: " + code + '\n';
		} else {
			std::cout << "Course: " + code + " [Teacher: " + teacher + "]\n";
		}
	}
};

#endif
