#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

#include "Queue.h"
#include "PriorityQueue.h"
#include "Element.h"

void ReadInput(const std::string&, Queue<char>&);
void ReadInput(const std::string&, Queue<Element>&);
PriorityQueue<char> Conversion(Queue<char>&);
//void WriteCollection(const std::string&, Queue<Element>&);

int main()
{
	// Step1. Queue.h
	{
		Queue<int> queue;
		queue.PushBack(1);
		queue.PushBack(2);
		queue.PushBack(3);
		std::cout << "queue = " << queue.ToString() << std::endl;
		queue.PopFront();
		std::cout << "queue = " << queue.ToString() << std::endl;
	}

	// Step2. PriorityQueue.h
	{
	PriorityQueue<int> pr_queue;
	pr_queue.SortInsert(1, 5);
	pr_queue.SortInsert(2, 7);
	pr_queue.SortInsert(3, 3);
	pr_queue.SortInsert(4, 5);
	pr_queue.SortInsert(5, 7);
	pr_queue.SortInsert(6, 3);
	std::cout << "pr_queue = " << pr_queue.ToString() << std::endl;
	pr_queue.PopHead();
	std::cout << "pr_queue = " << pr_queue.ToString() << std::endl;
}

	// ��������� 5 �������, ����� 5 ������

	// 6.	(1 �����) ������� ReadInput
	{
		Queue<char> queue;
		std::cout << "queue = " << queue.ToString() << std::endl;
		ReadInput("input.txt", queue);
		std::cout << "queue = " << queue.ToString() << std::endl;
	}

	// 7.	(0.5 �����) ���� ��� ������� ����� ������ �����-������� Element
	// ��������� �� ������������ �� 0.5 �����
	{
		Queue<Element> queue;
		std::cout << "queue = " << queue.ToString() << std::endl;
		ReadInput("input.txt", queue);
		std::cout << "queue = " << queue.ToString() << std::endl;
	}

	// 8.	(2.5 ����) ������� Conversion
	{
		Queue<char> queue;
		ReadInput("input.txt", queue);
		std::cout << "8. queue = " << queue.ToString() << std::endl;

		PriorityQueue<char> pr_queue = Conversion(queue);	// COPY CONSTRUCTOR!!!
		std::cout << "8. pr_queue = " << pr_queue.ToString() << std::endl;
	}

	// 9. � 10. - ������� ����, ����

 
    system("pause");
    return 0;
}

void ReadInput(const std::string& filePath, Queue<char>& queue)
{
    std::ifstream fin(filePath);
    if (!fin.is_open())
    {
        std::cout << "Error" << std::endl;
        return;
    }

    char t;
    while (!fin.eof())
    {
        fin.get(t);
        queue.PushBack(t);
    }
}
void ReadInput(const std::string& filePath, Queue<Element>& queue)
{
	std::ifstream fin(filePath);
	if (!fin.is_open())
	{
		std::cout << "Error" << std::endl;
		return;
	}

	char t;
	while (!fin.eof())
	{
		fin.get(t);
		queue.PushBack(Element(t));
	}
}


PriorityQueue<char> Conversion(Queue<char>& queue)
{
//�������: ������ � ������ �������� �������� ���������� ������(��� �����) � ���������  ������������� ��������, 
//� ��������� � �������� ������������ ������� � ���������� ����������� �� ���������, ������ �� ���������.�     
	
	PriorityQueue<char> priorityQueue;

    while (!queue.IsEmpty())
    {
        char element = queue.PopFront();
        if (element == '*')
        {
        }
        else
        {
            priorityQueue.SortInsert(element, 1);	// !!! ��: �������, ��� ������
        }
    }
	return priorityQueue;
}

//void WriteCollection(const std::string& filePath, Queue<Element>& queue)
//{
//    std::ofstream fout(filePath);
//    while (!queue.IsEmpty())
//    {
//        fout << queue.PopFront();
//    }
//    fout << std::endl;
//}