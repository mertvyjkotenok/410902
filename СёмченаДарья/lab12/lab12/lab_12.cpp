//��������� ������� �� 7-�� �������� -  �k�, �l�,�m�, �n�, �o�, �p�, �r�. 
// �������� �� ������� ��� ������� �l�, �m�, �r� � �������� � ����� ������� ������ �s�. 
// ���������� ��� �������������, ��� � �������� ����������� ���������� �� ������.
#include<iostream>
#include<queue>
#include<windows.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	queue <char> q, q2; char a;
	q.push('k'); q.push('l'); q.push('m'); q.push('n'); q.push('o'); q.push('p'); q.push('r');
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q2.push(q.front());
		q.pop();
	}
	cout << endl;
	while (!q2.empty())
	{
		q.push(q2.front());
		if ((q2.front() == 'l') || (q2.front() == 'm') || (q2.front() == 'r')) cout << q2.front()<<' ';
		q2.pop();
	}
	q.push('s');
	cout << endl;
	while (!q.empty())
	{
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}

