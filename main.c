#include"login system.c"
#include"meau.c"
#include"choseclass.c"
#include<windows.h>
int main() {
    SetConsoleOutputCP(65001);
  int No=-1,style=-1,meau=0;
  login(&No,&style);
  Sleep(1000);
  system("cls");
    meau:
  if(style==0){
      system("cls");
      meau=meau1();
      if(meau==1){
            system("cls");
          printf("请输入您想选的课程id");
          int a;
          scanf("%d",&a);
          writeEnrollmentsToFile(No,a);
          Sleep(1000);
          system("cls");
          goto meau;
      }
      if(meau==2){
          struct student student=readEnrollmentsFromFile(No);
          for (int i=0;i<student.num;i++)
          {
              struct Course course=readCoursesFromFile(student.courseCode[i]);
              printf("课程ID:%d 课程名称:%s 课程性质:%s 课程学期:%d学期 课程学分:%f学分\n",course.id,course.name,course.nature,course.term,course.credits);
          }
          getchar();
          system("cls");
          goto meau;
      }
      if(meau==3){
          int num=0,flag=10;
          system("cls");
          struct Course course;
          FILE *f=fopen("classinfo.dat","rb");
          while (fread(&course,sizeof(course),1,f)==1)
          {
              num++;
          }
          fclose(f);
          int num2=num;
          to:
          printf("共有%d个课程数据\n",num);
          f=fopen("classinfo.dat","rb");
          while (flag>0)
          {
              fread(&course,sizeof(course),1,f);
              flag--;
              printf("课程ID:%d 课程名称:%s 课程性质:%s 课程学期:%d学期 课程学分:%f学分\n",course.id,course.name,course.nature,course.term,course.credits);
              num2--;
              if (num2==0)
              {
                  break;
              }
          }
          printf("如果你想要退出；按下x键\n");
          printf("下一页；按下d键\n");
          printf("上一页；按下s键");
          char tuichu;
          scanf("%c",&tuichu);
          if(tuichu=='x')
          {
              flag=10;
              goto meau;
          }
          else if(tuichu=='d')
          {
              flag=10;
              num2-=10;
              goto to;
          }
          else
          {
              flag=10;
              fseek(f,-10*(signed long)sizeof(struct Course),SEEK_CUR);
              num2+=10;
              goto to;
          }
      }
      if (meau==4)
      {
          system("cls");
          queryModule();
          system("cls");
          goto meau;
      }
      if(meau==5){
          FILE *stu=fopen("studentinfo.dat","rb+");
          if(stu==NULL)
          {
              system("cls");
              exit(6);
          }
          struct student student;
          fseek(stu, 0, SEEK_SET);
          do
          {
              fread(&student,sizeof(student),1,stu);
              if (student.stuNo==No)
              {
                  system("cls");
                  printf("学号:%d\n",student.stuNo);
                  printf("密码:%s\n",student.code);
                  printf("修改密码请输入c");
                  char a;
                  scanf("%c",&a);
                  getchar();
                  if(a=='c')                        //修改密码
                  {
                      system("cls");
                      printf("请输入新密码：\n");
                      gets(student.code);
                      fseek(stu,(unsigned int)-sizeof(struct student),SEEK_CUR);
                      fwrite(&student,sizeof(struct student),1,stu);
                  }
                  fclose(stu);
                  goto meau;
              }
          }while (1);

      }
      else{
          exit(0);
      }
  }
  else if(style==1){
      system("cls");
      meau=meau2();
      if(meau==1){
          system("cls");
          struct student student;
          a:
          printf("请输入学生号：");
          scanf("%d",&student.stuNo);
          getchar();
          if(compare1(student.stuNo)==0)
          {
              printf("学生账号创建成功！");
              printf("初始密码为123456,请尽快更改。");
              printf("\n");
              Sleep(1000);
              system("cls");
              student.num=0;
              strcpy(student.code,"123456");
              FILE *stud=fopen("studentinfo.dat","a");
              fwrite(&student,sizeof(struct student),1,stud);
              fclose(stud);
              goto meau;
          }
          printf("学生账号已存在！\n请重新输入！");
          Sleep(1000);
          goto a;
      }
      if(meau==2){
          system("cls");
          writeCoursesToFile();
          system("cls");
          goto meau;
      }
      if(meau==3){
          int num=0,flag=10;
          system("cls");
          struct Course course;
          FILE *f=fopen("classinfo.dat","rb");
          while (fread(&course,sizeof(course),1,f)==1)
          {
              num++;
          }
          fclose(f);
          int num2=num;
          to2:
          printf("共有%d个课程数据\n",num);
          f=fopen("classinfo.dat","rb");
          while (flag>0)
          {
              fread(&course,sizeof(course),1,f);
              flag--;
              printf("课程ID:%d 课程名称:%s 课程性质:%s 课程学期:%d学期 课程学分:%f学分\n",course.id,course.name,course.nature,course.term,course.credits);
              num2--;
              if (num2==0)
              {
                  break;
              }
          }
          printf("如果你想要退出；按下x键\n");
          printf("下一页；按下d键\n");
          printf("上一页；按下s键");
          char tuichu;
          scanf("%c",&tuichu);
          if(tuichu=='x')
          {
              flag=10;
              goto meau;
          }
          else if(tuichu=='d')
          {
              flag=10;
              num2-=10;
              goto to2;
          }
          else
          {
              flag=10;
              fseek(f,-10*(signed long)sizeof(struct Course),SEEK_CUR);
              num2+=10;
              goto to2;
          }
      }
      if (meau==4)
      {
          system("cls");
          queryModule();
          getchar();
          system("cls");
          goto meau;
      }
      if(meau==5){
          FILE *stu=fopen("teacherinfo.dat","rb+");
          if(stu==NULL)
          {
              system("cls");
              exit(6);
          }
          struct teacher teacher;
          fseek(stu, 0, SEEK_SET);
          do
          {
              fread(&teacher,sizeof(teacher),1,stu);
              if (teacher.teaNo==No)
              {
                  system("cls");
                  printf("学号:%d\n",teacher.teaNo);
                  printf("密码:%s\n",teacher.code);
                  printf("修改密码请输入c");
                  char a;
                  scanf("%c",&a);
                  getchar();
                  if(a=='c')                        //修改密码
                  {
                      system("cls");
                      printf("请输入新密码：\n");
                      gets(teacher.code);
                      fseek(stu,(unsigned int)-sizeof(struct teacher),SEEK_CUR);
                      fwrite(&teacher,sizeof(struct teacher),1,stu);
                  }
                  fclose(stu);
                  goto meau;
              }
          }while (1);
      }
      else{
          exit(0);
      }
  }
  else{
      printf("error");
      exit(6);
  }
  return 0;
}
