#include "Evaluation.hpp"
#include <string>

Status Evaluate(string s, OPNDType &e) {
  OPND S1;
  InitStack(S1);

  int i = 0;
  while (s[i] != '#' && s[i] != '\0') {
    char c = s[i];
    if (c >= '0' && c <= '9') {
      Push(S1, c - '0');
    } else {
      OPNDType left, right, r;
      Pop(S1, right);
      Pop(S1, left);
      if (c == '+') {
        r = left + right;
      } else if (c == '-') {
        r = left - right;
      } else if (c == '*') {
        r = left * right;
      } else {
        r = left / right;
      }
      Push(S1, r);
    }
    i++;
  }
  Pop(S1, e);
  DestroyStack(S1);
  return OK;
}

int main() {
  string s1;
  cin >> s1;
  string s2;
  cin >> s2;
  OPNDType e;
  Evaluate(s1, e);
  cout << "结果：" << e << endl;
  Evaluate(s2, e);
  cout << "结果：" << e << endl;
  return 0;
}