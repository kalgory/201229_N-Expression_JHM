#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

using namespace std;

int number;

int getStickNumber(int count) {
  int stick_number = 0;
  do {
    stick_number += number * pow(10, count);
    count--;
  } while (count >= 0);
  return stick_number;
}

void makeSet(vector<set<int>>& result_set_vec, const int count) {
  int stick_number = getStickNumber(count);
  result_set_vec[count].insert(stick_number); // append nn;
  for (int i = 0; i < count; i++) {
    for (int result_1 : result_set_vec[i]) {
      for (int result_2 : result_set_vec[count - i - 1]) {
        result_set_vec[count].insert(result_1 + result_2);
        result_set_vec[count].insert(result_1 - result_2);
        result_set_vec[count].insert(result_1 * result_2);
        if (result_2 != 0) {
          result_set_vec[count].insert(result_1 / result_2);
        }
      }
    }
  }
}

int solution(int _number, int target) {
  number = _number;
  vector<set<int>> result_set_vec(8);

  for (int count = 0; count <= 7; count++) {
    makeSet(result_set_vec, count);

    auto iter = find(result_set_vec[count].begin(), result_set_vec[count].end(), target);
    if (iter != result_set_vec[count].end()) {
      return count + 1;
    }
  }
  return -1;
}

int main() {
  cout << solution(6, 65) << endl;
  return 0;
}