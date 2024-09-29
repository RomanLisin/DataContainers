#pragma once
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

template <typename T>
class List
{
    template<typename T>
    class Element
    {
        T Data;
        Element<T>* pNext;
        Element<T>* pPrev;

    public:

        Element<T>(T Data, Element* pNext = nullptr, Element* pPrev = nullptr)
            :Data(Data), pNext(pNext), pPrev(pPrev)
        {
            cout << "EConstructor:\t" << this << endl;
        }

        ~Element<T>()
        {
            cout << "EDestructor:\t" << this << endl;
        }
        friend class List<T>;
    };// *Head, * Tail;  // Объявляем два указателя на объекты класса 'Element' непостредственно после описания класса
    size_t size; // количество элементов списка
    Element<T>* Head;
    Element<T>* Tail;

    template<typename T>
    class Iterator
    {
        Element<T>* Temp;
    public:
        Iterator<T>(Element<T>* elem) : Temp(elem) {}

        Iterator<T>& operator++() { // переход к следующему элементу
            if (Temp) Temp = Temp->pNext;
            return *this;
        }

        bool operator!=(const Iterator<T>& other) const {
            return Temp != other.Temp;
        }

        T operator*() const { // разыменование итератора
            return Temp->Data;
        }
    };
public:

    // конструктор по умолчанию
    List<T>();
    List(const List<T>& list);
    List<T>(std::initializer_list<T>); // конструктор для считывания массива List list = {  3, 5, 8, 13, 21 };

    List<T>& operator = (const List<T>&);

    List<T>& operator + (const List<T>&);

    ~List<T>();
    //            Adding elements:
    void push_front(T);

    void push_back(T);

    void pop_front();

    void pop_back();

    void insert(T, int);

    void erase(int);

    void Clear();

    //    Methods:
    void print()const;

    void revers_print()const;

    Iterator<T> begin() const { return Iterator<T>(Head); }
    Iterator<T> end() const { return Iterator<T>(nullptr); }
};