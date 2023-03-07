#include <iostream>
#include <string>
using namespace std;

struct Train
{
    int win;
    string name;
};

Train train[7] = {
    {15, "summer"},
    {33, "cloe"},
    {24, "summer"},
    {28, "niki"},
    {32, "jenny"},
    {20, "summer"},
    {40, "coco"}};

int main()
{
    string name;
    int age;

    cin >> name;
    cin >> age;

    for (int i = 0; i < 7; i++)
    {
        if (train[i].name == name && train[i].win == age)
        {
            cout << i;
            break;
        }
    }
    return 0;
}
