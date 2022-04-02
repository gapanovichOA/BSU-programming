#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>

long long getMaxIncreasingSequence(long long* x,long long n) {
 long long* dp = new long long [n+1];
 int length = 0;
 for (int i = 0; i < n; i++)
 {
  int start = 1;
  int end = length;
  while (start <= end)
  {
   int mid =std::ceil(((double)start + end) / 2);
   if (x[dp[mid]] < x[i])
   {
    start = mid + 1;
   }
   else {
    end = mid - 1;
   }
  }
  if (start > length) {
   length = start;
  }
  dp[start] = i;
 }
 return length;
}
int main()
{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 long long n = 0;
 std::cin >> n;
 long long* x = new long long[n];
 for (int i = 0; i < n; i++) {
  std::cin >> x[i];
 }
 long long length = getMaxIncreasingSequence(x,n);
 std::cout << length;
}
