#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Node {
 long long value;
 long long max;
 long long min;

 Node(long long value) {
  this->value = value;
  max = INT64_MAX;
  min = INT64_MIN;
 }

};

int main() {
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 freopen("bst.in", "r", stdin);
 int n;
 std::cin >> n;
 std::vector<Node*> tree;
 long long root_;
 std::cin >> root_;
 Node* root=new Node(root_);
 tree.push_back(root);
 bool isBST = true;
 long long value;
 while (std::cin>>value && isBST) {
  Node* curr=new Node(value);
  tree.push_back(curr);
  int parent_number;
  std::cin >> parent_number;
  std::string side;
  std::cin >> side;
  if (side == "L") {
   curr->max = tree[parent_number - 1]->value;
   curr->min = tree[parent_number - 1]->min;
  }
  else {
   curr->min = tree[parent_number - 1]->value - 1;
   curr->max = tree[parent_number - 1]->max;
  }
  if (curr->value <= curr->min || curr->value >= curr->max) {
   isBST = false;
  }
 }
 freopen("bst.out", "w", stdout);
 if (isBST || n == 1) {
  std::cout<< "YES";
 }
 else {
  std::cout << "NO";
 }
 return 0;
}