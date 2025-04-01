//�������� ���������� ������ ������������� �� ����������� ����� �������� ������� ��������. ���������� ������ �����.
#include<iostream>
#include<windows.h>
using namespace std;

int dest(int a)
{
	int des = a / 10;
	if ((des > 9) || (des < -9)) des = des % 10;
	if (des < 0) des = -des;
	return (des);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float m;
	int i, j, n, mini;
	cout << "������� ��������� ����� � ����� �������?" << endl;
	cin >> n;
	float* a{ new float[n] };
	cout << "������� �������� �������: " << endl;
	for (i = 0; i < n; i++)
		cin >> a[i];

	for (i = 0; i < n - 1; i++)
	{
		mini =i;
		for (j = i + 1; j < n; j++)
			if (dest(a[j])< dest(a[mini])) mini = j;
		if (dest(a[mini]) < dest(a[i]))
		{
			m = a[i];
			a[i] = a[mini];
			a[mini] = m;
		}
	}

	for (i = 0; i < n; i++)
		cout<< a[i]<<' ';
	delete a;
	return 0;
}