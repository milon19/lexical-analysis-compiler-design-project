#include<cstdio>
#include<conio.h>
#include<windows.h>
using namespace std;
int i;

void gotoxy(int x,int y)
{
    COORD CRD;
    CRD.X=x; CRD.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

void setcolor(int ForgC)
{
    WORD wColor;
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    if(GetConsoleScreenBufferInfo(hStdOut, &csbi)){
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }
    return;
}
void box()
{
    gotoxy(10,3); printf("%c",201);
    gotoxy(11,3);
    for(i=1; i<100; i++) printf("%c",205);
    gotoxy(10,24);
    for(i=1; i<=100; i++)  printf("%c",205);
    gotoxy(110,3); printf("%c",187);
    for(i=0; i<=20; i++) {
        gotoxy(10,4+i); printf("%c",186);
    }
    for(i=0; i<=20; i++) {
        gotoxy(110,4+i); printf("%c",186);
    }
    gotoxy(10,24); printf("%c",200);
    gotoxy(110,24); printf("%c",188);
}

void About()
{
    box();
    gotoxy(45,5); printf("Welcome to our project");
    gotoxy(45,6); printf("Created by:");
    char str[100000];
    FILE *fp = fopen("team.txt", "r");
    int x = 15, y = 8;
    for(int i = 1; i <= 5; i++){
        gotoxy(x, y++); fgets(str, sizeof(str), fp);
        printf("%s", str);
    }x = 60, y = 8;
    for(int i = 1; i <= 5; i++){
        gotoxy(x, y++); fgets(str, sizeof(str), fp);
        printf("%s", str);
    }fclose(fp);
    gotoxy(40,22); setcolor(36); printf("Press Any Key to Continue......");
    setcolor(39); getch(); system("cls");
    box();
    gotoxy(45,5); printf("Submitted to");
    fp = fopen("teacher.txt", "r");
    x = 25, y = 9;
    for(int i = 1; i <= 5; i++){
        gotoxy(x, y++); fgets(str, sizeof(str), fp);
        printf("%s", str);
    }fclose(fp);
    gotoxy(40,22); setcolor(36); printf("Press Any Key to Continue......");
    setcolor(39); getch();
}

void Start()
{
    system("cls");
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tPLEASE WAIT OUR PROJECT IS LOADING . . .\n\n");
    printf("\t\t\t");
    for(int loading=0; loading<70; loading++){
        Sleep(40); printf("%c",219);
    }
    system("cls");
}
int main ()
{
    About();
    Start();
    return 0;
}
