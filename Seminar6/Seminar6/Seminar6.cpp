#include <queue>
#include <iostream>
#include <string>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <ctime>

using namespace std;

struct consumer {
    string name;
    string num;
    bool priority = false;
};

void FrontToLast(queue<consumer>& q, int queueSize);
void pushInQueue(queue<consumer>& q, consumer temp, int queueSize);
void sortQueue(queue<consumer>& q);
void printQueue(queue<consumer> q);
int menu();
int selectQueue(vector<queue <consumer>>& data);
void deleteUser(queue<consumer>& q, int index);
int selectUser(queue<consumer> q);
void mergeQueue(queue<consumer>& q, queue<consumer>& q1);

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand((unsigned)time(0));

    vector<queue <consumer>> data;
    data.push_back(queue <consumer>());

    int key = 1;
    int l;

    consumer tmp;
    tmp.name = "vasya";
    tmp.num = "100";
    tmp.priority = false;
    data[0].push(tmp);

    tmp.name = "petya";
    tmp.num = "1020";
    tmp.priority = true;
    data[0].push(tmp);


    while (true)
    {
        int answer = menu();
        switch (answer)
        {
        case 1:
            key = selectQueue(data);
            if (key == 0)
                break;
            else {
                printQueue(data[key - 1]);
                break;
            }

        case 2:
            key = selectQueue(data);
            if (key == 0)
                break;
            else {
                sortQueue(data[key - 1]);
                break;
            }

        case 3:
            data.push_back(queue <consumer>());
            break;

        case 4:
            key = selectQueue(data);
            if (key == 0)
                break;
            else {
                cout << "Приоритетный(1-да; 0-нет) заказ? ";

                cin >> tmp.priority;
                while (cin.fail())
                {
                    cin.clear();
                    cin >> tmp.priority;
                }

                cout << endl << "Введите имя клиента: ";
                cin.ignore();
                getline(cin, tmp.name);

                tmp.num = to_string(1000 + rand() % ((9999 + 1) - 1000));

                data[key - 1].push(tmp);
                break;
            }

        case 5:
            key = selectQueue(data);
            if (key == 0)
                break;
            else {
                l = selectUser(data[key - 1]);
                if (key == 0)
                    break;
                else {
                    deleteUser(data[key - 1], l - 1);
                    break;
                }
            }


        case 6:
            key = selectQueue(data);
            if (key == 0)
                break;
            else {
                l = selectQueue(data);
                if (key == 0 || l == key)
                    break;
                else {
                    mergeQueue(data[key - 1], data[l - 1]);
                    swap(data[l - 1], data.back());
                    data.pop_back();
                    break;
                }

            }
        case 7:
            key = selectQueue(data);
            if (key == 0)
                break;
            else {
                swap(data[key - 1], data.back());
                data.pop_back();
                break;
            }


        case 0:
            cout << "Завершение работы программы..." << endl;
            system("pause");
            return 0;
        }
        system("pause");
        system("cls");
    }

    system("pause");
    return 0;
}

void FrontToLast(queue<consumer>& q, int qsize)
{
    if (qsize <= 0)
        return;

    q.push(q.front());
    q.pop();

    FrontToLast(q, qsize - 1);
}


void pushInQueue(queue<consumer>& q, consumer temp, int qsize)
{

    if (q.empty() || qsize == 0) {
        q.push(temp);
        return;
    }

    else if (temp.priority > q.front().priority) {

        q.push(temp);

        FrontToLast(q, qsize);
    }
    else if (temp.priority == q.front().priority && temp.num <= q.front().num) {

        q.push(temp);

        FrontToLast(q, qsize);
    }
    else if (temp.priority == q.front().priority && temp.num <= q.front().num && !temp.priority) {

        q.push(temp);

        FrontToLast(q, qsize);
    }
    else {

        q.push(q.front());
        q.pop();

        pushInQueue(q, temp, qsize - 1);
    }
}

void sortQueue(queue<consumer>& q)
{

    if (q.empty())
        return;

    consumer temp = q.front();

    q.pop();

    sortQueue(q);

    pushInQueue(q, temp, q.size());
}

void printQueue(queue<consumer> q) {
    cout << setw(9) << "Важный заказ?" << setw(15) << "Имя клиента" << setw(15) << "Номер заказа" << endl;
    while (!q.empty()) {
        cout << setw(9) << boolalpha << q.front().priority << setw(15) << q.front().name << setw(15) << q.front().num << endl;
        q.pop();
    }
}


int menu() {
    int key = 1;
    int code;
    do {
        system("cls");
        cout << "Welcome to the club buddy!!!" << endl << endl;
        key = (key + 8) % 8;
        if (key == 1) cout << " -------------------------------------" << endl << "| РАСПЕЧАТАТЬ ОЧЕРЕДЬ                 |" << endl
            << " -------------------------------------" << endl;
        else  cout << "   распечатать очередь" << endl;

        if (key == 2) cout << " -------------------------------------" << endl << "| СОРТИРОВКА                          |" << endl
            << " -------------------------------------" << endl;
        else  cout << "   сортировка" << endl;

        if (key == 3) cout << " -------------------------------------" << endl << "| ДОБАВИТЬ НОВУЮ ОЧЕРЕДЬ              |" << endl
            << " -------------------------------------" << endl;
        else  cout << "   добавить новую очередь" << endl;

        if (key == 4) cout << " -------------------------------------" << endl << "| ДОБАВИТЬ НОВОГО КЛИЕНТА В ОЧЕРЕДЬ   |" << endl
            << " -------------------------------------" << endl;
        else  cout << "   добавить нового клиента в очередь" << endl;

        if (key == 5) cout << " -------------------------------------" << endl << "| УДАЛИТЬ КЛИЕНТА                     |" << endl
            << " -------------------------------------" << endl;
        else  cout << "   удалить клиента" << endl;

        if (key == 6) cout << " -------------------------------------" << endl << "| СЛИЯНИЕ ОЧЕРЕДЕЙ                    |" << endl
            << " -------------------------------------" << endl;
        else  cout << "   слияние очередей" << endl;

        if (key == 7) cout << " -------------------------------------" << endl << "| УДАЛИТЬ ОЧЕРЕДЬ                     |" << endl
            << " -------------------------------------" << endl;
        else  cout << "   удалить очередь" << endl;


        //cout << endl;
        if (key == 0) cout << " -------------------------------------" << endl << "| ЗАКРЫТЬ ПРОГРАММУ                   |" << endl
            << " -------------------------------------" << endl;
        else  cout << "   закрыть программу" << endl;

        code = _getch();
        if (code == 224)
        {
            code = _getch();
            if (code == 80) key++;
            if (code == 72) key--;
        }
    } while (code != 13);
    system("cls");
    return key;
}

int selectQueue(vector<queue <consumer>>& data) {
    int key = 1;
    int code;
    do {
        system("cls");
        cout << "Выберете очередь: " << endl << endl;
        key = (key + data.size() + 1) % (data.size() + 1);

        for (unsigned int i = 0; i < data.size(); i++) {
            if (key == i + 1) cout << "-> " << "Очередь №" << i + 1 << endl;
            else  cout << "   " << "Очередь №" << i + 1 << endl;
        }

        cout << endl;
        if (key == 0) cout << "-> Отмена" << endl;
        else  cout << "   Отмена" << endl;
        code = _getch();
        if (code == 224)
        {
            code = _getch();
            if (code == 80) key++;
            if (code == 72) key--;
        }
    } while (code != 13);
    system("cls");
    return key;
}

int selectUser(queue<consumer> q) {
    int key = 1;
    int code;
    int cnt = 0;
    queue <consumer> temp = q;
    do {
        temp = q;
        cnt = 0;
        system("cls");
        cout << "Выберете клиента: " << endl << endl;


        cout << "   " << setw(9) << "Важный заказ?" << setw(15) << "Имя клиента" << setw(15) << "Номер заказа" << endl;
        while (!temp.empty()) {

            if (key == cnt + 1) cout << "-> " << setw(9) << boolalpha << temp.front().priority << setw(15) << temp.front().name << setw(15) << temp.front().num << endl;
            else
                cout << "   " << setw(9) << boolalpha << temp.front().priority << setw(15) << temp.front().name << setw(15) << temp.front().num << endl;
            temp.pop();
            cnt++;
        }

        key = (key + cnt + 1) % (cnt + 1);

        cout << endl;
        if (key == 0) cout << "-> Отмена" << endl;
        else  cout << "   Отмена" << endl;
        code = _getch();
        if (code == 224)
        {
            code = _getch();
            if (code == 80) key++;
            if (code == 72) key--;
        }
    } while (code != 13);
    system("cls");
    return key;
}

void deleteUser(queue<consumer>& q, int index) {
    for (unsigned int i = 0; i < q.size(); i++) {
        if (i == index) q.pop();
        else {
            q.push(q.front());
            q.pop();
        }
    }
}

void mergeQueue(queue<consumer>& q, queue<consumer>& q1) {
    while (!q1.empty())
    {
        q.push(q1.front());
        q1.pop();
    }
}