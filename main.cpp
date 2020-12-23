#include <iostream>
#include <vector>


using namespace std;

vector<char> oper_element_vec = {'+', '-', '*', '/', 0};

string getExpression(const string& oper_str, int operand) {
  string expression;
  expression.push_back('+');
  for (char oper : oper_str) {
    expression.push_back('0' + operand);
    if (oper != 0) {
      expression.push_back(oper);
    }
  }
  expression.push_back('0' + operand);
  return expression;
}

int calculate(string expression_str) {
  int result = 0;
  int i = 0;

  while (i < expression_str.size()) {
    char oper = expression_str[i];
    i++;

    int operand;
    string operand_str;
    while (expression_str[i] >= '0' && expression_str[i] <= '9') {
      operand_str.push_back(expression_str[i]);
      i++;
    }

    operand = stoi(operand_str);

    switch (oper) {
      case '+':result += operand;
        break;
      case '-':result -= operand;
        break;
      case '*':result *= operand;
        break;
      case '/':result /= operand;
        break;
    }

  }
  return result;
}

void insertOper(vector<string>& current_oper_str_vec, vector<string>& next_oper_str_vec) {
  for (string current_oper_str : current_oper_str_vec) {
    for (char oper_element : oper_element_vec) {
      string next_oper_str(current_oper_str);
      next_oper_str.push_back(oper_element);
      next_oper_str_vec.push_back(next_oper_str);
    }
  }
}

int solution(int operand, int number) {
  if (operand == number) {
    return 1;
  }
  vector<vector<string>> oper_str_vec_vec(7);

  for (char oper_element : oper_element_vec) {
    string oper_str;
    oper_str.push_back(oper_element);
    oper_str_vec_vec[0].push_back(oper_str);
  }

  for (int i = 0; i <= 6; i++) {

    for (string oper_str : oper_str_vec_vec[i]) {
      string expression_str = getExpression(oper_str, operand);
      cout << expression_str << "=" << calculate(expression_str) << " ";
      if (number == calculate(expression_str)) {
        return i + 2;
      }
    }
    cout << endl;
    if (i <= 5) {
      insertOper(oper_str_vec_vec[i], oper_str_vec_vec[i + 1]);
    }
  }
  return -1;
}

int main() {
  cout << solution(6, 65) << endl;
  return 0;
}