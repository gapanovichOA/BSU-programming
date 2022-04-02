#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
std::string word;
std::string templ;
bool check(int i_t, int i_w) {
 if (i_t == templ.length()) {
  if (i_w == word.length()) { 
   return true;
  }
  else { 
   return false;
  }
 }
 if (i_w == word.length()) {
  for (int i = i_t; i < templ.length(); i++) {
   if (templ[i] != '*') {
    return false;
   }
  }
  return true;
 }
 if (templ[i_t] == '?') {
  return check(i_t + 1, i_w + 1);
 }
 if (templ[i_t] == '*') {
  if (templ[i_t + 1] == '*') {
   return check(i_t + 1, i_w);
  }
  for (int i = i_w; i <= word.length(); i++) {
   if (check(i_t + 1, i)) {
    return true;
   }
  }
  return false;
 }
 if (templ[i_t] == word[i_w]) {
  return check(i_t + 1, i_w + 1);
 }
 else {
  return false;
 }
}

bool isWordTemplate() {
 return check(0, 0);
}



int main()
{
 std::ios_base::sync_with_stdio(false);
 std::cin.tie(nullptr);
 std::string str1,str2;
 bool result;
 std::cin >> str1 >> str2;
 if (str1.find("*") != std::string::npos || str1.find("?") != std::string::npos) {
  word = str2;
  templ = str1;
  result = isWordTemplate();
 }
 else if (str2.find("*") != std::string::npos || str2.find("?") != std::string::npos) {
  word = str1;
  templ = str2;
  result = isWordTemplate();
 }
 else {
  if (str1 == str2) {
   result = true;
  }
  else {
   result = false;
  }
 }
 if (result) {
  std::cout << "YES";
 }
 else {
  std::cout << "NO";
 }
 return 0;
}
