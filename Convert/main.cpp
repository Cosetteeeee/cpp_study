#include "Convert.hpp"
#include <string>
using namespace std;

int isp(char op) {
  switch (op) {
  case '+':
  case '-':
    return 2;
  case '*':
  case '/':
    return 4;
  case '(':
  case '#':
    return 0;
  default:
    return -1;
  }
}

int icp(char op) {
  switch (op) {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 3;
  case '(':
    return 5;
  case ')':
  case '#':
    return 0;
  default:
    return -1;
  }
}

char Compare(char top, char c) {
  int inPriority = isp(top);
  int outPriority = icp(c);
  if (inPriority < outPriority) {
    return '<';
  }
  if (inPriority > outPriority) {
    return '>';
  }
  return '=';
}

void Convert(string s) {
  LinkStack OPTR;
  InitStack(OPTR);
  Push(OPTR, '#');
  int i = 0;
  while (true) {
    char c = s[i];
    if (c >= '0' && c <= '9') {
      cout << c;
      i++;
      continue;
    }
    OPTRType top;
    GetTop(OPTR, top);
    char relation = Compare(top, c);
    if (relation == '<') {
      Push(OPTR, c);
      i++;
    } else if (relation == '>') {
      OPTRType op;
      Pop(OPTR, op);
      cout << op;
    } else {
      Pop(OPTR, top);
      if (c == '#') {
        break;
      }
      i++;
    }
  }
  cout << endl;
  DestroyStack(OPTR);
}

int main() {
  string s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  s1 += '#';
  s2 += '#';
  s3 += '#';
  Convert(s1);
  Convert(s2);
  Convert(s3);
  return 0;
}