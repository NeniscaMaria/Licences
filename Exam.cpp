#include "Exam.h"
#include "qerrormessage.h"
#include <QtCharts/qpercentbarseries.h>
#include <QtCharts/qbarset.h>
#include <qbrush>
Exam::Exam(CotrollerStudents * s, Repository<Teacher>* ts, Teacher t, QWidget *parent)
	: QMainWindow(parent)
{
	students = s;
	teachers = ts;
	teacher = t;
	ui.setupUi(this);
	showStudents();
	showStatistics();
	this->setWindowTitle(QString::fromStdString( teacher.getName()));
	connect(ui.searchLine, &QLineEdit::textChanged, this, &Exam::search);
	connect(ui.pushButton, &QPushButton::clicked, this, &Exam::search);
	connect(ui.editButton, &QPushButton::clicked, this, &Exam::edit);
	connect(ui.coordButton, &QPushButton::clicked, this, &Exam::addCoordinator);
	connect(ui.pushButton_2, &QPushButton::clicked, this, &Exam::approve);
	
}
#include <map>
void Exam::showStatistics() {
	//newWindow = new QWidget;
	//newWindow->setWindowTitle("Statistics");
	//std::map<std::string, int> stats;
	//for (int i = 0; i < teachers->getSize(); i++) {
	//	stats[teacher.getName()] = 0;
	//	for (int j = 0; j < students->getSize(); j++) {
	//		if (students->getElement(j).getCoordinator() == teacher.getName())
	//			stats[teacher.getName()] += 1;
	//	}
	//}
	//stats[" "] = 0;
	//for (int j = 0; j < students->getSize(); j++) {
	//	if (students->getElement(j).getCoordinator() == " ")
	//		stats[" "] += 1;
	//}
	//QHBoxLayout* l = new QHBoxLayout{};
	//newWindow->setLayout(l);
	//QListWidget* newList = new QListWidget();
	//l->addWidget(newList);
	//for (int i = 0; i < teachers->getSize(); i++) {
	//	std::string s = teachers->getElement(i).getName();
	//	s += " has " + std::to_string( stats[teachers->getElement(i).getName()]) + " students";
	//	newList->addItem(QString::fromStdString(s));
	//}
	//newList->addItem(QString::fromStdString(std::to_string(stats[" "]) + " student(s) have no coordina tor"));
	
}
void Exam::approve() {
	for (auto item : ui.listWidget->selectedItems()) {
		std::string text = item->text().toStdString();
		int pos = text.find(",");
		std::string ID = text.substr(0, pos);
		Student student;
		for (int i = 0; i < students->getSize(); i++) {
			student = students->getElement(i);
			if (student.getID() == ID)
				break;
		}
		if (student.getCoordinator() != teacher.getName()) {
			QErrorMessage* boc = new QErrorMessage;
			boc->showMessage("This is not your student!");
		}
		else {
			if (student.getTitle() != " ") {
				std::ofstream file(student.getName() + ".txt");
				file << teacher.getName() + " approves the thesis " + student.getTitle() + " authored by " + student.getName();
				file.close();
				approved.push_back(ID);
				students->notify();
			}
		}
	}
}
void Exam::saveStudent(){
	std::string email = emailLine->text().toStdString();
	std::string thesis = thesisLine->text().toStdString();
	if (email != "")
		students->updateEmail(email, id);
	if (thesis != "")
		students->updateThesis(thesis,id);
	students->notify();
}
void Exam::showStudents() {
	ui.listWidget->clear();
	if (ui.resultList->count() != 0)
		search();
	std::vector<Student> studentsToPrint = students->getStudents(teacher.getName());
	for (int i = 0; i < studentsToPrint.size();i++) {
		if (studentsToPrint[i].getYear() == 2019) {
			for (auto id : approved) {
				if (id == studentsToPrint[i].getID()) {
					QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(studentsToPrint[i].toStr()) };
					item->setBackgroundColor("green");
					ui.listWidget->addItem(item);
				}

				else
					ui.listWidget->addItem(QString::fromStdString(studentsToPrint[i].toStr()));
				studentsToPrint.erase(studentsToPrint.begin() + i);
			}
		}
	}
	sort(studentsToPrint.begin(), studentsToPrint.end(), [](Student a, Student b) {
		return a.getYear() > b.getYear();
	});
	for (int i = 0; i < studentsToPrint.size(); i++) {
		if (id == studentsToPrint[i].getID()) {
			QListWidgetItem* item = new QListWidgetItem{ QString::fromStdString(studentsToPrint[i].toStr()) };
			item->setBackgroundColor("green");
			ui.listWidget->addItem(item);
		}

		else
			ui.listWidget->addItem(QString::fromStdString(studentsToPrint[i].toStr()));
	}
}
void Exam::search() {
	ui.resultList->clear();
	std::string text = ui.searchLine->text().toStdString();
	std::vector<Student> result = students->searchStudents(text);
	for (auto el : result)
		ui.resultList->addItem(QString::fromStdString(el.toStr()));
}
void Exam::addCoordinator() {
	try {
		for (auto item : ui.resultList->selectedItems()) {
			std::string text = item->text().toStdString();
			int pos = text.find(",");
			std::string ID = text.substr(0, pos);
			students->addCoordinator(ID, teacher.getName());
			id = ID;
		}
	}
	catch (std::exception& e) {
		QErrorMessage* box = new QErrorMessage{};
		box->showMessage(e.what());
	}
	students->notify();
	ui.editButton->setDisabled(false);
}
void Exam::edit() {
	window = new QWidget;
	window->setWindowTitle("Edit mode");
	layout = new QVBoxLayout;
	window->setLayout(layout);
	list = new QListWidget;
	layout->addWidget(list);
	label1 = new QLabel{ "Email:" };
	layout->addWidget(label1);
	emailLine = new QLineEdit;
	layout->addWidget(emailLine);
	label2 = new QLabel{ "Thesis:" };
	layout->addWidget(label2);
	thesisLine = new QLineEdit;
	layout->addWidget(thesisLine);
	second = new QWidget;
	hlayout = new QHBoxLayout;
	second->setLayout(hlayout);
	layout->addWidget(second);
	this->saveBut = new QPushButton("Save");
	this->cancelBut = new QPushButton("Cancel");
	connect(this->saveBut, &QPushButton::clicked, this, &Exam::saveStudent);
	connect(this->cancelBut, &QPushButton::clicked, this, &Exam::cancelAction);
	hlayout->addWidget(this->saveBut);
	hlayout->addWidget(this->cancelBut);
	for (auto item : ui.listWidget->selectedItems()) {
		std::string text = item->text().toStdString();
		int pos = text.find(",");
		std::string ID = text.substr(0, pos);
		id = ID;
		Student student;
		for (int i = 0; i < students->getSize(); i++) {
			student = students->getElement(i);
			if (student.getID() == ID)
				break;
		}
		if (student.getCoordinator() != teacher.getName()) {
			QErrorMessage* boc = new QErrorMessage;
			boc->showMessage("This is not your student!");
		}
		else
			list->addItem(QString::fromStdString(student.toStr()));
	}
	window->show();
}
