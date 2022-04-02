#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>

int main()
{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 int n;
 std::cin >> n;
 std::vector<long long> array(n+1);
 for (int i = 1; i < n+1; i++) {
  long long elem = 0;
  std::cin >> elem;
  array[i]=elem;
 }
 n++;
 bool isHeap = true;
 int i = 1;
 for (; i < (n / 2);i++) {
	if (array[i] > array[2 * i] || array[i] > array[2 * i + 1]) {
	 isHeap = false;
	}
 }
 if (i == (n / 2)) {
  if (array[i] > array[2 * i]) {
   isHeap = false;
  }
 }
 if (isHeap) {
  std::cout << "Yes";
 }
 else {
  std::cout << "No";
 }
}

