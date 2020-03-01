void bookFinder()
{
    system("cls");
    squareTemplate();
    system("COLOR F6");
    gotoxy(46,8);
    printf("BOOKFINDER");
    gotoxy(36,10);
    printf("Find the location of the books");
    gotoxy(40,14);
    printf("Press any key to continue  ");
    char i = getche();
    bookFinderMenu();
}

void bookFinderMenu()
{
    system("cls");
    squareTemplate();
    gotoxy(48,8);
    printf("BOOKFINDER");
    gotoxy(36,10);
    printf("1. Map of library");
    br(1);
    printf("2. Search for a particular book");
    br(1);
    printf("3. Exit from BOOKFINDER");
    gotoxy(40,20);
    printf("Enter your choice  ");
    char i = getche();
    switch(i)
    {
        case '1':
            blankMap();
            break;
        case '2':
            //bookOptions();
            break;
        case '3':
            system("COLOR 2E");
            mainMenu();
            break;
        default:
            bookFinderMenuError();
    }
}

void bookFinderMenuError()
{
    system("cls");
    squareTemplate();
    gotoxy(26,8);
    printf("You have entered invalid information");
    br(2);
    printf("Do you want to return to the BOOKFINDER(Y/N)? ");
    char ch = getche();
    switch(ch)
    {
        case 'Y':
        case 'y':
            bookFinderMenu();
            break;
        case 'N':
        case 'n':
            mainMenu();
            break;
        default:
            mainMenuError();
    }
}

void blankMap()
{
    system("cls");
    system("COLOR 0A");
    for(int p=5;p<=100;p++)
    {
        for(int q=3;q<=25;q++)
        {
            if(p==5||p==100||q==3||q==25)
            {
                gotoxy(p,q);
                printf("*");
            }
        }
    }
    // The map starts here
    lineHorizontal(5,100,8);
    lineVertical(75,8,25);
    lineVertical(25,8,15);
    lineHorizontal(5,75,15);
    lineVertical(36,15,25);


    getche();
    bookFinderMenu();
}
