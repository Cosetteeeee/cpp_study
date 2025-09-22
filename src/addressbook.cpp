#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

// 联系人结构体
struct Person {
  string memName;
  int memSex; // 1 男 2 女
  int memAge;
  string memPhone;
  string memAddr;
};
// 通讯录结构体
struct Addressbooks {
  struct Person personArray[MAX];
  int memSize;
};

// 1.添加联系人
void addPerson(Addressbooks *abs) {
  // 判断通讯录是否已满，如果满了就不再添加
  if (abs->memSize == MAX) {
    cout << "通讯录已满，无法添加！" << endl;
    return;
  } else {
    // 添加具体联系人
    // 姓名
    string name;
    cout << "请输入姓名：" << endl;
    cin >> name;
    abs->personArray[abs->memSize].memName = name;
    // 性别
    int sex = 0;
    cout << "请输入性别：" << endl;
    cout << "1.男" << endl;
    cout << "2.女" << endl;

    while (true) {
      cin >> sex;
      if (sex == 1 || sex == 2) {
        abs->personArray[abs->memSize].memSex = sex;
        break;
      }
      cout << "输入无效，请重新输入！" << endl;
    }
    // 年龄
    int age = 0;
    cout << "请输入年龄：" << endl;
    cin >> age;
    abs->personArray[abs->memSize].memAge = age;
    // 电话
    string phone;
    cout << "请输入电话:" << endl;
    cin >> phone;
    abs->personArray[abs->memSize].memPhone = phone;
    // 住址
    string addr;
    cout << "请输入住址：" << endl;
    cin >> addr;
    abs->personArray[abs->memSize].memAddr = addr;
    // 更新通讯录人数
    abs->memSize++;
    cout << "添加成功！" << endl;
    system("pause");
    system("cls"); // 清屏
  }
}

// 2.显示联系人
void showPerson(Addressbooks *abs) {
  if (abs->memSize == 0) {
    cout << "当前记录为空" << endl;
    return;
  } else {
    for (int i = 0; i < abs->memSize; i++) {
      cout << "姓名：" << abs->personArray[i].memName << "\t";
      cout << "性别：" << (abs->personArray[i].memSex == 1 ? "男" : "女")
           << "\t";
      cout << "年龄：" << abs->personArray[i].memAge << "\t";
      cout << "电话：" << abs->personArray[i].memPhone << "\t";
      cout << "住址：" << abs->personArray[i].memAddr << endl;
    }
  }
}

// 检测联系人是否存在，存在返回联系人在数组中的位置，不存在返回-1
int isExist(Addressbooks *abs, string name) {
  for (int i = 0; i < abs->memSize; i++) {
    if (abs->personArray[i].memName == name) {
      return i;
    }
  }
  return -1;
}

// 3.删除联系人
void deletePerson(Addressbooks *abs) {
  string name;
  cout << "请输入你想要删除的联系人：" << endl;
  cin >> name;
  int ret = isExist(abs, name);
  if (ret != -1) {
    for (int i = ret; i < abs->memSize; i++) {
      abs->personArray[i] = abs->personArray[i + 1];
    }
    abs->memSize--;
    cout << "删除成功！" << endl;
  } else {
    cout << "查无此人！" << endl;
  }
  system("pause");
  system("cls");
}

// 4.查找联系人
void findPerson(Addressbooks *abs) {
  string name;
  cout << "请输入需查找联系人的姓名：" << endl;
  cin >> name;
  int ret = isExist(abs, name);
  if (ret != -1) {
    cout << "姓名：" << abs->personArray[ret].memName << "\t";
    cout << "性别：" << (abs->personArray[ret].memSex == 1 ? "男" : "女")
         << "\t";
    cout << "年龄：" << abs->personArray[ret].memAge << "\t";
    cout << "电话：" << abs->personArray[ret].memPhone << "\t";
    cout << "住址：" << abs->personArray[ret].memAddr << endl;
  } else {
    cout << "查无此人！" << endl;
  }
  system("pause");
  system("cls");
}

// 5.修改联系人
void modifyPerson(Addressbooks *abs) {
  string name;
  cout << "请输入需修改联系人的姓名：" << endl;
  cin >> name;
  int ret = isExist(abs, name);
  if (ret != -1) {
    showPerson(abs);
    int content = 0;
    while (true) {
      cout << "请输入需要修改的内容" << endl;
      cout << "1.姓名\t2.性别\t\3.年龄\t4.电话\t5.住址\t0.退出" << endl;
      cin >> content;
      switch (content) {
      case 1: {
        string name;
        cout << "请输入修改后的姓名：" << endl;
        cin >> name;
        abs->personArray[ret].memName = name;
        cout << "修改成功！" << endl;
        break;
      }
      case 2: {
        int sex = 0;
        cout << "请输入修改后的性别：" << endl;
        cout << "1.男" << endl;
        cout << "2.女" << endl;

        while (true) {
          cin >> sex;
          if (sex == 1 || sex == 2) {
            abs->personArray[ret].memSex = sex;
            break;
          }
          cout << "输入无效，请重新输入！" << endl;
        }
        cout << "修改成功！" << endl;
        break;
      }
      case 3: {
        int age = 0;
        cout << "请输入修改后的年龄：" << endl;
        cin >> age;
        abs->personArray[ret].memAge = age;
        cout << "修改成功！" << endl;
        break;
      }
      case 4: {
        string phone;
        cout << "请输入修改后的电话:" << endl;
        cin >> phone;
        abs->personArray[ret].memPhone = phone;
        cout << "修改成功！" << endl;
        break;
      }
      case 5: {
        string addr;
        cout << "请输入修改后的住址：" << endl;
        cin >> addr;
        abs->personArray[ret].memAddr = addr;
        cout << "修改成功！" << endl;
        break;
      }
      case 0:
        system("pause");
        system("cls");
        return;
        break;
      default:
        break;
      }
    }
  } else {
    cout << "查无此人！" << endl;
  }
  system("pause");
  system("cls");
}

// 6.清空联系人
void cleanPerson(Addressbooks *abs) {
  abs->memSize = 0;
  cout << "通讯录已清空！" << endl;
  system("pause");
  system("cls");
}

// 菜单界面
void showMenu() {
  cout << "1、添加联系人" << endl;
  cout << "2、显示联系人" << endl;
  cout << "3、删除联系人" << endl;
  cout << "4、查找联系人" << endl;
  cout << "5、修改联系人" << endl;
  cout << "6、清空联系人" << endl;
  cout << "0、退出通讯录" << endl;
}

int main() {
  // 创建通讯录结构体变量
  Addressbooks abs1;
  // 初始化通讯录中人员个数
  abs1.memSize = 0;

  int select = 0;

  while (true) {
    // 菜单调用
    showMenu();
    cin >> select;
    switch (select) {
    case 1: // 1、添加联系人
      addPerson(&abs1);
      break;
    case 2: // 2、显示联系人
      showPerson(&abs1);
      break;
    case 3: // 3、删除联系人
      deletePerson(&abs1);
      break;
    case 4: // 4、查找联系人
      findPerson(&abs1);
      break;
    case 5: // 5、修改联系人
      modifyPerson(&abs1);
      break;
    case 6: // 6、清空联系人
      cleanPerson(&abs1);
      break;
    case 0: // 0、退出通讯录
      cout << "欢迎下次使用" << endl;
      return 0;
      break;
    default:
      break;
    }
  }

  return 0;
}