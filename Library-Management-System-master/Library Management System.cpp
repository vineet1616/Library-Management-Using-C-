//         LIBRARY MANAGEMENT SYSTEM        //

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
using namespace std;

void main_menu();
void admin();
void bookmenu();
void usermenu();
void addbook();
void adduser();
void deletebook();
void deleteuser();
void editbook();
void edituser();
int bidcheck(int);
int uidcheck(int);
void listbook();
void listuser();
void issuebook();
void collectbook();
void fine();
/*void savebook();
void saveuser();
void readbook();
void readuser();
*/
void exitcheck();

struct book
{
    int id;
    char name[20];
    char author[20];
    int copies;
    int copiesleft;
    book *next;
};
book *frontb=NULL,*rearb=NULL;

struct date
{
    int dd,mm,yy;
};

struct user
{
    int id;
    char name[20];
    int bookid;
    date issue;
    date due;
     user *next;
};
user *frontu=NULL,*rearu=NULL;

int main()
{
    system("cls");
    //readbook();
    //readuser();
    printf("\n\n\n\t\t\t\t\t Library Management Software \n\n\n\n\n\t\t\t\t\t\t\t\t  \n\t\t\t\t\t\t\t\t  \n\t\t\t\t\t\t\t\t");
    printf("\n\n\t\t\t\t\t Press any key to continue");
    getch();
    main_menu();
    return 0;
}
void main_menu()
{
    int choice;
    do
    {
        system("cls");
        printf("\n\n\n\t\t\t Main Menu");
        printf("\n\n\t\t 1.Administrator ");
        printf("\n\t\t 2.User ");
        printf("\n\t\t 3.Exit ");
        printf("\n\n\t\t Please enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: { admin();
                      break;
                    }
            case 2: { usermenu();
                      break;
                    }
            case 3: { exitcheck();
                      break;
                    }
            default:{ printf(" \n Invalid Choice ");
                       getch();
                    }
        }
    }while(1);
    getch();
}
void admin()
{
    system("cls");
    string password = "12345";
    printf("\n\n\t\t Please enter the password : ");
    string str = "";
    char ch;
    int i=0;
    while((ch=getch())&&i<5)
    {
        str+=ch;
        printf("*");
        i++;
    }
    if(str==password)
        {
            printf("\n\n\t\t Authentication successful");
            printf("\n\n\t\t Press any key to continue");
            getch();
        }
    else
        {
            printf("\n\n\t\t Incorrect password entered");
            printf("\n\n\t\t Press any key to continue");
            getch();
            return;
        }
    int choice;
    do
    {
    system("cls");
    printf("\n\n\t\t\t\t Administrator Menu");
    printf("\n\n\t\t 1. Add/Edit Book \n\t\t 2. Add/Edit User \n\t\t 3. List Books \n\t\t 4. List Users \n\t\t 5. Issue Book \n\t\t 6. Collect Book \n\t\t 7. Main Menu \n\t\t 8. Exit");
    printf("\n\n\t\t Please Enter the choice : ");
    scanf("%d",&choice);
    switch(choice)
        {
            case 1: { bookmenu();
                      break;
                    }
            case 2: { usermenu();
                        break;
                    }
            case 3: {
                        listbook();
                        break;
                    }
            case 4: {
                        listuser();
                        break;
                    }
            case 5: {
                        issuebook();
                        break;
                    }
            case 6: {
                        collectbook();
                        break;
                    }
            case 7: return;
            case 8: {
                        exitcheck();
                        break;
                    }
            default: {
                        printf("\n\n\t\t Invalid Choice");
                        getch();
                    }
        }
    }while(1);
}
void bookmenu()
{
    int choice;
    do
    {
        system("cls");
        printf("\n\n\t\t\t\t Book Menu");
        printf("\n\n\t\t 1. Add Book \n\t\t 2. Edit Book Details \n\t\t 3. Delete Book \n\t\t 4. List Books \n\t\t 5. Administrator Menu \n\t\t 6. Exit");
        printf("\n\n\t\t Please Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {
                    addbook();
                    break;
                    }
            case 2: {
                    editbook();
                    break;
                    }
            case 3: {
                    deletebook();
                    break;
                    }
            case 4: {
                    listbook();
                    break;
                    }
            case 5: return;
            case 6: {
                    exitcheck();
                    break;
                    }
            default: {
                        printf("\n\n\t\t Invalid Choice");
                        getch();
                    }
        }
    }while(1);
}
void addbook()
{
    system("cls");
    book *temp;
    temp = new book;
    printf("\n\n\t\t\t Add Book");
    printf("\n\n\t\t Please Enter the following details");
    printf("\n\n\t BookId : ");
    scanf("%d",temp->id);
    if(bidcheck(temp->id)==0)
    {
        printf("\n\t Book Name : ");
        scanf("%s",temp->name);
        printf("\n\t Author : ");
        scanf("%s",temp->author);
        printf("\n\t Number of copies :");
        scanf("%d",temp->copies);
        temp->copiesleft = temp->copies;
        temp->next=NULL;
        if(frontb==NULL)
        {
            frontb=temp;
            rearb=temp;
        }
        else
        {
            rearb->next=temp;
            rearb=temp;
        }
        printf("\n\t Book Successfully added");
        getch();
        return;
    }
     else
    {
        printf("\n\t BookId already exists ");
        printf("\n\t Press any key to continue ");
        getch();
        return;
    }
}
int bidcheck(int a)
{
    book *temp;
    for(temp=frontb;temp!=NULL;temp=temp->next)
    {
        if(temp->id==a)
        {
            return 1;
        }
    }
    return 0;
}
void editbook()
{
    system("cls");
    int x;
    printf("\n\n\t\t\t\t Edit Book Details");
    printf("\n\t Enter the BookId you want to edit : ");
    scanf("%d",&x);
    if(bidcheck(x)==1)
    {
        book *temp;
        for(temp=frontb;temp!=NULL;temp=temp->next)
        {
            if(temp->id==x)
            {
                break;
            }
        }
        printf("\n\t Existing Book Information : ");
        printf("\n\t BookId : %d \n\t 1. Book Name : %s \n\t 2. Author : %s \n\t 3. Number of copies : %d \n\t 4.Number of copies left : %d",temp->id,temp->name,temp->author,temp->copies,temp->copiesleft);
        printf("\n\n\t Please Enter all the details : ");
        printf("\n\t Book Name : ");
        scanf(" %s",temp->name);
        printf("\n\t Author : ");
        scanf(" %s",temp->author);
        printf("\n\t New number of copies :");
        scanf("%d",temp->copies);
        printf("\n\t New number of copies left :");
        getch();
    }
    else
    {
        printf("\n\n\t Entered BookId does not exist");
        printf("\n\n\t Press any key to continue");
        getch();
    }
    return;
}
void deletebook()
{
    system("cls");
    int x;
    printf("\n\n\t\t Delete Book");
    printf("\n\t Enter the BookId to be deleted : ");
    scanf("%d",&x);
    if(bidcheck(x)==1)
    {
        book *temp,*temp1;
        if(frontb->id==x)
        {
            temp = frontb;
            frontb = frontb->next;
            free(temp);
        }
        else
        {
            for(temp=frontb;temp->next!=NULL;temp=temp->next)
            {
            if(temp->next->id==x)
                break;
            }
            temp1 = temp->next;
            temp->next=temp1->next;
            free(temp1);
        }
        printf("\n\t Book successfully deleted");
        printf("\n\t Press any key to continue");
        getch();
    }
    else
    {
        printf("\n\t BookId does not exist");
        printf("\n\t Press any key to continue");
        getch();
    }
    return;
}
void usermenu()
{
    int choice;
    do
    {
        system("cls");
        printf("\n\n\t\t\t\t User Menu");
        printf("\n\n\t\t 1. Add User \n\t\t 2. Edit User Details \n\t\t 3. Delete User \n\t\t 4.List Users \n\t\t 5. Main Menu \n\t\t 6. Exit");
        printf("\n\n\t\t Please Enter the choice : ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: {
                    adduser();
                    break;
                    }
            case 2: {
                    edituser();
                    break;
                    }
            case 3: {
                    deleteuser();
                    break;
                    }
            case 4: {
                    listuser();
                    break;
                    }
            case 5: return;
            case 6: {
                    exitcheck();
                    break;
                    }
            default:{
                    printf("\n\n\t\t Invalid Choice");
                    getch();
                    }
        }
    }while(1);
}
void adduser()
{
    system("cls");
    user *temp;
    temp = new user;
    printf("\n\n\t\t\t Add User");
    printf("\n\n\t\t Please Enter the following details");
    printf("\n\n\t UserId : ");
    scanf("%d",temp->id);
    if(uidcheck(temp->id)==0)
    {
        printf("\n\t Name : ");
        scanf(" %s",temp->name);
        temp->bookid=0;
        temp->issue.dd=0;
        temp->issue.mm=0;
        temp->issue.yy=0;
        temp->due.dd=0;
        temp->due.mm=0;
        temp->due.yy=0;
        temp->next=NULL;
        if(frontu==NULL)
        {
            frontu=temp;
            rearu=temp;
        }
        else
        {
            rearu->next=temp;
            rearu=temp;
        }
        printf("\n\t User Successfully added");
        getch();
    }
    else
    {
        printf("\n\t User already exists");
        printf("\n\t Press any key to continue");
        getch();
    }
    return;
}
int uidcheck(int a)
{
    user *temp;
    for(temp=frontu;temp!=NULL;temp=temp->next)
    {
        if(temp->id==a)
        {
            return 1;
        }
    }
    return 0;
}
void edituser()
{
    system("cls");
    int x;
    printf("\n\n\t\t\t\t Edit User Details");
    printf("\n\t Enter the UserId you want to edit : ");
    scanf("%d",&x);
    if(uidcheck(x)==1)
    {
        user *temp;
        for(temp=frontu;temp!=NULL;temp=temp->next)
        {
            if(temp->id==x)
            {
                break;
            }
        }
        printf("\n\t Existing User Information : ");
        printf("\n\t 1. UserId : %d \n\t 2. User Name : %s \n\t3.Book ID : %d \n\t4.Date Issued : %d/%d/%d \n\t5.Due Date : %d/%d/%d",temp->id,temp->name,temp->issue.dd,temp->issue.mm,temp->issue.yy,temp->due.dd,temp->due.mm,temp->due.yy);
        printf("\n\t Please Enter all the details : ");
        printf("\n\n\t BookId : ");
        scanf("%d",temp->id);
        printf("\n\t Date Issued : ");
        scanf(" %d/%d/%d ",temp->issue.dd,temp->issue.mm,temp->issue.yy);
        printf("\n\t Due Date : ");
        scanf(" %d/%d/%d ",temp->due.dd,temp->due.mm,temp->due.yy);
        printf("\n\n\tBook has been succesfully updated.");
        getch();
    }
    else
    {
        printf("\n\n\t Entered BookId does not exist");
        printf("\n\n\t Press any key to continue");
        getch();
    }
    return;
}
void deleteuser()
{
    system("cls");
    int x;
    printf("\n\n\t\t Delete User");
    printf("\n\t Enter the UserId to be deleted : ");
    scanf("%d",&x);
    if(uidcheck(x)==1)
    {
        user *temp,*temp1;
        if(frontu->id==x)
        {
            temp = frontu;
            frontu = frontu->next;
            free(temp);
        }
        else
        {
            for(temp=frontu;temp->next!=NULL;temp=temp->next)
            {
            if(temp->next->id==x)
                break;
            }
            temp1 = temp->next;
            temp->next=temp1->next;
            free(temp1);
        }
        printf("\n\t User successfully deleted");
        printf("\n\t Press any key to continue");
        getch();
    }
    else
    {
        printf("\n\t User does not exist");
        printf("\n\t Press any key to continue");
        getch();
    }
    return;
}
void listbook()
{
    system("cls");
    printf("\n\n\t\t Book Record");
    book *temp;
    for(temp=frontb;temp!=NULL;temp=temp->next)
    {
        printf("\n\t BookId : %d \n\t 1. Book Name : %s \n\t 2. Author : %s \n\t 3. Number of copies : %d \n\t 4.Number of copies left : ",temp->id,temp->name,temp->author,temp->copies,temp->copiesleft);
    }
    printf("\n\n\t Press any key to continue");
    getch();
    return;
}
void listuser()
{
    system("cls");
    printf("\n\n\t\t User Record");
    user *temp;
    for(temp=frontu;temp!=NULL;temp=temp->next)
    {
        printf("\n\t 1. UserId : %d \n\t 2. User Name : %s \n\t3.Book ID : %d \n\t4.Date Issued : %d/%d/%d \n\t5.Due Date : %d/%d/%d",temp->id,temp->name,temp->issue.dd,temp->issue.mm,temp->issue.yy,temp->due.dd,temp->due.mm,temp->due.yy);
    }
    printf("\n\n\t Press any key to continue");
    getch();
    return;
}
void issuebook()
{
    system("cls");
    printf("\n\n\t\t\t Issue Book");
    printf("\n\t Enter the UserId : ");
    int idb,idu;
    scanf("%d",&idu);
    user *temp;
    for(temp=frontu;temp!=NULL;temp=temp->next)
        if(temp->id==idu)
            break;
    if(uidcheck(idu)==1)
    {
        if(temp->bookid!=0)
        {
            printf("\n\t One Book is already issued");
            printf("\n\t Press any key to continue");
            getch();
        }
        else
        {
            printf("\n\t Enter the BookId to be issued : ");
            scanf("%d",&idb);
            book *temp1;
            for(temp1=frontb;temp1!=NULL;temp1=temp1->next)
                if(temp1->id==idb)
                    break;
            if(bidcheck(idb)==1)
            {
                if(temp1->copiesleft==0)
                {
                    printf("\n\t Book not available now");
                    printf("\n\t Press any key to continue");
                    getch();
                }
                else
                {
                    printf("\n\t Enter today's date : (dd-mm-yyyy) : ");
                    scanf("%d-%d-%d",temp->issue.dd,temp->issue.mm,temp->issue.yy);
                    temp->due.dd=temp->issue.dd+7;
                    temp->due.mm=temp->issue.mm;
                    temp->due.yy=temp->issue.yy;
                    if(temp->due.mm==2&&temp->due.dd>28)
                    {
                        temp->due.mm++;
                        temp->due.dd=0;
                    }
                    else if(temp->due.mm%2==0&&temp->due.dd>30)
                    {
                        temp->due.mm++;
                        temp->due.dd=0;
                    }
                    else if(temp->due.mm%2!=0&&temp->due.dd>31)
                    {
                        temp->due.mm++;
                        temp->due.dd=0;
                    }
                    printf("\n\t Book Issued Successfully");
                    printf("\n\t Press any key to continue");
                    getch();
                }
            }
            else
            {
                printf("\n\t BookId does not exist");
                printf("\n\t Press any key to continue");
                getch();
            }
        }
    }
    else
    {
        printf("\n\t UserId does not exist");
        printf("\n\t Press any key to continue");
        getch();
    }
    return;
}
void collectbook()
{
    system("cls");
    date d;
    printf("\n\n\t\t\t Issue Book");
    printf("\n\t Enter the UserId : ");
    int idb,idu;
    scanf("%d",&idu);
    user *temp;
    for(temp=frontu;temp!=NULL;temp=temp->next)
        if(temp->id==idu)
            break;
    if(uidcheck(idu)==1)
    {
        if(temp->bookid==0)
        {
            printf("\n\t Book is not issued");
            printf("\n\t Press any key to continue");
            getch();
        }
        else
        {
            printf("\n\t Enter the BookId to be issued : ");
            scanf("%d",&idb);
            book *temp1;
            for(temp1=frontb;temp1!=NULL;temp1=temp1->next)
                if(temp1->id==idb)
                    break;
            if(bidcheck(idb)==1)
            {
                printf("Enter today's date : (dd/mm/yy) : ");
                scanf("%d/%d/%d",d.dd,d.mm,d.yy);
                if(temp->due.yy>d.yy)
                    fine();
                else if(temp->due.yy==d.yy)
                {
                    if(temp->due.mm>d.mm)
                        fine();
                    else if(temp->due.mm==d.mm)
                    {
                        if(temp->due.dd>d.dd)
                            fine();
                        else
                        {
                            temp->bookid=0;
                            temp->issue.dd=temp->issue.mm=temp->issue.yy=temp->due.dd=temp->due.mm=temp->due.yy=0;
                            temp1->copiesleft++;
                        }
                    }
                }
            }
            else
            {
                printf("\n\t BookId does not exist");
                printf("\n\t Press any key to continue");
                getch();
            }
        }
    }
    else
    {
        printf("\n\t UserId does not exist");
        printf("\n\t Press any key to continue");
        getch();
    }
    return;
}
void fine()
{
    printf("\n\n\tYou need to pay a fine of 50 bucks for late returns.");
}
void exitcheck()
{
    system("cls");
//    savebook();
 //   saveuser();
    printf("\n\n\t\t Do you really want to exit ?(Y/N) : ");
    char ch;
    scanf(" %c",&ch);
    if(ch=='Y'||ch=='y')
        exit(1);
    return;
}
/*void savebook()
{
    FILE *temp;
    temp=fopen("book.txt","w");
    book *b;
    for(b=front;b!=NULL;b=b->next)
    {
        fwrite(b,sizeof(book),1,temp);
    }
    fclose(temp);
}
void saveuser()
{
    FILE *temp;
    temp=fopen("user.txt","w");
    user *u;
    for(u=frontu;u!=NULL;u=u->next)
    {
        fwrite(u,sizeof(u),1,temp);
    }
    fclose(temp);
}
void readbook()
{
    FILE *temp;
    temp=fopen("book.txt","r");
    book *b;
    for(b=front;b!=NULL;b=b->next)
    {
        fread(b,sizeof(book),1,temp);
        if(front==NULL)
        {
            front=b;
            rear=b;
        }
        else
        {
            rear->next=b;
            rear=b;
        }
    }
    fclose(temp);
}
void readuser()
{
    FILE *temp;
    temp=fopen("user.txt","r");
    book *b;
    for(b=frontu;b!=NULL;b=b->next)
    {
        fread(b,sizeof(book),1,temp);
        if(frontu==NULL)
        {
            frontu=b;
            rearu=b;
        }
        else
        {
            rearu->next=b;
            rearu=b;
        }
    }
    fclose(temp);
}
*/
