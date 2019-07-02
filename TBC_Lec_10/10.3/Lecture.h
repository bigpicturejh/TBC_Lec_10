#pragma once

#include<vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string _name;

	//아래 두 instance는 Lecture class가 사라질때 같이 사라짐(Composition관계 때문)
	Teacher *teacher;
	std::vector<Student*> student;

public:
	Lecture(const std::string& name_in)
		:_name(name_in)
	{

	}
	~Lecture()
	{
	}

	void assignTeacher(Teacher* const teacher_input)
	{
		teacher = teacher_input;
	}

	void registerStudent( Student* const student_input)
	{
		student.push_back(student_input);
	}

	void study()
	{
		std::cout << _name << "Study" << std::endl << std::endl;

	/*	for (auto& idx : student)
		{
			idx.setIntel(idx.getIntel() + 1);
		}*/

		for (auto &idx : student)
		{
			//(*idx).setIntel((*idx).getIntel() + 1);
			idx->setIntel(idx->getIntel() + 1);//위와 동일
		}
	}

	friend std::ostream& operator << (std::ostream out, const Lecture& lecture)
	{
		out << " Lecture Name: " << lecture._name << std::endl;

		out << lecture.teacher << std::endl;
		for (auto idx : lecture.student)
			out << *idx << std::endl;

		return out;
	}
};