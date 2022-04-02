#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
long long n;
std::vector<long long> a(300002);
long long k;
std::vector<long long> b(550);

void Add(long long index, long long delta)
{
 a[index] += delta;
 b[index / k] += delta;
}
long long FindSum(long long l, long long r) {
 long long sum = 0;
 long long jl = l / k, jr = r / k;
 if (jl == jr) {
	for (long long i = l; i < r; ++i)
	{
	 sum += a[i];
	}
 }
 else {
	for (long long i = l, end = (jl + 1) * k - 1; i <= end; ++i)
	{
	 sum += a[i];
	}
	for (long long i = jl + 1; i <= jr - 1; ++i)
	{
	 sum += b[i];
	}
	for (long long i = jr * k; i < r; ++i)
	{
	 sum += a[i];
	}
 }
 return sum;
}
int main()
{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 std::cin >> n;
 k = std::floor(std::sqrt(n));
 for (long long i = 0; i < n; i++) {
  long long elem = 0;
  std::cin >> elem;
  a[i]=elem;
 }
 for (long long i = 0; i < n; i++) {
  b[i / k] += a[i];
 }

 long long n_;
 std::cin >> n_;
 std::vector<long long> results;
 for (long long i = 0; i < n_; i++) {
  std::string request;
  std::cin >> request;
	if (request == "FindSum") {
	 long long l, r;
	 std::cin >> l >> r;
	 results.push_back(FindSum(l, r));
	}
	else if (request == "Add") {
	 long long index, delta;
	 std::cin >> index >> delta;
	 Add(index, delta);
	}
 }
 for (long long res : results) {
	std::cout << res << std::endl;
 }
 return 0;
}

