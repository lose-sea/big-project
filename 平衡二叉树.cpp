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




// 插入操作
AVLNode* insert(AVLNode* root, int val) { 
    // 标砖BST插入
    if (root == nullptr) {
        return new AVLNode(val); 
    } 
    if (val < root->val) {
        root->left = insert(root->left, val); 
    } else if (val > root->val) {
        root->right = insert(root->right, val); 
    } else {
        return root;  // 不允许重复值
    } 
    // 更新当前节点的高度
    updateHeight(root); 
    // 获取平衡因子 
    int balance = getBalanceFactor(root); 
    // 根据平衡因子进行旋转
    
    // LL情况: 左子树比右子树高,且新节点插入到左子树的左子树
    if (balance > 1 && val < root->left->val) {
        return rightRotate(root); 
    } 
    // RR情况: 右子树比左子树高,并且新节点插入到右子树的右子树
    if (balance < -1 && val > root->right->val) {
        return leftRotate(root); 
    } 
    // LR情况: 左子树比右子树高,并且新节点插入到左子树的右子树
    if (balance > 1 && val > root->left->val) {
        return leftRightRotate(root); 
    } 
    // RL情况: 右子树比左子树高,并且新节点插入到右子树的左子树
    if (balance < -1 && val < root->right->val) {
        return rightLeftRotate(root); 
    } 
    return root; 
}





// 找的最小值的节点
AVLNode* minValueNode(AVLNode* node) {
    AVLNode* current= node; 
    while (current != nullptr) {
        current->left; 
    } 
    return current; 
}


// 删除操作 
AVLNode* deleteNode(AVLNode* root, int val) { 
    if (!root) {
        return root; 
    } 
    if (val < root->val) {
        root->left = deleteNode(root->left, val); 
    } else if (val > root->val) {
        root->right = deleteNode(root->right, val); 
    } else {
        // 找到要删除的节点
        if (!root->left || !root->right) {
            // 有一个或者没有子节点
            AVLNode* temp = root->left ? root->left : root->right; 
            if (!temp) { // 没有子节点
                temp = root; 
                root = nullptr; 
            } else {   // 有一个子节点
                *root = *temp;   // 复制子节点的内容
            } 
            delete temp; 
        } else {  // 有两个子节点 
            // 找到右子树的最小节点
            AVLNode* temp = minValueNode(root->right);  
            // 复制右子树的最小节点
            root->val = temp->val; 
            // 删除右子树的最小节点 
            root->right = deleteNode(root->right, temp->val); 
        }
    } 
    // 如果树只有一个节点 直接返回
    if (!root) {
        return root; 
    } 

    // 更新高度
    updateHeight(root); 

    // 获取平衡因子
    int balance = getBalanceFactor(root); 

    // 重新平衡
    
    // LL情况
    if (balance > 1 && getBalanceFactor(root) >= 0) {  
        return rightRotate(root); 
    } 
    // LR情况
    if (balance > 1 && getBalanceFactor(root) < 0) { 
        return leftRightRotate(root);  
    } 
    // RR情况
    if (balance < -1 && getBalanceFactor(root) <= 0) { 
        return leftRotate(root); 
    } 
    // RL情况 
    if (balance < -1 && getBalanceFactor(root) > 0) { 
        return leftRightRotate(root); 
    } 
    return root; 
}












int main() {

    return 0; 
}