#include<iostream> 
using namespace std; 
// 节点定义
struct AVLNode {
    int val; 
    int height; 
    AVLNode* left; 
    AVLNode* right;  
    AVLNode(int x) : val(x), height(1), left(nullptr), right(nullptr) {}
};  

// 辅助操作

// 获取节点高度
int getHeight(AVLNode* node) {
    return node ? node->height : 0; 
} 

// 获取平衡因子
int getBalanceFactor(AVLNode* node) {
    return node ? getHeight(node->left) - getHeight(node->right) : 0; 
} 

// 更新节点高度
void updateHeight(AVLNode* node) {
    if (node) {
        node->height = 1 + max(getHeight(node->left), getHeight(node->right)); 
    }
} 

// 旋转操作
// 右旋(LL型失衡)
AVLNode* rightRotate(AVLNode* y) {
    AVLNode* x = y->left; 
    AVLNode* T2 = x->right; 
    
    //执行旋转
    x->right = y;  
    y->left = T2; 
    updateHeight(y); 
    updateHeight(x); 
    return x; 
}


// 左旋(RR型失衡)
AVLNode* leftRotate(AVLNode* x) {
    AVLNode* y = x->right; 
    AVLNode* T2 = y->left; 

    // 执行旋转
    y->left = x; 
    x->right = T2; 

    // 更新高度
    updateHeight(x); 
    updateHeight(y);
    return y; 
}


// 左右旋(LR型失衡)
// 先对左子树左旋,再对失衡节点右旋
AVLNode* leftRightRotate(AVLNode* z) { 
    z->left = leftRotate(z->left); 
    return rightRotate(z); 
} 


// 右左旋
// 先对右孩子右旋,再对失衡节点左旋 
AVLNode* rightLeftRotate(AVLNode* z) {
    z->right = rightRotate(z->right); 
    return leftRotate(z); 
}






















int main() {

    return 0; 
}