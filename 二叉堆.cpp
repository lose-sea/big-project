#include<iostream> 
#include <iostream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std; 



class Heap {
public: 
    vector<int> heap; 
    bool isMaxHeap;      // true表示最大堆, false表示最小堆

    // 比较函数
    bool compare(const int& a, const int& b) {
        return isMaxHeap ? a > b : a < b; 
    } 

    // 获取父节点索引
    int parent(int index) {
        return (index - 1) / 2; 
    } 

    // 获取左孩子索引
    int leftChild(int index) {
        return 2 * index + 1; 
    } 

    // 获取有孩子索引
    int rightChild(int index) {
        return 2 * index + 2; 
    } 
 
    // 上浮操作
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2; 
            if (compare(heap[index], heap[parent])) {
                swap(heap[index], heap[parent]); 
                index = parent; 
            } else {
                break; 
            }
        }
    } 

    // 下沉操作
    void heapifyDown(int index) {
        int size = heap.size(); 
        while (true) {
            int leftChild = 2 * index + 1; 
            int rightChild = 2 * index + 2; 
            int target = index; 

            // 找到当前节点、左子节点、右子节点中最符合堆性质的节点
            if (leftChild < size && compare(heap[leftChild], heap[target])) {
                target = leftChild;
            }
            if (rightChild < size && compare(heap[rightChild], heap[target])) {
                target = rightChild;
            }
            
            // 如果当前节点不是最大的/最小的，交换并继续下沉
            if (target != index) {
                swap(heap[index], heap[target]);
                index = target;
            } else {
                break;
            }
        } 
    } 

    // 构造函数 
    Heap(bool maxHeap = true) : isMaxHeap(maxHeap) {} 


    // 从数组建堆的构造函数
    Heap(const vector<int>& arr, bool maxHeap = true) : isMaxHeap(maxHeap) {
        heap = arr;
        // 从最后一个非叶子节点开始建堆
        for (int i = heap.size() / 2 - 1; i >= 0; i--) {
            heapifyDown(i);
        }
    } 

    // 插入元素
    void push(int value) {
        heap.push_back(value); 
        heapifyUp(heap.size() - 1); 
    }  

    // 删除堆顶元素
    void pop() {
        if (heap.empty()) {
            cout << "堆为空，无法删除！" << endl;
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
    } 

    // 获取堆顶元素
    int top() {
        if (heap.empty()) {
            cout << "堆为空！" << endl;
            return -1;
        }
        return heap[0];
    }
    
    // 堆是否为空
    bool empty() {
        return heap.empty();
    }
    
    // 获取堆大小
    int size() {
        return heap.size();
    }
    
    // 获取堆类型
    string getType() {
        return isMaxHeap ? "最大堆" : "最小堆";
    }

}; 