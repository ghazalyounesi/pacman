#include "pac.h"


void sum(int a){
    ++a;
    printf("%d", a);
}

void gotoxy(int a, int hh) {
    COORD pos = {a, hh};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

struct game_karbar* addgamer(struct game_karbar *p){
   system("cls");
   struct game_karbar *pNewItem;
   struct game_karbar *po=NULL;
   struct game_karbar *poo=NULL;
   struct game_karbar *ph=NULL;
   int number=0;
   
   po=p;
   poo=p;
   ph=p;
   pNewItem = (struct game_karbar*)malloc(sizeof(struct game_karbar));
   pNewItem->pBEFOR = pNewItem->pNEXT=NULL;
   int i;
   char contolor[number_of_ID];
   printf("please enter your user information\n");
   int b=1;
  
   while(b){
      printf("enter your ID\n");
      
      scanf("%s",contolor);
      poo=p;
      if(poo==NULL){
        b=0;
        break;
      }
      while(poo){
         if(strcmp(poo->ID,contolor)==0){
           
           printf("this ID is already taken, please enter new ID\n");
           b=1;
           break;
        }else{
            b=0;
        }
        poo=poo->pNEXT;
      }

   }
   while(ph){
       ++number;
       ph=ph->pNEXT;
   }
   strcpy(pNewItem->ID,contolor);
   
   if(p==NULL){
      p=pNewItem;
      po=pNewItem;
      pNewItem->pBEFOR=NULL;
   }
   else{
      while(po->pNEXT){
         po=po->pNEXT;
      }
         
      po->pNEXT=pNewItem;
      pNewItem->pBEFOR=po;
   }
   

   printf("enter your username\n");
   scanf("%s",pNewItem->name);
   printf("create a password\n");
   scanf("%d",&pNewItem->pasword);
   pNewItem->type_lastgame=0;
   pNewItem->score=0;
   pNewItem->last_game_status=0;
   //pNewItem->map_gamer[10][11]={};
   pNewItem->pNEXT=NULL;
   ++number;
   sprintf(pNewItem->game_file,"c:\\gamefile%d.bin",number);
   
   strcpy(pNewItem->Account_status,"on");
   return pNewItem;
   
    
}
struct game_karbar* loadinfo(char *strfilename){
   struct game_karbar tmp , *phead=NULL, *pNewItem, *pLastItem;
   int map;
   int i,j;
   int row,cols;
   FILE *fp;
   fp = fopen(strfilename, "rb");
   if( fp == NULL)
      return NULL;
   char filegame[100];
   while(fread(&tmp, sizeof(struct game_karbar), 1, fp) > 0){
      pNewItem = (struct game_karbar*)malloc(sizeof(struct game_karbar));
      pNewItem->pBEFOR = pNewItem->pNEXT = NULL;
      strcpy(pNewItem->ID,tmp.ID);
      strcpy(pNewItem->name,tmp.name);
      strcpy(pNewItem->game_file,tmp.game_file);
      strcpy(pNewItem->Account_status,tmp.Account_status);
      pNewItem->last_game_status=tmp.last_game_status;
      pNewItem->pasword=tmp.pasword;
      pNewItem->type_lastgame=tmp.type_lastgame;
      pNewItem->score=tmp.score;
      if(pNewItem->type_lastgame==1){
         row=5;
         cols=10;
      }else if(pNewItem->type_lastgame==2){
         row=8;
         cols=10;
      }else if(pNewItem->type_lastgame==3){
         row=10;
         cols=11;
      }else if(pNewItem->type_lastgame==0){
         row=cols=0;
      }
      strcpy(filegame,pNewItem->game_file);
      FILE *fpp;
      fpp = fopen(filegame, "rb");
      for(i=0;i<row;++i){
          for(j=0;j<cols;++j){
            fread(&map,sizeof(int),1,fpp);
            pNewItem->map_gamer[i][j]=map;
          }
      }
      fclose(fpp);

      if(phead == NULL)
            pLastItem = phead = pNewItem;
        else
        {
            pNewItem->pBEFOR = pLastItem;
            pLastItem->pNEXT = pNewItem;  
            pLastItem =  pNewItem;
        }      
      
   }
   fclose(fp);
   return phead;

}

void updatefile(struct game_karbar *phead, char *strfilename){
   int i,j;
   int row,cols;
   char gamefilewr[100];
   int c;
   struct game_karbar *pp=phead;
   FILE *fp1;
   fp1= fopen(strfilename, "wb");
   fseek(fp1,0,SEEK_SET);
   while(pp){
        fwrite(pp,sizeof(struct game_karbar),1,fp1);
        strcpy(gamefilewr,pp->game_file);
        FILE *fp2;
        fp2= fopen(gamefilewr,"wb"); 
        fseek(fp2,0,SEEK_SET);
        if(pp->type_lastgame==1){
           row=5;
           cols=10;
        }else if(pp->type_lastgame==2){
           row=8;
           cols=10;
        }else if(pp->type_lastgame==3){
           row=10;
           cols=11;
        }else if(pp->type_lastgame==0){
           row=cols=0;
        }
        for(i=0;i<row;++i){
          for(j=0;j<cols;++j){
            c=pp->map_gamer[i][j];
            fwrite(&c,sizeof(int),1,fp2);
          }
        }
        
        fclose(fp2);
        pp=pp->pNEXT;
   } 
   fclose(fp1); 
}

void printmap(struct game_karbar *p){
   system("cls");
   int rowss,cloums;
   int i,j;
   int a1,y1;//mokhtasat console
   int a2,y2;
   if(p->type_lastgame==0){
      rowss=cloums=0;
   }else if(p->type_lastgame==1){
      rowss=5;
      cloums=10;
   }else if(p->type_lastgame==2){
      rowss=8;
      cloums=10;
   }else if(p->type_lastgame==3){
      rowss=10;
      cloums=11;
   }
   for(i=0;i<rowss;++i){
      for(j=0;j<cloums;++j){
         if(p->map_gamer[i][j]==0){
            a1=6*i+1;
            y1=6*j+1;
            a2=6*i+7;
            y2=6*j+7;
            for(a1=6*i+1;a1<a2;++a1){
               
               for(y1=6*j+1;y1<y2;++y1){
                  gotoxy(y1,a1);
                  printf(BLUE"."RESET);
               }
            }


         }else if(p->map_gamer[i][j]==1){

         }else if(p->map_gamer[i][j]==2){
            
            a1=6*i+2;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("_");
            a1=6*i+3;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+3;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+4;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("|");
            a1=6*i+4;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("|");
            a1=6*i+5;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("|");
            a1=6*i+5;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("|");
            a1=6*i+6;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+6;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+6;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("^");
            a1=6*i+6;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("^");
            a1=6*i+6;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("^");
            a1=6*i+4;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("O");
            a1=6*i+4;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("O");



            
         }else if(p->map_gamer[i][j]==3){
            printf(YELLOW);
            a1=6*i+2;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+2;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+3;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+3;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+4;
            y1=6*j+1;
            gotoxy(y1,a1);
            printf("/"); 
            a1=6*i+5;
            y1=6*j+1;
            gotoxy(y1,a1);
            printf("\\"); 
            a1=6*i+6;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+6;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+6;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+6;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+5;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("."); 
            a1=6*i+4;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+4;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+5;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+4;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("."); 
            a1=6*i+5;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+4;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+3;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("O"); 
            a1=6*i+3;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("O"); 
            printf(RESET);
            
            
         }else if(p->map_gamer[i][j]==4){
            printf(RED);
            a1=6*i+4;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("-");
            a1=6*i+4;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("."); 
            a1=6*i+5;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+5;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("-");
             a1=6*i+5;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("'");
             a1=6*i+4;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("."); 
            printf(RESET);
            
         }
      }
   }
   i=70;
   j=15;
   gotoxy(i,j);
   printf(GREEN "Enter '8' to move up" RESET);
   i=70;
   j=16;
   gotoxy(i,j);
   printf(YELLOW "Enter '2' to move down" RESET);
   i=70;
   j=17;
   gotoxy(i,j);
   printf(RED "Enter '6' to move right" RESET);
   i=70;
   j=18;
   gotoxy(i,j);
   printf(BLUE "Enter '4' to move left" RESET);
   i=70;
   j=19;
   gotoxy(i,j);
   printf(BLUE "Enter '0' to end the game" RESET);


}

void clearsouls(struct game_karbar *p){
   int rowss,cloums;
   int i,j;
   int a1,y1;//mokhtasat console
   int a2,y2;
   if(p->type_lastgame==0){
      rowss=cloums=0;
   }else if(p->type_lastgame==1){
      rowss=5;
      cloums=10;
   }else if(p->type_lastgame==2){
      rowss=8;
      cloums=10;
   }else if(p->type_lastgame==3){
      rowss=10;
      cloums=11;
   }
   for(i=0;i<rowss;++i){
      for(j=0;j<cloums;++j){
         if(p->map_gamer[i][j]==2){
            a1=6*i+1;
            y1=6*j+1;
            a2=6*i+7;
            y2=6*j+7;
            for(a1=6*i+1;a1<a2;++a1){
               
               for(y1=6*j+1;y1<y2;++y1){
                  gotoxy(y1,a1);
                  printf(" ");
               }
            }
         }
      }
   }

}

void printsouls(struct game_karbar *p){
   int rowss,cloums;
   int i,j;
   int a1,y1;//mokhtasat console
   int a2,y2;
   if(p->type_lastgame==0){
      rowss=cloums=0;
   }else if(p->type_lastgame==1){
      rowss=5;
      cloums=10;
   }else if(p->type_lastgame==2){
      rowss=8;
      cloums=10;
   }else if(p->type_lastgame==3){
      rowss=10;
      cloums=11;
   }
   for(i=0;i<rowss;++i){
      for(j=0;j<cloums;++j){
         if(p->map_gamer[i][j]==2){

            a1=6*i+2;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("_");
            a1=6*i+3;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+3;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+4;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("|");
            a1=6*i+4;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("|");
            a1=6*i+5;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("|");
            a1=6*i+5;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("|");
            a1=6*i+6;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+6;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+6;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("^");
            a1=6*i+6;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("^");
            a1=6*i+6;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("^");
            a1=6*i+4;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("O");
            a1=6*i+4;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("O");
  
         }
      }
   }
   i=100;
   j=20;
   gotoxy(i,j);

}
void clearpacman(struct game_karbar *p){
   int rowss,cloums;
   int i,j;
   int a1,y1;//mokhtasat console
   int a2,y2;
   if(p->type_lastgame==0){
      rowss=cloums=0;
   }else if(p->type_lastgame==1){
      rowss=5;
      cloums=10;
   }else if(p->type_lastgame==2){
      rowss=8;
      cloums=10;
   }else if(p->type_lastgame==3){
      rowss=10;
      cloums=11;
   }
   for(i=0;i<rowss;++i){
      for(j=0;j<cloums;++j){
         if(p->map_gamer[i][j]==3){
            a1=6*i+1;
            y1=6*j+1;
            a2=6*i+7;
            y2=6*j+7;
            for(a1=6*i+1;a1<a2;++a1){
               
               for(y1=6*j+1;y1<y2;++y1){
                  gotoxy(y1,a1);
                  printf(" ");
               }
            }
         }
      }
   }

}

void printpacman(struct game_karbar *p){
   int rowss,cloums;
   int i,j;
   int a1,y1;//mokhtasat console
   int a2,y2;
   if(p->type_lastgame==0){
      rowss=cloums=0;
   }else if(p->type_lastgame==1){
      rowss=5;
      cloums=10;
   }else if(p->type_lastgame==2){
      rowss=8;
      cloums=10;
   }else if(p->type_lastgame==3){
      rowss=10;
      cloums=11;
   }
   for(i=0;i<rowss;++i){
      for(j=0;j<cloums;++j){
         if(p->map_gamer[i][j]==3){
            printf(YELLOW);
            a1=6*i+2;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+2;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+3;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+3;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+4;
            y1=6*j+1;
            gotoxy(y1,a1);
            printf("/"); 
            a1=6*i+5;
            y1=6*j+1;
            gotoxy(y1,a1);
            printf("\\"); 
            a1=6*i+6;
            y1=6*j+2;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+6;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+6;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+6;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+5;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("."); 
            a1=6*i+4;
            y1=6*j+6;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+4;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+5;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+4;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("."); 
            a1=6*i+5;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+4;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+3;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("O"); 
            a1=6*i+3;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("O"); 
            printf(RESET);
            
         }
      }
   }
   i=100;
   j=20;
   gotoxy(i,j);

}

void clearpill(struct game_karbar *p){
   int rowss,cloums;
   int i,j;
   int a1,y1;//mokhtasat console
   int a2,y2;
   if(p->type_lastgame==0){
      rowss=cloums=0;
   }else if(p->type_lastgame==1){
      rowss=5;
      cloums=10;
   }else if(p->type_lastgame==2){
      rowss=8;
      cloums=10;
   }else if(p->type_lastgame==3){
      rowss=10;
      cloums=11;
   }
   for(i=0;i<rowss;++i){
      for(j=0;j<cloums;++j){
         if(p->map_gamer[i][j]==4){
            a1=6*i+1;
            y1=6*j+1;
            a2=6*i+7;
            y2=6*j+7;
            for(a1=6*i+1;a1<a2;++a1){
               
               for(y1=6*j+1;y1<y2;++y1){
                  gotoxy(y1,a1);
                  printf(" ");
               }
            }
         }
      }
   }

}

void printpill(struct game_karbar *p){
      int rowss,cloums;
   int i,j;
   int a1,y1;//mokhtasat console
   int a2,y2;
   if(p->type_lastgame==0){
      rowss=cloums=0;
   }else if(p->type_lastgame==1){
      rowss=5;
      cloums=10;
   }else if(p->type_lastgame==2){
      rowss=8;
      cloums=10;
   }else if(p->type_lastgame==3){
      rowss=10;
      cloums=11;
   }
   for(i=0;i<rowss;++i){
      for(j=0;j<cloums;++j){
         if(p->map_gamer[i][j]==4){
            printf(RED);
            a1=6*i+4;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("-");
            a1=6*i+4;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("."); 
            a1=6*i+5;
            y1=6*j+3;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+5;
            y1=6*j+4;
            gotoxy(y1,a1);
            printf("-");
            a1=6*i+5;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("'");
             a1=6*i+4;
            y1=6*j+5;
            gotoxy(y1,a1);
            printf("."); 
            printf(RESET);
         }
      }
   }
   i=100;
   j=20;
   gotoxy(i,j);


}

void win(){
   system("cls");
   int i,j;
   i=10;
   j=5;
   gotoxy(i,j);
   printf(RED "X--YOU WIN--X" RESET);
   sleep(1);
   system("cls");
   i=120;
   j=5;
   gotoxy(i,j);
   printf(BLUE "X--YOU WIN--X" RESET);
   sleep(1);
   system("cls");
   i=80;
   j=20;
   gotoxy(i,j);
   printf(YELLOW "X--YOU WIN--X" RESET);
   sleep(1);
   system("cls");
   for(i=140,j=5;i>70;i=i-5,j=j+2){
      gotoxy(i,j);
      printf(GREEN "X--YOU WIN--X" RESET); 
   }
   for(i=62,j=29;i>30;i=i-5,j=j-2){
      gotoxy(i,j);
      printf(GREEN "X--YOU WIN--X" RESET); 
   }
   sleep(5);
   
}
void lose(){
   system("cls");
   int i,j;
   i=10;
   j=5;
   gotoxy(i,j);
   printf(RED "X--YOU lose--X" RESET);
   sleep(1);
   system("cls");
   i=120;
   j=5;
   gotoxy(i,j);
   printf(BLUE "X--YOU lose--X" RESET);
   sleep(1);
   system("cls");
   i=80;
   j=20;
   gotoxy(i,j);
   printf(YELLOW "X--YOU lose--X" RESET);
   sleep(1);
   system("cls");
   for(i=10,j=5;i<35;i=i+5,j=j+2){
      gotoxy(i,j);
      printf(RED "X--YOU lose--X" RESET);
   }
   for(i=25,j=15;i>5;i=i-5,j=j+2){
      gotoxy(i,j);
      printf(RED "X--YOU lose--X" RESET);
   }
   for(i=45,j=13;j>3;i=i+5,j=j-2){
      gotoxy(i,j);
      printf(RED "X--YOU lose--X" RESET);
   }
   for(i=50,j=15;j<23;j=j+2,i=i+5){
      gotoxy(i,j);
      printf(RED "X--YOU lose--X" RESET);
   }
   sleep(5);

}

void start_game(){
   system("cls");
   int row,cols,i;
   row=70;
   cols=10;
   gotoxy(row,cols);
   printf("_______________");
   row=86;
   for(i=0;i<10;++i){
       ++cols;
       gotoxy(row,cols);
       printf("|");
   }
   row=70;
   cols=21;
   gotoxy(row,cols);
   printf("_______________");
   row=86;
   for(i=0;i<10;++i){
       ++cols;
       gotoxy(row,cols);
       printf("|");
   }
   row=70;
   cols=32;
   gotoxy(row,cols);
   printf("_______________");
   
   sleep(1);
   system("cls");
   row=70;
   cols=10;
   gotoxy(row,cols);
   printf("_______________");
   row=86;
   for(i=0;i<10;++i){
       ++cols;
       gotoxy(row,cols);
       printf("|");
   }
   row=70;
   cols=21;
   gotoxy(row,cols);
   printf("_______________");
   row=69;
   for(i=0;i<10;++i){
       ++cols;
       gotoxy(row,cols);
       printf("|");
   }
   row=70;
   cols=32;
   gotoxy(row,cols);
   printf("_______________");
   
   sleep(1);
   system("cls");
   row=86;
   cols=10;
   for(i=0;i<20;++i){
       ++cols;
       gotoxy(row,cols);
       printf("|");
   }
   sleep(1);

}

int random(struct game_karbar *p, int *z,int *y){
   int i,j;
   int move;
   move =rand()%4;
   if(move==0){
      if(p->map_gamer[(*z)+1][(*y)]==1){
         clearsouls(p);
         p->map_gamer[(*z)+1][(*y)]=2;
         p->map_gamer[(*z)][(*y)]=1;
         (*z)++;
         printsouls(p);
         sleep(1);
         return 1;

      }else if(p->map_gamer[(*z)+1][(*y)]==2){
         random(p,z,y);
         return 1;
      }else if(p->map_gamer[(*z)+1][(*y)]==3){
         clearsouls(p);
         clearpacman(p);
         p->map_gamer[(*z)+1][(*y)]=2;
         p->map_gamer[(*z)][(*y)]=1;
         (*z)++;
         printsouls(p);
         i=70;
         j=5;
         lose();
         return 0;

      }else if(p->map_gamer[(*z)+1][(*y)]==4){
         random(p,z,y);      
         return 1;

      }else if(p->map_gamer[(*z)+1][(*y)]==0){
         random(p,z,y);      
         return 1;

      }

   }else if(move==1){
      if(p->map_gamer[(*z)-1][(*y)]==1){
         clearsouls(p);
         p->map_gamer[(*z)-1][(*y)]=2;
         p->map_gamer[(*z)][(*y)]=1;
         (*z)--;
         
         printsouls(p);
         sleep(1);
         return 1;

      }else if(p->map_gamer[(*z)-1][(*y)]==2){
         random(p,z,y);      
         return 1;
      }else if(p->map_gamer[(*z)-1][(*y)]==3){
         clearsouls(p);
         clearpacman(p);
         p->map_gamer[(*z)-1][(*y)]=2;
         p->map_gamer[(*z)][(*y)]=1;
         (*z)--;
         
         printsouls(p);
         i=70;
         j=5;
         lose();
         return 0;

      }else if(p->map_gamer[(*z)-1][(*y)]==4){
         random(p,z,y);      
         return 1;

      }else if(p->map_gamer[(*z)-1][(*y)]==0){
         random(p,z,y);      
         return 1;

      }

   }else if(move==2){
      if(p->map_gamer[(*z)][(*y)+1]==1){
         clearsouls(p);
         p->map_gamer[(*z)][(*y)+1]=2;
         p->map_gamer[(*z)][(*y)]=1;
         (*y)++;
         
         printsouls(p);
         sleep(1);
         return 1;

      }else if(p->map_gamer[(*z)][(*y)+1]==2){
         random(p,z,y);      
         return 1;
      }else if(p->map_gamer[(*z)][(*y)+1]==3){
         clearpacman(p);
         clearsouls(p);
         p->map_gamer[(*z)][(*y)+1]=2;
         p->map_gamer[(*z)][(*y)]=1;
         (*y)++;
         
         printsouls(p);
         i=70;
         j=5;
         lose();
         return 0;

      }else if(p->map_gamer[(*z)][(*y)+1]==4){
         random(p,z,y);      
         return 1;

      }else if(p->map_gamer[(*z)][(*y)+1]==0){
         random(p,z,y);      
         return 1;

      }
      
   }else if(move==3){
      if(p->map_gamer[(*z)][(*y)-1]==1){
         clearsouls(p);
         p->map_gamer[(*z)][(*y)-1]=2;
         p->map_gamer[(*z)][(*y)]=1;
         (*y)--;
         
         printsouls(p);
         sleep(1);
         return 1;

      }else if(p->map_gamer[(*z)][(*y)-1]==2){
         random(p,z,y);      
         return 1;
      }else if(p->map_gamer[(*z)][(*y)-1]==3){
         clearsouls(p);
         clearpacman(p);
         p->map_gamer[(*z)][(*y)-1]=2;
         p->map_gamer[(*z)][(*y)]=1;
         (*y)--;
         printsouls(p);
         i=70;
         j=8;
         lose();
         return 0;

      }else if(p->map_gamer[(*z)][(*y)-1]==4){
         random(p,z,y);      
         return 1;

      }else if(p->map_gamer[(*z)][(*y)-1]==0){
         random(p,z,y);      
         return 1;

      }
      
   }
}

int gameA(struct game_karbar *p){
   start_game();
   char buffer[50];
   int input=111;
   int row,cols;
   int e,o,i,j,z1,y1,z2,y2;
   int b1,b2;
   b1=b2=1;
   int a=1;
   int pil=0;
   int score=0;
   if(p->type_lastgame==1){
      row=5;
      cols=10;
   }else if(p->type_lastgame==2){
      row=8;
      cols=10;
   }else if(p->type_lastgame==3){
      row=10;
      cols=11;
   }
   for(i=0;i<row;++i){
      for(j=0;j<cols;++j){
         if(p->map_gamer[i][j]==3){
            e=i;
            o=j;
         }
      }
   }
   for(i=0;i<row;++i){
      for(j=0;j<cols;++j){
         if(p->map_gamer[i][j]==2){
            z1=i;
            y1=j;
         }
      }
   }
   if(p->type_lastgame != 1){
      for(i=0;i<row;++i){
         for(j=0;j<cols;++j){
            if(p->map_gamer[i][j]==2){
               if(i == z1 && j==y1 ){

               }else{
                  z2=i;
                  y2=j;
               }
               
            }
         }
      }
   }
   for(i=0;i<row;++i){
      for(j=0;j<cols;++j){
         if(p->map_gamer[i][j]==4){
            ++pil;
         }
      }
   }
   if(p->type_lastgame==1){
      score=(1-pil)*5;
   }else if(p->type_lastgame==2){
      score=(2-pil)*5;
   }else if(p->type_lastgame==3){
      score=(3-pil)*5;
   }
   system("cls");
   printmap(p);
   row=70;
   cols=10;
   gotoxy(row,cols);
   printf(GREEN "username:"RESET);
   printf("%s",p->name);
   row=70;
   cols=11;
   gotoxy(row,cols);
   printf(GREEN "level:"RESET);
   printf("%d",p->score);
   row=70;
   cols=12;
   gotoxy(row,cols);
   printf(GREEN "score:"RESET);
   printf("%d",score);
   while(1){
      a=1;
      b1=b2=1;
      while(a){
         
        b1=random(p,&z1,&y1);         
        if(b1==0){
            --(p->score);
            p->last_game_status=2;
            return 0;
         }
         if(p->type_lastgame != 1){
            b2=random(p,&z2,&y2);
            if(b2==0){
              --(p->score);
              p->last_game_status=2;
              return 0;
            }
         }
         if(kbhit()){
            fgets(buffer,sizeof(buffer),stdin);
            sscanf(buffer,"%d",&input);
            a=0;
         }

      }
      
      if(input==0){
        char gamefilewr[100];
        int c;
        strcpy(gamefilewr,p->game_file);
        FILE *fp2;
        fp2= fopen(gamefilewr,"wb"); 
        fseek(fp2,0,SEEK_SET);
        if(p->type_lastgame==1){
           row=5;
           cols=10;
        }else if(p->type_lastgame==2){
           row=8;
           cols=10;
        }else if(p->type_lastgame==3){
           row=10;
           cols=11;
        }else if(p->type_lastgame==0){
           row=cols=0;
        }
        for(i=0;i<row;++i){
          for(j=0;j<cols;++j){
            c=p->map_gamer[i][j];
            fwrite(&c,sizeof(int),1,fp2);
          }
        }
        
        fclose(fp2);
        p->last_game_status=1;
        return 3;
      
      }else if(input==2){
         if(p->map_gamer[e+1][o]==0){
            
            

         }else if(p->map_gamer[e+1][o]==1){
            clearpacman(p);
            p->map_gamer[e+1][o]=3;
            p->map_gamer[e][o]=1;
            ++e;
            
            printpacman(p);

         }else if(p->map_gamer[e+1][o]==2){
            clearpacman(p);
            p->map_gamer[e+1][o]=2;
            p->map_gamer[e][o]=1;
            
            i=70;
            j=8;
            lose();
            b1=0;
            --(p->score);
            p->last_game_status=2;
            return 0;
            
         }else if(p->map_gamer[e+1][o]==4){
            clearpacman(p);
            clearpill(p);
            p->map_gamer[e+1][o]=3;
            p->map_gamer[e][o]=1;
            ++e;
            --pil;
            if(p->type_lastgame==1){
               score=(1-pil)*5;
            }else if(p->type_lastgame==2){
               score=(2-pil)*5;
            }else if(p->type_lastgame==3){
               score=(3-pil)*5;
            }
            printpacman(p);
            printpill(p);
            row=76;
            cols=12;
            gotoxy(row,cols);
            printf("     ");
            row=76;
            cols=12;
            gotoxy(row,cols);
            printf("%d",score);
            if(p->type_lastgame==1){
               if(pil==0){
                  b1=2;
               }
            }else if(p->type_lastgame==2){
               if(pil==0){
                  b1=2;
               }

            }else if(p->type_lastgame==3){
               if(pil==0){
                  b1=2;
               }
               
            }
            if(b1==2){
               win();
               p->score=(p->score)+3;
               p->last_game_status=2;
               return 2;
            }
         }
         
      }else if(input==8){
         if(p->map_gamer[e-1][o]==0){
            

         }else if(p->map_gamer[e-1][o]==1){
            clearpacman(p);
            p->map_gamer[e-1][o]=3;
            p->map_gamer[e][o]=1;
            --e;
            
            printpacman(p);
           

         }else if(p->map_gamer[e-1][o]==2){
            clearpacman(p);
            p->map_gamer[e-1][o]=2;
            p->map_gamer[e][o]=1;
            --e;
            i=70;
            j=8;
            lose();
            b1=0;
            --(p->score);
            p->last_game_status=2;
            return 0;
            
         }else if(p->map_gamer[e-1][o]==4){
            clearpacman(p);
            clearpill(p);
            p->map_gamer[e-1][o]=3;
            p->map_gamer[e][o]=1;
            --e;
            --pil;
            if(p->type_lastgame==1){
               score=(1-pil)*5;
            }else if(p->type_lastgame==2){
               score=(2-pil)*5;
            }else if(p->type_lastgame==3){
               score=(3-pil)*5;
            }
            printpacman(p);
            printpill(p);
            row=76;
            cols=12;
            gotoxy(row,cols);
            printf("     ");
            row=76;
            cols=12;
            gotoxy(row,cols);
            printf("%d",score);
            if(p->type_lastgame==1){
               if(pil==0){
                  b1=2;
               }
            }else if(p->type_lastgame==2){
               if(pil==0){
                  b1=2;
               }

            }else if(p->type_lastgame==3){
               if(pil==0){
                  b1=2;
               }
               
            }
            if(b1==2){
               win();
               p->score=(p->score)+3;
               p->last_game_status=2;
               return 2;
            }
         }

      }else if(input==6){
         if(p->map_gamer[e][o+1]==0){
            

         }else if(p->map_gamer[e][o+1]==1){
            clearpacman(p);
            p->map_gamer[e][o+1]=3;
            p->map_gamer[e][o]=1;
            ++o;
            
            printpacman(p);
            

         }else if(p->map_gamer[e][o+1]==2){
            clearpacman(p);
            p->map_gamer[e][o+1]=2;
            p->map_gamer[e][o]=1;
            ++o;
            i=70;
            j=8;
            lose();
            b1=0;
            --(p->score);
            p->last_game_status=2;
            return 0;
         }else if(p->map_gamer[e][o+1]==4){
            clearpill(p);
            clearpacman(p);
            p->map_gamer[e][o+1]=3;
            p->map_gamer[e][o]=1;
            ++o;
            --pil;
            if(p->type_lastgame==1){
               score=(1-pil)*5;
            }else if(p->type_lastgame==2){
               score=(2-pil)*5;
            }else if(p->type_lastgame==3){
               score=(3-pil)*5;
            }
            printpacman(p);
            printpill(p);
            row=76;
            cols=12;
            gotoxy(row,cols);
            printf("     ");
            row=76;
            cols=12;
            gotoxy(row,cols);
            printf("%d",score);
            if(p->type_lastgame==1){
               if(pil==0){
                  b1=2;
               }
            }else if(p->type_lastgame==2){
               if(pil==0){
                  b1=2;
               }

            }else if(p->type_lastgame==3){
               if(pil==0){
                  b1=2;
               }
               
            }
            if(b1==2){
               win();
               p->score=(p->score)+3;
               p->last_game_status=2;
               return 2;
            }
         }
         
      }else if(input==4){
         if(p->map_gamer[e][o-1]==0){
           

         }else if(p->map_gamer[e][o-1]==1){
            clearpacman(p);
            p->map_gamer[e][o-1]=3;
            p->map_gamer[e][o]=1;
            --o;
            
            printpacman(p);
            

         }else if(p->map_gamer[e][o-1]==2){
            clearpacman(p);
            p->map_gamer[e][o-1]=2;
            p->map_gamer[e][o]=1;
            --o;
            i=70;
            j=8;
            lose();
            b1=0;
            --(p->score);
            p->last_game_status=2;
            return 0;
         }else if(p->map_gamer[e][o-1]==4){
            clearpacman(p);
            clearpill(p);
            p->map_gamer[e][o-1]=3;
            p->map_gamer[e][o]=1;
            --o;
            --pil;
            if(p->type_lastgame==1){
               score=(1-pil)*5;
            }else if(p->type_lastgame==2){
               score=(2-pil)*5;
            }else if(p->type_lastgame==3){
               score=(3-pil)*5;
            }
            printpacman(p);
            printpill(p);
            row=76;
            cols=12;
            gotoxy(row,cols);
            printf("     ");
            row=76;
            cols=12;
            gotoxy(row,cols);
            printf("%d",score);
            if(p->type_lastgame==1){
               if(pil==0){
                  b1=2;
               }
            }else if(p->type_lastgame==2){
               if(pil==0){
                  b1=2;
               }

            }else if(p->type_lastgame==3){
               if(pil==0){
                  b1=2;
               }
               
            }
            if(b1==2){
               win();
               p->score=(p->score)+3;
               p->last_game_status=2;
               return 2;
            }
            
         }
      }

      if(b1==0){
         --(p->score);
         p->last_game_status=2;
         return 0;
      }else if(b1==2){
         p->score=(p->score)+3;
         p->last_game_status=2;
         return 2;
      }
   }
   
}

void help_login(){
      int row,cols;
      row=70;
      cols=10;
      gotoxy(row,cols);
      printf(GREEN "Enter 1 for new game");
      row=70;
      cols=11;
      gotoxy(row,cols);
      printf("Enter 2 for delete account");
      row=70;
      cols=12;
      gotoxy(row,cols);
      printf("Enter 0 for logout"RESET); 

}


void login(struct game_karbar *phead,char *filemapA,char *filemapB,char *filemapC){
   system("cls");
   int row,cols;
   
   printf("Enter your ID\n");
   char id[10];
   scanf("%s",id);
   struct game_karbar *p=NULL;
   struct game_karbar *pp;
   pp=phead;
   while(pp){
      if(strcmp(pp->Account_status,"on")==0){
         if(strcmp(pp->ID,id)==0){
             p=pp;
             break;
         }else{
             pp=pp->pNEXT;
         }
         
      }else{
         pp=pp->pNEXT;
      }
   }
   if(p==NULL){
      printf("wrong username\n");
      sleep(1);
      return;
   }
   printf("Enter your password.\n");
   int pas;
   scanf("%d",&pas);
   if(p->pasword!=pas){
      printf("your password is wrong\n");
      sleep(5);
      return;
   }else{
      system("cls");
      row=70;
      cols=5;
      gotoxy(row,cols);
      printf(RED "username:" RESET);
      printf("%s",p->name);
      row=70;
      cols=6;
      gotoxy(row,cols);
      printf(RED "level:" RESET);
      printf("%d",p->score);
      row=70;
      cols=7;
      gotoxy(row,cols);
      printf(RED "last game statue:" RESET);
      if(p->last_game_status==2){
         printf("finished\n");
      }else if(p->last_game_status==1){
         printf("incompleted\n");
      }else if(p->last_game_status==0){
         printf("unavailable\n");
      }
      help_login();
      int cmdd;
      int a;//1=nime tamam, 2= payan yafte
      int c;//game level
      int i,j;
      scanf("%d",&cmdd);
      
      while(cmdd){
         switch (cmdd)
         {
         case 1:
            if(p->last_game_status==1){
               system("cls");
               row=70;
               cols=5;
               gotoxy(row,cols);
               printf(RED "username:" RESET);
               printf("%s",p->name);
               row=70;
               cols=6;
               gotoxy(row,cols);
               printf(RED "level:" RESET);
               printf("%d",p->score);
               row=70;
               cols=7;
               gotoxy(row,cols);
               printf(RED "last game statue:" RESET);
               if(p->last_game_status==2){
                   printf("finished\n");
               }else if(p->last_game_status==1){
                   printf("incompleted\n");
               }else if(p->last_game_status==0){
                  printf("unavailable\n");
               }
               
               row=70;
               cols=10;
               gotoxy(row,cols);
               printf(BLUE "Enter 1 for play last game");
               row=70;
               cols=11;
               gotoxy(row,cols);
               printf(BLUE"Enter 2 for new game"RESET);
               scanf("%d",&a);
               
               if(a==1){
                  gameA(p);
               }else if(a==2){
                  system("cls");
                  row=70;
                  cols=5;
                  gotoxy(row,cols);
                  printf(RED "username:" RESET);
                  printf("%s",p->name);
                  row=70;
                  cols=6;
                  gotoxy(row,cols);
                  printf(RED "level:" RESET);
                  printf("%d",p->score);
                  row=70;
                  cols=7;
                  gotoxy(row,cols);
                  printf(RED "last game statue:" RESET);
                  if(p->last_game_status==2){
                     printf("finished\n");
                  }else if(p->last_game_status==1){
                     printf("incompleted\n");
                  }else if(p->last_game_status==0){
                     printf("unavailable\n");
                  }
                  row=70;
                  cols=10;
                  gotoxy(row,cols);
                  printf(YELLOW "choose your game level" RESET);
                  row=70;
                  cols=11;
                  gotoxy(row,cols);
                  printf(YELLOW "Enter 1 for level one" RESET);
                  row=70;
                  cols=12;
                  gotoxy(row,cols);
                  printf(YELLOW "Enter 2 for level two" RESET);
                  row=70;
                  cols=13;
                  gotoxy(row,cols);
                  printf(YELLOW "Enter 3 for level three" RESET);
                  scanf("%d",&c);

                  if(c==1){
                     p->type_lastgame=1;
                     int AA;
                     FILE *fpAA;
                     fpAA = fopen(filemapA, "rb");
                     for(i=0;i<5;++i){
                        for(j=0;j<10;++j){
                           fread(&AA,sizeof(int),1,fpAA);
                           p->map_gamer[i][j]=AA;
                        }
                     }
                     fclose(fpAA);
                     gameA(p);
                  }else if(c==2){
                     p->type_lastgame=2;
                     int BB;
                     FILE *fpBB;
                     fpBB = fopen(filemapB, "rb");
                     for(i=0;i<8;++i){
                        for(j=0;j<10;++j){
                           fread(&BB,sizeof(int),1,fpBB);
                           p->map_gamer[i][j]=BB;
                        }
                     }
                     fclose(fpBB);
                     gameA(p);
                  }else if(c==3){
                     int CC;
                     FILE *fpCC;
                     fpCC = fopen(filemapC, "rb");
                     for(i=0;i<10;++i){
                        for(j=0;j<11;++j){
                           fread(&CC,sizeof(int),1,fpCC);
                           p->map_gamer[i][j]=CC;
                        }
                     }
                     fclose(fpCC);
                     gameA(p);

                  }


               }


            }else{
                  system("cls");
                  row=70;
                  cols=5;
                  gotoxy(row,cols);
                  printf(RED "username:" RESET);
                  printf("%s",p->name);
                  row=70;
                  cols=6;
                  gotoxy(row,cols);
                  printf(RED "level:" RESET);
                  printf("%d",p->score);
                  row=70;
                  cols=7;
                  gotoxy(row,cols);
                  printf(RED "last game statue:" RESET);
                  if(p->last_game_status==2){
                     printf("finished\n");
                  }else if(p->last_game_status==1){
                     printf("incompleted\n");
                  }else if(p->last_game_status==0){
                     printf("unavailable\n");
                  }
                  row=70;
                  cols=10;
                  gotoxy(row,cols);
                  printf(YELLOW "choose your game level" RESET);
                  row=70;
                  cols=11;
                  gotoxy(row,cols);
                  printf(YELLOW "Enter 1 for level one" RESET);
                  row=70;
                  cols=12;
                  gotoxy(row,cols);
                  printf(YELLOW "Enter 2 for level two" RESET);
                  row=70;
                  cols=13;
                  gotoxy(row,cols);
                  printf(YELLOW "Enter 3 for level three" RESET);
                  scanf("%d",&c);
                  if(c==1){
                     p->type_lastgame=1;
                     int AA;
                     FILE *fpAA;
                     fpAA = fopen(filemapA, "rb");
                     for(i=0;i<5;++i){
                        for(j=0;j<10;++j){
                           fread(&AA,sizeof(int),1,fpAA);
                           p->map_gamer[i][j]=AA;
                        }
                     }
                     fclose(fpAA);
                     gameA(p);
                  }else if(c==2){
                     p->type_lastgame=2;
                     int BB;
                     FILE *fpBB;
                     fpBB = fopen(filemapB, "rb");
                     for(i=0;i<8;++i){
                        for(j=0;j<10;++j){
                           fread(&BB,sizeof(int),1,fpBB);
                           p->map_gamer[i][j]=BB;
                        }
                     }
                     fclose(fpBB);
                     gameA(p);
                  }else if(c==3){
                     p->type_lastgame=3;
                     int CC;
                     FILE *fpCC;
                     fpCC = fopen(filemapC, "rb");
                     for(i=0;i<10;++i){
                        for(j=0;j<11;++j){
                           fread(&CC,sizeof(int),1,fpCC);
                           p->map_gamer[i][j]=CC;
                        }
                     }
                     fclose(fpCC);
                     gameA(p);

                  }

            }
            break;
         case 2:
            strcpy(p->Account_status,"off");
            system("cls");
            row=70;
            cols=15;
            gotoxy(row,cols);
            printf(RED "...your account has been deleted..." RESET);
            sleep(1);
            system("cls");
            sleep(1);
            row=70;
            cols=15;
            gotoxy(row,cols);
            printf(RED "...your account has been deleted..." RESET);
            sleep(1);
            system("cls");
            sleep(1);
            row=70;
            cols=15;
            gotoxy(row,cols);
            printf(RED "...your account has been deleted..." RESET);
            sleep(1);
            break;
         
         default:

            break;
         }
         if(cmdd==2){
            break;
         }
         system("cls");
         row=70;
         cols=5;
         gotoxy(row,cols);
         printf(RED "username:" RESET);
         printf("%s",p->name);
         row=70;
         cols=6;
         gotoxy(row,cols);
         printf(RED "level:" RESET);
         printf("%d",p->score);
         row=70;
         cols=7;
         gotoxy(row,cols);
         printf(RED "last game statue:" RESET);
         if(p->last_game_status==2){
            printf("finished\n");
         }else if(p->last_game_status==1){
            printf("incompleted\n");
         }else if(p->last_game_status==0){
            printf("unavailable\n");
         }
         help_login();
         scanf("%d",&cmdd);
      }
      
   }
   

}
void vorod(){
      system("cls");
      int row,cols;
      row=70;
      cols=10;
      gotoxy(row,cols);
      printf(YELLOW "Enter 1 to create a new account");
      row=70;
      cols=11;
      gotoxy(row,cols);
      printf("Enter 2 for login");
      row=70;
      cols=12;
      gotoxy(row,cols);
      printf("Enter 0 for exit"RESET); 

}

void pac(){
   system("cls");
   int i,j;
   int row,cols;
   int pacman[7][11];
   int a1,y1;
   for(i=0;i<7;++i){
      for(j=0;j<11;++j){
         pacman[i][j]=100;
      }
   }
   for(i=3;i<9;++i){
      pacman[0][i]=0;
   }
   for(i=3;i<9;++i){
      pacman[6][i]=0;
   }
   pacman[1][2]=0;
   pacman[1][9]=0;
   pacman[2][1]=0;
   pacman[1][6]=0;
   pacman[1][5]=0;
   pacman[2][10]=0;
   pacman[3][0]=0;
   pacman[3][9]=0;
   pacman[3][8]=0;

   pacman[4][1]=0;
   
   pacman[4][10]=0;

   pacman[5][2]=0;
   pacman[5][9]=0;

   for(i=0;i<7;++i){
      for(j=0;j<11;++j){
         if(pacman[i][j]==0){
            
            a1=6*i+2;
            y1=6*j+3+x;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+2;
            y1=6*j+4+x;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+3;
            y1=6*j+2+x;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+3;
            y1=6*j+5+x;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+4;
            y1=6*j+1+x;
            gotoxy(y1,a1);
            printf("/"); 
            a1=6*i+5;
            y1=6*j+1+x;
            gotoxy(y1,a1);
            printf("\\"); 
            a1=6*i+6;
            y1=6*j+2+x;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+6;
            y1=6*j+3+x;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+6;
            y1=6*j+4+x;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+6;
            y1=6*j+5+x;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+5;
            y1=6*j+6+x;
            gotoxy(y1,a1);
            printf("."); 
            a1=6*i+4;
            y1=6*j+6+x;
            gotoxy(y1,a1);
            printf("'"); 
            a1=6*i+4;
            y1=6*j+5+x;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+5;
            y1=6*j+5+x;
            gotoxy(y1,a1);
            printf("-"); 
            a1=6*i+4;
            y1=6*j+4+x;
            gotoxy(y1,a1);
            printf("."); 
            a1=6*i+5;
            y1=6*j+4+x;
            gotoxy(y1,a1);
            printf("'");
            a1=6*i+4;
            y1=6*j+3+x;
            gotoxy(y1,a1);
            printf("_"); 
            a1=6*i+3;
            y1=6*j+3+x;
            gotoxy(y1,a1);
            printf("O"); 
            a1=6*i+3;
            y1=6*j+4+x;
            gotoxy(y1,a1);
            printf("O"); 
            
            
         
         }
      }
      
   }
   
   return;
    
}
void start(){
   
   int row,cols;
   system("cls");
   pac();
   
   row=10;
   cols=18;
   gotoxy(row,cols);
   printf("welcome");

   row=13;
   cols=19;
   gotoxy(row,cols);
   printf("to");
   
   row=10;
   cols=20;
   gotoxy(row,cols);
   printf("pacman");
   


   sleep(1);
   
   row=10;
   cols=18;
   gotoxy(row,cols);
   printf("        " );
   row=13;
   cols=19;
   gotoxy(row,cols);
   printf("   ");
   row=10;
   cols=20;
   gotoxy(row,cols);
   printf("       ");

   sleep(1);
   row=10;
   cols=18;
   gotoxy(row,cols);
   printf("welcome");
   row=13;
   cols=19;
   gotoxy(row,cols);
   printf("to");
   row=10;
   cols=20;
   gotoxy(row,cols);
   printf("pacman");

   sleep(1);
   row=10;
   cols=18;
   gotoxy(row,cols);
   printf("        ");
   row=13;
   cols=19;
   gotoxy(row,cols);
   printf("   ");
   row=10;
   cols=20;
   gotoxy(row,cols);
   printf("       ");

   sleep(1);
   row=10;
   cols=18;
   gotoxy(row,cols);
   printf("welcome");
   row=13;
   cols=19;
   gotoxy(row,cols);
   printf("to");
   row=10;
   cols=20;
   gotoxy(row,cols);
   printf("pacman");

   sleep(1);

  
}

