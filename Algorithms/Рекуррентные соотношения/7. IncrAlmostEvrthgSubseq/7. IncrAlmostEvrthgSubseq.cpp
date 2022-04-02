#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

int getMaxIncreasingSequence(int* x, int n) {
 int* dp = new int[n + 1];
 int* max_length = new int[n];
 int* x2 = new int[n]; //массив х в обратном порядке
 for (int i = 0; i < n; i++) {
  x2[n - 1 - i] = x[i];
 }
 int length=0,newLength = 0;
 for (int i = 0; i < n; i++)
 {
  int start = 1;
  int end = length;
  while (start <= end)
  {
   int mid = std::ceil(((double)start + end) / 2);
   if (x[dp[mid]] < x[i])
   {
    start = mid + 1;
   }
   else {
    end = mid - 1;
   }
  }
  newLength = start;
  if (start > length) {
   length = start;
  }
  dp[newLength] = i;
  max_length[i] = length;
 }
 length = 0;
 for (int i = 0; i < n - 1; i++) {
  int start = 1;
  int end = length;
  while (start <= end)
  {
   int mid = std::ceil(((double)start + end) / 2);
   if (x2[dp[mid]] > x2[i])
   {
    start = mid + 1;
   }
   else {
    end = mid - 1;
   }
  }
  newLength = start;
  if (start > length) {
   length = start;
  }
  dp[newLength] = i;
  max_length[n-i-2] += length;
 }
 int max = 0;
 for (int i = 0; i < n; i++) {
  if (max < max_length[i]) {
   max = max_length[i];
  }
 }
 return max;
}
int main()
{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 int n = 0;
 std::cin >> n;
 int* x = new int[n];
 for (int i = 0; i < n; i++) {
  std::cin >> x[i];
 }
 int length = getMaxIncreasingSequence(x, n);
 std::cout << length;
}
