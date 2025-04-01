/*1.Описать функцию, которая вычисляет значение заданного выражения.
Входные данные.В первой строке содержит обратную польскую запись арифметического выражения.
Все операнды целые положительные числа.
Выходные данные.Вывести результат вычисления ОПЗ.
Технические требования.Используются знаки операций : +, -, *, / .
Примеры
input.txt output.txt
3 1 + 4
12 5 * 10 - 50
1 2 30 + *32
2 10 + 2 4 + 6 – 2 / 6*/

#include<iostream>
#include<stack>
#include<string>
#include<windows.h>
#include<sstream>

using namespace std;
bool isOperator(string a) { return a == "+" || a == "-" || a == "*" || a == "/"; }

int calc(string s, int a, int b) {
	if (s == "+") return (a + b);
	if (s == "-") return (a - b);
	if (s == "*") return (a * b);
	if (s == "/") return (a / b);
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str; int i; string cur, ch;
	stack<int>numbers;
	
	cout << "Введите обратную польскую запись выражения: ";
	getline(cin, str);
	istringstream iss(str);

	while (iss>>cur)
	{
		if (isOperator(cur)) {
			int n2 = numbers.top();
			numbers.pop();
			int n1 = numbers.top();
			numbers.pop();
			numbers.push(calc(cur, n1, n2));
		}
		else {
			int n = stoi(cur); numbers.push(n);
		}
	}
	cout << "Результат вычисления: " << numbers.top();
	return 0;
}