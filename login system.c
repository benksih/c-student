#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <time.h>
int comparestudent(int a,char *b);
int compareteacher(int a,char *b);
int compare1(int a);
int compare2(int a);
struct student {
    int stuNo;
    char courseCode[10];
    char code[20];
};
struct teacher {
    int teaNo;
    char code[20];
};
int compare1(int a)
{
    struct student s1;
    FILE *fp=fopen("studentinfo.dat","rb");
    if(fp==NULL)
    {
        printf("studentinfo.dat not found\n");
        exit(1);
    }
    while(fread(&s1,sizeof(struct student),1,fp))
    {
        if(a==s1.stuNo)
        {
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int compare2(int a)
{
    struct teacher s1;
    FILE *fp=fopen("teacherinfo.dat","rb");
    if(fp==NULL)
    {
        printf("teacherinfo.dat not found\n");
        exit(1);
    }
    while(fread(&s1,sizeof(struct teacher),1,fp))
    {
        if(a==s1.teaNo)
        {
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
int comparestudent(int a,char *b)
{
    struct student s1;
    FILE *stud=fopen("studentinfo.dat","rb");
    if(stud==NULL)
    {
        printf("studentinfo.dat not found\n");
        exit(1);
    }
    while(fread(&s1,sizeof(struct student),1,stud))
    {
        if(a==s1.stuNo&&strcmp(s1.code,b)==0)
        {
            return 1;
        }
    }
    fclose(stud);
    return 0;
}
int compareteacher(int a,char *b)
{
    struct teacher t1;
    FILE *teach=fopen("teacherinfo.dat","rb");
    if(teach==NULL)
    {
        printf("teacherinfo.dat not found\n");
        exit(1);
    }
    while(fread(&t1,sizeof(struct teacher),1,teach))
    {
        if(a==t1.teaNo&&strcmp(t1.code,b)==0)
        {
            return 1;
        }
    }
    fclose(teach);
    return 0;
}
int main()
{
    FILE *stud, *teach;
    printf("***********************\n");
    printf("*      注册请按1       *\n");
    printf("*      登录请按2       *\n");
    printf("***********************\n");
    int a;
    scanf("%d",&a);
    getchar(); // 吸收换行符
    system("cls");
    if(a==1)
    {
        int c;
        printf("****************************\n");
        printf("*      学生注册请按1       *\n");
        printf("*      教师注册请按2       *\n");
        printf("****************************\n");
        scanf("%d",&c);
        getchar();
        if(c==1)
        {
            struct student s1;
            system("cls");
            printf("因为您选择注册，注册后自动跳转到登录界面；按下回车键以继续");
            getchar();
            system("cls");
            again:
            printf("账号：\n");
            scanf("%d",&s1.stuNo);
            getchar();
            if(compare1(s1.stuNo)==0)
            {
                printf("密码：\n");
            scanf("%s",&s1.code[0]);
            getchar();
            stud=fopen("studentinfo.dat","a");
            if(stud==NULL) {
                printf("studentinfo.dat not found\n");
                return 1;
            }
            fwrite(&s1,sizeof(struct student),1,stud);
            fclose(stud);
            system("cls");
                printf("注册成功.即将跳转至登录页面\n");
                Sleep(2000);
                system("cls");
            goto ok;
            }
            else
            {
                system("cls");
                printf("账号已存在，请重新输入\n");
                Sleep(2000);
                system("cls");
                goto again;
            }
        }
        else if(c==2)
        {
            system("cls");
            printf("因为您选择注册，注册后自动跳转到登录界面；按下回车键以继续");
            getchar();
            struct teacher s1;
            system("cls");
            also:
            printf("账号：\n");
            scanf("%d",&s1.teaNo);
            getchar();
            if(compare2(s1.teaNo)==0)
            {
              printf("密码\n");
            scanf("%s",&s1.code[0]);
            getchar();
            teach=fopen("teacherinfo.dat","a");
            if(teach==NULL) {
                printf("teacherinfo.dat not found\n");
                return 1;
            }
            fwrite(&s1,sizeof(struct teacher),1,teach);
            fclose(teach);
            system("cls");
                printf("注册成功.即将跳转至登录页面\n");
                Sleep(2000);
                system("cls");
            goto ok;
            }
            else
            {
                system("cls");
                printf("账号已存在，请重新输入\n");
                Sleep(2000);
                system("cls");
                goto also;
            }
        }
        else
        {
            system("cls");
            printf("Sorry,input error");
        }
    }
    else if(a==2)
    {
        ok:
        printf("****************************\n");
        printf("*      学生登录请按1       *\n");
        printf("*      教师登录请按2       *\n");
        printf("****************************\n");
        int d;
        scanf("%d",&d);
        getchar();
        system("cls");
        if(d==1)
        {
            printf("账号：\n");
            int e;
            scanf("%d",&e);
            getchar();
            printf("密码：\n");
            char f[20];
            fgets(f,20,stdin);
            size_t len = strlen(f);
            if (len > 0 && f[len - 1] == '\n')
            {
                f[len - 1] = '\0';
            }
            if(comparestudent(e,f))
            {
                system("cls");
                printf("****登录成功****\n");
            }
            else
            {
                system("cls");
                printf("****登录失败****\n");
            }
        }
        else if(d==2)
        {
            printf("账号：\n");
            int g;
            scanf("%d",&g);
            getchar();
            printf("密码：\n");
            char h[20];
            fgets(h,20,stdin);
            size_t len = strlen(h);
            if (len > 0 && h[len - 1] == '\n')
            {
                h[len - 1] = '\0';
            }
            if(compareteacher(g,h))
            {
                system("cls");
                printf("登录成功\n");
                getchar();
            }
            else
            {
                system("cls");
                printf("登录失败\n");
                getchar();
            }
        }
        else
        {
            printf("Input error");
        }
    }
    else
    {
        printf("Input error");
        getchar();
        getchar();
    }
    fclose(stud);
    fclose(teach);
    return 0;
}
