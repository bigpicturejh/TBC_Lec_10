#pragma once

#include<vector>
#include "Student.h"
#include "Teacher.h"

class Lecture
{
private:
	std::string _name;

	//�Ʒ� �� instance�� Lecture class�� ������� ���� �����(Composition���� ����)
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
			idx->setIntel(idx->getIntel() + 1);//���� ����
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