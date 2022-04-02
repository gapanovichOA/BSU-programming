#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <queue> 

int main()
{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("huffman.in", "r", stdin);
 freopen("huffman.out", "w", stdout);
 int n;
 std::vector<long long> sums;
 std::priority_queue<long long,std::vector<long long>, std::greater<long long>> priorityQueue;
 long long textLength = 0;
 std::cin >> n;
 for (int i = 0; i < n; i++)
 {
  long long elem;
	std::cin >> elem;
	priorityQueue.push(elem);
 }
 while (priorityQueue.size() != 1)
 {
	long long one = priorityQueue.top();
	priorityQueue.pop();
	long long two = priorityQueue.top();
	priorityQueue.pop();
	sums.push_back(one + two);
	priorityQueue.push(one + two);
 }
 for (int i = 0; i < sums.size(); i++) {
	textLength += sums[i];
 }
 std::cout << textLength;
 return 0;
}