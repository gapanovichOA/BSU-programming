#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>


int main()
{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("in.txt", "r", stdin);
 freopen("out.txt", "w", stdout);
 int d,in,r;
 std::cin >> d>>in>>r;
 std::string x,y;
 std::cin >> x>>y;
 int n = x.length()+1;
 int m = y.length()+1;
 int** dp = new int* [n];
 for (int i = 0; i < n; i++) {
  dp[i] = new int[m];
 }
 for (int i = 0; i < n; i++) {
  dp[i][0] = i * d;
 }
 for (int j = 0; j < m; j++) {
  dp[0][j] = j * in;
 }
 int delta = 1;
 for (int i = 1; i < n; i++) {
  for (int j = 1; j < m; j++) {
   if (x[i-1] == y[j-1]) {
    delta = 0;
   }
   else {
    delta = 1;
   }
   dp[i][j] = dp[i - 1][j] + d;
   if (dp[i][j - 1] + in < dp[i][j]) {
    dp[i][j] = dp[i][j - 1] + in;
   }
   if (dp[i - 1][j - 1] + delta * r < dp[i][j]) {
    dp[i][j] = dp[i - 1][j - 1] + delta * r; 
   }
  }
 }
 std::cout<< dp[n-1][m-1];
}
