#include <stdio.h>
#include <windows.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>


#define x 40
#define number_of_char 100
#define number_of_ID 50
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define RESET "\x1b[0m"
#define Row_A 5
#define Cols_A 10
#define Row_B 8
#define Cols_B 10
#define Row_C 10
#define Cols_C 11

struct game_karbar{
    char name[number_of_char];
    char ID[number_of_ID];
    int pasword;
    int last_game_status;//0=angam nashode 1=nime tamam, 2= payan yafte
    char Account_status[5];//off=delete account, on=active account
    int score;
    int map_gamer[10][11];
    int type_lastgame;//1=level one, 2=level two, 3=level three 
    char game_file[number_of_char];
    struct game_karbar *pNEXT;
    struct game_karbar *pBEFOR;
};

struct food{
    int a;
};

void sum(int a);

void gotoxy(int a, int y);
struct game_karbar* addgamer(struct game_karbar *p);
struct game_karbar* loadinfo(char *strfilename);
void updatefile(struct game_karbar *phead, char *strfilename);
void login(struct game_karbar *phead,char *filemapA,char *filemapB,char *filemapC);
int gameA(struct game_karbar *p);
int random(struct game_karbar *p, int *z,int *y);
void printmap(struct game_karbar *p);
void clearsouls(struct game_karbar *p);
void printsouls(struct game_karbar *p);
void clearpacman(struct game_karbar *p);
void printpacman(struct game_karbar *p);
void clearpill(struct game_karbar *p);
void printpill(struct game_karbar *p);
void win();
void lose();
void help_login();
void vorod();
void start_game();
void pac();
void start();
