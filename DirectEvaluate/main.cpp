#include "DirectEvaluate.hpp"
#include <string>
using namespace std;

int main() {
  string infix;
  cin>>infix;
  int result;
  Status status=Evaluate(infix,result);
  if (status!=OK) {
    cout<<"表达式错误"<<endl;
    return 0;
  }
  cout<<"结果："<<result<<endl;
  return 0;
}