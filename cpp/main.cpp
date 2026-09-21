#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

class Animal {
public:
    Animal(const string& name) : name_(name) {}
    virtual ~Animal() = default;

    virtual void speak() const {
        cout << name_ << " 发出了一些声音" << endl;
    }

    virtual void move() const {
        cout << name_ << " 在移动" << endl;
    }

    string getName() const { return name_; }

protected:
    string name_;
};

class Mammal : public Animal {
public:
    Mammal(const string& name) : Animal(name) {}

    void move() const override {
        cout << name_ << " 用四条腿走路" << endl;
    }

    void nurse() const {
        cout << name_ << " 在哺乳" << endl;
    }
};

class Bird : public Animal {
public:
    Bird(const string& name) : Animal(name) {}

    void move() const override {
        cout << name_ << " 在飞翔" << endl;
    }

    void layEggs() const {
        cout << name_ << " 在下蛋" << endl;
    }
};

class Dog : public Mammal {
public:
    Dog(const string& name) : Mammal(name) {}

    void speak() const override {
        cout << name_ << "：汪汪！" << endl;
    }

    void wagTail() const {
        cout << name_ << " 在摇尾巴" << endl;
    }
};

class Cat : public Mammal {
public:
    Cat(const string& name) : Mammal(name) {}

    void speak() const override {
        cout << name_ << "：喵喵～" << endl;
    }

    void scratch() const {
        cout << name_ << " 在磨爪子" << endl;
    }
};

class Eagle : public Bird {
public:
    Eagle(const string& name) : Bird(name) {}

    void speak() const override {
        cout << name_ << "：嘤——" << endl;
    }

    void hunt() const {
        cout << name_ << " 在俯冲捕猎" << endl;
    }
};

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
#endif

    Dog dog("旺财");
    Cat cat("咪咪");
    Eagle eagle("金雕");

    Animal* animals[] = { &dog, &cat, &eagle };

    cout << "=== 动物们说话 ===" << endl;
    for (auto* a : animals) {
        a->speak();
    }

    cout << "\n=== 动物们移动 ===" << endl;
    for (auto* a : animals) {
        a->move();
    }

    cout << "\n=== 各自独特的行为 ===" << endl;
    dog.wagTail();
    cat.scratch();
    eagle.hunt();

    cout << "\n=== 第二层特有方法 ===" << endl;
    dog.nurse();
    eagle.layEggs();

    return 0;
}
