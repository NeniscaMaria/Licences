#pragma once
#include <vector>
#include <fstream>
#include "Subject.h"
template <typename Type>
class Repository :public Subject {
private:
	std::vector<Type> elems;
public:
	int getSize() {
		return elems.size();
	}
	Type getElement(int i) {
		return elems[i];
	}
	void readFromFile(std::string filename) {
		std::ifstream file;
		file.open(filename);
		Type* a = new Type{};
		while (file >> a)
			elems.push_back(*a);
		file.close();
	}
	void remove(int i,std::string filename) {
		elems.erase(elems.begin() + i);
		std::ofstream file;
		file.open(filename);
		for (auto el : elems)
			file << el;
		file.close();
	}
	void insert(int i, Type* a, std::string filename) {
		elems.insert(elems.begin() + i, *a);
		std::ofstream file;
		file.open(filename);
		for (auto el : elems)
			file << el;
		file.close();
	}
};