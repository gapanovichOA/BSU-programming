#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;

const ll MAX = 30000000;
ll treeSum[MAX];
ll treeMax[MAX];
ll treeMin[MAX];
ll lazy[MAX];

ll getElem(ll value_index, ll p, ll tl, ll tr, ll plus) {
 if (p == tl && tr == p) {
  return (treeSum[value_index] + lazy[value_index] + plus);
 }
 ll mid = (tr + tl) / 2;
 if (p <= mid) {
  return getElem(value_index * 2 + 1, p, tl, mid, plus + lazy[value_index]);
 }
 else {
  return getElem(value_index * 2 + 2, p, mid + 1, tr, plus + lazy[value_index]);
 }
}


void updateRange(ll value_index, ll l, ll r, ll tl, ll tr, ll diff) {
 if (l > r) {
  return;
 }
 if (l == tl && tr == r) {
  treeMin[value_index] += diff;
  treeMax[value_index] += diff;
  lazy[value_index] += diff;
  return;
 }

 ll mid = (tr + tl) / 2;
 updateRange(value_index * 2 + 1, l, min(r, mid), tl, mid, diff);
 updateRange(value_index * 2 + 2, max(mid + 1, l), r, mid + 1, tr, diff);

 treeSum[value_index] += diff * (r - l + 1);
 treeMin[value_index] = min(treeMin[value_index * 2 + 1], treeMin[value_index * 2 + 2]) + lazy[value_index];
 treeMax[value_index] = max(treeMax[value_index * 2 + 1], treeMax[value_index * 2 + 2]) + lazy[value_index];
}


void updateValue(ll value_index, ll p, ll tl, ll tr) {
 ll elem = getElem(0, p, tl, tr, 0);
 updateRange(0, p, p, tl, tr, -elem);
 updateRange(0, p, p, tl, tr, value_index);
}

ll findSum(ll value_index, ll l, ll r, ll tl, ll tr, ll plus) {
 if (l > r) {
  return 0;
 }
 if (l == tl && r == tr) {
  ll res = (lazy[value_index] + plus) * (r - l + 1) + treeSum[value_index];
  return res;
 }
 ll mid = (tr + tl) / 2;
 return findSum(value_index * 2 + 1, l, min(r, mid), tl, mid, lazy[value_index] + plus) + findSum(value_index * 2 + 2, max(l, mid + 1), r, mid + 1, tr, lazy[value_index] + plus);
}

ll findMin(ll value_index, ll l, ll r, ll tl, ll tr) {
 if (l > r) {
  return LLONG_MAX;
 }
 if (l == tl && r == tr) {
  return treeMin[value_index];
 }
 ll mid = (tr + tl) / 2;
 return min(findMin(value_index * 2 + 1, l, min(mid, r), tl, mid), findMin(value_index * 2 + 2, max(l, mid + 1), r, mid + 1, tr)) + lazy[value_index];
}

ll findMax(ll value_index, ll l, ll r, ll tl, ll tr) {
 if (l > r) {
  return LLONG_MIN;
 }
 if (l == tl && r == tr) {
  return treeMax[value_index];
 }
 ll mid = (tr + tl) / 2;
 return max(findMax(value_index * 2 + 1, l, min(r, mid), tl, mid), findMax(value_index * 2 + 2, max(l, mid + 1), r, mid + 1, tr)) + lazy[value_index];
}

int main() {
 ios_base::sync_with_stdio(false);
 freopen("input.txt","r",stdin);
 freopen("output.txt", "w", stdout);

 ll n;
 cin >> n;

 ll l, r, i, x, num, request;
 while (cin >> request) {
 switch (request) {
  case 1: {
   cin >> i >> x;
   updateValue(x, i, 0, n - 1);
   break;
  }
  case 2: {
   cin >> l >> r >> x;
   updateRange(0, l, r, 0, n - 1, x);
   break;
  }
  case 3: {
   cin >> l >> r;
   num = findSum(0, l, r, 0, n - 1, 0);
   cout << num << endl;
   break;
  }
  case 4: {
   cin >> l >> r;
   num = findMin(0, l, r, 0, n - 1);
   cout << num << endl;
   break;
  }
  case 5: {
   cin >> l >> r;
   num = findMax(0, l, r, 0, n - 1);
   cout << num << endl;
   break;
  }
  case 0: {
   break;
  }
  }
 }
 return 0;
}
