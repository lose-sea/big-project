#include<iostream> 
#include<string> 
using namespace std; 
#define MAX 1000 


struct Person {
    string name; 
    string sex; 
    int age; 
    string phone; 
    string addr;  // 住址
}; 


// 设计通讯录结构体
struct Addressbooks {
    // 通讯录中保存的联系人数组
    struct Person personArrat[MAX]; 

    // 通讯录中保存的联系人个数
    int size; 
}; 



// 添加联系人功能
void addPerson(struct Addressbooks* abs) {
    if (abs->size == MAX) {
        cout << "通讯录已满, 无法添加" << endl; 
        return; 
    } 
    // 添加具体联系人 
    cout << "请输入你要添加的联系人姓名" << endl; 
    string name; 
    cin >> name; 
    abs->personArrat[abs->size].name = name; 

    cout << "请输入性别 " << endl; 
    while (1) {
        string sex; 
        cin >> sex;  
        if (sex == "男" || sex == "女") {
            abs->personArrat[abs->size].sex = sex; 
            break; 
        } else {
            cout << "输入错误, 请重新输入" << endl; 
        }
    } 

    cout << "请输入年龄" << endl; 
    int age = 0; 
    cin >> age; 
    abs->personArrat[abs->size].age = age; 

    cout << "请输入联系方式" << endl; 
    string phone; 
    cin >> phone; 
    abs->personArrat[abs->size].phone = phone; 
    
    cout << "请输入住址" << endl; 
    string addr; 
    cin >> addr; 
    abs->personArrat[abs->size].addr = addr; 

}




void showMenu() { 
    cout << "***************************" << endl; 
    cout << "*****  1. 添加联系人  *****" << endl; 
    cout << "*****  2. 显示联系人  *****" << endl; 
    cout << "*****  3. 删除联系人  *****" << endl; 
    cout << "*****  4. 查找联系人  *****" << endl; 
    cout << "*****  5. 修改联系人  *****" << endl; 
    cout << "*****  6. 清空联系人  *****" << endl; 
    cout << "*****  7. 推出通讯录  *****" << endl; 
    cout << "***************************" << endl; 
}


int main() { 

    // 创建通讯录结构体变量
    Addressbooks abs; 
    // 初始化通讯录中当前人员个数
    abs.size = 0; 



    while(1) {
        // 显示菜单
        showMenu(); 
        // 创建用户选择输入的变量
        int select = 0; 
        cin >> select; 
        switch(select) {
            case 1 :        // 1. 添加联系人 
                addPerson(&abs);   
                break; 
            case 2 :        // 2. 显示联系人 
                break; 
            case 3 :        // 3. 删除联系人
                break; 
            case 4 :        // 4. 查找联系人 
                break; 
            case 5 :        // 5. 修改联系人
                break; 
            case 6 :        // 6. 清空联系人 
                break; 
            case 7 :        // 7. 推出通讯录
                cout << "欢迎下次使用" << endl; 
                return 0; 
                break; 
            default : 
                break; 
        }
        system("pause"); 
        system("cls"); 
    }
    system("pause"); 
    system("cls"); 
    return 0; 
}