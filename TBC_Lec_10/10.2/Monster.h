#pragma once

#include <string>
#include"Position2D.h"
class Monster
{
private:

	std::string _name; //char *data, unsigned length
	Position2D _location; //COmposition클래스는 가능한한 빨리 세부화 해서 구현하는것이 좋고, 상위 클래스에서는 하위클래스의 상세한 일은 알 필요가 없음
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