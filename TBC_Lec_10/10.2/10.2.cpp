#include"Monster.h"
using namespace std;




int main()
{
	Monster mon1("SAn",Position2D(0,0));
	cout << mon1 << endl;

	{
		//event
		mon1.moveTo(Position2D(1,1));
		cout << mon1 << endl;
	}


	return 0;
}

