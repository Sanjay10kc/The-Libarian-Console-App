#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include<time.h>

#include "bookfinder (1).c"
#include "login.c"
#include "bookData (1).c"



static int x,y; // the co-ordinate points

void lineVertical(int x,int y1,int y2)
{
    for(int i=y1;i<=y2; i++){
        gotoxy(x,i);
        printf("*");
    }
}

void lineHorizontal(int x1,int x2,int y)
{
    for(int i=x1;i<=x2; i++){
        gotoxy(i,y);
        printf("*");
    }
}

void gotoxy(int i, int j) // to put the cursor in a certain co-ordinate
{
    x = i;
    y = j;
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

void br(int l) // line break. arguement refers no of lines to be skipped.
{
    gotoxy(x,y+l);
}

void squareTemplate()
{
    for(int p=10;p<=100;p++)
    {
        for(int q=2;q<=30;q++)
        {
            if(p==10||p==100||q==2||q==30)
            {
                gotoxy(p,q);
                printf("*");
            }
        }
    }
}


void welcome() // the welcome page
{
    system("cls");
    system("COLOR 2E"); // change background and text color
    squareTemplate();
    gotoxy(38,8);
    printf("\t          LIBRARIAN");
    br(2);
    printf("The Library Management Console App");
    gotoxy(25,20);
    printf("Made By:");
    br(1);
    printf("1. Rujal Acharya");
    br(1);
    printf("2. Prayag Man Mane");
    br(1);
    printf("3. Sanjay K.C.");
    br(1);
    printf("4. Asmin Silwal");
    gotoxy(38,14);
    printf("     Press any key to continue ");
    char i;
    //scanf("%c",&i);
    i = getche();
    mainMenu();
    gotoxy(25,7);

}

void mainMenu()// The Main Menu
{
    system("cls");
    squareTemplate();
    gotoxy(48,8);
    printf("MENU");
    gotoxy(30,11);
    printf("1. Log In (if you already have an account)");
    br(1);
    printf("2. Sign Up (if you don't have an account)");
    br(1);
    printf("3. Book Searcher");
    br(1);
    printf("4. Exit");
    gotoxy(25,20);
    printf("Enter your choice  ");
    char i = getche();
    switch(i)
    {
        case '1':
            logIn();
            break;
        case '2':
            signUp();
            break;
        case '3':
            bookFinder();
            break;
        case '4':
            exitPage();
            break;
        default:
            mainMenuError();
    }
}

void mainMenuError()
{
    system("cls");
    squareTemplate();
    gotoxy(26,8);
    printf("You have entered invalid information");
    br(2);
    printf("Do you want to return to the main menu(Y/N)? ");
    char ch = getche();
    switch(ch)
    {
        case 'Y':
        case 'y':
            mainMenu();
            break;
        case 'N':
        case 'n':
            exitPage();
            break;
        default:
            mainMenuError();
    }
}

void exitPage()
{
    system("cls");
    squareTemplate();
    gotoxy(26,8);
    printf("Thank you for using LIBRARIAN -> The Library Management Console App");
    br(1);
    printf("\t\t   See You Soon");
    getche();
    blankPage();
}

void blankPage()
{
    system("cls");
}

void main()
{
    welcome();
}

