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
}; 