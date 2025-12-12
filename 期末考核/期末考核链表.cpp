#include<iostream> 
#include<stack> 
using namespace std;  


// 英雄节点类
class ListNode { 
public: 
    string name; 
    char rarity; 
    ListNode* next; 
    ListNode(string name = "", char r = {}) : name(name), rarity(r), next(nullptr) {} 
}; 
// 英雄链表类
class heroList {
public: 
    ListNode* head; 
public: 
    // 构造函数
    heroList() : head(nullptr) {}
    
    

    // 插入节点
    void insertAtTail(string name, char rarity) { 
        ListNode* node = new ListNode(name, rarity); 
        if (head == nullptr) {
            head = node; 
        } else {
            ListNode* curr = head; 
            while (curr->next != nullptr) {
                curr = curr->next; 
            } 
            curr->next = node; 
        }
    }


    // 通过姓名查看熟练度
    void search(string name) {
        ListNode* curr = head; 
        while (curr != nullptr) { 
            if (curr->name == name) {
                cout << name << "的熟练度为" << curr->rarity << endl; 
                return; 
            }
            curr = curr->next; 
        } 
        cout << "没有找到" << endl; 
    } 


    // 删除英雄
    void remove(string name) {
        ListNode* dummy = new ListNode(); 
        dummy->next = head; 
        ListNode* curr = dummy; 
        while (curr->next != nullptr) {
            if (curr->next->name == name) {
                ListNode* temp = curr->next; 
                curr->next = temp->next; 
                delete temp; 
                break; 
            }  
            curr = curr->next; 
        } 
        head = dummy->next; 
        delete dummy; 
    }
   

    // 通过姓名修改稀有度
    void modify(string name, char rarity) {
        ListNode* curr = head; 
        while (curr != nullptr) {
            if (curr->name == name) { 
                cout << "已将" << name << "的熟练度改为" << rarity << endl; 
                curr->rarity = rarity; 
                return; 
            }
            curr = curr->next; 
        } 
        cout << "没有找到" << endl; 
    } 

    // 将链表保存到文件中
    void saveToFile(char* filename) {
        FILE* pf = fopen(filename, "w"); 
        if (pf == nullptr) {
            cout << "文件打开失败\n" << endl; 
            return; 
        }  
        ListNode* curr = head;  
        while (curr != NULL) {
            fprintf(pf, "%s %c\n", curr->name, curr->rarity);  
            curr = curr->next; 
        } 
        fclose(pf);  
        pf = nullptr;  
        cout << "数据已保存到文件" << endl; 
    } 


    // 从文件中读取数据并创建链表
    ListNode* loadFromFile(char* filename) {
        FILE* pf = fopen(filename, "r"); 
        if (pf == nullptr) {
            cout << "文件打开失败\n" << endl;  
            return nullptr; 
        } 
        char name[100]; 
        char rarity; 
        ListNode* dummy = new ListNode(); 
        ListNode* curr = dummy; 
        while (fscanf(pf, "%s %c", name, &rarity) == 2) {
            // 创建新节点
            ListNode* newNode = new ListNode(name, rarity); 
            curr->next = newNode; 
            curr = curr->next; 
        }  
        fclose(pf); 
        cout << "数据已从文件中读取"  << endl; 
        ListNode* temp = dummy->next; 
        delete dummy; 
        return temp; 
    }

    // 打印链表
    void printList() {
        ListNode* curr = head; 
        while (curr != nullptr) {
            cout << "姓名 :" << curr->name << "稀有度 :" << curr->rarity << endl; 
            curr = curr->next; 
        }
    }
};  



int main() {
    heroList s; 
    s.insertAtTail("斯派克", 'S'); 
    s.insertAtTail("阿方", 'A'); 
    s.insertAtTail("斯图", 'B'); 
    // 查询
    string name01; 
    cin >> name01; 
    s.search(name01); 


    // 删除
    string name02; 
    cin >> name02; 
    s.remove(name02); 
    cout << name02 << "已删除" << endl; 
    s.printList();  


    // 修改稀有度
    string name03; 
    char ch; 
    cin >> name03 >> ch; 
    s.modify(name03, ch); 
    s.printList(); 


    return 0; 
}










