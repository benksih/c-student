#include <stdio.h>
int meau1() {
    printf("****************************\n");
    printf("*      填写选课信息按1     *\n");
    printf("*      观看选课信息按2     *\n");
    printf("*      浏览课程信息按3     *\n");
    printf("*      搜索课程信息按4     *\n");
    printf("*      查看自己信息按5     *\n");
    printf("****************************\n");
    int a;
    scanf("%d",&a);
    getchar();
    return a;
}
int meau2() {
    printf("****************************\n");
    printf("*      输入学生信息按1     *\n");
    printf("*      输入课程信息按2     *\n");
    printf("*      浏览课程信息按3     *\n");
    printf("*      搜索课程信息按4     *\n");
    printf("*      查看自己信息按5     *\n");
    printf("****************************\n");
    int a;
    scanf("%d",&a);
    getchar();
    return a;
}
