#include<iostream> 
using namespace std; 



class ListNode {
public : 
    int val; 
    ListNode* next; 
    ListNode() : val(0), next(nullptr) {}
    ListNode(int val) : val(val), next(nullptr) {} 
    ListNode(int val, ListNode* node) : val(val), next(node) {}
}; 


class List {
public : 
    ListNode* head; 
    int size; 
    // 构造函数
    List() : head(nullptr) , size(0) {}
    
    // 头插
    void insertAthead(int val) {
        ListNode* newhead  = new ListNode(val); 
        newhead->next = head; 
        head = newhead; 
        size++; 
    }


    // 尾插 
    void insertAttail(int val) {
        ListNode* newnode = new ListNode(val); 
        if (head == nullptr) {
            head = newnode; 
        } else {
            ListNode* curr = head; 
            while (curr->next != nullptr) {
                curr = curr->next; 
            } 
            curr->next = newnode; 
        }
        size++; 
    } 

    // 在任意位置插入节点
    void insert(int index, int val) { 
        if (index == 0) {
            insertAthead(val); 
            return; 
        }
        ListNode* node = new ListNode(val); 
        
        ListNode* curr = head; 
        for (int i = 1; i < index; i++) {
            curr = curr->next; 
        } 
        node->next = curr->next; 
        curr->next = node; 
        size++; 
    } 

    // 删除头节点
    void pop_front() { 
        if (head == nullptr) {
            return; 
        }
        ListNode* temp = head; 
        head = head->next; 
        delete temp; 
        size--; 
    } 



    // 删除尾节点
    void pop_back() {
        if (head == nullptr) {
            return;  
        }  
        ListNode* curr = head; 
        if  (head->next == nullptr) {
            delete head; 
            head = nullptr; 
            return; 
        }
        while (curr->next->next != nullptr) {
            curr = curr->next; 
        } 
        delete curr->next; 
        curr->next = nullptr; 
    } 
}; 

    // 链表反转
    ListNode* reverse(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        } 
        ListNode* newhead = reverse(head->next); 
        head->next->next = head; 
        head->next = nullptr; 
        return newhead; 
    } 




