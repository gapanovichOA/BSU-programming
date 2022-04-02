#pragma once
#include <iostream>
#include<initializer_list>
#include "C:\Users\User\Documents\��\���������������� �������� ������+ ����\���������������� �������� ������+ ����\List.h"

template<typename T>
struct NodeStack
	{
	public:
		T value;
	private:
		NodeStack() = default;
		NodeStack(T value_, NodeStack* next_=NULL) :value(value_), next(next_) {};
		NodeStack* next;
		template<typename T>
		friend class StackOnList;
	};
template<typename T>
class StackOnList
{
public:

	StackOnList<T>() :top(new NodeStack<T>()), size(0) {};
	StackOnList<T>(std::initializer_list<T> list)
	{
		size = list.size();
		for (T value : list)
		{
			NodeStack<T>* newElem = new NodeStack<T>(value, top);
			top = newElem;
		}
	}
	int Size() { return size; }
	bool IsEmpty() { return (size == 0); }
	void Push(const int& value)
	{
		NodeStack<T>* newElem = new NodeStack<T>(value, top);
		top = newElem;
		size++;
	}
	NodeStack<T>* Top() { return top; }
	NodeStack<T>* Top() const { return top; }
	int Pop()
	{
		if (size == 0)
		{
			std::cout << "Stack is empty";
			return 0;
		}
		else
		{
			NodeStack<T>* elem = top;
			top = top->next;
			int value = elem->value;
			delete elem;
			size--;
			return value;
		}
	}
	bool operator==(const StackOnList<T>& stack)
	{
		if (size != stack.size)
		{
			return false;
		}
		NodeStack<T>* elem1 = top;
		NodeStack<T>* elem2 = stack.top;
		while (elem1 != nullptr)
		{
			if (elem1->value != elem2->value)
			{
				return false;
			}
			elem1 = elem1->next;
			elem2 = elem2->next;
		}
		return true;
	}
	bool operator!=(const StackOnList<T>& stack) { return !(*this == stack); }
	void print()
	{
		NodeStack<T>* temp;
		if (top == NULL) {
			std::cout << "\nStack Underflow";
			exit(1);
		}
		else {
			temp = top;
			while (temp != NULL) {
				std::cout << temp->value << " ";
				temp = temp->next;
			}
		}
	}
	StackOnList<T>& operator=(const StackOnList& stackOnList) {
		//���� ������� �����
		if (this == &stackOnList) {
			return *this;
		}
		//������������ ������ ������� ��� ������ ����� ������ �� ������� �������
		while (top != nullptr) {
			NodeStack<T>* temp = top;
			top = top->next;
			delete temp;
		}

		//���� ������ �������, ������� �� ��������=0
		size = stackOnList.size;
		if (size == 0) {
			top = nullptr;
			return *this;
		}

		//����������� ���������
		NodeStack<T>* element = new NodeStack<T>(stackOnList.top->value, nullptr);
		top = element;
		NodeStack<T>* cur_element = stackOnList.top->next;
		while (cur_element != nullptr) {
			element->next = new NodeStack<T>(cur_element->value, nullptr);
			element = element->next;
			cur_element = cur_element->next;
		}
	}

	StackOnList<T>& operator=(StackOnList&& stackOnList) {
		if (this == &stackOnList) {

			//�������� ������� �������
			while (stackOnList.top != nullptr) {
				NodeStack<T>* temp = stackOnList.top;
				stackOnList.top = stackOnList.top->next;
				delete temp;
			}
			stackOnList.size = 0;
			return *this;
		}

		//������������ ������ ������� ��� ������ ����� ������ �� ������� �������
		while (top != nullptr) {
			NodeStack<T>* temp = top;
			top = top->next;
			delete temp;
		}

		size = stackOnList.size;

		if (size == 0) {
			top = nullptr;
			//�������� ������� �������
			while (stackOnList.top != nullptr) {
				NodeStack<T>* temp = stackOnList.top;
				stackOnList.top = stackOnList.top->next;
				delete temp;
			}
			stackOnList.size = 0;
			return *this;
		}

		//����������� ���������
		NodeStack<T>* element = new NodeStack<T>(stackOnList.top->value, nullptr);
		top = element;
		NodeStack<T>* cur_element = stackOnList.top->next;
		while (cur_element != nullptr) {
			element->next = new NodeStack<T>(cur_element->value, nullptr);
			element = element->next;
			cur_element = cur_element->next;
		}

		//�������� ������� �������
		while (stackOnList.top != nullptr) {
			NodeStack<T>* temp = stackOnList.top;
			stackOnList.top = stackOnList.top->next;
			delete temp;
		}
		stackOnList.size = 0;
		return *this;
	}
private:
	int size;
	NodeStack<T>* top;
};
