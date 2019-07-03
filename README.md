# Licences

This application helps multiple teachers to coordinate their students for their licence exam. The GUI was created with Qt and using the design pattern: Observer.

All the teachers are saved in the teachers.txt file and all the students are saved in the students.txt file.
Each teacher has a name and each student has an ID, a name, the e-mail address, the year they will have their bachelor licence, a coordinator (if not, " "), a thesis title( if it does not exist, " ").

A new window is opened for each teacher. They can see in a list their students. They can also search for students by ID and by name. They can select a student and choos to be their coordinator, if that student doesn't already have one.
A teacher can select one of his/her student and edit their e-mail address or their thesis title. They can also approvr the thesis of one of their students and a new file will be generated of the form: <StudentName>.txt and the content: <TeacherName> approves the thesis <title> authored by <StudentName>.
