#include<iostream>
#include<windows.h>
using namespace std;

float summa(float k, float c)
{
	float sum, a;
	//cout<<k<<" " << c << endl;
	a = sqrt(k);
	c = c - 1;
	sum = pow(c, 3) + a;
	//cout<<a<<" " << c << " " << sum << endl;
	if (c > 1) summa(sum, c);
	else return(sum);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	float n, s, l;
	cout << "¬ведите n:"<<endl;
	cin >> n;
	l= pow(n, 1 / 3.0);
	s=sqrt(summa(n, l));
	cout << "»тог вычислений: " << s;
	return 0;
}