//
//  学生管理系统.c
//  
//
//  Created by lose_sea on 2025/12/16.
//


#include<stdio.h> 
#include<stdlib.h> 
#include<limits.h>



// 学生
typedef struct student { 
    char id[INT_MAX]; 
    char name[INT_MAX]; 
    char sex[20]; 
    int age; 
    int telephone; 
    int score; 
    char major[INT_MAX]; 
    char garde; 
    char ; 
}student; 

int studentSize = 0; 
struct student stu[INT_MAX];

void showStudent() {
    if (studentSize == 0) {
        printf("学生数量为0\n"); 
        return; 
    } 
    for (int i = 0; i < studentSize; i++) {
        printf("%s %s %s", stu[i].name, stu[i].id, stu[i].sex); 
    }
}













void displayMenu() {
    printf("*********************\n");
    printf("***1. 展示学生信息 ****\n");
    printf("***2. 添加学生信息 ****\n");
    printf("***3. 修改学生信息 ****\n");
    printf("***4.   删除学生  ****\n");
    printf("*********************\n");
}








int  main() {
    // 显示菜单 
    displayMenu(); 
    char choise; 
    scanf("%c", &choise); 
    return 0; 
}
