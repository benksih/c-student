#include <stdio.h>
#include <string.h>
typedef struct Course{
    int id; // 课程ID
    char name[20]; // 课程名称
    char nature[10]; // 课程性质
    int term; // 课程学期
    float credits;// 课程学分
} Course;
// 定义课程数组和课程数量
