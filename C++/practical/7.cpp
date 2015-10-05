#include <iostream>

using namespace std;

class PC
{
public:
	PC();

	void setRAM(int r);
	void setSpeed(double s);

	int getRAM();
	double getSpeed();

private:
	int RAM;
    double speed;
};

PC::PC()
{
}
void PC::setRAM(int r)
{
	RAM = r;
}
void PC::setSpeed(double s)
{
	speed = s;
}
int PC::getRAM()
{
	return RAM;
}
double PC::getSpeed()
{
	return speed;
}

int main()
{
	PC p;

	p.setRAM(2048);
	p.setSpeed(7.5);

	cout << "This computer has " << p.getRAM() << "MBs of memory and a " << p.getSpeed() << "GHz processor!" << endl;
}
