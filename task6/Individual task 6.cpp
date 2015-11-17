#include <iostream>

using namespace std;

bool IsDataValid(double a, double b, double step, double eps);
void DisplayTable(double a, double b, double step, double eps);
double Arctangens(double a, double eps, int &n);

int main()
{
	while (true)
	{
		double a, b, h, eps;
		int n = 0;


		while (true)
		{

			cout << "Enter the 1-st number: " << endl;
			cin >> a;
			cout << "Enter the last number: " << endl;
			cin >> b;
			cout << "Enter the step: " << endl;
			cin >> h;
			cout << "Enter epsilon:" << endl;
			cin >> eps;
			system("cls");
			if (IsDataValid(a, b, h, eps)) break;
			cout << "Invalid Data" << endl;
			system("cls");
		}

		cout << "Result is: " << endl;
		DisplayTable(a, b, h, eps);

		system("pause");
		system("cls");

		char yes;
		cout << "Would you like to countinie? Press y/Y: " << endl;
		cin >> yes;
		if (yes == 'y' || yes == 'Y')
			continue;
		break;
	}
	return 0;
}
bool IsDataValid(double a, double b, double h, double eps)
{
	if (a < -1 && b > 1) return false;
	if (a > b) return false;
	if (eps < 0 || eps >= 1) return false;
	if (h < 0) return false;
	return true;
}
double Arctangens(double a, double eps, int &n)
{
	double sum = 0, term = a, t = a;
	int i = 0;
	while (fabs(t)>eps)
	{
		sum += t;
		term *= -a*a;
		i++;
		t = term / (2 * i + 1);

	}
	n = i;
	return sum;
}


void DisplayTable(double a, double b, double h, double eps)
{
	cout.width(15);
	cout << "  x  ";
	cout.width(15);
	cout << " Arctangens ";
	cout.width(15);
	cout << " Exact value ";
	cout.width(15);
	cout << " Difference";
	cout.width(15);
	cout << " Addends ";


	for (double x = a; x <= b; x += h)
	{
		cout << endl;
		cout.width(15);
		cout << x;
		cout.width(15);
		int n = 0;
		cout << Arctangens(x, eps, n);
		cout.width(15);
		cout << atan(x);
		cout.width(15);
		cout << fabs(Arctangens(x, eps, n) - atan(x));
		cout.width(15);
		cout << n << endl;
	}

}