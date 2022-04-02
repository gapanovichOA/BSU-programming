#include <cmath>
#include <iostream>
#include <vector>

int main() {
std::ios_base::sync_with_stdio(false);
std::cin.tie(nullptr);
int n = 0;
std::cin >> n;
int* array = new int[n];
int n_ = 0;
for (int i = 0; i < n; i++) {
 std::cin >> n_;
 array[i] = n_;
}
if (n == 1) {
std::cout << array[0] << "\n" << 1;
}
else if (n == 3) {
 std::cout << array[0] + array[2] << "\n" << 1 << " " << 3;
}
else {
 int* F = new int[n];
 int* indexes = new int[n];
 F[0] = array[0];
 F[1] = -INFINITY;
 F[2] = array[0] + array[2];
 F[n - 1] = -1;
 for (int i = 3; i < n; i++) {
  F[i] = std::max(F[i - 2], F[i - 3]) + array[i];
  if (F[i - 2] >= F[i - 3]) {
   indexes[i] = i - 1;
  }
  else {
   indexes[i] = i - 2;
  }
 }
 std::vector<int> path;
 if (F[n - 1] != -1) {
  path.push_back(n);
  for (int i = n - 1; i > 0; i = indexes[i] - 1) {
   if (indexes[i] == 0) {
    path.push_back(1);
    break;
   }
   path.push_back(indexes[i]);
  }
 }
 if (n == 2 || F[n - 1] == -1) {
  std::cout << -1;
 }
 else {
  std::cout << F[n - 1] << '\n';
  for (int i = path.size(); i > 0; i--) {
   std::cout << path[i - 1] << " ";
  }
 }
}
return 0;
}