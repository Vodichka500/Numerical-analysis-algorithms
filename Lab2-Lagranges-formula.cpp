#include <iostream>
#include <string>

using namespace std;

void lagrange(int n, double tabx[], double taby[], double p);

int main()
{
	int n;
	cout << "Podaj Liczbe wezlow" << endl;
	cin >> n;
	cout << "Podaj wartosci wezlow" << endl;
	double* tabx = new double[n];
	double* taby = new double[n];
	for (int i = 0; i < n; i++)
	{
		cout << "X[" << i << "] - ";
		cin >> tabx[i];
	}
	cout << "Podaj wartosci funkcji w tych wezlach" << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Y[" << i << "] - ";
		cin >> taby[i];
	}
	cout << "Ile punktow?" << endl;
	int j;
	cin >> j;
	for (int i = 0; i < j; i++)
	{
		cout << "Podaj punkt p"<<i+1 << endl;
		double p;
		cin >> p;
		if (p > tabx[0] && p < tabx[n-1])
		{
			lagrange(n, tabx, taby, p);
		}
		else
		{
			cout << "Punkt nie spelnia warunki interpolacji" << endl;
		}
	}
	



}

void lagrange(int n, double tabx[], double taby[], double p)
{
	double l, yl;
	yl = 0;
	for (int i = 1; i <= n;i++)
	{
		l = 1;
		for (int j = 1; j <= n; j++)
		{
			if (i != j)
			{
				l *= (p - tabx[j]) / (tabx[i] - tabx[j]);
			}
		}
		cout << " l[" << i << "] = " << l << endl;
		yl = yl + l * taby[i];
	}
	cout << endl <<  "Odp: " << yl<<endl;
}