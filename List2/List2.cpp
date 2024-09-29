#include "List2.h"

#define tab "\t"
#define delimetr "\n--------------------------------------------\n"   

template<typename T>
List<T>::List<T>() :Head(nullptr), Tail(nullptr), size(0)
{
    cout << "LConstructor:\t" << this << endl;
}

template<typename T>
List<T>::List(const List<T>& list) : List()
{
    Element<T>* Temp = list.Head;
    while (Temp)
    {
        push_back(Temp->Data);
        Temp = Temp->pNext;
    }
}

template<typename T>
List<T>::List<T>(std::initializer_list<T> values)
{
    for (T value : values)
        push_back(value);
    cout << "initializer_list_Constructor:\t" << this << endl;
}

template<typename T>
List<T>::~List<T>()
{
    cout << "LDestructor:\t" << this << endl;
    Clear();
}

template<typename T>
List<T>& List<T>::operator = (const List<T>& list)
{
    if (this == &list)return *this;
    Clear();  
    Element<T>* Temp = list.Head;
    while (Temp)
    {
        push_back(Temp->Data);
        if (!Temp->pNext)Temp = Temp->pNext;
    }
    return *this;  
}

template<typename T>
List<T>& List<T>::operator + (const List<T>& list)
{
    List<T>* Lst = new List<T>(*this);
    for (T i : list) { Lst->push_back(i); }
    return *Lst;
}

template<typename T>
void List<T>::push_front(T Data)
{
    if (Head == nullptr && Tail == nullptr)
        Head = Tail = new Element<T>(Data);
    else
    {
        //1) ������� ������� ����� �������
        Element<T>* New = new Element<T>(Data);
        //2) ������������ ������� � ������
        New->pNext = Head;

        //3) ������������ ������ � ��������
        Head->pPrev = New;
        //4) ������� ������ �� ����� �������:
        Head = New;
    }
    size++;
}

template<typename T>
void List<T>::push_back(T Data)
{
    if (Head == nullptr && Tail == nullptr)
        Head = Tail = new Element<T>(Data);
    else
    {
        //1) ������� ����� �������
        Element<T>* New = new Element<T>(Data);
        //2) ������������ ������� � ������
        New->pPrev = Tail;
        //3) ������������ ������ � ��������
        Tail->pNext = New;
        //4) ������� ����� �� ����� �������
        Tail = New;
    }
    size++;
}

template<typename T>
void List<T>::pop_front()
{
    if (Head == nullptr)return;
    if (Head->pNext != nullptr)
    {
        Element<T>* New = Head->pNext;
        New->pPrev = nullptr;
        delete Head;
        Head = New;
    }
    else { delete Head;  Head = Tail = nullptr; }
    size--;
}

template<typename T>
void List<T>::pop_back()
{
    if (Tail == nullptr)return;
    if (Head->pNext != nullptr)
    {
        Element<T>* New = Tail->pPrev;
        New->pNext = nullptr;
        delete Tail;
        Tail = New;
        size--;
    }
    else pop_front();
}

template<typename T>
void List<T>::insert(T Data, int index)
{
    if (index > size) {
        cout << "Index > size" << endl; return;
    }
    if (Head == nullptr && Tail == nullptr)
        Head = Tail = new Element<T>(Data);
    if (index == 0)
    {
        push_front(Data); return;
    }
    else
    {
        Element<T>* Temp = Head;
        for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
        Element<T>* New = new Element<T>(Data);
        // �������� ������� � ������
        if (Temp->pNext != nullptr) New->pNext = Temp->pNext; else { push_back(Data); return; }
        Temp->pNext = New;
        Temp->pNext->pPrev = New;
        New->pPrev = Temp;
    }
    size++;
}

template<typename T>
void List<T>::erase(int index)
{
    if (index > size || Head == nullptr && Tail == nullptr)return;
    if (index == size-1) {
        pop_back(); return;
    }
    if (index == 0)
    {
        pop_front();
        return;
    }

    Element<T>* Temp = Head;
    for (int i = 0; i < index; i++)
    {
        Temp = Temp->pNext;
    }
    Temp->pPrev->pNext = Temp->pNext;
    Temp->pNext->pPrev = Temp->pPrev;
    delete Temp;
    Temp->pNext = nullptr;
    Temp->pPrev = nullptr;
    size--;
}

template<typename T>
void List<T>::Clear()
{
    while (Head)pop_back();
    Head = nullptr;
    size = 0;
}

template<typename T>
void List<T>::print()const
{
    cout << "Head:\t" << Head << endl;
    for (Element<T>* Temp = Head; Temp; Temp = Temp->pNext)
        cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
    cout << "Tail:\t" << Tail << endl;
    cout << "���������� ��������� ������: " << size << endl;
}

template<typename T>
void List<T>::revers_print()const
{
    cout << "Tail:\t" << Tail << endl;
    for (Element<T>* Temp = Tail; Temp; Temp = Temp->pPrev)
        cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
    cout << "Head:\t" << Head << endl;
    cout << "���������� ��������� ������: " << size << endl;
}
