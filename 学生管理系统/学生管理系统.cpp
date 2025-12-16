//
//  学生管理系统.c
//  
//
//  Created by lose_sea on 2025/12/16.
//


#include<iostream> 
#include<string> 
using namespace std; 

// 老师类
class Teacther { 
public: 
    string name;        // 姓名
    string phone;       // 电话
    string sex;         // 性别
    int age;            // 年龄
    int id;             // 工号
}; 


// 学生类
class Student {
public: 
    string name;        // 姓名
    string id;          // 学号 
    int age;            // 年龄
    string sex;         // 性别
    string phone;       // 电话
    Teacther teacher[5]; // 老师 
    int Chinese;        // 语文成绩
    int math;           // 数学成绩
    int English;        // 英语成绩 
    string major;       // 专业
};











int  main() {

    return 0; 
}
