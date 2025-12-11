
#include<iostream>
using namespace std; 


class ListNode {
public: 
    string name;       
    char s; 
    ListNode* next; 
    ListNode(string ming, char ch) : name(ming), s(ch), next(nullptr) {}
}; 


ListNode* pushAthead(ListNode* head, string s, char ch) { 
    ListNode* node = new ListNode(s, ch); 
    node->next = head; 
    head = node; 
    return head; 
}  



char search(ListNode* head, string s) {
    ListNode* curr = head; 
    while (curr->name != s && curr != NULL) {
        curr = curr->next; 
    } 
    return curr->s; 
} 


// 删除数据
ListNode* erase(ListNode* head, string name) {
    ListNode* dummy = (ListNode*)malloc(sizeof(ListNode)); 
    dummy->next = head; 
    ListNode* curr = dummy; 
    while (curr->next->name != name) {
        curr = curr->next; 
    } 
    ListNode* temp = curr->next; 
    curr->next = curr->next->next; 
    free(temp);  
    return head; 
}


// 修改熟练度
ListNode* fixList(ListNode* head, string name, char r) {
    ListNode* curr = head; 
    while (curr->name != name) {
        curr = curr->next; 
    } 
    curr->s = r; 
    cout << "已将" << name << "的熟练度修改为" << r << endl; 
    return head; 
}


// 打印链表
void printList(ListNode* head) {
    ListNode* curr = head; 
    while (curr != NULL) {
        cout << "姓名: " << curr->name << " " << "稀有度" << curr->s << endl; 
        curr = curr->next; 
    } 
    return; 
}

int main() {
    ListNode* node01 = new ListNode("斯派克", 'S'); 
    ListNode* node02 = new ListNode("阿方", 'A'); 
    node01->next = node02; 
    ListNode* node03 = new ListNode("斯图", 'B'); 
    node02->next = node03; 



    printf("请输入要查询的姓名: \n");  
    string s; 
    cin >> s; 
    char ch = search(node01, s); 
    cout << ch << endl; 

    printf("请输入要删除的姓名 : \n"); 
    string era; 
    cin >> era; 
    node01 = erase(node01, era); 
    printList(node01); 


    cout << "请输入要修改的姓名和稀有度" << endl; 
    string a; 
    cin >> a; 
    char fix; 
    cin >> fix; 
    node01 = fixList(node01, a, fix); 
    printList(node01);  

    FILE* pf = fopen("test.txt", "w"); 
    if (pf == NULL) {
        printf("打开失败"); 
        return 1; 
    } 
    ListNode* curr = node01; 
    while (curr != nullptr) {
        fprintf(pf, "姓名 : %s , 稀有度: %c", curr->name, curr->s); 
        curr = curr->next; 
    }
    return 0; 
}


