using System;
using System.Collections.Generic;
using System.Collections;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ForwardList
{
	internal class Element
	{
		public int Data { get; set; }       // значение элемента
		public Element pNext { get; set; }  // следующий элемент
		
		public Element(int Data, Element pNext = null)
		{
			this.Data = Data;
			this.pNext = pNext;
			Console.WriteLine($"EConstructor:\t{GetHashCode()}");
		}
		~Element()
		{
            Console.WriteLine($"Destructor:\t{GetHashCode()}");

		}
	
	}
}
