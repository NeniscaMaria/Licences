#pragma once
#include <vector>
#include <fstream>
class Teacher {
private:
	std::string name;
public:
	Teacher() {};
	Teacher(std::string n) {
		name = n;
	}
	std::string getName() {
		return name;
	}
	~Teacher() {};
	friend std::istream& operator>>(std::istream& is, Teacher* t) {
		std::string line;
		getline(is, line);
		char array[256];
		strcpy(array, line.c_str());
		std::vector<char*> tokens;
		char* token = strtok(array, ",");
		while (token != NULL) {
			tokens.push_back(token);
			token = strtok(NULL, ",");
		}
		if (tokens.size() != 1)
			return is;
		std::string n = tokens[0];
		t->name = n;
		return is;
	}
	friend std::ostream& operator<<(std::ostream&os, Teacher s) {
		os << s.name << '\n';
		return os;
	}
};
class Student {
private:
	std::string ID;
	std::string name;
	std::string email;
	int year;
	std::string title;
	std::string coordinator;
public:
	Student() {};
	Student(std::string i, std::string n, std::string e, int y, std::string t, std::string c) {
		ID = i;
		name = n;
		email = e;
		year = y;
		title = t;
		coordinator = c;
	}
	std::string getID() {
		return ID;
	}
	std::string getName() {
		return name;
	}
	std::string getEmail() {
		return email;
	}
	std::string getTitle() {
		return title;
	}
	std::string getCoordinator() {
		return coordinator;
	}
	int getYear() {
		return year;
	}
	std::string toStr() {
		std::string res = ID + "," + name + "," + email + ",";
		res += std::to_string(year) + "," + title + "," + coordinator;
		return res;
	}
	~Student() {};
	friend std::istream& operator>>(std::istream& is, Student* s) {
		std::string line;
		getline(is, line);
		char array[256];
		strcpy(array, line.c_str());
		std::vector<char*> tokens;
		char* token = strtok(array, ",");
		while (token != NULL) {
			tokens.push_back(token);
			token = strtok(NULL, ",");
		}
		if (tokens.size() != 6)
			return is;
		std::string i = tokens[0];
		s->ID = i;
		std::string n = tokens[1];
		s->name = n;
		std::string e = tokens[2];
		s->email = e;
		int y = atoi(tokens[3]);
		s->year = y;
		if (tokens[4] == " ") {
			s->title = "";
			s->coordinator = "";
		}
		else {
			std::string t = tokens[4];
			s->title = t;
			std::string c = tokens[5];
			s->coordinator = c;
		}
		return is;
	}
	friend std::ostream& operator<<(std::ostream&os, Student s) {
		os << s.toStr() << '\n';
		return os;
	}
};