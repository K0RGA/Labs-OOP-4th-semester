#include <iostream>
#include <string>
#include <vector>
using namespace std;

class LegoDetail {
protected:
	string color;
	string shape ;
	int width, length;

public:
	bool state = 0;


	LegoDetail(string shape, string color, int width, int length) {
		this->shape = shape;
		this->color = color;
		this->width = width;
		this->length = length;
	}


	void setColor(string color)  {
		this->color = color;
	}

	string getColor()  {
		return color;
	}
	
	void virtual toHurt() = 0;
};

class Brick : public LegoDetail {
	
	using LegoDetail::LegoDetail;
public:	
	void toHurt() override 
	{
		if (width == 1 && length == 1)
			cout << "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
		
		else  cout << "AAA";
	}
};

//методы для условного интерфейса
void connect(int,int,vector<Brick>&);
void unconnect(int,int,vector<Brick>&);

int main()
{
	vector <Brick> v1 = { {"plate","red",1,1} , {"brick","black",2,2} };

	connect(0, 1, v1);
	cout << v1[0].state << endl;
	unconnect(0, 1, v1);
	cout << v1[0].state << endl;
	v1[0].toHurt();

}

void connect(int first, int second, vector<Brick>& v1) {
	v1[first].state = 1;
	v1[second].state = 1;
}

void unconnect(int first, int second, vector<Brick>& v1) {
	v1[first].state = 0;
	v1[second].state = 0;
}