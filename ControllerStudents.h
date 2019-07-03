#pragma once
#include "Repository.h"
#include "domain.h"
class CotrollerStudents {
private:
	Repository<Student>* repo;
public:
	CotrollerStudents() {}
	CotrollerStudents(Repository<Student>* r) :repo{ r } {}
	~CotrollerStudents() {
		delete repo;
	}
	int getSize() {
		return repo->getSize();
	}
	Student getElement(int pos) {
		return repo->getElement(pos);
	}
	void updateEmail(std::string email, std::string ID) {
		Student student;
		for (int i = 0; i < repo->getSize(); i++) {
			student = repo->getElement(i);
			int pos = student.getID().find(ID);
			if (pos != std::string::npos) {
				break;
			}
		}
		Student* newStudent = new Student{ student.getID(),student.getName(),email,student.getYear(),student.getTitle(),student.getCoordinator() };
		for (int i = 0; i < repo->getSize(); i++) {
			if (student.getID() == repo->getElement(i).getID()) {
				repo->remove(i, "students.txt");
				repo->insert(i, newStudent, "students.txt");
			}
		}
	}
	void updateThesis(std::string thesis, std::string ID) {
		Student student;
		for (int i = 0; i < repo->getSize(); i++) {
			student = repo->getElement(i);
			int pos = student.getID().find(ID);
			if (pos != std::string::npos) {
				break;
			}
		}
		Student* newStudent = new Student{ student.getID(),student.getName(),student.getEmail(),student.getYear(),thesis,student.getCoordinator() };
		for (int i = 0; i < repo->getSize(); i++) {
			if (student.getID() == repo->getElement(i).getID()) {
				repo->remove(i, "students.txt");
				repo->insert(i, newStudent, "students.txt");
			}
		}
	}
	std::vector<Student> getStudents(std::string name) {
		std::vector<Student> result;
		for (int i = 0; i < repo->getSize(); i++) {
			if (repo->getElement(i).getCoordinator() == name)
				result.push_back(repo->getElement(i));
		}
		sort(result.begin(), result.end(), [](Student a, Student b) {
			return a.getYear() < b.getYear();
		});
		return result;
	}
	std::vector<Student> searchStudents(std::string text) {
		/*
		This function searches for students by name and id
		INPUT:std::String text = by what we compare the candidate's id and name
		OUTPUT:std::vector<student> the vector of students that match the criteria(text)
		*/
		std::vector<Student> result;
		for (int i = 0; i < repo->getSize(); i++) {
			Student student = repo->getElement(i);
			int pos = student.getID().find(text);
			if (pos != std::string::npos) {
				bool ok = false;
				for (auto el : result)
					if (el.getID() == student.getID())
						ok = true;
				if(ok==false)
					result.push_back(student);
			}
			pos = student.getName().find(text);
			if (pos != std::string::npos) {
				bool ok = false;
				for (auto el : result)
					if (el.getID() == student.getID())
						ok = true;
				if (ok == false)
					result.push_back(student);
			}
		}
		return result;
	}
	void notify() {
		repo->notify();
	}
	void addCoordinator(std::string id, std::string name) {
		/*
		This function sets the coordinator of a student with a given ID with a given teacher
		INPUT:id=string,name=string
		OUTPUT:-
		*/
		std::vector<Student> students = this->searchStudents(id);
		if (students.size() != 1)
			return;
		Student student = students[0];
		if (student.getCoordinator() != " ")
			throw std::exception("This student already has a coordinator!");
		Student* newStudent = new Student{ student.getID(),student.getName(),student.getEmail(),student.getYear(),student.getTitle(),name };
		for (int i = 0; i < repo->getSize(); i++) {
			if (student.getID() == repo->getElement(i).getID()) {
				repo->remove(i,"students.txt");
				repo->insert(i, newStudent,"students.txt");
			}
		}
	}
};
