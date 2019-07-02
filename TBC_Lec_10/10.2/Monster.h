#pragma once

#include <string>
#include"Position2D.h"
class Monster
{
private:

	std::string _name; //char *data, unsigned length
	Position2D _location; //COmpositionŬ������ �������� ���� ����ȭ �ؼ� �����ϴ°��� ����, ���� Ŭ���������� ����Ŭ������ ���� ���� �� �ʿ䰡 ����
	//int _x; //location
	//int _y;



public:
	Monster (const std::string name_in, const Position2D & pos_in)
		: _name(name_in), _location(pos_in)
	{}

	
	void moveTo(const Position2D& pos_target)
	{
		_location.set(pos_target);
	/*	_x = x_target;
		_y = y_target;*/
	}

	friend std::ostream& operator <<(std::ostream& out, Monster& monster)
	{
		out << monster._name << " " << monster._location;
		return out;
	}
};