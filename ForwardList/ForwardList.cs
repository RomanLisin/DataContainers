using System;
using System.CodeDom.Compiler;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics.Eventing.Reader;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;


// Generics
namespace ForwardList
{

	internal class ForwardList<T> : IEnumerable
	{ 
		Element<T> Head;  // голова
		public uint Size { get; private set; }
		public IEnumerator GetEnumerator()=> new Enumerator<T>(Head);
		public void Add(T Data) => push_back(Data);
		public ForwardList()
		{
			Head = null;
			Size = 0;
			Console.WriteLine($"LConstructor:\t{GetHashCode()}");
		}
		//public ForwardList(int number)
		//{
		//	Head = null;
		//	Size = 0;
		//	this.push_back(number);
			
		//}
		
		public ForwardList(T[] array)
		{
			for (int i = 0; i < array.Length; i++) push_back(array[i]);
		}
		//public IEnumerator GetEnumerator() => new Enumerator(Head);
		// цикл foreach ожидает метод GetEnumerator() и поддержку методов MoveNext() и Current
		//public IEnumerator<T> GetEnumerator()
		//{
		//	Element<T> Temp = Head;
		//	while (Temp != null)
		//	{
		//		yield return Temp.Data;  // yield return приостанавливает, но не завершает метод
		//		Temp = Temp.pNext; // цикл возобновляется, выполнение продолжается с того места, где оно было приостановлено, а не завершено
		//	}
		//}
		//IEnumerator<T> IEnumerable.GetEnumerator()
		//{
		//	return GetEnumerator();
		//}

		~ForwardList()
		{
			Console.WriteLine($"Destructor:\t{GetHashCode()}");
		}
		public void Clear()
		{
			while (Head != null) pop_back();
			Head = null;
		}

		////          Adding elements:
		//public void Add(T Data)   // переопределяем метод Add
		//{
		//	push_back(Data);
		//}
		public void push_front(T Data)
		{
			//1) создаём новый элемент
			//Element New = new Element(Data);
			//2) подключаем новый элемент к списку
			//New.pNext = Head;
			//3) смещаем голову на новый элемент
			//Head = New;
			Head = new Element<T>(Data,Head);
			Size++;
		}
		public void push_back(T Data)
		{
			if (Head == null) push_front(Data);
			else
			{
				Element<T> Temp = Head;
				while (Temp.pNext != null)
					Temp = Temp.pNext;
				Element<T> New = new Element<T>(Data);
				Temp.pNext = New;
				Size++;
			}

		}
		public void insert(T Data, int Index)
		{
			if (Index > Size) return;
			if (Index == 0) push_front(Data);
			else
			{
				//1)доходим до нужного элеамента
				Element<T> Temp = Head;
				for (int i = 0; i < Index - 1; i++) Temp = Temp.pNext;
				//if (Temp.pNext != null) break;
				//	Temp = Temp.pNext;
				// 2) создаём новый элемнт
				Element<T> New = new Element<T>(Data);
				//3) Включаем элемент в список
				New.pNext = Temp.pNext;
				Temp.pNext = New;
				Size++;
			}

		}
		//			Removing elements:
		public void pop_front()
		{
			//Element erased = Head; // сохраняем адрес удаляемого элемента , нужен в c++ в с# не нужен
			Head = Head.pNext; // Исключаем элемент из списка
			Size--;
		}
		public void pop_back()
		{
			if (Head == null) return;
			else if (Head.pNext == null) pop_front();
			else
			{
				Element<T> Temp = Head;
				while (Temp.pNext.pNext != null)
				{
					Temp = Temp.pNext;
					Temp.pNext = null;
				} 
			}
			Size--;

		}
		public void erase(int index)
		{
			if (Head == null || index > Size-1) return;
			else if (index == 0) pop_front();
			else if (index < Size)
			{
				Element<T> Temp = Head;
				for (int i = 0; i < index - 1; i++) Temp = Temp.pNext;
				Temp.pNext = Temp.pNext.pNext;
			}
			else pop_back();
			Size--;
			

		}
		//           Methods:
		public void Print()
		{
			Element<T> Temp = Head; // Temp - это итератор. Это указатель при помощи которого можно получить доступ к элементам к структуре данных
			while (Temp != null)
			{
                Console.Write($"{Temp.Data}\t");
				Temp = Temp.pNext; // переход на следующий элемент

            }
            Console.WriteLine();
        }
		
	}
}
