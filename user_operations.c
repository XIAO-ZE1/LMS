#include "LMS.h"

void member_log_up() /*��Աע�ắ��*/
{
    char choice1, choice2;
    int flag = 1;
    FILE *p2;
    MEMBER member;

    while (1)
    {
        system("cls");
        fflush(stdin);

        printf("����ע��ID��:");
        gets(member.ID);

        if (check_repeat_ID(member.ID))
        {
            printf("��ID�ѱ�ע�ᣡ������ע��^_^\n");
            printf("�����������ע��\n\n");
            getch();
            flag = 1;
        }
        else
        {
            flag = 0;
            printf("��������:");
            gets(member.password);

            printf("�����һ��������Կ:");
            gets(member.password_key);

            printf("������������:");
            gets(member.name);

            printf("���������Ա�(��ʿmale,Ůʿfemale):");
            gets(member.sex);

            printf("�Ƿ񱣴����ע����Ϣ(y/n):");
            choice1 = getch();
            while (choice1 != 'Y' && choice1 != 'y' && choice1 != 'N' && choice1 != 'n')
                choice1 = getch();
            printf("%c", choice1);
            printf("\n");
            if (choice1 == 'Y' || choice1 == 'y')
            {
                p2 = fopen(MEMFILE, "a");
                fprintf(p2, "%s %s %s %s %s\n", member.ID, member.password, member.password_key, member.name, member.sex);
                fclose(p2);
                printf("\n�����˻���ע��ɹ���\n");
            }
            else
            {
                printf("\n����ע����Ϣδ����!\n");
            }
            printf("\n�Ƿ����ע���Ա(y/n):");
            choice2 = getch();
            while (choice2 != 'Y' && choice2 != 'y' && choice2 != 'N' && choice2 != 'n')
                choice2 = getch();
            printf("%c", choice2);
            printf("\n");
        }
        if (choice2 == 'Y' || choice2 == 'y' || flag == 1)
            continue;
        else
            break;
    }
}

int user_account(char account[20]) /*�û���Ϣ�Լ������޸ĺ���*/
{
    FILE *p2, *p3;
    int n, number, booknumber, flag = 0, i, flag2 = 1, count = 0;
    char new_password[20], key[30], choice;
    MEMBER member[MAX_ITEMS];
    BOOKGRASP bookgrasp[100];
    system("cls");

    p2 = fopen(MEMFILE, "r");
    number = 0;
    while (!feof(p2))
    {
        fscanf(p2, "%s %s %s %s %s\n", member[number].ID, member[number].password,
               member[number].password_key, member[number].name, member[number].sex);
        number++;
    }
    fclose(p2);

    p3 = fopen(MBFILE, "r");
    booknumber = 0;
    while (!feof(p3))
    {
        fscanf(p3, "%s %s %s %s %s %f %s\n",
               bookgrasp[booknumber].number, bookgrasp[booknumber].name, bookgrasp[booknumber].author, bookgrasp[booknumber].press,
               bookgrasp[booknumber].category, &bookgrasp[booknumber].price, bookgrasp[booknumber].account);
        booknumber++;
    }
    fclose(p3);
    if (bookgrasp[0].price <= 1e-8)
    {
        printf("��ǰͼ���δ���κν�����Ϣ");
        flag = 0;
        printf("\n\n�����������!\n");
        getch();
    }
    else
    {
        for (n = 0; n < number; n++)
            if (strcmp(member[n].ID, account) == 0)
            {
                i = 0;
                printf("\n");
                printf("|---------------------------������Ϣ-------------------------|\n");
                printf("|����        �Ա�      ID              ����                  |\n");
                printf("|%-12s%-10s%-16s%-22s%|\n", member[n].name, member[n].sex, member[n].ID, member[n].password);
                printf("|                                                            |\n");
                printf("|----------------------------ͼ�������Ϣ--------------------|\n");
                printf("|���  ����        ����      ������          ���    ����    |\n");

                while (i < booknumber)
                {
                    if (strcmp(bookgrasp[i].account, account) == 0)
                    {
                        printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n", bookgrasp[i].number,
                               bookgrasp[i].name, bookgrasp[i].author, bookgrasp[i].press,
                               bookgrasp[i].category, bookgrasp[i].price);
                        count++;
                    }
                    i++;
                }
                if (strcmp(member[n].sex, "male") == 0)
                    printf("\n%s����������ǰ���ĵ��鼮����%d����", member[n].name, count);
                else if (strcmp(member[n].sex, "female") == 0)
                    printf("\n%sŮʿ������ǰ���ĵ��鼮����%d����", member[n].name, count);
                else
                    printf("\n%s������ǰ���ĵ��鼮����%d����", member[n].name, count);

                if (bookgrasp[0].price <= 1e-8)
                    printf("\n��ͼ����ڹ���0���鼮���ڱ����ġ�\n");
                else
                    printf("\n��ͼ����ڹ���%d���鼮���ڱ����ġ�\n", booknumber);

                printf("\nPS:�Ƿ���Ҫ�޸�����(y/n):");
                fflush(stdin);
                choice = getch();
                while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                    choice = getch();
                printf("%c", choice);
                printf("\n");
                if (choice == 'Y' || choice == 'y')
                {
                    printf("\n�������޸��������Կ(user_key):");
                    fflush(stdin);
                    gets(key);
                    if (strcmp(member[n].password_key, key) == 0)
                    {
                        printf("�����������룺");
                        fflush(stdin);
                        gets(new_password);
                        strcpy(member[n].password, new_password);
                        flag = 1;
                        p2 = fopen(MEMFILE, "w");
                        for (n = 0; n < number; n++)
                            fprintf(p2, "%s %s %s %s %s\n", member[n].ID, member[n].password,
                                    member[n].password_key, member[n].name, member[n].sex);
                        fclose(p2);
                    }
                    else
                    {
                        printf("\n������Կ����!");
                    }
                }
                else
                    flag = 0;
            }
    }
    if (flag == 1)
    {
        printf("\n�����޸ĳɹ���");
        printf("\n�����������!\n");
        getch();
        return 1;
    }
    else
    {
        return 0;
    }
}

void find_account() /*�˻��һغ���*/
{
    FILE *p2;
    MEMBER member[MAX_ITEMS];
    int number, n, k = 3, flag = 1, mark = 0;
    char choice = '0';
    char vacancy[10] = "";
    char search[30], compare[30], new_password[20];

    system("cls");
    fflush(stdin);
    printf("������������:");
    gets(search);
    p2 = fopen(MEMFILE, "r");
    number = 0;
    while (!feof(p2))
    {
        fscanf(p2, "%s %s %s %s %s\n", member[number].ID, member[number].password, member[number].password_key, member[number].name, member[number].sex);
        number++;
    }
    fclose(p2);
    if (strcmp(member[0].ID, vacancy) == 0)
    {
        printf("ϵͳ�л�û���κλ�Ա��Ϣ!\n\n");
    }
    else
    {
        for (n = 0; n < number; n++)
            if (strcmp(member[n].name, search) == 0)
            {
                mark = 1;
                while (flag)
                {
                    printf("������������Կ:");
                    fflush(stdin);
                    gets(compare);
                    if (strcmp(member[n].password_key, compare) == 0)
                    {
                        printf("\n");
                        printf("|------------------------------������Ϣ------------------------------|\n");
                        printf("|����        �Ա�      ID                  ����	                     |\n");
                        printf("|%-12s%-10s%-20s%-26s%|\n", member[n].name, member[n].sex, member[n].ID, member[n].password);

                        printf("\n�Ƿ���Ҫ�޸�����(y/n):");
                        fflush(stdin);
                        choice = getch();
                        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                            choice = getch();
                        printf("%c", choice);
                        printf("\n");
                        if (choice == 'Y' || choice == 'y')
                        {
                            printf("\n�����������룺");
                            fflush(stdin);
                            gets(new_password);
                            strcpy(member[n].password, new_password);
                            flag = 0;
                        }
                        else
                            flag = 0;
                    }
                    else
                    {
                        --k; /*�����������count*/
                        if (k != 0)
                        {
                            printf("\n\n\n\t\t����������������!\n\t\t������%d�λ��������������룡", k);
                            printf("���Ƿ�Ҫ������������(y/n):");
                            fflush(stdin);
                            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                                choice = getch();
                            printf("%c", choice);
                            printf("\n");
                            if (choice == 'Y' || choice == 'y')
                                flag = 1;
                            else
                                flag = 0;
                        }
                        else
                        {
                            printf("��������������꣡�����˻�������...");
                            flag = 0;
                        }
                    }
                }
            }
    }
    if (mark == 0)
    {
        printf("����δע�᱾ϵͳ��Ա!\n");
    }
    else
    {
        if (choice != '0' && choice != 'n' && choice != 'N')
        {
            p2 = fopen(MEMFILE, "w");
            for (n = 0; n < number; n++)
                fprintf(p2, "%s %s %s %s %s\n", member[n].ID, member[n].password,
                        member[n].password_key, member[n].name, member[n].sex);
            fclose(p2);
            printf("���ѳɹ��һ�/�޸��˻�!\n");
        }
    }
    printf("\n\n��������ص����˵�!\n");
    fflush(stdin);
    getch();
}

int member_log_in(char account[15]) /*��Ա��¼����*/
{
    FILE *p2;
    MEMBER member[MAX_ITEMS];
    char choice1, choice2;
    int flag1 = 0, flag2 = 1, n, k = 3;
    int number;

    p2 = fopen(MEMFILE, "r");
    number = 0;
    while (!feof(p2))
    {
        fscanf(p2, "%s %s %s %s %s\n", member[number].ID, member[number].password,
               member[number].password_key, member[number].name, member[number].sex);
        number++;
    }
    fclose(p2);
    for (n = 0; n < number; n++)
        if (strcmp(member[n].ID, account) == 0)
        {
            flag1 = 1;
            break;
        }
    if (flag1)
    {
        while (flag2)
        {
            if (compare_password(member[n].password)) /* ���û�Ա����ȶԺ��� */
            {
                printf("\n\n\n\t\t\t   �˶���ȷ�����ڽ����Ա����...");
                clock_delay();
                return 1;
            }
            else
            {
                --k; /*�����������count*/
                if (k != 0)
                {
                    printf("\n\n\n\t\t\t   ����������������!����%d�λ��������������룡", k);
                    printf("\n\t\t\t   ���Ƿ�Ҫ������������(y/n):");
                    fflush(stdin);
                    choice1 = getch();
                    while (choice1 != 'Y' && choice1 != 'y' && choice1 != 'N' && choice1 != 'n')
                        choice1 = getch();
                    printf("%c", choice1);
                    printf("\n");
                    if (choice1 == 'Y' || choice1 == 'y')
                        flag2 = 1;
                    else
                        return 0;
                }
                else
                {
                    printf("\n\n\t\t\t   ��������������꣡��������˳�...");
                    fflush(stdin);
                    getch();
                    return 0;
                }
            }
        }
        flag2 = 1;
    }
    else
    {
        printf("\n\n\n\t\t\t  ��ID��δע��,�Ƿ���Ҫע���Ա(y/n):");
        choice2 = getch();
        while (choice2 != 'Y' && choice2 != 'y' && choice2 != 'N' && choice2 != 'n')
            choice2 = getch();
        printf("%c", choice2);
        printf("\n");
        if (choice2 == 'Y' || choice2 == 'y')
        {
            member_log_up();
            return 2;
        }
        else
            return 0;
    }
}

int compare_password(char *password) /*����ȶԺ��� */
{
    int i = 0;
    char compare[20], c;
    fflush(stdin);
    printf("\n\t\t\t   ����(password):");
    while ((c = getch()) != 13) //\r�ǽ�����Ƶ�������λ
    {
        if (c == 8 && i > 0)
        {
            printf("\b \b"); // ���*�źʹ��
            i--;
            continue;
        }
        if (c != 8)
        {
            compare[i++] = c;
            putchar('*');
        }
    }
    compare[i] = '\0';
    if (strcmp(password, compare) == 0)
    {
        printf("\a"); // ����
        return 1;
    }
    else
    {
        printf("\a"); // ����
        return 0;
    }
}

int check_repeat_ID(char *id_account) /*���غ���*/
{
    FILE *p2;
    MEMBER member[MAX_ITEMS];
    int flag1 = 0, flag2 = 1, n, number;

    p2 = fopen(MEMFILE, "r");
    number = 0;
    while (!feof(p2))
    {
        fscanf(p2, "%s %s %s %s %s\n", member[number].ID, member[number].password,
               member[number].password_key, member[number].name, member[number].sex);
        number++;
    }
    fclose(p2);
    for (n = 0; n < number; n++)
        if (strcmp(member[n].ID, id_account) == 0)
        {
            flag1 = 1;
            break;
        }
    if (flag1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void ADMIN_watch_member() /*�鿴��Ա��Ϣ����*/
{
    FILE *p2;
    MEMBER member[MAX_ITEMS];
    int n, number;
    system("cls");
    fflush(stdin);

    p2 = fopen(MEMFILE, "r");
    number = 0;
    while (!feof(p2))
    {
        fscanf(p2, "%s %s %s %s %s\n", member[number].ID, member[number].password, member[number].password_key, member[number].name, member[number].sex);
        number++;
    }
    fclose(p2);

    printf("ϵͳע���û���%dλ:", number);
    printf("\n\n");
    printf("|-----------------------��Ա��Ϣ-----------------------|\n");
    printf("|����      �Ա�    ID            ����  	         ��Կ  |\n");
    for (n = 0; n < number; n++)
        printf("|%-10s%-8s%-14s%-16s%-6s%|\n", member[n].name, member[n].sex, member[n].ID, member[n].password, member[n].password_key);

    printf("\n\n�������������һ���˵�!\n");
    getch();
}

void display_memberbook() /*�鿴����ͼ�������Ϣ����*/
{
    FILE *p3;
    BOOKGRASP bookgrasp[100];
    int booknumber, n;
    system("cls");

    p3 = fopen(MBFILE, "r");
    booknumber = 0;
    while (!feof(p3))
    {
        fscanf(p3, "%s %s %s %s %s %f %s\n", bookgrasp[booknumber].number, bookgrasp[booknumber].name, bookgrasp[booknumber].author, bookgrasp[booknumber].press, bookgrasp[booknumber].category, &bookgrasp[booknumber].price, bookgrasp[booknumber].account);
        booknumber++;
    }
    if (bookgrasp[0].price == 0.0)
        printf("��ǰû�н�����Ϣ");
    else
    {
        printf("��ǰ����%dλ��Ա�����鼮��", booknumber);
        printf("\n");
        printf("|---------------------------����ͼ����Ϣ-----------------------------------|\n");
        printf("|���  ����        ����      ������          ���    ����    ����ID        |\n");
        printf("|                                                                          |\n");
        for (n = 0; n < booknumber; n++)
            printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-14s|\n", bookgrasp[n].number, bookgrasp[n].name, bookgrasp[n].author, bookgrasp[n].press, bookgrasp[n].category, bookgrasp[n].price, bookgrasp[n].account);
    }
    printf("\n\n�������������...");
    fflush(stdin);
    getch();
}

void password_circle() /*������*/
{
    system("cls");
    printf("\n\n\n\t\t\t***================================*** \n");
    printf("\t\t\t                                   \n");
    printf("\t\t\t   �˻� (account):");
}

void find_account_circle() /*�һ��˻���������*/
{
    printf("\n\n\n\n");
    printf("\t\t\t===============H-E-L-P===================\n");
    printf("\t\t\t|                                       |\n");
    printf("\t\t\t* ���費��Ҫͨ����Կ�һ��˻���(����y/n) *\n");
    printf("\t\t\t|                                       |\n");
    printf("\t\t\t=========================================\n");
    printf("\n\t\t\t����ѡ����:");
}

void clock_delay()/*ʱ����ʱ����*/
{
	clock_t tm;
	tm=clock();
    while(clock()<tm+1000);
}	
