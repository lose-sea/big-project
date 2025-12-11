#include<iostream> 
using namespace std; 




// int main() {
//     FILE* pf = fopen("test.txt", "w"); 
//     if (pf == NULL) {
//         printf("fail to open\n");
//         return 1; 
//     } 
//     // 打开文件成功
//     // 写文件
//     // 写入字符
//     for (char i = 'a'; i <= 'z'; i++) {
//         fputc(i, pf); 
//     } 
//     fputc('\n', pf); 
//     printf("\n"); 


//     // 逐行写入
//     fputs("the first floor\n", pf); 
//     fputs("the second floor\n", pf); 
//     fputs("the third floor\n", pf); 
//     // 关闭文件
//     fclose(pf); 

//     // 读取文件
//     // 以只读的形式打开
//     pf = fopen("test.txt", "r"); 
//     if (pf == NULL) {
//         printf("fail to open\n"); 
//         return 1; 
//     } 
//     printf("文件内容: \n"); 
//     char arr[10000]; 
//     while (fgets(arr, 100, pf) != NULL) {
//         printf("%s", arr); 
//     }
//     // 关闭文件
//     fclose(pf); 
//     pf = nullptr; 
//     return 0; 
// }


// // 将9 x 9乘法表打印到文件中
// int main() {
    
//     FILE* pf = fopen("xinyan.txt", "w"); 
//     if (pf == nullptr) {
//         perror("fopen"); 
//     } 
//     for (int i = 1; i <= 9; i++) {
//         for (int j = 1; j <= i; j++) {
//             fprintf(pf, "%d * %d = %-2d", i, j, i * j); 
//             printf("%d * %d = %-2d", i, j, i * j); 
//         } 
//         fprintf(pf, "\n"); 
//         printf("\n"); 
//     }
//     fclose(pf); 
//     pf = nullptr; 
//     return 0; 
// } 



// 二进制的方式写文件 

struct S {
    char arr[10]; 
    int age; 
    float score; 
}; 

int main() {    
    struct S s = {"xinyan", 25, 20.5f}; 
    
    FILE* pf = fopen("test.txt", "wb"); 
    if (pf == NULL) {
        perror("fopen"); 
        return 1; 
    } 
    // 打开成功 
    // 二进制的方式写
    fwrite(&s, sizeof(struct S), 1, pf); 
    printf("%s %d %f\n", s.arr, s.age, s.score); 
    fclose(pf); 
    pf = nullptr; 
    return 0; 
}