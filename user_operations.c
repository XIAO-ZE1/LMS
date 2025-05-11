#include "LMS.h"

void member_log_up() /*会员注册函数*/
{
    char choice1, choice2;
    int flag = 1;
    FILE *p2;
    MEMBER member;

    while (1)
    {
        system("cls");
        fflush(stdin);

        printf("输入注册ID名:");
        gets(member.ID);

        if (check_repeat_ID(member.ID))
        {
            printf("该ID已被注册！请重新注册^_^\n");
            printf("按任意键重新注册\n\n");
            getch();
            flag = 1;
        }
        else
        {
            flag = 0;
            printf("输入密码:");
            gets(member.password);

            printf("输入找回密码的密钥:");
            gets(member.password_key);

            printf("输入您的姓名:");
            gets(member.name);

            printf("输入您的性别(男士male,女士female):");
            gets(member.sex);

            printf("是否保存这次注册信息(y/n):");
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
                printf("\n您的账户已注册成功！\n");
            }
            else
            {
                printf("\n您的注册信息未保存!\n");
            }
            printf("\n是否继续注册会员(y/n):");
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

int user_account(char account[20]) /*用户信息以及密码修改函数*/
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
        printf("当前图书馆未有任何借书信息");
        flag = 0;
        printf("\n\n按任意键返回!\n");
        getch();
    }
    else
    {
        for (n = 0; n < number; n++)
            if (strcmp(member[n].ID, account) == 0)
            {
                i = 0;
                printf("\n");
                printf("|---------------------------个人信息-------------------------|\n");
                printf("|姓名        性别      ID              密码                  |\n");
                printf("|%-12s%-10s%-16s%-22s%|\n", member[n].name, member[n].sex, member[n].ID, member[n].password);
                printf("|                                                            |\n");
                printf("|----------------------------图书借阅信息--------------------|\n");
                printf("|编号  书名        作者      出版社          类别    单价    |\n");

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
                    printf("\n%s先生，您当前借阅的书籍共有%d本。", member[n].name, count);
                else if (strcmp(member[n].sex, "female") == 0)
                    printf("\n%s女士，您当前借阅的书籍共有%d本。", member[n].name, count);
                else
                    printf("\n%s，您当前借阅的书籍共有%d本。", member[n].name, count);

                if (bookgrasp[0].price <= 1e-8)
                    printf("\n而图书馆内共有0本书籍正在被借阅。\n");
                else
                    printf("\n而图书馆内共有%d本书籍正在被借阅。\n", booknumber);

                printf("\nPS:是否需要修改密码(y/n):");
                fflush(stdin);
                choice = getch();
                while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                    choice = getch();
                printf("%c", choice);
                printf("\n");
                if (choice == 'Y' || choice == 'y')
                {
                    printf("\n请输入修改密码的密钥(user_key):");
                    fflush(stdin);
                    gets(key);
                    if (strcmp(member[n].password_key, key) == 0)
                    {
                        printf("请输入新密码：");
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
                        printf("\n输入密钥错误!");
                    }
                }
                else
                    flag = 0;
            }
    }
    if (flag == 1)
    {
        printf("\n密码修改成功！");
        printf("\n按任意键返回!\n");
        getch();
        return 1;
    }
    else
    {
        return 0;
    }
}

void find_account() /*账户找回函数*/
{
    FILE *p2;
    MEMBER member[MAX_ITEMS];
    int number, n, k = 3, flag = 1, mark = 0;
    char choice = '0';
    char vacancy[10] = "";
    char search[30], compare[30], new_password[20];

    system("cls");
    fflush(stdin);
    printf("输入您的姓名:");
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
        printf("系统中还没有任何会员信息!\n\n");
    }
    else
    {
        for (n = 0; n < number; n++)
            if (strcmp(member[n].name, search) == 0)
            {
                mark = 1;
                while (flag)
                {
                    printf("请输入您的密钥:");
                    fflush(stdin);
                    gets(compare);
                    if (strcmp(member[n].password_key, compare) == 0)
                    {
                        printf("\n");
                        printf("|------------------------------个人信息------------------------------|\n");
                        printf("|姓名        性别      ID                  密码	                     |\n");
                        printf("|%-12s%-10s%-20s%-26s%|\n", member[n].name, member[n].sex, member[n].ID, member[n].password);

                        printf("\n是否需要修改密码(y/n):");
                        fflush(stdin);
                        choice = getch();
                        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                            choice = getch();
                        printf("%c", choice);
                        printf("\n");
                        if (choice == 'Y' || choice == 'y')
                        {
                            printf("\n请输入新密码：");
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
                        --k; /*密码输入次数count*/
                        if (k != 0)
                        {
                            printf("\n\n\n\t\t您的密码输入有误!\n\t\t您还有%d次机会重新输入密码！", k);
                            printf("您是否要继续输入密码(y/n):");
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
                            printf("您输入次数已用完！正在退回主界面...");
                            flag = 0;
                        }
                    }
                }
            }
    }
    if (mark == 0)
    {
        printf("您并未注册本系统会员!\n");
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
            printf("您已成功找回/修改账户!\n");
        }
    }
    printf("\n\n按任意键回到主菜单!\n");
    fflush(stdin);
    getch();
}

int member_log_in(char account[15]) /*会员登录函数*/
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
            if (compare_password(member[n].password)) /* 调用会员密码比对函数 */
            {
                printf("\n\n\n\t\t\t   核对正确！正在进入会员界面...");
                clock_delay();
                return 1;
            }
            else
            {
                --k; /*密码输入次数count*/
                if (k != 0)
                {
                    printf("\n\n\n\t\t\t   您的密码输入有误!还有%d次机会重新输入密码！", k);
                    printf("\n\t\t\t   您是否要继续输入密码(y/n):");
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
                    printf("\n\n\t\t\t   您输入次数已用完！按任意键退出...");
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
        printf("\n\n\n\t\t\t  该ID还未注册,是否需要注册会员(y/n):");
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

int compare_password(char *password) /*密码比对函数 */
{
    int i = 0;
    char compare[20], c;
    fflush(stdin);
    printf("\n\t\t\t   密码(password):");
    while ((c = getch()) != 13) //\r是将光标移到该行首位
    {
        if (c == 8 && i > 0)
        {
            printf("\b \b"); // 清除*号和错符
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
        printf("\a"); // 响铃
        return 1;
    }
    else
    {
        printf("\a"); // 响铃
        return 0;
    }
}

int check_repeat_ID(char *id_account) /*查重函数*/
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

void ADMIN_watch_member() /*查看会员信息函数*/
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

    printf("系统注册用户有%d位:", number);
    printf("\n\n");
    printf("|-----------------------会员信息-----------------------|\n");
    printf("|姓名      性别    ID            密码  	         密钥  |\n");
    for (n = 0; n < number; n++)
        printf("|%-10s%-8s%-14s%-16s%-6s%|\n", member[n].name, member[n].sex, member[n].ID, member[n].password, member[n].password_key);

    printf("\n\n按任意键返回上一级菜单!\n");
    getch();
}

void display_memberbook() /*查看所有图书借阅信息函数*/
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
        printf("当前没有借阅信息");
    else
    {
        printf("当前共有%d位会员借阅书籍。", booknumber);
        printf("\n");
        printf("|---------------------------借阅图书信息-----------------------------------|\n");
        printf("|编号  书名        作者      出版社          类别    单价    借阅ID        |\n");
        printf("|                                                                          |\n");
        for (n = 0; n < booknumber; n++)
            printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-14s|\n", bookgrasp[n].number, bookgrasp[n].name, bookgrasp[n].author, bookgrasp[n].press, bookgrasp[n].category, bookgrasp[n].price, bookgrasp[n].account);
    }
    printf("\n\n输入任意键返回...");
    fflush(stdin);
    getch();
}

void password_circle() /*画框函数*/
{
    system("cls");
    printf("\n\n\n\t\t\t***================================*** \n");
    printf("\t\t\t                                   \n");
    printf("\t\t\t   账户 (account):");
}

void find_account_circle() /*找回账户弹出框函数*/
{
    printf("\n\n\n\n");
    printf("\t\t\t===============H-E-L-P===================\n");
    printf("\t\t\t|                                       |\n");
    printf("\t\t\t* 您需不需要通过密钥找回账户？(输入y/n) *\n");
    printf("\t\t\t|                                       |\n");
    printf("\t\t\t=========================================\n");
    printf("\n\t\t\t您的选择是:");
}

void clock_delay()/*时间延时函数*/
{
	clock_t tm;
	tm=clock();
    while(clock()<tm+1000);
}	
