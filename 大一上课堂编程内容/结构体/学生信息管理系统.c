/*创建学生信息管理系统，具体要求如下：

学生信息包括：学号 姓名 数学成绩 英语成绩 计算机成绩

功能1：添加学生信息
执行1时，输入学号，姓名，三门科目成绩；如果添加学生成功则输出“Add success”，如果学生已存在则输出“Students already exist”

功能2：删除学生信息
执行2时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，则输出“Delete success”

功能3：更改学生成绩信息
执行3时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，输出“Update success”

功能4：显示学生平均分成绩
执行4时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，则输出学生信息，如下格式：

Student ID:2019989890

Name:Jerry

Average Score:89.3

其中平均分为三门科目相加除以3，保留一位小数，每行之间换行。

输入格式:
第一行为一个整数n(0<n<130)，后边共n行，每一行表示执行一种功能。其中1，2，3，4分别对应执行上面4种功能，具体格式见输入样例。
测试用例保证：学号和名字均为长度不超过10的字符串，各门课成绩为0到100之间的整数。
特别提醒：当执行更改学生成绩操作时，无论学生是否存在，你的程序都要读入那三个成绩。否则会影响后续的输入。

输出格式:
输入样例:
8
1 201817123 Tom 89 80 76
1 2019989890 Jerry 78 99 67
4 201817123
2 201817123
4 201817123
4 2019989890
3 2019989890 79 90 99
4 2019989890

输出样例:
Add success
Add success
Student ID:201817123
Name:Tom
Average Score:81.7
Delete success
Students do not exist
Student ID:2019989890
Name:Jerry
Average Score:81.3
Update success
Student ID:2019989890
Name:Jerry
Average Score:89.3*/
#include<stdio.h>
#include<string.h>
typedef struct {
    char xu[15];
    char name[15];
    int score[3];
}stu;
int add_student(stu *a,int j){
    int i,x=0;
    char id[15], name[15];
    int scores[3];
    scanf("%s %s %d %d %d",id, name, &scores[0], &scores[1], &scores[2]);
    for(i=0;i<j;i++){
        if(strcmp(id, a[i].xu)==0){
            x=1;
            break;
        }
    }
    if(x==0||j==0){
        strcpy(a[j].xu, id);
        strcpy(a[j].name, name);
        a[j].score[0] = scores[0];
        a[j].score[1] = scores[1];
        a[j].score[2] = scores[2];
        printf("Add success\n");
        j++;
    }
    else printf("Students already exist\n");
    return j;
}
void delete_student(stu *a,int j){
    int i,x=0;
    char id[15]={0};
    scanf("%s",id);
    for(i=0;i<j;i++){
        if(strcmp(id,(a+i)->xu)==0&& a[i].xu[0]!='\0'){
            x=1;
            a[i].xu[0]='\0';
            a[i].name[0]='\0';
            break;
        }
    }
    if(x==1)printf("Delete success\n");
    else printf("Students do not exist\n");
}
void update_student(stu *a,int j){
    int i,k,x=0;
    char id[15];
    scanf("%s",id);
    int scores[3];
    for(i=0;i<3;i++){
        scanf("%d",scores+i);
    }
    for(i=0;i<j;i++){
        if(strcmp((a+i)->xu,id)==0&& a[i].xu[0]!='\0'){
            x=1;
            break;
        }
    }
    if(x==1){
        a[i].score[0] = scores[0];
        a[i].score[1] = scores[1];
        a[i].score[2] = scores[2];
        printf("Update success\n");
    }
    else printf("Students do not exist\n");
}
void show_student(stu *a,int j){
    int i,k,x=0;
    float b=0.0;
    char id[15];
    scanf("%s",id);
    for(i=0;i<j;i++){
        if(strcmp((a+i)->xu,id)==0&& a[i].xu[0]!='\0'){
            x=1;
            break;
        }
    }
    if(x==1){
        printf("Student ID:%s\n",a[i].xu);
        printf("Name:%s\n",a[i].name);
        for(k=0;k<3;k++){
            b+=a[i].score[k];
        }
        printf("Average Score:%.1f\n",b/3.0);
    }
    else printf("Students do not exist\n");
}
int main(){
    int n,i,j=0,state;
    scanf("%d",&n);
    stu a[130];
    for(i=0;i<n;i++){
        scanf("%d",&state);
        switch(state){
            case 1:
                j=add_student(a,j);
                break;
            case 2:
                delete_student(a,j);
                break;
            case 3:
                update_student(a,j);
                break;
            case 4:
                show_student(a,j);
                break;
        }
    }
    return 0;
}

