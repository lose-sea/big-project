#include<iostream> 
#include<string> 
using namespace std; 



struct 





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





    while(1) {
        // 显示菜单
        showMenu(); 
        // 创建用户选择输入的变量
        int select = 0; 
        cin >> select; 
        switch(select) {
            case 1 :        // 1. 添加联系人
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
    }

    return 0; 
}