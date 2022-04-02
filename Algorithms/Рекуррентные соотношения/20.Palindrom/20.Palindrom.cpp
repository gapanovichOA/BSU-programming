#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

std::string getMaxStringPalindrom(std::string string) {
 int n = string.length();
 int** dp = new int*[n];
 for (int i = 0; i < n; i++) {
  dp[i] = new int[n];
 }
 for (int i = 0; i < n; ++i) {
  dp[i][i] = 1;
 }
 for (int i = 0; i < n - 1; ++i) {
  if (!(string[i]==string[i + 1])) {
   dp[i][i + 1] = 1;
  }
  else {
   dp[i][i + 1] = 2;
  }
 }
 for (int stolbec = 2; stolbec < n; stolbec++) {
  for (int i = 0, j = i + stolbec; j < n; i++, j++) {
   if (string[i]==string[j]) {
    dp[i][j] = (dp[i + 1][j - 1] + 2);
   }
   else {
    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
   }
  }
 }
 int length = dp[0][n - 1];
 std::string palindrom;
 for (int i = 0; i < length; i++) {
  palindrom.append(" ");
 }
 int curr_row = 0;
 int curr_column = n - 1;
 int start = 0;
 int end = length - 1;
 while (length >= length / 2) {
  if (string[curr_row]==string[curr_column]) {
   palindrom[start] = string[curr_row];
   palindrom[end] = string[curr_row];
   start++;
   end--;
   curr_row++;
   curr_column--;
   length -= 2;
  }
  else if (dp[curr_row][curr_column] == dp[curr_row + 1][curr_column]) {
   curr_row++;
  }
  else {
   curr_column--;
  }
 }
 return palindrom;
}


int main()
{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 std::string string;
 std::cin >> string;
 std::string palindrom = getMaxStringPalindrom(string);
 std::cout << palindrom.length() << "\n" << palindrom;

}
