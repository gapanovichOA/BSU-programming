#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <vector>

bool BinarySearch(std::vector<long long> &a, long long x) {
 int l = 0, r = a.size();
 while (l < r) {
  int k = (l + r) / 2;
  if (x == a[k]) { return true; }
  else if (x < a[k]) { r = k; }
  else {
   l = k + 1;
  }
 }
 return false;
}

int LowerBound(std::vector<long long> &a, long long x) {
 int l = 0, r = a.size();
 while (l < r) {
  int k = (l + r) / 2;
  if (x <= a[k]) { r = k; }
  else {
   l = k + 1;
  }
 }
 return l;
}

int UpperBound(std::vector<long long> &a, long long x) {
 int l = 0, r = a.size();
 while (l < r) {
  int k = (l + r) / 2;
  if (x < a[k]) { r = k; }
  else {
   l = k + 1;
  }
 }
 return l;
}

int main() {
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 //freopen("input.txt", "r", stdin);
 int n;
 std::cin >> n;
 std::vector<long long> array;
 for (int i = 0; i < n; i++) {
  long long elem = 0;
  std::cin >> elem;
  array.push_back(elem);
 }
 int n_;
 std::cin >> n_;
 std::vector<long long> requests;
 for (int i = 0; i < n_; i++) {
  long long request = 0;
  std::cin >> request;
  requests.push_back(request);
 }
 //freopen("output.txt", "w", stdout);
 for (long long x : requests) {
  std::cout << BinarySearch(array, x) << " " << LowerBound(array, x) << " " << UpperBound(array, x) << '\n';
 }
 return 0;
}