#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

int main() {
    // 设置控制台编码为UTF-8
    SetConsoleOutputCP(65001);

    // 打印标题
    setColor(14); // 黄色
    cout << "\n★ 炫彩九九乘法表 ★\n" << endl;

    // 打印表格
    for (int i = 1; i <= 9; i++) {
        setColor(13); // 粉色
        cout << "┌─────";
        for (int j = 1; j < i; j++) {
            cout << "┬─────";
        }
        cout << "┐" << endl;

        setColor(11); // 亮蓝色
        for (int j = 1; j <= i; j++) {
            cout << "│";
            setColor((i + j) % 6 + 10); // 循环使用不同的颜色
            cout << setw(2) << j << "×" << setw(2) << i << "=" << setw(2) << i*j;
        }
        setColor(11);
        cout << "│" << endl;
    }

    // 打印最后一行底边
    setColor(13);
    cout << "└─────";
    for (int j = 1; j < 9; j++) {
        cout << "┴─────";
    }
    cout << "┘" << endl;

    // 恢复默认颜色
    setColor(7);
    return 0;
}