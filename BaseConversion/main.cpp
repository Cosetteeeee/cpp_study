#include "SqStack.h"

int main() {
    if (DecimalToBase(11, 2) != OK ||
        DecimalToBase(1348, 8) != OK ||
        DecimalToBase(0, 2) != OK ||
        DecimalToBase(255, 16) != OK) {
        return 1;
    }
    return 0;
}
