#include<iostream> 
using namespace std; 


typedef struct {
    int* data;   // 堆数组 
    int capacity;   // 堆容量
    int size;      // 当前堆大小
    bool is_min_heap;  // true: 最小堆, false: 最大堆
}Heap; 


// 创建堆
Heap* createHeap(int capacity, bool is_min_heap) {
    Heap* heap = (Heap*)malloc(sizeof(Heap)); 
    if (!heap) { 
        return NULL;  
    }  
    heap->data = (int*)malloc(sizeof(int) * capacity);  
    if (!heap->data) { 
        free(heap);  
        return NULL;  
    }  
    heap->capacity = capacity;  
    heap->size = 0;  
    heap->is_min_heap = is_min_heap;  
    return heap;  
} 

//  释放堆
void freeHeap(Heap* heap) {
    if (heap) {
        free(heap->data); 
        free(heap); 
    } 
}  



// 交换两个元素