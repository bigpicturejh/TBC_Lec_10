#include <iostream>
#include< string>
#include<vector>
using namespace std;

class Doctor;

class Patient
{
private:
	string _name;
	vector <Doctor*> _doctors;
public:
	Patient(string name_in)
		:_name(name_in)
	{}

	void addDoctor(Doctor* new_doctor)
	{
		_doctors.push_back(new_doctor);
	}

	void meetDoctors();
	//전방선언 Doctor안에 _name이 있는지 알 수 있는 방법이 없기 때문에 초기 에러 발생(solution; body를 밑으로 빼서 구현함)
	
	
	friend class Doctor;
};

class Doctor
{
private:
	string _name;
	vector<Patient*> _patients;
public:
	Doctor(string name_in)
		:_name(name_in)
	{}
	
	void addPatient(Patient * new_patient)
	{
		_patients.push_back(new_patient);
	}

	void meetPatient()
	{
		for (auto& idx : _patients)
		{
			cout << "Meet patient: " << idx->_name << endl;
		}
	}

	friend class Patient; //meetDoctor()에서 Doctor 클래스의 private멤버에 접근 가능하도록 하기 위함
};

void Patient::meetDoctors()
{
	for (auto& idx : _doctors)
	{
		cout << "Meet doctor: " << idx->_name << endl; //전방선언 Doctor안에 _name이 있는지 알 수 있는 방법이 없기 때문에 초기 에러 발생(solution; body를 밑으로 빼서 구현함)
	}
}

int main()
{

	Patient* p1 = new Patient("A");
	Patient* p2 = new Patient("B");
	Patient* p3 = new Patient("C");

	Doctor* d1 = new Doctor(" D C");
	Doctor* d2 = new Doctor(" D A");

	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d2);
	d2->addPatient(p2);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	p1->meetDoctors();

	d1->meetPatient();

		

	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;
	return 0;
}


