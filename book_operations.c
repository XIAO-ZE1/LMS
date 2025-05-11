#include "LMS.h"

void add_book() /*�����½���ͼ����Ϣ*/
{
    char choice;
    FILE *p1;
    BOOKINFO newbook;
    int flag;
    system("cls");
    while (1)
    {
        flag = 0;
        fflush(stdin);
        char next = ' ';
        printf("������ͼ����:");
        gets(newbook.number);

        if (check_repeat_book(newbook.number))
        {
            printf("��ͼ�����ѱ�ռ��");
            printf("\n�����������ע�ᣬ��x����ע��\n\n");
            next = getch(); /*�������ʹ��x��ֱ�ӽ���ע��*/
            flag = 1;
        }
        else
        {
            fflush(stdin);
            printf("����������:");
            gets(newbook.name);

            printf("����������:");
            gets(newbook.author);

            printf("�����������:");
            gets(newbook.press);

            printf("���������(��ѧ/��ѧ/��ѧ/��ѧ/��):");
            gets(newbook.category);

            printf("������۸�:");
            scanf("%f", &newbook.price);

            printf("������ݲ���:");
            scanf("%d", &newbook.quantity);

            printf("��������Ĵ���(��������0):");
            scanf("%d", &newbook.time);
            fflush(stdin);
            printf("�Ƿ񱣴������Ŀ(y/n):");
            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();
            printf("%c", choice);
            if (choice == 'Y' || choice == 'y')
            {
                p1 = fopen(LIBFILE, "a");
                fprintf(p1, "%s %s %s %s %s %f %d %d\n",
                        newbook.number, newbook.name, newbook.author, newbook.press,
                        newbook.category, newbook.price, newbook.quantity, newbook.time);
                fclose(p1);
                printf("\n������Ŀ����ӵ�library.txt�ļ���!\n");
            }
            else
            {
                printf("\n������Ŀδ����!\n");
            }
            printf("\n\n�Ƿ���������Ŀ(y/n):");
            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();
            printf("%c", choice);
            printf("\n");
        }
        if (choice == 'Y' || choice == 'y' || flag == 1)
        {
            if (next == 'x' || next == 'X')
            {
                break;
            }
            continue;
        }
        else
            break;
    }
}

void display_book() /*��ʾȫ��ͼ����Ϣ*/
{
    int i = 0;
    FILE *p1;
    int n;
    BOOKINFO bookinfo[100];
    int booknumber = 0;
    system("cls");
    fflush(stdin);
    p1 = fopen(LIBFILE, "r");
    while (!feof(p1))
    {
        fscanf(p1, "%s %s %s %s %s %f %d %d\n",
               bookinfo[booknumber].number, bookinfo[booknumber].name, bookinfo[booknumber].author,
               bookinfo[booknumber].press, bookinfo[booknumber].category,
               &bookinfo[booknumber].price, &bookinfo[booknumber].quantity, &bookinfo[booknumber].time);
        booknumber++;
    }
    fclose(p1);
    printf("��ǰͼ�������%dĿ�鼮\n\n", booknumber);
    if (bookinfo[0].quantity == 0)
    {
        printf("\nû���κ�ͼ����Ϣ!\n\n");
    }
    else
    {
        printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
        printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
        printf("|                                                                          |\n");
        for (i = 0; i < booknumber; i++)
        {

            printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n",
                   bookinfo[i].number, bookinfo[i].name, bookinfo[i].author,
                   bookinfo[i].press, bookinfo[i].category,
                   bookinfo[i].price, bookinfo[i].quantity, bookinfo[i].time);
        }
    }
    printf("\n\n�������������һ���˵�!\n");
    getch();
}

void search_book() /*����ͼ��������ʾͼ�����Ϣ*/
{
    int flag = 1;
    int flag1 = 1;
    char select;
    char name_compare[30] = "";   /*name_compare�������Ҫ��ѯ������*/
    char number_compare[30] = ""; /*number_compare�������Ҫ��ѯ���鼮���*/
    char author_compare[30] = ""; /*author_compare�������Ҫ��ѯ����������*/
    char search[30] = "";         /*search�Ǳȶ�����,����Ҫ���ҵ���������ȶ�����*/
    char compare[30] = "";        /*compare�Ǳȶ�����,������е���������ȶ�����*/
    int n = 0;
    FILE *p1;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber = 0;

    system("cls");
    fflush(stdin);
    p1 = fopen(LIBFILE, "r");
    while (!feof(p1))
    {
        fscanf(p1, "%s %s %s %s %s %f %d %d\n",
               bookinfo[booknumber].number, bookinfo[booknumber].name, bookinfo[booknumber].author,
               bookinfo[booknumber].press, bookinfo[booknumber].category,
               &bookinfo[booknumber].price, &bookinfo[booknumber].quantity, &bookinfo[booknumber].time);
        booknumber++;
    }
    fclose(p1);

    while (flag)
    {
        system("cls");
        while (flag1)
        {
            system("cls");
            fflush(stdin);
            printf("����ͨ��\n\n1.<-ͼ����->\n\n2.<-����->\n\n3.<-������->\n\n���ַ�ʽ��ѯͼ��:");
            select = getch();
            printf("%c", select);
            printf("\n\n�������������Ϣ:");
            switch (select)
            {
            case '1':
                gets(number_compare);
                strcpy(search, number_compare);
                flag1 = 0;
                break;
            case '2':
                gets(name_compare);
                strcpy(search, name_compare);
                flag1 = 0;
                break;
            case '3':
                gets(author_compare);
                strcpy(search, author_compare);
                flag1 = 0;
                break;
            default:
                printf("\n��Ҫ����˵�֮�������~�������������");
                fflush(stdin);
                getch();
            }
        }
        if (bookinfo[0].quantity == 0)
        {
            printf("�����û���κ���Ϣ!\n\n");
            printf("��������ص����˵�!\n\n");
            getch();
            break;
        }
        else
        {
            int have = 0;
            int cmp = 0;
            for (n = 0; n < booknumber; n++)
            {
                switch (select)
                {
                case '1':
                    cmp = strcmp(compare, bookinfo[n].number);
                    break;
                case '2':
                    cmp = strcmp(compare, bookinfo[n].name);
                    break;
                case '3':
                    cmp = strcmp(compare, bookinfo[n].author);
                    break;
                }
                if (cmp == 0)
                {
                    printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
                    printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
                    printf("|                                                                          |\n");
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                           bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
                    have = 1;
                    break;
                }
            }
            if (have == 0)
                printf("\nû�в��ҷ�����Ҫ����鼮!\n");

            printf("\n\n�Ƿ������ѯ(y/n):");
            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();
            printf("%c", choice);
            printf("\n");
            if (choice == 'Y' || choice == 'y')
                flag = 1;
            else
                flag = 0;
        }
    }
}

void delete_book() /*����ͼ�����ƶ�ͼ����Ϣ����ɾ��*/
{
    char search[20] = ""; /*search�������Ҫɾ��������*/
    int n, i;
    FILE *p1;
    char choice;
    BOOKINFO bookinfo[100];
    int booknumber;

    system("cls");
    while (1)
    {
        fflush(stdin);
        printf("����Ҫɾ�����鱾����:");
        gets(search);
        p1 = fopen(LIBFILE, "r");
        booknumber = 0;
        while (!feof(p1))
        {
            fscanf(p1, "%s %s %s %s %s %f %d %d\n",
                   bookinfo[booknumber].number, bookinfo[booknumber].name, bookinfo[booknumber].author,
                   bookinfo[booknumber].press, bookinfo[booknumber].category,
                   &bookinfo[booknumber].price, &bookinfo[booknumber].quantity, &bookinfo[booknumber].time);
            booknumber++;
        }
        fclose(p1);
        if (bookinfo[0].quantity == 0)
        {
            printf("�����û���κ���Ϣ!\n\n");
            printf("��������ص����˵�!\n\n");
            getch();
            break;
        } /*if����*/
        else
        {
            for (n = 0; n < booknumber; n++)
                if (strcmp(bookinfo[n].name, search) == 0)
                {
                    break;
                }
            if (n >= booknumber)
                printf("\n�����û���ҵ�������κ���Ϣ!\n");
            else
            {
                printf("\n�Ƿ�ȷ����Ҫɾ��������Ŀ(y/n):");
                choice = getch();
                while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                    choice = getch();
                printf("%c", choice);
                if (choice == 'Y' || choice == 'y')
                {
                    for (i = n; i < booknumber - 1; i++)
                        bookinfo[i] = bookinfo[i + 1];
                    booknumber--;
                    p1 = fopen(LIBFILE, "w");
                    for (n = 0; n < booknumber; n++)
                        fprintf(p1, "%s %s %s %s %s %f %d %d\n",
                                bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                                bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
                    fclose(p1);
                    printf("\n��ɾ������Ŀ");
                }
                else
                    printf("\n������Ŀû�б�ɾ��!");
            }
            printf("\n\n�Ƿ��������ɾ��������(y/n):");
            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();
            printf("%c", choice);
            printf("\n");
            if (choice == 'Y' || choice == 'y')
                continue;
            else
                break;
        }
    }
}

void display_price_lower() /*���ݼ۸��г�ͼ����Ϣ*/
{
    float price;
    int n;
    int count = 0;
    BOOKINFO bookinfo[100];
    int booknumber;

    system("cls");
    printf("�������������۸�,���ǽ��Ƽ����������λ�Ե͵��鼮:");
    scanf("%f", &price);
    booknumber = read_books_from_file(LIBFILE, bookinfo, 100);
    if (bookinfo[0].quantity == 0)
    {
        printf("\n��ǰ���Ϊ��!\n");
    }
    else
    {
        for (n = 0; n < booknumber; n++)
        {
            if (bookinfo[n].price <= price)
                count++;
        }
        if (count == 0)
            printf("�����û�б�%.1fԪ�۸���͵�ͼ�顣��̫������", price);
        else
        {
            printf("\n�۸����%.1fԪ��ͼ����Ϣ��%d��\n", price, count);
            printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
            printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
            printf("|                                                                          |\n");
            for (n = 0; n < booknumber; n++)
            {
                if (bookinfo[n].price <= price)
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                           bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
            }
        }
    }
    printf("\n\n��������ص����˵�!\n");
    getch();
}

void modify_book() /*�޸�ͼ����Ϣ*/
{
    int flag = 1, flag1 = 1, flag2 = 0, n;
    char change, choice;
    char number[15];   /*ͼ����*/
    char name[30];     /*ͼ������*/
    char author[20];   /*����*/
    char press[30];    /*������*/
    char category[20]; /*���*/
    int quantity;      /*������*/
    float price;       /*����*/

    char search[30]; /*Ҫ�޸ĵ�����*/
    FILE *p1;
    BOOKINFO bookinfo[100];
    int booknumber;
    while (flag)
    {
        flag2 = 0;
        system("cls");
        fflush(stdin);
        printf("����Ҫ�޸���Ϣ���鱾��:");
        gets(search);
        booknumber = read_books_from_file(LIBFILE, bookinfo, 100);
        if (bookinfo[0].quantity == 0)
        {
            printf("��ǰ���Ϊ��!\n\n");
            printf("��������ص����˵�!\n\n");
            getch();
            break;
        }
        else
        {
            for (n = 0; n < booknumber; n++)
                if (strcmp(bookinfo[n].name, search) == 0)
                {
                    printf("\n");
                    printf("|---------------------------------ͼ����Ϣ---------------------------------|\n");
                    printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
                    printf("|                                                                          |\n");
                    printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                           bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);

                    while (flag1)
                    {
                        printf("\n1.�鼮���\n2.�鼮����\n3.�鼮����\n4.������\n5.�鼮���\n6.�鼮����\n7.������\n\n����Ҫ�޸ĵ���:");
                        change = getch();
                        while (change != '1' && change != '2' && change != '3' && change != '4' && change != '5' && change != '6' && change != '7')
                            change = getch();
                        printf("%c", change);
                        printf("\n�������޸ĵ���Ϣ:");
                        fflush(stdin);
                        switch (change)
                        {
                        case '1':
                            gets(number);
                            flag1 = 0;
                            flag2 = check_repeat_book(number);
                            if (!flag2)
                                strcpy(bookinfo[n].number, number);
                            break;
                        case '2':
                            gets(name);
                            strcpy(bookinfo[n].name, name);
                            flag1 = 0;
                            break;
                        case '3':
                            gets(author);
                            strcpy(bookinfo[n].author, author);
                            flag1 = 0;
                            break;
                        case '4':
                            gets(press);
                            strcpy(bookinfo[n].press, press);
                            flag1 = 0;
                            break;
                        case '5':
                            gets(category);
                            strcpy(bookinfo[n].category, category);
                            flag1 = 0;
                            break;
                        case '6':
                            scanf("%f", &price);
                            bookinfo[n].price = price;
                            flag1 = 0;
                            break;
                        case '7':
                            scanf("%d", &quantity);
                            bookinfo[n].quantity = quantity;
                            flag1 = 0;
                            break;
                        default:
                            break; /*��Ȼѹ���������default����������º���������©���¼ӵ�case��while�������Լ���*/
                        }
                    }
                    flag1 = 1;
                    break;
                }
            if (n >= booknumber)
                printf("\nû�в��ҵ��κ���ص���Ϣ!");
            else if (!flag2)
            {
                p1 = fopen(LIBFILE, "w");
                for (n = 0; n < booknumber; n++)
                    fprintf(p1, "%s %s %s %s %s %f %d %d\n",
                            bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                            bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
                fclose(p1);
                printf("\n�޸ĳɹ�!");
            }
            else
                printf("�����޸ĵ�ͼ����Ϣ�������Ϣ�ظ���");
            printf("\n�Ƿ���������޸�(y/n):");
            choice = getch();
            while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
                choice = getch();
            printf("%c", choice);
            printf("\n");
            if (choice == 'Y' || choice == 'y')
                flag = 1;
            else
                flag = 0;
        }
    }
}
void borrow_book(char account[20])
{
    FILE *p1, *p3;
    BOOKINFO bookinfo[100];
    char search[30], choice;
    int flag = 1, n;
    int booknumber1;
    system("cls");

    while (flag)
    {
        printf("����Ҫ���ĵ��鱾��:");
        gets(search);
        p1 = fopen("library.txt", "r");
        booknumber1 = 0;
        while (!feof(p1))
        {
            fscanf(p1, "%s %s %s %s %s %f %d %d\n",
                   bookinfo[booknumber1].number, bookinfo[booknumber1].name, bookinfo[booknumber1].author,
                   bookinfo[booknumber1].press, bookinfo[booknumber1].category,
                   &bookinfo[booknumber1].price, &bookinfo[booknumber1].quantity, &bookinfo[booknumber1].time);
            booknumber1++;
        }
        fclose(p1);

        if (bookinfo[0].quantity == 0)
        {
            printf("\n�����û���κ���Ϣ!\n");
            printf("��������ص����˵�!\n\n");
            getch();
            break;
        }
        else
        {
            for (n = 0; n < booknumber1; n++)
                if (strcmp(bookinfo[n].name, search) == 0)
                {
                    bookinfo[n].quantity--;
                    bookinfo[n].time++;

                    p3 = fopen("memberbook.txt", "a"); /*������a׷�ӵķ�ʽ�����ļ�������һ����*/
                    fprintf(p1, "%s %s %s %s %s %f %s\n",
                            bookinfo[n].number, bookinfo[n].name, bookinfo[n].author, bookinfo[n].press,
                            bookinfo[n].category, bookinfo[n].price, account);
                    fclose(p3);
                    break;
                }
        }
        if (n >= booknumber1)
            printf("\nû�в��Ҹ�����κ���Ϣ!\n");
        else
        {
            p1 = fopen("library.txt", "w");
            for (n = 0; n < booknumber1; n++)
                fprintf(p1, "%s %s %s %s %s %f %d %d\n",
                        bookinfo[n].number, bookinfo[n].name, bookinfo[n].author, bookinfo[n].press,
                        bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
            fclose(p1);
            printf("\n����ɹ�!\n");
        }
        printf("\n�Ƿ��������(y/n):");
        choice = getch();
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
            choice = getch();
        printf("%c", choice);
        printf("\n");
        if (choice == 'Y' || choice == 'y')
            flag = 1;
        else
            flag = 0;
    }
}

void return_book(char account[20])
{
    FILE *p1, *p3;
    BOOKINFO bookinfo[100];
    BOOKGRASP bookgrasp[100];
    char search[30], choice;
    int flag = 1, flag2 = 0, n, i, k, j, t = 0;
    int booknumber, booknumber2;
    system("cls");

    while (flag)
    {
        flag2 = 0;
        fflush(stdin);
        p1 = fopen("library.txt", "r");
        booknumber = 0;
        while (!feof(p1))
        {
            fscanf(p1, "%s %s %s %s %s %f %d %d\n",
                   bookinfo[booknumber].number, bookinfo[booknumber].name, bookinfo[booknumber].author,
                   bookinfo[booknumber].press, bookinfo[booknumber].category,
                   &bookinfo[booknumber].price, &bookinfo[booknumber].quantity, &bookinfo[booknumber].time);
            booknumber++;
        }
        fclose(p1);

        p3 = fopen("memberbook.txt", "r");
        booknumber2 = 0;
        while (!feof(p3))
        {
            fscanf(p3, "%s %s %s %s %s %f %s\n",
                   bookgrasp[booknumber2].number, bookgrasp[booknumber2].name, bookgrasp[booknumber2].author, bookgrasp[booknumber2].press,
                   bookgrasp[booknumber2].category, &bookgrasp[booknumber2].price, bookgrasp[booknumber2].account);
            booknumber2++;
        }
        fclose(p3);

        printf("�������ĵ�����ͼ����Ϣ����:\n");
        printf("|----------------------------ͼ�������Ϣ--------------------|\n");
        printf("|���  ����        ����      ������          ���    ����    |\n");
        while (t < booknumber2)
        {
            if (strcmp(bookgrasp[t].account, account) == 0)
            {
                printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f|\n", bookgrasp[t].number,
                       bookgrasp[t].name, bookgrasp[t].author, bookgrasp[t].press,
                       bookgrasp[t].category, bookgrasp[t].price);
            }
            t++;
        }

        printf("\n����Ҫ�黹���鱾��:");
        gets(search);
        if (bookinfo[0].quantity == 0)
        {
            printf("\n�����û���κ���Ϣ!\n");
            printf("��������ص����˵�!\n\n");
            getch();
            break;
        }
        else
        {
            for (n = 0; n < booknumber; n++)
                if (strcmp(bookinfo[n].name, search) == 0)
                {
                    bookinfo[n].quantity++;

                    if (bookgrasp[0].price == 0)
                        printf("\n��û�н�����Ϣ��");
                    else
                    {
                        for (k = 0; k < booknumber2; k++)
                            if (!strcmp(bookgrasp[k].account, account) && !strcmp(bookgrasp[k].name, search))
                            {
                                flag2 = 1;
                                for (i = k; i < booknumber2 - 1; i++)
                                    bookgrasp[i] = bookgrasp[i + 1];
                                booknumber2--;
                                break;
                            }

                        p3 = fopen("memberbook.txt", "w");
                        for (j = 0; j < booknumber2; j++)
                        {
                            fprintf(p3, "%s %s %s %s %s %f %s\n",
                                    bookgrasp[j].number, bookgrasp[j].name, bookgrasp[j].author, bookgrasp[j].press,
                                    bookgrasp[j].category, bookgrasp[j].price, bookgrasp[j].account);
                        }
                        fclose(p3);
                    }
                    break;
                }
        }
        if (n == booknumber || flag2 == 0)
            printf("����û������������Ϣ!\n");
        if (n < booknumber && flag2 == 1)
        {
            p1 = fopen("library.txt", "w");
            for (n = 0; n < booknumber; n++)
                fprintf(p1, "%s %s %s %s %s %f %d %d\n",
                        bookinfo[n].number, bookinfo[n].name, bookinfo[n].author,
                        bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
            fclose(p1);
            printf("\n����ɹ���");
        }
        else
            printf("\n����ʧ�ܣ�");

        fflush(stdin);
        printf("\n�Ƿ��������(y/n):");
        choice = getch();
        while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
            choice = getch();
        printf("%c", choice);
        printf("\n");
        if (choice == 'Y' || choice == 'y')
            flag = 1;
        else
            flag = 0;
    }
}

void dispaly_popular() /*ͼ���ܻ�ӭ�����а�*/
{

    int n, i, j, k;
    int count = 0;
    BOOKINFO bookinfo[101];
    int booknumber;

    system("cls");
    fflush(stdin);
    booknumber = read_books_from_file(LIBFILE, bookinfo, 100);

    if (bookinfo[0].quantity == 0)
    {
        printf("�����û���κ���Ŀ!\n\n");
    }
    else
    {
        for (i = 0; i < booknumber - 1; i++)
        {
            k = i;
            for (j = i + 1; j < booknumber; j++)
                if (bookinfo[j].time > bookinfo[k].time)
                    k = j;
            if (k != i)
            {
                bookinfo[100] = bookinfo[i];
                bookinfo[i] = bookinfo[k];
                bookinfo[k] = bookinfo[100];
            }
        }

        printf("|---------------------------ͼ���ܻ�ӭ�����а�-----------------------------|\n");
        printf("|���  ����        ����      ������          ���    ����    �ݲ���  ������|\n");
        printf("|                                                                          |\n");
        for (n = 0; n < booknumber; n++)
        {
            printf("|%-6s%-12s%-10s%-16s%-8s%-8.1f%-8d%-6d|\n", bookinfo[n].number, bookinfo[n].name, bookinfo[n].author, bookinfo[n].press, bookinfo[n].category, bookinfo[n].price, bookinfo[n].quantity, bookinfo[n].time);
        }
    }
    printf("\n\n��������ص����˵�!\n");
    getch();
}

int check_repeat_book(char number[30])
{

    BOOKINFO bookinfo[100];
    int flag1 = 0, flag2 = 1, n, booknumber;

    booknumber = read_books_from_file(LIBFILE, bookinfo, 100);
    for (n = 0; n < booknumber; n++)
        if (strcmp(bookinfo[n].number, number) == 0)
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

int read_books_from_file(const char *filename, BOOKINFO *books, int max_books) /*��ȡ����*/
{
    FILE *fp = fopen(filename, "r");
    if (!fp)
        return 0;

    int count = 0;
    while (count < max_books && fscanf(fp, "%s %s %s %s %s %f %d %d\n",
                                       books[count].number, books[count].name, books[count].author,
                                       books[count].press, books[count].category, &books[count].price,
                                       &books[count].quantity, &books[count].time) == 8)
    {
        count++;
    }
    fclose(fp);
    return count;
}
