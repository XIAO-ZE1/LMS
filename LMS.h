#ifndef __LMS_H
#define __LMS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h> /*控制台输入输出函数*/

/*宏定义区*/
#define ADMIN_password "123456"  /*管理员登录密码*/
#define MAX_ITEMS 100            // 结构体数组最大条目数
#define MEMFILE "infomember.txt" // 会员数据文件名
#define MBFILE "memberbook.txt"  // 借阅数据文件名
#define LIBFILE "library.txt"    // 图书数据文件名

/*结构体声明区*/
typedef struct bookinfo /*系统图书信息 */
{
    char number[15];   /*图书编号*/
    char name[30];     /*图书名称*/
    char author[20];   /*作者*/
    char press[30];    /*出版社*/
    char category[20]; /*类别*/
    float price;       /*单价*/
    int quantity;      /*馆藏量*/
    int time;          /*借书次数*/
} BOOKINFO;

typedef struct bookgrasp /*会员借出的书籍信息*/
{
    char number[15];   /*图书编号*/
    char name[30];     /*图书名称*/
    char author[20];   /*作者*/
    char press[30];    /*出版社*/
    char category[20]; /*类别*/
    float price;       /*单价*/
    char account[30];  /*借书者ID*/
} BOOKGRASP;

typedef struct member /*会员个人信息 */
{
    char name[30];         /*姓名*/
    char ID[20];           /*会员ID*/
    char password[30];     /*会员密码*/
    char sex[15];          /*性别*/
    char password_key[30]; /*秘钥*/
} MEMBER;

// 函数的声明

/* 菜单相关函数 */
void menu1();
void menu2();
void menu3();

/*会员信息系统函数*/
int user_account(char account[20]);       /*个人账户信息*/
void member_log_up();                     /*会员注册函数*/
int member_log_in(char account[20]);      /*会员登录函数*/
void ADMIN_watch_member();                /*查看会员信息函数*/
void display_memberbook();                /*查看所有图书借阅信息函数*/
int check_repeat_ID(char id_account[20]); /*检查账户重复性函数*/
void find_account();                      /*账户找回函数*/
int compare_password(char password[20]);  /*密码比对函数 */
void password_circle();                   /*密码框装饰函数*/
void find_account_circle();               /*找回帐户弹出框函数*/
void clock_delay();                       /*时间延时函数*/

/*图书信息系统函数*/
void add_book();     /*增:输入添加图书信息*/
void delete_book();  /*删:以图书名称删除图书信息*/
void modify_book();  /*改:修改图书信息*/
void display_book(); /*显:显示全部图书信息*/
void search_book();  /*查:根据图书名称显示图书的信息*/

void borrow_book(char account[20]); /*借书*/
void return_book(char account[20]); /*还书*/
void display_price_lower();         /*排序:根据价格列出图书信息*/
void dispaly_popular();             /*排序:图书受欢迎度排行榜*/

int check_repeat_book(char number[30]); /*查重书籍编号*/

#endif