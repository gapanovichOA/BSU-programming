#pragma once
#include<iostream>

class Rational
{
public:
	//����������� �� ���������
	Rational() = default;
	//����������� � �����������
	Rational(int a_, int b_);
	//����������� �����������
	Rational(const Rational& r);
	//����������
	~Rational() = default;
	Rational operator+(const Rational &r);
	Rational operator*(const Rational& r);
	Rational operator/(const Rational& r);
	friend long compare(const Rational& r, const Rational& r1);
	friend bool operator==(const Rational& r, const Rational& r1);
	friend bool operator<(const Rational& r, const Rational& r1);
	friend bool operator>(const Rational& r, const Rational& r1);
	friend std::ostream& operator<<(std::ostream& out, const Rational& r);
private:
	int a, b;
	void reduce();
};


