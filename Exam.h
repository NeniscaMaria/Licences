#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Exam.h"
#include "ControllerStudents.h"
#include "Observer.h"
#include "qpainter.h"
class Exam : public QMainWindow,public Observer
{
	Q_OBJECT

public:
	QPainter* painter;
	QWidget* newWindow;
	QWidget* window;
	QVBoxLayout* layout;
	QListWidget* list;
	QLabel* label1;
	QLabel* label2;
	QLineEdit* thesisLine;
	QLineEdit* emailLine;
	QPushButton* saveBut;
	QPushButton* cancelBut;
	QHBoxLayout* hlayout;
	QWidget* second;
	CotrollerStudents* students;
	Repository<Teacher>* teachers;
	Teacher teacher;
	std::string id;
	std::vector<std::string> approved;
	Exam(CotrollerStudents * students,Repository<Teacher>* teachers,Teacher teacher, QWidget *parent = Q_NULLPTR);
	void showStudents();
	void search();
	void showStatistics();
	void addCoordinator();
	void edit();
	void approve();
	void update()override {
		showStudents();
		showStatistics();
	}
	void saveStudent();
	void cancelAction() {
		window->close();
	}
private:
	Ui::ExamClass ui;
};
