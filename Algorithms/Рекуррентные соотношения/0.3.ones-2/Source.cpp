#include <iostream>
#include <fstream>

using namespace std;
using ll = long long;

ll stepenMod(ll a, ll p, ll mod) {
 if (p == 0) return 1;
 if (p % 2 == 0) {
  ll templ = stepenMod(a, p / 2, mod);
  return (templ * templ) % mod;
 }
 else return (a * stepenMod(a, p - 1, mod)) % mod;
}

ll multyFromToMod(int start, int end, ll mod) {
 long long multyMod = 1;
 for (int i = start + 1; i <= end; i++) {
  multyMod = (multyMod * i) % mod;
 }
 return multyMod;

}

int main()
{
 int n;
 int k;
 ll mod = 1000000007;
 cin >> n >> k;

 int minNum = k;
 int maxNum;

 if (n - k > k) maxNum = n - k;
 else {
  maxNum = k;
  minNum = n - k;
 }


 ll modUpfac = multyFromToMod(maxNum, n, mod);
 ll modLowfac = multyFromToMod(1, minNum, mod);

 ll ans = (stepenMod(modLowfac, mod - 2, mod) * modUpfac) % mod;
 cout << ans;

}