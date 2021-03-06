// Task3_CPP.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Сынкова Анастасия 91гр. задача 4а
/*
Реализовать шаблон класса очередь Queue<X>, хранящий элементы произвольного типа. Класс должен содержать методы:
	1) вычисление длины очереди
	2) добавление нового элемента в конец очереди
	3) получение элемента из головы очереди
	4) удаление элемента из головы очереди
	5) поиск элемента в очереди
	6) печать очереди
*/

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

template<class T>
class Queue
{
private:
	int const N = 10;
	T *qu = new T[N];
	int first, last;
	int size = N;
public:

	//конструктор
	Queue()
	{
		first = last = 0;
	}

	//увеличение размера массива на заданную величину n 
	T *incSize(T *array, int sz, int n)
	{
		T *a = new T[sz + n];
		for (int i = 0; i < sz; i++)
			a[i] = array[i];
		delete[] array;
		return a;
	}

	//добавить элемент в конец очереди
	void Push(T value)
	{
		if (last >= 1 && last == size)
			qu = incSize(qu, size, N);
		qu[last] = value;
		last++;
	}

	//достать элемент из начала очереди
	T Pop()
	{
		if (last != 0 && first <last)
		{
			T q = qu[first];
			first++;
			return q;
		}
		else
			throw out_of_range("Очередь пуста");
	}

	//посмотреть элемент из головы очереди, не доставая его
	T See()
	{
		T q = qu[first];
		return q;
	}

	//удалить элемент из начала очереди
	void Delete()
	{
		if (last != 0 && first < last)
		{
			T q = qu[first];
			first++;
		}
		else
			throw out_of_range("Очередь пуста");
	}

	//поиск элемента в очереди
	int Search(T el)
	{
		bool ok = false;
		int i = first;
		while (!ok && i < last)
		{
			if (qu[i] == el)
				ok = true;
			else
				i++;
		}
		if (ok)
			return(i-first);
		else
			return (-2);
	}

	//печать очереди
	void Print()
	{
		if (first == last)
			cout << "Очередь пуста";
		for (int i = first; i < last; i++)
			cout << qu[i] << " ";
		cout << endl;
	}

	//ввод с клавиатуры
	void ReadKey(string txt, T &value)
	{
		cout << txt << endl;
		cin >> value;
	}

	//длина очереди
	int Length()
	{
		return (last - first);
	}
};

struct Student
{
	string fam;
	int age;
	//const Account &s2
	friend ostream& operator << (ostream& s, const Student& my)
	{
		return cout << "Имя: " << my.fam << " Возраст: " << my.age << endl;
	}

	friend istream& operator >> (istream& s, Student& my)
	{
		cout << "Имя: ";
		cin >> my.fam;
		cout << "Возраст ";
		cin >> my.age;
		cout << endl;
		return s;
	}

	friend bool operator == (const Student &s1, const Student &s2)
	{
		if ((s1.fam == s2.fam) && (s1.age == s2.age))
			return true;
		//else return false;
	}
};

//ввод числа с заданными границами
int InputNum(const char *txt, int min, int max)
{
	int num;
	cout << txt << endl; //вывод вопроса на экран
	cin >> num;
	while ((num < min) || (num > max)) //пока число num не попадает в диапозон [min..max] 
	{
		cout << "Недопустимое значение, введите еще раз:" << endl;
		cin >> num;
	}
	return num;
}

int SelectMenuItem()
{
	cout << "1 - Очередь из чисел" << endl;
	cout << "2 - Очередь из строк" << endl;
	cout << "3 - Очередь из студентов" << endl;
	return InputNum("0 - выход", 0, 3);
}

int SelectMenuItem2()
{
	cout << "1 - Добавить элемент в конец очереди" << endl;
	cout << "2 - Получить элемент из головы очереди" << endl;
	cout << "3 - Удалить элемент из головы очереди" << endl;
	cout << "4 - Вычислить длину очереди" << endl;
	cout << "5 - Найти элемент в очереди" << endl;
	cout << "6 - Напечатать очередь" << endl;
	cout << "7 - Посмотреть первый элемент" << endl;
	return InputNum("0 - Выйти", 0, 7);
}


int main()
{

	setlocale(LC_ALL, "Russian");
	int MenuItem1 = -1, MenuItem2 = -1, m, k;
	string nw;
	Student st;
	Queue<int> q1;
	Queue<string> q2;
	Queue<Student> q3;
	while (MenuItem2 != 0)
	{
		MenuItem2 = SelectMenuItem2();
		try {
			switch (MenuItem2)
			{
			case 1:
				q1.ReadKey("Введите число", k);
				q1.Push(k);
				break;
			case 2:
				cout << q1.Pop() << endl;
				break;
			case 3:

				q1.Delete();
				break;
			case 4:
				cout << "Длина очереди = " << q1.Length() << endl;
				break;
			case 5:
				cout << "Введите элемент, который хотите найти" << endl;
				cin >> k;
				if (q1.Search(k) != -1)

					cout << "Искомый элемент имеет в очереди номер " << q1.Search(k) << endl;
				else
					cout << "Такого элемента нет" << endl;
				break;
			case 6:
				q1.Print();
				break;
			case 7:
				cout << q1.See() << endl;
				break;
			default:
				break;

			}
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		
		

		/*
		try {
		switch (MenuItem2)
		{
				case 1:
					q2.ReadKey("Введите строку", nw);
					q2.Push(nw);
					break;
				case 2:
					cout << q2.Pop() << endl;
					break;
				case 3:
					q2.Delete();
					break;
				case 4:
					cout << "Длина очереди = " << q2.Length() << endl;
					break;
				case 5:
					cout << "Введите элемент, который хотите найти" << endl;
					cin >> nw;
					if (q2.Search(nw) != -1)

						cout << "Искомый элемент имеет в очереди номер " << q2.Search(nw) << endl;
					else
						cout << "Такого элемента нет" << endl;
					break;
				case 6:
					q2.Print();
					break;
				case 7:
					cout << q2.See() << endl;
					break;
				default:
					break;
				
		}
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		
		*/

		/*
		try 
		{
			//Student s = new Student();
		switch (MenuItem2)
		{		
				case 1:
					q3.ReadKey("", st);
					q3.Push(st);
					break;
				case 2:
					st = q3.Pop();
					cout << st << endl;
					break;
				case 3:
					q3.Delete();
					break;
				case 4:
					cout << "Длина очереди = " << q3.Length() << endl;
					break;
				case 5:
					cout << "Введите элемент, который хотите найти" << endl;
					cin >> st;
					if (q3.Search(st) > -1)

						cout << "Искомый элемент имеет в очереди номер " << q3.Search(st) << endl;
					else
						cout << "Такого элемента нет" << endl;
					break;
				case 6:
					q3.Print();
					break;
				case 7:
					st = q3.See();
					cout << st << endl;
					break;
				default:
					break;
				
		}
		}
		catch (exception& e)
		{
			cout << e.what() << endl;
		}
		*/
	}
}