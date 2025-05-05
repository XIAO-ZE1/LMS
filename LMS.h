#ifndef __LMS_H
#define __LMS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <conio.h> /*����̨�����������*/

/*�궨����*/
#define ADMIN_password "123456"  /*����Ա��¼����*/
#define MAX_ITEMS 100            // �ṹ�����������Ŀ��
#define MEMFILE "infomember.txt" // ��Ա�����ļ���
#define MBFILE "memberbook.txt"  // ���������ļ���
#define LIBFILE "library.txt"    // ͼ�������ļ���

/*�ṹ��������*/
typedef struct bookinfo /*ϵͳͼ����Ϣ */
{
    char number[15];   /*ͼ����*/
    char name[30];     /*ͼ������*/
    char author[20];   /*����*/
    char press[30];    /*������*/
    char category[20]; /*���*/
    float price;       /*����*/
    int quantity;      /*�ݲ���*/
    int time;          /*�������*/
} BOOKINFO;

typedef struct bookgrasp /*��Ա������鼮��Ϣ*/
{
    char number[15];   /*ͼ����*/
    char name[30];     /*ͼ������*/
    char author[20];   /*����*/
    char press[30];    /*������*/
    char category[20]; /*���*/
    float price;       /*����*/
    char account[30];  /*������ID*/
} BOOKGRASP;

typedef struct member /*��Ա������Ϣ */
{
    char name[30];         /*����*/
    char ID[20];           /*��ԱID*/
    char password[30];     /*��Ա����*/
    char sex[15];          /*�Ա�*/
    char password_key[30]; /*��Կ*/
} MEMBER;

// ����������

/* �˵���غ��� */
void menu1();
void menu2();
void menu3();

/*��Ա��Ϣϵͳ����*/
int user_account(char account[20]);       /*�����˻���Ϣ*/
void member_log_up();                     /*��Աע�ắ��*/
int member_log_in(char account[20]);      /*��Ա��¼����*/
void ADMIN_watch_member();                /*�鿴��Ա��Ϣ����*/
void display_memberbook();                /*�鿴����ͼ�������Ϣ����*/
int check_repeat_ID(char id_account[20]); /*����˻��ظ��Ժ���*/
void find_account();                      /*�˻��һغ���*/
int compare_password(char password[20]);  /*����ȶԺ��� */
void password_circle();                   /*�����װ�κ���*/
void find_account_circle();               /*�һ��ʻ���������*/
void clock_delay();                       /*ʱ����ʱ����*/

/*ͼ����Ϣϵͳ����*/
void add_book();     /*��:�������ͼ����Ϣ*/
void delete_book();  /*ɾ:��ͼ������ɾ��ͼ����Ϣ*/
void modify_book();  /*��:�޸�ͼ����Ϣ*/
void display_book(); /*��:��ʾȫ��ͼ����Ϣ*/
void search_book();  /*��:����ͼ��������ʾͼ�����Ϣ*/

void borrow_book(char account[20]); /*����*/
void return_book(char account[20]); /*����*/
void display_price_lower();         /*����:���ݼ۸��г�ͼ����Ϣ*/
void dispaly_popular();             /*����:ͼ���ܻ�ӭ�����а�*/

int check_repeat_book(char number[30]); /*�����鼮���*/

#endif