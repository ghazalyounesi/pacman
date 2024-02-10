#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "pac.h"



int main(){


    int i,j;
    int row,cols;
    char strfilename[100];
    char filemapA[100];
    char filemapB[100];
    char filemapC[100];
    strcpy(strfilename,"c:\\gameeeeeeeeeeeeeeebbbff.bin");
    strcpy(filemapA,"c:\\filemapA.bin");
    strcpy(filemapB,"c:\\filemapB.bin");
    strcpy(filemapC,"c:\\filemapC.bin");
    struct game_karbar *phead=NULL;
    struct game_karbar *ptmp;
    int mapA[5][10];
    int mapB[8][10];
    int mapC[10][11];
    for(i=0;i<10;++i){
        mapA[0][i]=0;//0=wall
        mapA[4][i]=0;//0=wall
    }
    for(i=0;i<5;++i){
        mapA[i][0]=0;
        mapA[i][9]=0;
    }
    mapA[1][4]=0;
    mapA[1][7]=0;
    mapA[2][3]=0;
    mapA[2][4]=0;
    mapA[3][7]=0;
    mapA[2][6]=3;//3=pacman
    mapA[2][7]=4;//4=pill
    mapA[3][2]=2;//2=soul
    mapA[1][1]=1;//0=space
    mapA[1][2]=1;//0=space
    mapA[1][3]=1;//0=space
    mapA[1][5]=1;//0=space
    mapA[1][6]=1;//0=space
    mapA[1][8]=1;//0=space
    mapA[2][1]=1;//0=space
    mapA[2][2]=1;//0=space
    mapA[2][5]=1;//0=space
    mapA[2][8]=1;//0=space
    mapA[3][1]=1;//0=space
    mapA[3][3]=1;//0=space
    mapA[3][4]=1;//0=space
    mapA[3][5]=1;//0=space
    mapA[3][6]=1;//0=space
    mapA[3][8]=1;//0=space

    
    for(i=0;i<8;++i){
        mapB[i][0]=0;//0=wall
        mapB[i][9]=0;
    }
    for(i=0;i<10;++i){
        mapB[0][i]=0;
        mapB[7][i]=0;
    }
    mapB[1][4]=0;
    mapB[2][4]=0;
    mapB[6][4]=0;
    mapB[2][5]=0;
    mapB[4][1]=0;
    mapB[4][2]=0;
    mapB[5][7]=0;
    mapB[3][1]=2;//2=soul
    mapB[3][7]=2;
    mapB[5][4]=3;//3=pacman
    mapB[1][5]=4;//4=pill
    mapB[6][1]=4;
    mapB[1][1]=1;//1=space
    mapB[1][2]=1;
    mapB[1][3]=1;
    mapB[1][6]=1;
    mapB[1][7]=1;
    mapB[1][8]=1;
    mapB[2][1]=1;//1=space
    mapB[2][2]=1;
    mapB[2][3]=1;
    mapB[2][6]=1;
    mapB[2][7]=1;
    mapB[2][8]=1;
    mapB[3][4]=1;//1=space
    mapB[3][2]=1;
    mapB[3][3]=1;
    mapB[3][6]=1;
    mapB[3][5]=1;
    mapB[3][8]=1;
    mapB[4][7]=1;//1=space
    mapB[4][3]=1;
    mapB[4][4]=1;
    mapB[4][5]=1;
    mapB[4][6]=1;
    mapB[4][8]=1;
    mapB[5][1]=1;//1=space
    mapB[5][5]=1;
    mapB[5][3]=1;
    mapB[5][6]=1;
    mapB[5][2]=1;
    mapB[5][8]=1;
    mapB[6][7]=1;//1=space
    mapB[6][2]=1;
    mapB[6][3]=1;
    mapB[6][6]=1;
    mapB[6][5]=1;
    mapB[6][8]=1;
    
    
    

    for(i=0;i<10;++i){
        mapC[i][0]=0;//0=wall
        mapC[i][10]=0;
    }
    for(i=0;i<11;++i){
        mapC[0][i]=0;//0=wall
        mapC[9][i]=0;
    }
    mapC[1][4]=0;
    mapC[1][7]=0;
    mapC[2][4]=0;
    mapC[2][3]=0;
    mapC[2][6]=0;
    mapC[3][3]=0;
    mapC[3][6]=0;
    mapC[3][7]=0;
    mapC[4][3]=0;
    mapC[5][9]=0;
    mapC[5][8]=0;
    mapC[6][8]=0;
    mapC[8][4]=0;
    mapC[1][2]=2;//2=soul
    mapC[7][6]=2;
    mapC[1][5]=4;//4=pill
    mapC[2][7]=4;
    mapC[6][9]=4;
    mapC[7][1]=3;//3=pacman
    mapC[1][1]=1;//1=space
    mapC[1][3]=1;
    mapC[1][6]=1;
    mapC[1][8]=1;
    mapC[1][9]=1;
    mapC[2][1]=1;
    mapC[2][2]=1;
    mapC[2][5]=1;
    mapC[2][8]=1;
    mapC[2][9]=1;
    mapC[3][1]=1;
    mapC[3][2]=1;
    mapC[3][4]=1;
    mapC[3][5]=1;
    mapC[3][8]=1;
    mapC[3][9]=1;
    mapC[4][1]=1;
    mapC[4][2]=1;
    mapC[4][4]=1;
    mapC[4][5]=1;
    mapC[4][6]=1;
    mapC[4][7]=1;
    mapC[4][8]=1;
    mapC[4][9]=1;
    mapC[5][1]=1;
    mapC[5][2]=1;
    mapC[5][4]=1;
    mapC[5][5]=1;
    mapC[5][6]=1;
    mapC[5][7]=1;
    mapC[5][3]=1;
    mapC[6][1]=1;
    mapC[6][2]=1;
    mapC[6][4]=1;
    mapC[6][5]=1;
    mapC[6][6]=1;
    mapC[6][7]=1;
    mapC[6][3]=1;
    mapC[7][8]=1;
    mapC[7][2]=1;
    mapC[7][4]=1;
    mapC[7][5]=1;
    mapC[7][9]=1;
    mapC[7][7]=1;
    mapC[7][3]=1;
    mapC[8][1]=1;
    mapC[8][2]=1;
    mapC[8][3]=1;
    mapC[8][5]=1;
    mapC[8][6]=1;
    mapC[8][7]=1;
    mapC[8][8]=1;
    mapC[8][9]=1;
    int A,B,C;
    FILE *fpA;
    fpA= fopen(filemapA,"wb"); 
    fseek(fpA,0,SEEK_SET);
    for(i=0;i<5;++i){
        for(j=0;j<10;++j){
            A=mapA[i][j];
            fwrite(&A,sizeof(int),1,fpA);
        }
    }
    fclose(fpA);
    FILE *fpB;
    fpB= fopen(filemapB,"wb"); 
    fseek(fpB,0,SEEK_SET);
    for(i=0;i<8;++i){
        for(j=0;j<10;++j){
            B=mapB[i][j];
            fwrite(&B,sizeof(int),1,fpB);
        }
    }
    fclose(fpB);
    FILE *fpC;
    fpC= fopen(filemapC,"wb"); 
    fseek(fpC,0,SEEK_SET);
    for(i=0;i<10;++i){
        for(j=0;j<11;++j){
            C=mapC[i][j];
            fwrite(&C,sizeof(int),1,fpC);
        }
    }
    fclose(fpC);
    phead=loadinfo(strfilename);
    start();
            

    int cmd;
     vorod();
    scanf("%d",&cmd);
    while(cmd){
        switch (cmd)
        {
        case 1:
            ptmp=addgamer(phead);
            if(phead==NULL){
              phead=ptmp;
            }
            updatefile(phead,strfilename);
            break;
        case 2:
            login(phead,filemapA,filemapB,filemapC);
            updatefile(phead,strfilename);

        default:
            system("cls");
        
            break;
            
        }
        vorod();
        scanf("%d",&cmd);
        
    }
    
    
    return 0;
}