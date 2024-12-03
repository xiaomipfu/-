#pragma once
#include  "std.h"
#include  "main.h"

#define N 100



//总学生个数
int n=0;

//成绩结构
typedef struct score{
    double Linux;
    double C;
    double shu;
    double zong;

}Score;


//学生结构包含姓名.学号.成绩.下标
typedef struct std{
    char name[50];
    int ID;
    Score score;
    int Idx;
   /*  Std* pNext; */
}Std;

Std Class[N];




//创造目录
void munu(){

    while (1)
    {
    int c;
    printf("-----华清学生成绩管理系统-------\n");
    printf("1.录入学生信息和成绩\n ");
    printf("2.所有学生成绩总分统计\n ");
    printf("3.各科成绩统计(总分和平均分)\n ");
    printf("4.学生学号查询成绩信息\n ");
    printf("5.学生按成绩总分排名\n ");
   
    printf("10.清屏\n ");
    printf("0.退出系统\n ");

    printf("请选择：");
    scanf("%d",&c);
    switch (c)
    {
    case 1:insertscore();       break;//学生成绩录入
    case 2:statscore();         break;//学生成绩统计
    case 3:statgrateSubjcet();  break;//各科成绩统计
    case 4:findByID();          break;//学生学号查询成绩信息
    case 5:rank();              break;//学生成绩排名
    case 10:sleep(3);    
            system("clear");    break;//清屏
    case 0:  return;
    
    default:printf("说啥嘞，给你一次机会重新说！！");  break;
    }
    }
    
   

}


//学生成绩录入
void insertscore(){
    printf("请输入要输入学生个数：");
    //新增学生个数
    int m;  
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        //分别为c，linux，数据结构
        double j,k,l;
        int f;  //学号
        char s[30]; //姓名
        printf("请输入第%d个学生的学号：",i+1);
        scanf("%d",&f);
        Class[n+i].ID=f;
        printf("请输入第%d个学生的姓名：",i+1);
        scanf("%s",s);
        strcpy(Class[n+i].name,s);
         printf("请输入第%d个学生C语言成绩：",i+1);
        scanf("%lf",&k);
        Class[n+i].score.C=k;
        printf("请输入第%d个学生linux成绩：",i+1);
        scanf("%lf",&j);
        Class[n+i].score.Linux=j;
        printf("请输入第%d个学生数据结构成绩：",i+1);
        scanf("%lf",&l);
        Class[n+i].score.shu=l;
        Class[i].score.zong=Class[i].score.C+Class[i].score.Linux+Class[i].score.shu;
    }
    //学生总个数
    n+=m; 

 test();

}

//学生成绩统计
void statscore(){
    for(int i=0;i<n;i++){
        printf("第%d个学生总分为%g\n",i+1,Class[i].score.zong);
    }

}


//各科成成绩统计
void statgrateSubjcet(){
    double lin=0,cyy=0,sjjg=0;//各科总成绩总分
    for(int i;i<n;i++){
        lin+=Class[i].score.Linux;
        cyy+=Class[i].score.C;
        sjjg+=Class[i].score.shu;
    }
    printf("C语言的总分为%g,班级平均分为%g。\n",lin,lin/n);
    printf("linux的总分为%g,班级平均分为%g。\n",lin,lin/n);
    printf("数据结构的总分为%g,班级平均分为%g。\n",lin,lin/n);
    
}





//测试
void test(){

    for(int i=1;i<=n;i++){
    printf("第%d个学生的C语言是%g分\n",i,Class[i-1].score.C);


    printf("第%d个学生的linux是%g分\n",i,Class[i-1].score.Linux);


    printf("第%d个学生的数据结构是%g分\n",i,Class[i-1].score.shu);

    printf("第%d个学生的总分是%g分\n",i,Class[i-1].score.zong);
    }
}


//学生学号查询成绩信息
void findByID(){
     printf("请输入要查询学生的学号：");
     int s;
     scanf("%d",&s);
     for(int i=0;i<n;i++){
        if(Class[i].ID == s){
            printf("找到了！\n");
            printf("%-10s%-10s%-15s%-15s%-15s%-15s\n","姓名","学号","C语言""linux基础","数据结构","总分");
            printf("%-10s%-10d%-15g%-15g%-15g%-15g\n",Class[i].name,Class[i].ID,
            Class[i].score.C,Class[i].score.Linux,Class[i].score.shu,Class[i].score.zong);
            break;
        }
     }
     /*  printf("没找到，请重试！\n");//else 没找到 */

}


//学生成绩排名
void rank(){
    double max=0;
    /* Std a[N];//创造一个数组把成绩排好序存进去，再依次释放打印出来 */
    Std temp;
    //冒泡排序进行从小到大排序
    for(int i=0;i<n-1;i++){
        for(int s=0;s<n-i-1;s++){
            if(Class[s].score.zong>Class[s+1].score.zong){
                temp=Class[s+1];
                Class[s+1]=Class[s];
                Class[s]=temp;
            }
        }
      
    }
    printf("%-10s%-10s%-15s%-15s%-15s%-15s\n","姓名","学号","C语言""linux","数据结构","总分");
    for(int i=0;i<n;i++){
        printf("%-10s%-10d%-15g%-15g%-15g%-15g\n",Class[i].name,Class[i].ID,
            Class[i].score.C,Class[i].score.Linux,Class[i].score.shu,Class[i].score.zong);

    }
}






