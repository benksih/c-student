#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义课程结构体
struct Course{
    int id; // 课程ID
    char name[20]; // 课程名称
    char nature[10]; // 课程性质
    int term; // 课程学期
    float credits;// 课程学分
} ;
#define MAX_COURSES 1000
struct Course courses[MAX_COURSES];
int courseCount = 0;

// 函数声明

#define MAX_COURSES 1000



struct Course courses[MAX_COURSES];

void loadCourses() {
    FILE *file = fopen("classinfo.dat", "rb");
    if (file == NULL) {
        perror("无法打开文件");
        exit(1);
    }
    while (fread(&courses[courseCount], sizeof(struct Course), 1, file)) {
        courseCount++;
        if (courseCount >= MAX_COURSES) {
            printf("达到最大课程数量限制。\n");
            break;
        }
    }
    fclose(file);
    printf("加载了%d门课程。\n", courseCount);
}
void printCourseInfo(int index) {
    if (index >= 0 && index < courseCount) {
        printf("课程ID:%d 课程名称:%s 课程性质:%s 课程学期:%d 课程学分:%f\n",
               courses[index].id, courses[index].name, courses[index].nature, courses[index].term, courses[index].credits);
    } else {
        printf("未找到课程信息。\n");
    }
}

int searchCoursesById(int targetId) {
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].id == targetId) {
            printCourseInfo(i);
        }
    }
    getchar();
    return 0;
}

int searchCoursesByName(const char* targetName) {
    int count = 0;
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].name, targetName) == 0) {
            printCourseInfo(i);
            count++;
        }
    }
    getchar();
    return count;
}

int searchCoursesByNature(const char* targetNature) {
    int count = 0;
    for (int i = 0; i < courseCount; i++) {
        if (strcmp(courses[i].nature, targetNature) == 0) {
            printCourseInfo(i);
            count++;
        }
    }
    getchar();
    return count;
}

int searchCoursesByTerm(int targetTerm) {
    int count = 0;
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].term == targetTerm) {
            printCourseInfo(i);
            count++;
        }
    }
    getchar();
    return count;
}

int searchCoursesByCredits(float targetCredits) {
    int count = 0;
    for (int i = 0; i < courseCount; i++) {
        if (courses[i].credits == targetCredits) {
            printCourseInfo(i);
            count++;
        }
    }
    getchar();
    return count;
}


void queryModule() {
    loadCourses();
    int choice, index;
    do {
        system("cls");
        printf("****************************\n");
        printf("*      按1查询课程编号     *\n");
        printf("*      按2查询课程名称     *\n");
        printf("*      按3查询课程性质     *\n");
        printf("*      按4查询开课学期     *\n");
        printf("*        按5查询学分      *\n");
        printf("*         退出查询       *\n");
        printf("****************************\n");
        scanf("%d", &choice);
        getchar(); // 吸收换行符

        switch (choice) {
        case 1: {
                int id;
                printf("请输入课程编号: ");
                scanf("%d", &id);
                getchar();
                searchCoursesById(id);
                break;
        }
        case 2: {
                char name[20];
                printf("请输入课程名称: ");
                scanf("%19s", name);
                getchar();
                searchCoursesByName(name);
                break;
        }
        case 3: {
                char nature[10];
                printf("请输入课程性质: ");
                scanf("%9s", nature);
                getchar();
                searchCoursesByNature(nature);
                break;
        }
        case 4: {
                int term;
                printf("请输入开课学期: ");
                scanf("%d", &term);
                getchar();
                searchCoursesByTerm(term);
                break;
        }
        case 5: {
                float credits;
                printf("请输入学分: ");
                scanf("%f", &credits);
                getchar();
                searchCoursesByCredits(credits);
                break;
        }
        case 6:
            return;
        default:
            printf("无效选项，请重新输入。\n");
        }
    } while (1);
}
struct Course readCoursesFromFile(int a);
struct Course course;
// 全局变量，用于存储课程和选课信息
void writeCoursesToFile() {
    struct Course course;
    printf("输入课程ID: ");
    scanf("%d", &course.id);
    while (getchar() != '\n'); // 清空缓冲区

    // 检查课程ID是否已存在
    FILE *file = fopen("classinfo.dat", "ab+"); // 打开文件以追加和读取
    if (file == NULL) {
        perror("无法打开文件");
        return;
    }

    // 移动文件指针到文件开头
    fseek(file, 0, SEEK_SET);

    struct Course course2;
    while(fread(&course2, sizeof(struct Course), 1, file)) {
        if (course2.id == course.id) {
            printf("课程已存在\n");
            fclose(file);
            return;
        }
    }

    printf("输入课程名称: ");
    scanf("%19s", course.name);
    while (getchar() != '\n'); // 清空缓冲区

    printf("输入课程性质: ");
    scanf("%9s", course.nature);
    while (getchar() != '\n'); // 清空缓冲区

    printf("输入课程学期: ");
    scanf("%d", &course.term);
    while (getchar() != '\n'); // 清空缓冲区

    printf("输入课程学分: ");
    if (scanf("%f", &course.credits) != 1) {
        printf("输入无效，请输入数字。\n");
        fclose(file);
        return;
    }
    while (getchar() != '\n'); // 清空缓冲区

    // 写入课程信息
    fwrite(&course, sizeof(struct Course), 1, file);
    fclose(file);
    printf("课程添加成功\n");
    Sleep(1000);
}

struct Course readCoursesFromFile(int a)
{
  FILE *file = fopen("classinfo.dat", "rb");
    course.term=-1;
  while(fread(&course,sizeof(struct Course),1,file))
    {
          if(a==course.id)
            {
            return course;
            }
    }
    fclose(file);
    strcpy(course.name,"Not Found");
    strcpy(course.nature,"Not Found");
    course.term=-1;
    course.credits=-1;
    course.id=a;
    return course;
}


// 写入选课信息到文件
void writeEnrollmentsToFile(int a,int b) {
    FILE *fp = fopen("studentinfo.dat", "rb+ ");
    struct student student;
    while(fread(&student,sizeof(struct student),1,fp))
    {
        if(a==student.stuNo)
        {
            if (student.num==0)
            {
                student.courseCode[student.num]=b;
                student.num++;
                break;
            }
            if (student.num>0)
            {
                for(int i=0;i<student.num;i++)
                {
                    if (b==student.courseCode[i])
                    {
                        printf("已经选过此课程了！");
                        goto close;
                    }
                }
            }
        }
    }
    fseek(fp,(unsigned int)-sizeof(struct student),SEEK_CUR);
    fwrite(&student, sizeof(struct student),1,fp);
    printf("选课成功！");
    close:
    fclose(fp);
}

// 从文件读取选课信息
struct student readEnrollmentsFromFile(int a)
{
    FILE *file = fopen("studentinfo.dat", "rb");
    if (file == NULL) {
        perror("无法打开文件");
        exit(1);
    }
    struct student student;
    while (fread(&student,sizeof(struct student),1,file))
    {
        if(student.stuNo==a)
        {
            return student;
        }
    }
}
