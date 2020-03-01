FILE *fp;
char uName[10], pwd[10];int i;char c;


struct user{
    char username[10];
    char password[10];
}*userp;



void logIn()
{
    system("cls");
    squareTemplate();
    userp=(struct user *)malloc(sizeof(struct user));


    if ( ( fp=fopen("user.dat", "r+")) == NULL) {
                if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                    printf ("Could not open file\n");
                    exit ( 1);
                }
            }
            gotoxy(38,8);
            printf("Username: ");
            scanf("%9s",uName);
            gotoxy(38,9);
            printf("Password: ");
            scanf("%9s",pwd);
            while ( fread (userp, sizeof(struct user), 1, fp) == 1) {
                if( strcmp ( userp->username, uName) == 0) {
                    printf ("username Matched\n");
                    if( strcmp ( userp->password, pwd) == 0) {
                        printf ("password Matched\n");
                        getche();
                        system("cls");
                         system("cls");
                        printf("Enter your choice");
                        /*UPDATED*/
                        printf("\n1.Issue book\n2.Transactions");
                        char l=getche();
                        switch(l)
                        {
                        case '1':
                            student(userp->username);
                            break;
                        case '2':
                            transaction(userp->username);
                            break;
                        default:
                            printf("Invalid");
                        }

                    }
                }

            }
            free (userp);
    fclose(fp);
}

void signUp()
{

    userp=(struct user *)malloc(sizeof(struct user));

    do
            {
                system("cls");
                squareTemplate();
                if ( ( fp=fopen("user.dat", "a+")) == NULL) {
                    if ( ( fp=fopen("user.dat", "w+")) == NULL) {
                        gotoxy(38,8);
                        printf ("Could not open file\n");
                        exit (1);
                    }
                }
                gotoxy(38,8);
                printf("Choose A Username: ");
                scanf("%9s",userp->username);
                gotoxy(38,9);
                printf("Choose A Password: ");
                scanf("%9s",userp->password);
                fwrite (userp, sizeof(struct user), 1, fp);
                printf("Add another account? (Y/N): ");
                c = getche();
            }while(c=='Y'||c=='y');
            free (userp);
    fclose(fp);
    mainMenu();

}

