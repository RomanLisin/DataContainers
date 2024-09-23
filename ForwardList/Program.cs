using System;
using System.Collections.Generic;
using System.Dynamic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForwardList
{
	internal class Program
	{
		static void Main(string[] args)
		{
			//Random rand = new Random(0);
   //         Console.Write("Введите размер списка: ");
			//int n = Convert.ToInt32(Console.ReadLine());
			//ForwardList lists = new ForwardList();
			//for (int i = 0; i < n; i++)
			//{
			//	list.push_back(rand.Next(100));
			//}
			//list.Print();
			//list.insert(123,3);
			//list.Clear();
			//list.Print();
			//Console.WriteLine("Введиет индекс добавляемого элемента: ");
			//int index = Convert.ToInt32(Console.ReadLine());
			//Console.WriteLine("Введиет значение добавляемого элемента: ");
			//int value = Convert.ToInt32(Console.ReadLine());
			//list.insert(value, index);
			//list.push_front(3453);
			//list.push_front(342);
			//list.Print();
			//Console.WriteLine("Введиет индекс удаляемого элемента: ");
			//int index = Convert.ToInt32(Console.ReadLine());
			//list.erase(index);
			//lists.Print();
			ForwardList list = new ForwardList(){ 3, 5, 8, 13, 21 };
			list.Print();
			foreach (int i in list)
			{
				Console.Write(i + "\t");
			}
			Console.WriteLine();
		}
	}
}
