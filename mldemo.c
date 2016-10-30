#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>

#define row 20
#define col 20

int delay=100;
char world[row][col];
int pos=0;
int frame=0;
char inp;
char mind=' ';
int lpos=6;
int maybe;
int manual=0;

//create a world
int init() {
    srand ( time(NULL) );
    int i=0;int j=0;
    for (i=0;i<row;i++) {
            for (j=0;j<col;j++) {
                    if(j<=4) { world[i][j]='.'; }
                    else if(j>=15) { world[i][j]='.'; }

                    else { world[i][j]=' '; }
            }
    }
    pos=8; //initial position of enemy
    return 1;
}//end init

float temp=0;
int flag=0;
int i=0;int j=0;

int rblock() {

            for(j=0;j<row;j++) {
                            world[j][pos]='X';      //spawn enemy
                            world[j+1][pos]='X';    //spawn enemy shadow
                            world[j-1][pos]=' ';
                            world[18][lpos]='O';    //spawn player
                            if((lpos==pos)&&j==17) { printf("\n\nCrash!!\n\n");Sleep(1000);exit(0); }
                            flag=1;
                            Sleep(delay);
                            display();

                    }
    randomize();
    rblock();

    return 1;
}//end rblock func

int display() {
    int i=0;
    int j=0;
    frame++;
    system("cls");
    for (i=0;i<row-1;i++) {
            for (j=0;j<col;j++) {
                    printf("%c",world[i][j]);
            }
            printf("\n");
    }
    player();
    printf("\n\nRunning..\n");
    printf("Obs Pos: %d\n",pos-4);
    printf("Score: %d",frame);
    printf("\n\n---------NEURAL NETWORK LOG----------\n\n");
    if(manual==0) {
            printf("Mode : AI\n");
    }else {
            printf("Mode : Manual\n");
    }
    printf("Certainity: %d0%%",maybe);
    printf("\nDecision: %c",mind);

    return 1;
}

int player() {
    if (kbhit()) {
        inp=getch();
        if(inp=='m') { manual=1; }
        if(inp=='i') { manual=0; }
        if(inp=='a') { world[18][lpos]=' ';lpos=lpos-1;}
        if(inp=='d') { world[18][lpos]=' ';lpos=lpos+1;}
        if(inp=='[') {delay=delay+20;}
        if(inp==']') {delay=delay-20;}
    }

    if (manual==0) {
    maybe=rand()%5;

    //Neural Netowork Chain pending
    if (((lpos>=pos)||(lpos==pos-1)||(lpos==pos+1))&&(j==16)) {maybe=0;}
    if (((lpos<=pos)||(lpos==pos-1)||(lpos==pos+1))&&(j==16)) {maybe=1;}
    if (((lpos>=pos)||(lpos==pos-1)||(lpos==pos+1))&&(j==17)) {maybe=0;}
    if (((lpos<=pos)||(lpos==pos-1)||(lpos==pos+1))&&(j==17)) {maybe=1;}
    if (((lpos>=pos)||(lpos==pos-1)||(lpos==pos+1))&&(j==15)) {maybe=0;}
    if (((lpos<=pos)||(lpos==pos-1)||(lpos==pos+1))&&(j==15)) {maybe=1;}
    if (maybe==1) {world[18][lpos]=' ';lpos=lpos-1;mind='L';}
    else if (maybe==0) {world[18][lpos]=' ';lpos=lpos+1;mind='R';}
    else {mind='S';}
    }
    if(lpos<5) {lpos=lpos+1;}
    if (lpos>14) {lpos=lpos-1;}
}

int randomize() {
    pos=rand()%10 + 5;
}

int main() {
    init();
    rblock();

    return 1;
}//end main




