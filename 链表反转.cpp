#include<iostream>  
#include<list> 
using namespace std; 

class ListNode { 
public: 
    int val; 
    ListNode* next; 
    ListNode(int x) : val(x), next(nullptr) {} 
};  


// 迭代法
class Solution {
public: 
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr; 
        ListNode* curr = head; 
        while (curr != nullptr) {
            ListNode* next = curr->next; 
            curr->next = prev; 
            prev = curr; 
            curr = next; 
        } 
        return prev; 
    }
}; 
 

// 递归法
class Solution {
public: 
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        } 
        ListNode* newhead = reverseList(head->next); 
        head->next->next = head; 
        head->next = nullptr; 
        return newhead; 
    } 
}; 

// 头插法 
class Solution {
public: 
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        } 
        ListNode* newhead = new ListNode(0); 
        ListNode* curr = head; 
        while (curr != nullptr) {
            ListNode* next = curr->next; 
            curr->next = newhead->next;
            newhead->next = curr; 
            curr = next; 
        } 
        ListNode* result = newhead->next; 
        delete newhead; 
        return result; 
    }
}; 


class Solution {
public: 
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head; 
        }
        list<int> myList; 
        ListNode* curr = head; 
        while (curr != nullptr) {
            myList.push_back(curr->val); 
            curr = curr->next;  
        } 
        myList.reverse(); 
        curr = head; 
        list<int>::iterator it = myList.begin(); 
        while (curr != nullptr && it != myList.end()) {
            curr->val = *it; 
            curr = curr->next; 
        } 
        return head; 
    }
}; 


int main() {


    return 0; 
}