#include <iostream>
#include <vector>
#include <cmath>
#include<algorithm>
#include<iterator>
#include<fstream>
#include<sstream>

/*
������� 1:
���� ����������� ����� n <=10. ����� ���� n-������� ����� ����� �����, ���������
������ �� ��������� ����. ������������ ��������� ����� �����. �����������
��������� ��������� � ����.
������� 2:
��� ��������� ����, � ������ ������ �������� ������ ����� ����� k, �.�.
0 <= k <= 31, �� ������ ������ - ������������������ ����� ������������� �����, �����
��������� ��������.
�� �������� ������������������ ����� ������������ ������������������, � �������
��� ������� ����� ������������������ ����������� �������: ������������������ ����
11 � �������� ������������� ����� ����������� k ��� (��������, � ��������
������������� 11110111 ��� ����������� 5 ���).
����������� ��������� ��������� � ����.
*/
bool CheckUnique(int num)
{
	size_t digits[10] = { 0 };
	int helperI = num;
	while (helperI != 0)
	{
		digits[helperI % 10]++;
		helperI /= 10;
	}
	for (int j = 0; j < 10; j++)
	{
		if (digits[j] > 1)
		{
			return false;
		}
	}
	return true;
}
void FindUniqueNum(int n, std::vector<size_t>& V)
{
	for (int i = pow(10, n - 1); i < pow(10, n); i++)
	{
		if (CheckUnique(i))
		{
			V.push_back(i);
		}
	}
}
void PrintNumbers(std::ostream& out, std::vector<size_t>& V)
{
	std::copy(V.begin(), V.end(), std::ostream_iterator<int>(out, " "));
}

std::string RemakeNum(int num)
{
	std::ostringstream ostr;
	for (int i = 31; i >= 0; i--)
	{
		ostr << ((num >> i) & 1);
	}
	std::string str;
	str = ostr.str();
	return str;
}
int Count11(std::string str)
{
	int position = 0;
	int count = 0;
	while (position != std::string::npos)
	{
		position = str.find("11", position);
		if (position == std::string::npos)
		{
			break;
		}
		else
		{
			count++;
			position++;
		}
	}
	return count;
}
int main()
{
	bool flag = true;
	while (flag)
	{
		std::cout << "1-Task1, 2-Task2\n";
		int choice;
		std::cin >> choice;
		switch (choice)
		{
		case 1:
		{size_t n;
		std::cout << "Enter n\n";
		std::cin >> n;
		std::ofstream out("output.txt");
		std::vector<size_t>Res;
		FindUniqueNum(n, Res);
		PrintNumbers(out, Res);
		break;
		}
		case 2:
		{
		 std::ifstream in("�����.txt");
		 std::ofstream out("output2.txt");

		 int k;
		 in >> k;
		 std::vector<size_t>V;
		 while (!in.eof())
		 {
			int numb, check;
			in >> numb;
			std::string str;
			str = RemakeNum(numb);
			check = Count11(str);
			if (check == k)
			{
			 V.push_back(numb);
			}
		 }
		 PrintNumbers(out, V);
		 break;
		}

		}

	}
	system("pause");
	return 0;
}