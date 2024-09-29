#include<iostream>
#include "List2.h"
#include "List2.cpp"
using std::string;

void main()
{
    setlocale(LC_ALL, "");
    /*int n;
    /*cout << "Введите размер списка: "; cin >> n;
    List listOne;
    for (int i = 0; i < n; i++)
    {
      listOne.push_front(rand() % 100);
    }
    listOne.print();
    listOne.push_front(3452);
    listOne.print();*/

    /*List list = { 3, 5, 8, 13, 21 };

    list.print();

    for (int i : list)
    {
      cout << i << tab;
    }
    cout << endl;*/

   /* List<double> list1 = { 3.25, 6.923, 0.24, 230.23, 233.34 };
    List<double> list2 = { 8.356, 232.92, 23.222 };
    List<double> list3 = list1 + list2;
    for (double i : list3)
    {
        cout << i << tab;
    }
    cout << endl;*/

    List<string> list1 = { "3.523", "5.23", "82.323", "13.03", "21" };
    List<string> list2 = { "34", "55.3234", "89" };
    List<string> list3 = list1 + list2;
    for (string i : list3)
    {
        cout << i << tab;
    }
    cout << endl;
}