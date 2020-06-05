
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

int main()
{
    //объявление переменных и открытие файла
    string line;
    int counter = 0;
    int amountOfarithmeticOperations = 0;
    ifstream in("C:\\Users\\nikit\\source\\repos\\Seminar5\\source.txt");
    vector <int> v;
    vector <char> v1;
    
    //отделение знаков от чисел по разым векторам
    for (in >> line; !in.eof(); in >> line) {
        if (line[0] >= 48 && line[0] <=57){
                counter++;
                v.push_back(stoi(line));
        }
        else {
            amountOfarithmeticOperations++;
            v1.push_back(line[0]);
        }
        
    }

    //определение длинны матрицы
    int lengthOfMatrix = ceil(counter / (amountOfarithmeticOperations + 1));

    //вычисления
    for (int i = 0; i < v1.size(); i++) {
        if (v1[i] == '+') {
            for (int j = 0; j < lengthOfMatrix; j++) {
                v[j] += v[((i+1) * lengthOfMatrix) + j];
            }
        }

        if (v1[i] == '-') {
            for (int j = 0; j < lengthOfMatrix; j++) {
                v[j] -= v[((i+1) * lengthOfMatrix) + j];
            }
        }
    }

    //вывод
    for (int i = 0; i < lengthOfMatrix; i++) {
        cout << v[i] << " ";
        if (((i+1) % (int)sqrt(lengthOfMatrix)) == 0) {
            cout << endl;
        }
    }

    cout << 12 + 4 * 3 + ;


    in.close();
}


