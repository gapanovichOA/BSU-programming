#pragma once
#include <initializer_list>
#include <fstream>

class Visitor;
class Iterator;

class MyContainer {
private:
 bool* data;
 int size = 100;
public:
 // ����������� �� ���������
 MyContainer();

 // ����������� � ����� ����������
 explicit MyContainer(int size_);

 // ��������������� �� ������ ������������� (std::initializer_list)
 MyContainer(const std::initializer_list<int>& list);

 // ����������
 ~MyContainer();

 void add(int item);

 bool& GetAt(int index) const;
 int Size() const { return size; }

 void Accept(Visitor* visitor);

 void save(std::string file_name);
 std::string ToStringSet();
private:
 //��������� ����������� � �����������
 MyContainer(const MyContainer& obj) {}
 MyContainer(MyContainer&& obj) {}

 MyContainer& operator=(const MyContainer& obj) {}
 MyContainer& operator=(MyContainer&& obj) {}
};