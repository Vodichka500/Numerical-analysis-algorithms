#include <iostream>

using namespace std;

double Horner(int n, double a[], double c)
{
	double w = a[0];
	for (int i = 1; i <= n; i++)
	{
		w = w * c + a[i];
	}
	return w;
}

void HornerU(int n, double a[], double c)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 1; k <= n - i; k++)
		{
			a[k] = a[k - 1] * c + a[k];
			cout << a[k]<<  " | ";
		}
		cout << "\n";
	}
}



int main()
{
	int n; 
	cout << "Podaj stopien wielomianu" << endl;
	cin >> n;
	double* a = new double[n];
	double c;
	cout << "Podaj wartosc punktu" << endl;
	cin >> c;
	for (int i = 0; i <= n; i++)
	{
		cout << "Podaj w[" << i << "]" << endl;
		cin >> a[i];
	}
	cout << "------------------------------------\n" << endl;
	
	cout << "W punkcie " << c << " wartosc wielomianu wynosi: " << Horner(n, a, c) <<endl;

	cout << "------------------------------------" << endl;
	
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " | ";
	}
	cout << "\n";
	HornerU(n, a, c);

}