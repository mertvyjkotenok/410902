//ƒаны указатели head1 и head2 на вершины стеков, хран€щих некоторые отсортированные 
// по убыванию наборы целых чисел.
// –азработать программу, позвол€ющую построить стек(head3), содержащий набор 
// упор€доченных по возрастанию четных чисел, извлеченных из исходных стеков.
#include<iostream>
#include<stack>
#include<Windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	stack<int> st1;
	stack<int> st2;
	stack<int> st3;
	stack<int> st4;
	int n1, n2, i,a, n3;

	cout << "—колько элементов будет в стеке 1?"<<endl;
	cin >> n1;
	cout << "¬ведите целые числа дл€ хранени€ в стеке в пор€дке убывани€."<<endl;

	for (i = 0; i < n1; i++)
	{
		cin >> a;
		if (a%2==0) st1.push(a);
	}

	cout << "—колько элементов будет в стеке 2?" << endl;
	cin >> n2;
	cout << "¬ведите целые числа дл€ хранени€ в стеке в пор€дке убывани€." << endl;

	for (i = 0; i < n2; i++)
	{
		cin >> a;
		if (a%2==0) st2.push(a);
	}

	n3 = st1.size() + st2.size();

	for (i=0; i<n3; i++)
	{
		if (st1.empty())
		{
			st3.push(st2.top());
			st2.pop();
		}
		else
		{
			if (st2.empty())
			{
				st3.push(st1.top());
				st1.pop();
			}
			else
			{
				if (st1.top()<st2.top())
				{
					st3.push(st1.top());
					st1.pop();
				}
				else
				{
					st3.push(st2.top());
					st2.pop();
				}
			}
		}
	} //возрастает

	while (!st3.empty())
	{
		st4.push(st3.top());
		st3.pop();
	}

	cout << "ѕолученный стек, содержащий набор упор€доченных по возрастанию четных чисел, \nизвлеченных из исходных стеков:\n";
	while (!st4.empty())
	{
		cout << st4.top() << " ";
		st4.pop();
	}//убывает

	return 0;
}