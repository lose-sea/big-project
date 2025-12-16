#include<iostream>  
#include<string> 
#include<algorithm>
#include<ctime>
using namespace std; 
// struct student {
//     string name; 
//     int age; 
//     int score; 
// }; 
// struct teacher {
//     string name; 
//     int age; 
//     student stu; 
// }; 
// int main() {
//     teacher t; 
//     t.name = "Mr.zhang"; 
//     t.age = 54; 
//     t.stu.name = "zhangsan"; 
//     t.stu.age = 18; 
//     t.stu.score = 88; 
//     cout << t.name << "\n" << t.age << "\n" << t.stu.name << "\n" << t.stu.age << endl << t.stu.score << endl;  
//     return 0; 
// }
struct student {
    string name; 
    int score; 
}; 

struct teacher {
    string name; 
    student stu[5]; 
}; 
// 给老师和学生符赋值的函数
void allocateSpace(teacher t[], int len) {  
    string nameSeed = "ABCDE"; 
    for (int i = 0; i < len; i++) {
        t[i].name = "Teacher"; 
        t[i].name += nameSeed[i];  
        // 给老师所带的学生赋值 
        for (int j = 0; j < 5; j++) {
            t[i].stu[j].name = "Student_"; 
            t[i].stu[j].name += nameSeed[j];  
            int random = rand() % 101; 
            t[i].stu[j].score = random; 
        }
    } 
}
 
void printStruct(teacher t[], int len) {
    for (int i = 0; i < len; i++) {
        cout << t[i].name << endl;  
        for (int j = 0; j < 5; j++) {
            cout << t[i].stu[j].name << t[i].stu[j].score << endl; 
        } 
    }
}
int main() { 
    // 随机数种子d'f'g
    srand((unsigned int)time(NULL)); 

    teacher t[3]; 
    int len = sizeof(t) / sizeof(t[0]);  
    // 赋值函数
    allocateSpace(t, len); 
    // 打印函数 
    printStruct(t, len); 
    return 0; 
}



// struct hero {
//     string name; 
//     int age; 
//     string sex; 
// }; 
// bool cmp(hero e1, hero e2) {
//     return e1.age <e2.age; 
// }
// // 打印函数
// void printhero(hero h[], int len) {
//     for (int i = 0; i < len; i++) {
//         cout << h[i].name << "\t" <<  h[i].age << "\t" << h[i].sex << endl; 
//     }
// }
// int main() {
//     hero h[5] = {
//         {"zhangfei", 21, "nan"}, 
//         {"diaochan", 18, "nv"}, 
//         {"lvbu", 26, "nan"}, 
//         {"liuchan", 14, "nan"}, 
//         {"guanyu", 24, "nan"}
//     }; 
//     sort(h, h + 5, cmp); 
//     printhero(h, 5); 
//     return 0; 
// }