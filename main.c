/**********************************************
�����ţ�01-1.1
�������ƣ�ͼ�����ϵͳ   Library Management System
�����ܣ�
�������룺ͼ����Ϣ�����ļ� ��Ա��Ϣ�����ļ� ������Ϣ�����ļ�
����������Գ�����ʵ�ֵ���Ļ��ʾ���
����Ա��
���ʱ�䣺5.1-5.5
�޸��ˣ�
�޸�ʱ�䣺
�汾�ţ�V1.0

�ļ�����ԭ��
1. main.c - �����������ͳ������
2. menu.c - �������в˵���صĺ���
3. user_operations.c - �����û�������غ���
4. book_operations.c - ����ͼ����Ϣ��ɾ�Ĳ麯��
5. LMS.h - ����������ݽṹ����ͺ�������
*************************************************

/*�Կ⺯���Ķ���*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LMS.h"

/* ϵͳ����������ʼ�������õȹ��� */

int main()
{
    /* �������ݽṹ */
    // ����ṹ�����飬�������һֱ��Ϊ��������Ҫ�ĺ���֮�䴫��
    MEMBER member[MAX_ITEMS];
    BOOKGRASP bookgrasp[MAX_ITEMS];
    BOOKINFO bookinfo[MAX_ITEMS];

    // �洢��Ա���� ���������һֱ��Ϊ��������Ҫ�ĺ���֮�䴫��

    int flag1 = 1, flag2 = 1, flag3 = 1; /* flag���ж�����,flagΪ 1 ʱΪ�棬Ϊ 0 ʱΪ�� */
    char choice1, choice2, choice3;

    system("title ���-ͼ�����ϵͳ");

    FILE *p1, *p2, *p3;
    // ��������ļ���LIBFILE��MEMFILE �� MBFILE���Ƿ���ڣ�����������򴴽����ǡ�
    if ((p1 = fopen(LIBFILE, "r")) == NULL) /*p1��ͼ�����ϵͳ���鼮��Ϣ�ļ�ָ��*/
    {
        p1 = fopen(LIBFILE, "w");
        fclose(p1);
    }
    if ((p2 = fopen(MEMFILE, "r")) == NULL) /*p2��ͼ�����ϵͳ�Ļ�Ա������Ϣ�ļ�ָ��*/
    {
        p2 = fopen(MEMFILE, "w");
        fclose(p2);
    }
    if ((p3 = fopen(MBFILE, "r")) == NULL) /*p3��ͼ�����ϵͳ�Ļ�Ա�鼮��Ϣ�ļ�ָ��*/
    {
        p3 = fopen(MBFILE, "w");
        fclose(p3);
    }

    while (flag1)
    {
        system("cls");
        menu1(); /*�������˵� */

        printf("\n");
        printf("����ѡ��(1-4):");
        choice1 = getch();
        while (choice1 != '1' && choice1 != '2' && choice1 != '3' && choice1 != '4')
            choice1 = getch(); /*��������ѡ���1-4֮�䣬����������*/
        printf("%c", choice1); 
        fflush(stdin); 

        if (choice1 == '1') /*��Ա��¼*/
        {
            int flag = 0;
            char account1[20], account_choice;
            system("cls");
            password_circle();
            fflush(stdin);
            gets(account1);
            flag = member_log_in(account1); /*�˻���¼����*/
            if (flag == 2)
            {
                system("cls");
                password_circle();
                fflush(stdin);
                gets(account1);
                flag = member_log_in(account1); /*�˻���¼����*/
            }
            if (flag == 1)
            {
                while (flag2 && flag3)
                {
                    system("cls");
                    menu2();
                    printf("\n");
                    printf("����ѡ��(1-8):");
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
                            printf("\n\n\t\t\t��¼��Ϣ�ı䣬�����µ�¼...");
                            clock_delay();
                            flag3 = 0;
                        }
                        break;
                    case '8':
                        flag2 = 0;
                        printf("\n\n\t\t\t�����˳��û�����...");
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
                find_account_circle(); /*װ�ε�������*/
                fflush(stdin);
                account_choice = getch();
                while (account_choice != 'Y' && account_choice != 'y' && account_choice != 'N' && account_choice != 'n')
                    account_choice = getch();
                printf("%c", account_choice);
                printf("\n");
                if (account_choice == 'Y' || account_choice == 'y')
                    find_account(); /*�˻��һغ���*/
            }
            flag2 = 1, flag3 = 1;
        }

        else if (choice1 == '2') /*��Աע��*/
        {
            system("cls");
            printf("\n\n\n\t\t\t���ڽ����û�ע�����...");
            clock_delay();
            member_log_up();
        }

        else if (choice1 == '3') /*����Ա��¼*/
        {
            if (compare_password(ADMIN_password))
            {
                printf("\n\n\t\t\t\t  --����������ȷ!--\n\n\t\t\t\t==���ڽ������Ա����==\n");
                clock_delay();
                while (flag2)
                {
                    system("cls");
                    menu3();
                    printf("\n");
                    printf("����ѡ��(1-8):");
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
                        printf("\n\n\t\t\t�����˳�����Ա����...");
                        clock_delay();
                        break;
                    default:
                        break;
                    }
                }
            }
            else
            {
                printf("\n\n\t\t\t\t  --�����������!--\n");
                clock_delay();
            }
            flag2 = 1;
        }

        else if (choice1 == '4') /*�˳�ϵͳ*/
        {
            flag1 = 0;
        }
    }
    fflush(stdin); /*������뻺����*/
    system("cls");
    printf("���Ѿ��˳�ϵͳ!(��������رս���)\n\n\t");
    getch();
    return 0;
}