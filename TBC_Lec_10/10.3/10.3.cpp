#include<iostream>
#include<vector>
#include<string>
#include"Lecture.h"

using namespace std;

int main()
{


	Student *std1=new Student (" A", 0);
	Student *std2=new Student (" B", 0);
	Student* std3 = new Student (" C", 0);

	Teacher *teacher1=new Teacher("Prof. Mun");
	Teacher *teacher2= new Teacher("Prof. Choi");

	Lecture lec1("I t C P");
	lec1.assignTeacher(teacher1);
	lec1.registerStudent(std1);
	lec1.registerStudent(std2);
	lec1.registerStudent(std3);

	Lecture lec2("KTKT");
	lec2.assignTeacher(teacher2);
	lec2.registerStudent(std1);

	
	cout << lec1 << endl;
	cout << lec2 << endl;

	//event
	lec2.study();

	cout << lec1 << endl;
	cout << lec2 << endl;
	

	delete[] std1;
	delete[] std2;
	delete[] std3;

	delete[] teacher1;
	delete[] teacher2;


	return 0;
}

