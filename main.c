/**********************************************
程序编号：01-1.1
程序名称：图书管理系统   Library Management System
程序功能：
程序输入：图书信息数据文件 会员信息数据文件 借阅信息数据文件
程序输出：对程序功能实现的屏幕显示输出
程序员：
编程时间：5.1-5.5
修改人：
修改时间：
版本号：V1.0

文件划分原则：
1. main.c - 包含主函数和程序入口
2. menu.c - 包含所有菜单相关的函数
3. user_operations.c - 包含用户操作相关函数
4. book_operations.c - 包含图书信息增删改查函数
5. LMS.h - 存放所有数据结构定义和函数声明
*************************************************

/*对库函数的定义*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LMS.h"

/* 系统主函数，初始化，调用等功能 */

int main()
{
    /* 基本数据结构 */
    // 定义结构体数组，这个数组一直作为参数在需要的函数之间传递
    MEMBER member[MAX_ITEMS];
    BOOKGRASP bookgrasp[MAX_ITEMS];
    BOOKINFO bookinfo[MAX_ITEMS];

    // 存储会员个数 ，这个个数一直作为参数在需要的函数之间传递

    int flag1 = 1, flag2 = 1, flag3 = 1; /* flag是判断条件,flag为 1 时为真，为 0 时为假 */
    char choice1, choice2, choice3;

    system("title 电科-图书管理系统");

    FILE *p1, *p2, *p3;
    // 检查三个文件（LIBFILE、MEMFILE 和 MBFILE）是否存在，如果不存在则创建它们。
    if ((p1 = fopen(LIBFILE, "r")) == NULL) /*p1是图书管理系统的书籍信息文件指针*/
    {
        p1 = fopen(LIBFILE, "w");
        fclose(p1);
    }
    if ((p2 = fopen(MEMFILE, "r")) == NULL) /*p2是图书管理系统的会员个人信息文件指针*/
    {
        p2 = fopen(MEMFILE, "w");
        fclose(p2);
    }
    if ((p3 = fopen(MBFILE, "r")) == NULL) /*p3是图书管理系统的会员书籍信息文件指针*/
    {
        p3 = fopen(MBFILE, "w");
        fclose(p3);
    }

    while (flag1)
    {
        system("cls");
        menu1(); /*调出主菜单 */

        printf("\n");
        printf("请您选择(1-4):");
        choice1 = getch();
        while (choice1 != '1' && choice1 != '2' && choice1 != '3' && choice1 != '4')
            choice1 = getch(); /*如果输入的选项不在1-4之间，则重新输入*/
        printf("%c", choice1); 
        fflush(stdin); 

        if (choice1 == '1') /*会员登录*/
        {
            int flag = 0;
            char account1[20], account_choice;
            system("cls");
            password_circle();
            fflush(stdin);
            gets(account1);
            flag = member_log_in(account1); /*账户登录函数*/
            if (flag == 2)
            {
                system("cls");
                password_circle();
                fflush(stdin);
                gets(account1);
                flag = member_log_in(account1); /*账户登录函数*/
            }
            if (flag == 1)
            {
                while (flag2 && flag3)
                {
                    system("cls");
                    menu2();
                    printf("\n");
                    printf("请您选择(1-8):");
                    choice2 = getch();
                    while (choice2 != '1' && choice2 != '2' && choice2 != '3' && choice2 != '4' && choice2 != '5' && choice2 != '6' && choice2 != '7' && choice2 != '8')
                        choice2 = getch();
                    printf("%c", choice2);

                    switch (choice2)
                    {
                    case '1':
                        search_book();
                        break;
                    case '2':
                        borrow_book(account1);
                        break;
                    case '3':
                        return_book(account1);
                        break;
                    case '4':
                        display_book();
                        break;
                    case '5':
                        display_price_lower();
                        break;
                    case '6':
                        dispaly_popular();
                        break;
                    case '7':
                        if (user_account(account1))
                        {
                            printf("\n\n\t\t\t登录信息改变，请重新登录...");
                            clock_delay();
                            flag3 = 0;
                        }
                        break;
                    case '8':
                        flag2 = 0;
                        printf("\n\n\t\t\t正在退出用户界面...");
                        clock_delay();
                        break;
                    default:
                        break;
                    }
                }
            }
            else
            {
                system("cls");
                find_account_circle(); /*装饰弹出框函数*/
                fflush(stdin);
                account_choice = getch();
                while (account_choice != 'Y' && account_choice != 'y' && account_choice != 'N' && account_choice != 'n')
                    account_choice = getch();
                printf("%c", account_choice);
                printf("\n");
                if (account_choice == 'Y' || account_choice == 'y')
                    find_account(); /*账户找回函数*/
            }
            flag2 = 1, flag3 = 1;
        }

        else if (choice1 == '2') /*会员注册*/
        {
            system("cls");
            printf("\n\n\n\t\t\t正在进入用户注册界面...");
            clock_delay();
            member_log_up();
        }

        else if (choice1 == '3') /*管理员登录*/
        {
            if (compare_password(ADMIN_password))
            {
                printf("\n\n\t\t\t\t  --输入密码正确!--\n\n\t\t\t\t==正在进入管理员界面==\n");
                clock_delay();
                while (flag2)
                {
                    system("cls");
                    menu3();
                    printf("\n");
                    printf("请您选择(1-8):");
                    choice3 = getch();
                    while (choice3 != '1' && choice3 != '2' && choice3 != '3' && choice3 != '4' && choice3 != '5' && choice3 != '6' && choice3 != '7' && choice3 != '8')
                        choice3 = getch();
                    printf("%c", choice3);

                    switch (choice3)
                    {
                    case '1':
                        add_book();
                        break;
                    case '2':
                        delete_book();
                        break;
                    case '3':
                        modify_book();
                        break;
                    case '4':
                        search_book();
                        break;
                    case '5':
                        display_book();
                        break;
                    case '6':
                        ADMIN_watch_member();
                        break;
                    case '7':
                        display_memberbook();
                        break;
                    case '8':
                        flag2 = 0;
                        printf("\n\n\t\t\t正在退出管理员界面...");
                        clock_delay();
                        break;
                    default:
                        break;
                    }
                }
            }
            else
            {
                printf("\n\n\t\t\t\t  --输入密码错误!--\n");
                clock_delay();
            }
            flag2 = 1;
        }

        else if (choice1 == '4') /*退出系统*/
        {
            flag1 = 0;
        }
    }
    fflush(stdin); /*清空输入缓冲区*/
    system("cls");
    printf("你已经退出系统!(按任意键关闭界面)\n\n\t");
    getch();
    return 0;
}