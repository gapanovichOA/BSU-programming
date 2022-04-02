#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

int h_code(int i, int x,int m,int c) { return ((x % m) + c * i) % m; }

int main() {
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("input.txt", "r", stdin);
 freopen("output.txt", "w", stdout);
 int m=0, c=0, n=0;
 std::cin >> m >> c >> n;
 int* arr=new int[m];
 for (int i = 0; i < m; i++) {
  arr[i] = -1;
 }
 int x = 0;
 int index;
 for (int i = 0; i < n; ++i) {
  std::cin >> x;
  for (int j = 0; j < m; ++j) {
   index = h_code(j, x,m,c);
   if (arr[index] == x) { break; }
   if (arr[index] == -1) {
    arr[index] = x;
    break;
   }
  }
 }
 for (int i = 0; i < m; i++) {
  std::cout << arr[i] << " ";
 }
 return 0;
}
