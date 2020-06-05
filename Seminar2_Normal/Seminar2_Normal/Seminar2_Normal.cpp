
#include <iostream>
#include <string>
using namespace std;

class TypeOfDates {
public:
    signed int sInt= 0;
    unsigned int unInt = 0;
    double doubleNum = 0;

    int mantisOrder = 0;
    double mantis = 0;
    int signOfNumber = 0;

    string typeOfDates;

    TypeOfDates(signed int now) {
        sInt = now;
        if (sInt < 0) {
            signOfNumber = 1;
            mantis = -sInt;
        }
        else {
            signOfNumber = 0;
            mantis = sInt;
        };

        while (mantis >= 1) {
            mantis /= 10;
            mantisOrder++;
        }

        typeOfDates = "signed int";
    }

   TypeOfDates(unsigned int now) {
        unInt = now;

            signOfNumber = 0;
            mantis = unInt;

       while (mantis >= 1) {
            mantis /= 10;
            mantisOrder++;
        }

        typeOfDates = "unsigned int";
    }

    TypeOfDates(double now) {
        doubleNum = now;

        sInt = now;
        if (doubleNum < 0) {
            signOfNumber = 1;
            mantis = -doubleNum;
        }
        else {
            signOfNumber = 0;
            mantis = doubleNum;
        };

        while (mantis >= 1) {
            mantis /= 10;
            mantisOrder++;
        }

        typeOfDates = "double";
    }

    void print() {
        cout << "Sign of number: " << signOfNumber << endl << "Mantis:" << mantis << endl << "Mantis order:" << mantisOrder << endl;
    }

    ~TypeOfDates(){}

};

int main()
{
    TypeOfDates s{ -345 };
    s.print();
    cout << s.typeOfDates << endl << endl;

    TypeOfDates s1{(unsigned int)3123000000};
    s1.print();
    cout << s1.typeOfDates << endl << endl;

    TypeOfDates s2{ 123.456 };
    s2.print();
    cout << s2.typeOfDates << endl << endl;

    system("PAUSE");
};


