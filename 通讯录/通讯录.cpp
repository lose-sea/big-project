#include<iostream> 
#include<string> 
#include<cstdlib>
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
    struct Person personArray[MAX]; 

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
    abs->personArray[abs->size].name = name; 

    cout << "请输入性别 " << endl; 
    while (1) {
        cout << "请选择性别 " << endl; 
        cout << "1. 男" << endl; 
        cout << "2. 女" << endl;  
        int select_sex = 0; 
        cin >> select_sex; 
        if (select_sex == 1 || select_sex == 2) { 
            if (select_sex == 1) {
                abs->personArray[abs->size].sex = "男"; 
            } else {
                abs->personArray[abs->size].sex = "女"; 
            }
            break; 
        } else {
            cout << "输入错误, 请重新输入" << endl; 
        }
    } 

    cout << "请输入年龄" << endl; 
    string age; 
    cin >> age; 
    int m_age = stoi(age); 
    abs->personArray[abs->size].age = m_age; 

    cout << "请输入联系方式" << endl; 
    string phone; 
    cin >> phone; 
    abs->personArray[abs->size].phone = phone; 
    
    cout << "请输入住址" << endl; 
    string addr; 
    cin >> addr; 
    abs->personArray[abs->size].addr = addr; 

    abs->size++;        // 添加成功后通讯录人数加 1
}  

// 显示联系人
void showPerson(Addressbooks* abs) {
    // 判断通讯录人数是否为0 
    if (abs->size == 0) {
        cout << "通讯录为空" << endl; 
        return; 
    } 
    cout << "联系人" << endl; 
    for (int i = 0; i < abs->size; i++) {
        cout << abs->personArray[i].name << endl; 
        cout << abs->personArray[i].sex << endl; 
        cout << abs->personArray[i].age << endl; 
        cout << abs->personArray[i].phone << endl; 
        cout << abs->personArray[i].addr << endl; 
    } 
    system("pause");   // 按任意键继续
    system("cls");      //  清屏
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
        string select;  
         
        cout << "请选择" << endl; 
        cin >> select; 
        int m_select = stoi(select);
        switch(m_select) {
            case 1 :        // 1. 添加联系人 
                addPerson(&abs);   
                break; 
            case 2 :        // 2. 显示联系人 
                showPerson(&abs); 
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
    system("pause"); 
    system("cls"); 
    return 0; 
}