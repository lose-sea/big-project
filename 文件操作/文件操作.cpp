#include<iostream> 
using namespace std; 




int main() {
    FILE* pf = fopen("test.txt", "w"); 
    if (pf == NULL) {
        printf("fail\n");
        return 1; 
    } 
    // 打开文件成功
    // 写文件

    for (char i = 'a'; i <= 'z'; i++) {
        fputc(i, pf); 
    } 


    // 关闭文件
    fclose(pf); 
    pf = nullptr; 
    return 0; 
}