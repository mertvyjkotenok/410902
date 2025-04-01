/*2.На вход программы поступает выражение, состоящее из односимвольных идентификаторов и знаков арифметических действий. 
Требуется преобразовать это выражение в обратную польскую запись или же сообщить об ошибке.
*/
#include<iostream>
#include<stack>
#include<queue>
#include<windows.h>
using namespace std;
bool isOperator(char a) { return a == '+' || a == '-' || a == '*' || a == '/'; }
int precendence(char a) {
	if (a == '+' || a == '-') return 1;
	if (a == '*' || a == '/') return 2;
	return 0;
}
int main() 
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	string str, strout; int i; char cur;
	stack<char>operators;
	queue<char>out;
	cout << "Введите выражение для преобразования: ";
	cin >> str;
	
	for (i = 0; i < str.length(); i++)
	{
		cur = str[i];
		if (cur == ' ') continue;
		if (cur == '(') operators.push(cur);
		else if (cur == ')')
		{
			while (operators.top() != '('&&!operators.empty())
			{
				out.push(operators.top());
				operators.pop();
			}
			operators.pop();
		}
		else if (isOperator(cur))
		{
			while (!operators.empty() && precendence(operators.top()) >= precendence(cur))
			{
				out.push(operators.top()); operators.pop();
			}
			operators.push(cur);
		}
		else out.push(cur);
	}
	while (!operators.empty())
	{
		out.push(operators.top()); operators.pop();
	}
	cout << "Преобразованное выражение: ";
	while (out.size()>0)
	{
		cout << out.front();
		out.pop();
	}
	return 0;
}