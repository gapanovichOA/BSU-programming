#include <iostream>
#include <string>
using namespace std;
int main() {

	{
		/*
		������� ��� ������������ � ����������������� ���.
    �������� �� ����� ������ �What�s your name�. ����� ����, ��� ������������ ������ 
    ���� ��� (��������, Sasha), ��������: �Nice to meet you, Sasha�
		*/
		cout << "What�s your name\n";
		string text;
		cin >> text;
		cout << "Nice to meet you," << text << endl;
	}
	{
		//��������� �������������� �������� � ����� ������ ������� x � y
		cout << "Enter x and y" << endl;
		int x, y;
		cin >> x >> y;
		cout << x << "+" << y << "=" << x + y << endl;
		cout << x << "-" << y << "=" << x - y << endl;
		cout << x << "*" << y << "=" << x * y << endl;
		cout << x << "/" << y << "=" << x / y << endl;
	}
	{
		//��������� ������� �������� ���������� x � y.
		cout << "Enter x and y" << endl;
		int x, y;
		cin >> x >> y;
		cout << y << " " << x << endl;
	}
	{
		//��� �������� � � � ���������� �������� ���������
		cout << "Enter x and y" << endl;
		int x, y;
		cin >> x >> y;
		float c;
		c = (float)(3 + x * x - y * y * y) * (x + 3) * (x + 3) / (x - y * y);
		cout << c << endl;
	}
	{
		//� ������ ���� ������ m ������. ���������� ������� ������ ��� (� �������, 
	  //������� ����� ������������).
		cout << "Enter m" << endl;
		int m;
		cin >> m;
		cout << (m - (m / (3600 * 24)) * 3600 * 24) / 60 << endl;
	}
	{
		//������� 6a
		cout << "Enter a" << endl;
		double a, a1, a2;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		cout << a2 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a1 * a2;
		cout << a3 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a1 * a2 * a; 
		cout << a3 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2;
		cout << a3 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2 * a;
		cout << a3 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2 * a1; 
		cout << a3 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2 * a2 * a;
		cout << a3 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3, a4;
		cin >> a;
		a1 = a * a * a;
		a2 = a1 * a1;
		a3 = a2 * a2;
		a4 = a3 * a1; 
		cout << a4 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3, a4;
		cin >> a;
		a1 = a * a * a;
		a2 = a1 * a1;
		a3 = a2 * a2;
		a4 = a2 * a3 * a1; 
		cout << a4 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3, a4, a5;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2 * a2;
		a4 = a3 * a3;
		a5 = a4 * a2; 
		cout << a5 << endl;
	}
	{
		//������� 6�
		cout << "Enter a" << endl;
		double a, a1, a2, a3, a4, a5;
		cin >> a;
		a1 = a * a;
		a2 = a1 * a1;
		a3 = a2 * a2;
		a4 = a3 * a3;
		a5 = a4 * a4 * a4;
		cout << a5 << endl;
	}
	{
		/*
		���� ������������ ����� x. �� ��������� �������� ������� 
    ��������������� ���������� ����� ��������, ��������� � ��������� 
    ��������� ���������:
		*/
		cout << "Enter x" << endl;
		double x;
		cin >> x;
		cout << x * (4 * x * x + 3 * x + 2) + 1 << endl;
		cout << -x * (4 * x * x - 3 * x + 2) + 1 << endl;
	}

	system("pause");
	return 0;
}