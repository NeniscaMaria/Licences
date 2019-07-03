#include "Exam.h"
#include <QtWidgets/QApplication>
#include "ControllerStudents.h"
#include <assert.h>
void test() {
	//testing search
	Repository<Teacher>* teachers = new Repository<Teacher>;
	teachers->readFromFile("teachers.txt");
	Repository<Student>* studentRepo = new Repository<Student>;
	studentRepo->readFromFile("students.txt");
	CotrollerStudents* studentsController = new CotrollerStudents{ studentRepo };
	std::vector<Student> s = studentsController->searchStudents("1");
	std::string m = "1,John Smith,johnsmith@gmail.com,2020,Climate change,Jane Doe";
	assert(s[0].toStr() == m);
	assert(s.size() == 1);
	s = studentsController->searchStudents("45");
	assert(s.size() == 0);
	//testing coordinator
}

int main(int argc, char *argv[])
{
	test();
	QApplication a(argc, argv);
	Repository<Teacher>* teachers = new Repository<Teacher>;
	teachers->readFromFile("teachers.txt");
	Repository<Student>* studentRepo = new Repository<Student>;
	studentRepo->readFromFile("students.txt");
	CotrollerStudents* studentsController = new CotrollerStudents{ studentRepo };
	std::vector<Exam*> windows;
	for (int i = 0; i < teachers->getSize(); i++)
		windows.push_back(new Exam{ studentsController,teachers,teachers->getElement(i) });
	for (auto win : windows) {
		win->show();
		teachers->addObserver(win);
		studentRepo->addObserver(win);
	}
	return a.exec();
}
