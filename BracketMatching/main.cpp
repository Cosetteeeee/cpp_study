#include "LinkStack.h"

int main() {
    Status result;

    cout << "样例：([]())" << endl;
    result = BracketMatch("([]())");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：[([][])]" << endl;
    result = BracketMatch("[([][])]");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：[(]" << endl;
    result = BracketMatch("[(]");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：([())" << endl;
    result = BracketMatch("([())");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：(()])" << endl;
    result = BracketMatch("(()])");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：((])" << endl;
    result = BracketMatch("((])");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：((([])" << endl;
    result = BracketMatch("((([])");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：(([][])))))" << endl;
    result = BracketMatch("(([][])))))");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：{[(4+5)*(5-8)+2]-[(9-8)*(5-2)]}#" << endl;
    result = BracketMatch("{[(4+5)*(5-8)+2]-[(9-8)*(5-2)]}#");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：{[[(4+5)*(5-8)+2]-[(9-8)*(5-2)]}#" << endl;
    result = BracketMatch("{[[(4+5)*(5-8)+2]-[(9-8)*(5-2)]}#");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：{[(4+5)*(5-8)+2]-[(9-8))*(5-2)]}#" << endl;
    result = BracketMatch("{[(4+5)*(5-8)+2]-[(9-8))*(5-2)]}#");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：}[(4+5)*#" << endl;
    result = BracketMatch("}[(4+5)*#");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    cout << "样例：不含括号的普通文本#" << endl;
    result = BracketMatch("不含括号的普通文本#");
    if (result == OK) {
        cout << "结果：匹配" << endl;
    } else {
        cout << "结果：不匹配" << endl;
    }

    return 0;
}
