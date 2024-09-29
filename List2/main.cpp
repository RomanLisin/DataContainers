#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimetr "\n--------------------------------------------\n"   



class List
{

    class Element
    {
        int Data;
        Element* pNext;
        Element* pPrev;

    public:

        Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
            :Data(Data), pNext(pNext), pPrev(pPrev)
        {
            cout << "EConstructor:\t" << this << endl;
        }

        ~Element()
        {
            cout << "EDestructor:\t" << this << endl;
        }
        friend class List;
    }*Head, * Tail;  // Объявляем два указателя на объекты класса 'Element' непостредственно после описания класса
    size_t size; // количество элементов списка
    /*Element* Head;
    Element* Tail;*/

    class Iterator
    {
        Element* Temp;
    public:
        Iterator(Element* elem) : Temp(elem) {}

        Iterator& operator++() { // переход к следующему элементу
            if (Temp) Temp = Temp->pNext;
            return *this;
        }

        bool operator!=(const Iterator& other) const {
            return Temp != other.Temp;
        }

        int operator*() const { // разыменование итератора
            return Temp->Data;
        }
    };
public:

    // конструктор по умолчанию
    List();

    List(std::initializer_list<int> values); // конструктор для считывания массива List list = {  3, 5, 8, 13, 21 };

    List& operator = (const List&);

    List& operator + (const List&);

    ~List();
    //            Adding elements:
    void push_front(int Data);

    void push_back(int Data);

    void pop_front();

    void pop_back();

    void insert(int Data, int index);

    void erase(int index = 0);

    void Clear();

    //    Methods:
    void print()const;

    void revers_print()const;

    Iterator begin() const { return Iterator(Head); }
    Iterator end() const { return Iterator(nullptr); }
};

List::List() :Head(nullptr), Tail(nullptr), size(0)
{
    cout << "LConstructor:\t" << this << endl;
}

List::List( std::initializer_list<int> values)
{
    for (int value : values)
        push_back(value);
    cout << "initializer_list_Constructor:\t" << this << endl;
}

List::~List()
{
    cout << "LDestructor:\t" << this << endl;
    Clear();
}

List& List::operator = (const List& list)
{
    if (this == &list)return *this;
    this->~List();
    Element* Temp = list.Head;
    while (Temp)
    {
        push_back(Temp->Data);
        if (!Temp->pNext)Temp = Temp->pNext;
    }
}

List& List::operator + (const List& list)
{
    List* Lst = new List(*this);
    for (int i : list) { Lst->push_back(i); }
    return *Lst;
}

void List::push_front(int Data)
{
    if (Head == nullptr && Tail == nullptr)
        Head = Tail = new Element(Data);
    else
    {
        //1) Создаем элемент новый элемент
        Element* New = new Element(Data);
        //2) Присоединяем элемент к списку
        New->pNext = Head;

        //3) Присоединяет список к элементу
        Head->pPrev = New;
        //4) Смещаем голову на новый элемент:
        Head = New;
    }
    size++;
}

void List::push_back(int Data)
{
    if (Head == nullptr && Tail == nullptr)
        Head = Tail = new Element(Data);
    else
    {
        //1) создаем новый элемент
        Element* New = new Element(Data);
        //2) присоединяем элемент к хвосту
        New->pPrev = Tail;
        //3) присоединяем список к элементу
        Tail->pNext = New;
        //4) Смещаем хвост на новый элемент
        Tail = New;
    }
    size++;
}
void List::pop_front()
{
    if (Head == nullptr)return;
    if (Head->pNext != nullptr)
    {
        Element* New = Head->pNext;
        New->pPrev = nullptr;
        delete Head;
        Head = New;
    }
    else { delete Head;  Head = Tail = nullptr; }
    size--;
}

void List::pop_back()
{
    if (Tail == nullptr)return;
    if (Head->pNext != nullptr)
    {
        Element* New = Tail->pPrev;
        New->pNext = nullptr;
        delete Tail;
        Tail = New;
        size--;
    }
    else pop_front();
}

void List::insert(int Data, int index)
{
    if (index > size) {
        cout << "Index > size" << endl; return;
    }
    if (Head == nullptr && Tail == nullptr)
        Head = Tail = new Element(Data);
    if (index == 0)
    {
        push_front(Data); return;
    }
    else
    {
        Element* Temp = Head;
        for (int i = 0; i < index - 1; i++)Temp = Temp->pNext;
        Element* New = new Element(Data);
        // включаем элемент в список
        if (Temp->pNext != nullptr) New->pNext = Temp->pNext; else { push_back(Data); return; }
        Temp->pNext = New;
        Temp->pNext->pPrev = New;
        New->pPrev = Temp;
    }
    size++;
}

void List::erase(int index)
{
    if (index > size || Head == nullptr && Tail == nullptr)return;
    if (index == size) {
        pop_back(); return;
    }
    if (index == 0)
    {
        pop_front();
        return;
    }

    Element* Temp = Head;
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

void List::Clear()
{
    while (Head)pop_back();
    Head = nullptr;
    size = 0;
}

void List::print()const
{
    cout << "Head:\t" << Head << endl;
    for (Element* Temp = Head; Temp; Temp = Temp->pNext)
        cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
    cout << "Tail:\t" << Tail << endl;
    cout << "Количество элементов списка: " << size << endl;
}

void List::revers_print()const
{
    cout << "Tail:\t" << Tail << endl;
    for (Element* Temp = Tail; Temp; Temp = Temp->pPrev)
        cout << Temp->pPrev << tab << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
    cout << "Head:\t" << Head << endl;
    cout << "Количество элементов списка: " << size << endl;
}

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

    List list1 = { 3, 5, 8, 13, 21 };
    List list2 = { 34, 55, 89 };
    List list3 = list1 + list2;
    for (int i : list3)
    {
        cout << i << tab;
    }
    cout << endl;
}