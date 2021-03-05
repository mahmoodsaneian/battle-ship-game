#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX 1000
#include <stdbool.h>
#include <windows.h>
#include <dos.h>
#include <dir.h>


struct ships{
    int length;
    int x_start,y_start,x_end,y_end;
    int mode;
    struct ships *next;
};

struct ships* create_new(int new_length,int new_mode,int x1,int y1,int x2,int y2){
    struct ships *mm;
    mm=(struct ships *)calloc(1,sizeof(struct ships));
    mm->x_start=x1;
    mm->x_end=x2;
    mm->y_start=y1;
    mm->y_end=y2;
    mm->length=new_length;
    mm->mode=new_mode;
    mm->next=NULL;
    return mm;
}

bool delete_ship(struct ships **head,int x,int y){

    //FIRST CONDITION
    //IF EMPTY
    if(*head == NULL)
        return false;
     //SECOND CONDITION
    //IF THE FIRST HOUSE WANTS TO BE REMOVED
    if (((*head)->x_start == x) && ((*head)->y_start == y)){
        struct ships *help=*head;
        *head=(*head)->next;
        free(help);
        return true;
    }
    //THIRD CONDITION
      struct ships *current=*head;
      struct ships *last=NULL;
      while(current != NULL)
      {
          if((current->x_start == x) && (current->y_start == y)){
                last->next=current->next;
                free(current);
                return true;
          }

          last=current;
          current=current->next;
      }
      return false;
}

void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
}

void random_map(struct ships **head,char arr[10][10]){
        int i,j,code;
        struct ships *current;struct ships *new_node;
        //GENERATE A RANDOM NUMBER
        srand(time(0));
        code=rand();
        code=(code%3)+1;

        //FIRST MAP
        if(code == 1){
            //SHIP WITH A LENGTH OF FIVE
            i=2;j=2;
            arr[i][j-1]='n';
            while(j<=6){
                arr[i][j]='s';arr[i+1][j]='n';arr[i-1][j]='n';
                j++;
            }
            arr[i][j]='n';
            *head=create_new(5,-1,2,2,2,6);current=*head;
           //FIRST SHIP WITH A LENGTH OF THREE
           i=5;j=2;
           arr[i-1][j]='n';
           while(i<=7){
            arr[i][j]='s';arr[i][j+1]='n';arr[i][j-1]='n';
            i++;
           }
           arr[i][j]='n';
           new_node=create_new(3,1,5,2,7,2);current->next=new_node;current=new_node;
           //SECOND SHIP WITH A LENGTH OF THREE
           i=5;j=6;
           arr[i][j-1]='n';
           while(j<=8){
            arr[i][j]='s';arr[i+1][j]='n';arr[i-1][j]='n';
            j++;
           }
           arr[i][j]='n';
           new_node=create_new(3,-1,5,6,5,8);current->next=new_node;current=new_node;
           //FIRST SHIP WITH A LENGTH OF TWO
           i=3;j=0;
           while(j<=1){
            arr[i][j]='s';arr[i-1][j]='n';arr[i+1][j]='n';
            j++;
           }
           arr[i][j]='n';
           new_node=create_new(2,-1,3,0,3,1);current->next=new_node;current=new_node;
           //SECOND SHIP WITH A LENGTH OF TWO
           i=7;j=5;
           arr[i][j-1]='n';
           while(j<=6){
            arr[i][j]='s';arr[i+1][j]='n';arr[i-1][j]='n';
            j++;
           }
           arr[i][j]='n';
           new_node=create_new(2,-1,7,5,7,6);current->next=new_node;current=new_node;
           //THIRD SHIP WITH A LENGTH OF TWO
           i=9;j=5;
           arr[i][j-1]='n';
           while(j<=6){
            arr[i][j]='s';arr[i-1][j]='n';
            j++;
           }
           arr[i][j]='n';
           new_node=create_new(2,-1,9,5,9,6);current->next=new_node;current=new_node;
           // SHIPS WITH A LENGTH OF ONE
           arr[0][2]='s';arr[0][4]='s';arr[0][6]='s';arr[0][8]='s';
           arr[0][1]='n';arr[0][3]='n';arr[1][2]='n';arr[0][5]='n';arr[1][4]='n';
           arr[0][7]='n';arr[1][6]='n';arr[1][8]='n';arr[0][9]='n';
           new_node=create_new(1,1,0,2,0,2);current->next=new_node;current=new_node;
           new_node=create_new(1,1,0,4,0,4);current->next=new_node;current=new_node;
           new_node=create_new(1,1,0,6,0,6);current->next=new_node;current=new_node;
           new_node=create_new(1,1,0,8,0,8);current->next=new_node;current=new_node;
           //END OF FIRST MAP
        }
        //SECOND MAP
        if(code == 2){
            //SHIP WITH A LENGTH OF FIVE
            i=0;j=4;
            arr[i][j-1]='n';
            while(j<=8){
                arr[i][j]='s';arr[i+1][j]='n';
                j++;
            }
            arr[i][j]='n';
            *head=create_new(5,-1,0,4,0,8);current=*head;
            //FIRST SHIP WITH A LENGTH OF THREE
            i=4;j=8;
            arr[i-1][j]='n';
            while(i<=6){
                arr[i][j]='s';arr[i][j+1]='n';arr[i][j-1]='n';
                i++;
            }
            arr[i][j]='n';
            new_node=create_new(3,1,4,8,6,8);current->next=new_node;current=new_node;
            //SECOND SHIP WITH A LENGTH OF THREE
            i=6;j=4;
            arr[i][j-1]='n';
            while(j<=6){
                arr[i][j]='s';arr[i+1][j]='n';arr[i-1][j]='n';
                j++;
            }
            arr[i][j]='n';
            new_node=create_new(3,-1,6,4,6,6);current->next=new_node;current=new_node;
            //FIRST SHIP WITH A LENGTH OF TWO
            i=8;j=2;
            arr[i][j-1]='n';
            while(j<=3){
                arr[i][j]='s';arr[i+1][j]='n';arr[i-1][j]='n';
                j++;
            }
            arr[i][j]='n';
            new_node=create_new(2,-1,8,2,8,3);current->next=new_node;current=new_node;
            //SECOND SHIP WITH A LENGTH OF TWO
            i=8;j=5;
            arr[i][j-1]='n';
            while(j<=6){
                arr[i][j]='s';arr[i+1][j]='n';arr[i-1][j]='n';
                j++;
            }
            arr[i][j]='n';
            new_node=create_new(2,-1,8,5,8,6);current->next=new_node;current=new_node;
            //THIRD SHIP WITH A LENGTH OF TWO
            i=9;j=8;
            arr[i][j-1]='n';
            while(j<=9){
                arr[i][j]='s';arr[i-1][j]='n';
                j++;
            }
            new_node=create_new(2,-1,9,8,9,9);current->next=new_node;current=new_node;
            //SHIPS WITH A LENGTH OF ONE
            arr[2][1]='s';arr[2][3]='s';arr[2][5]='s';arr[2][7]='s';arr[3][7]='n';
            arr[2][0]='n';arr[2][2]='n';arr[2][4]='n';arr[2][6]='n';arr[2][8]='n';arr[1][7]='n';
            arr[1][1]='n';arr[3][1]='n';arr[1][3]='n';arr[3][3]='n';arr[1][5]='n';arr[3][5]='n';
            new_node=create_new(1,1,2,1,2,1);current->next=new_node;current=new_node;
            new_node=create_new(1,1,2,3,2,3);current->next=new_node;current=new_node;
            new_node=create_new(1,1,2,5,2,5);current->next=new_node;current=new_node;
            new_node=create_new(1,1,2,7,2,7);current->next=new_node;current=new_node;
            //END OF SECOND MAP
        }
        //THIRD MAP
        if(code == 3){
            //SHIP WITH A LENGTH OF FIVE
            i=2;j=1;
            arr[i-1][j]='n';
            while(i<=6){
                arr[i][j]='s';arr[i][j+1]='n';arr[i][j-1]='n';
                i++;
            }
            arr[i][j]='n';
            *head=create_new(5,1,2,1,6,1);current=*head;
            //FIRST SHIP WITH A LENGTH OF THREE
            i=0;j=5;
            arr[i][j-1]='n';
            while(j<=7){
                arr[i][j]='s';arr[i+1][j]='n';
                j++;
            }
            arr[i][j]='n';
            new_node=create_new(3,-1,0,5,0,7);current->next=new_node;current=new_node;
            //SECOND SHIP WITH A LENGTH OF THREE
            i=7;j=4;
            arr[i][j-1]='n';
            while(j<=6){
                arr[i][j]='s';arr[i+1][j]='n';arr[i-1][j]='n';
                j++;
            }
            arr[i][j]='n';
            new_node=create_new(3,-1,7,4,7,6);current->next=new_node;current=new_node;
            //FIRST SHIP WITH A LENGTH OF TWO
            i=2;j=8;
            arr[i-1][j]='n';
            while(i<=3){
                arr[i][j]='s';arr[i][j+1]='n';arr[i][j-1]='n';
                i++;
            }
            arr[i][j]='n';
            new_node=create_new(2,1,2,8,3,8);current->next=new_node;current=new_node;
            //SECOND SHIP WITH A LENGTH OF TWO
            i=5;j=8;
            while(i<=6){
                arr[i][j]='s';arr[i][j+1]='n';arr[i][j-1]='n';
                i++;
            }
            arr[i][j]='n';
            new_node=create_new(2,1,5,8,6,8);current->next=new_node;current=new_node;
            //THIRD SHIP WITH A LENGTH OF TWO
            i=3;j=5;
            arr[i][j-1]='n';
            while(j<=6){
                arr[i][j]='s';arr[i+1][j]='n';arr[i-1][j]='n';
                j++;
            }
            new_node=create_new(2,-1,3,5,3,6);current->next=new_node;current=new_node;
            //SHIPS WITH A LENGTH OF ONE
            arr[9][2]='s';arr[9][4]='s';arr[9][6]='s';arr[9][8]='s';
            arr[9][1]='n';arr[9][3]='n';arr[9][5]='n';arr[9][7]='n';arr[9][9]='n';
            arr[8][2]='n';arr[8][4]='n';arr[8][6]='n';arr[8][8]='n';
            new_node=create_new(1,1,9,2,9,2);current->next=new_node;current=new_node;
            new_node=create_new(1,1,9,4,9,4);current->next=new_node;current=new_node;
            new_node=create_new(1,1,9,6,9,6);current->next=new_node;current=new_node;
            new_node=create_new(1,1,9,8,9,8);current->next=new_node;current=new_node;
            //END OF THIRD MAP
        }
}

int load_last_game(char first1[10][10],char first2[10][10],char second1[10][10],char second2[10][10],struct ships **head1,struct ships **head2,int *coin1,int *coin2,char name1[30],char name2[30],int *counter_ships1,int *counter_ships2){
      char sign;int sign_1;
      struct ships *current;struct ships *new_node;
      int tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;

     //OPEN FILE
     FILE *last_game=fopen("D:\\lastgame.data","rb");
     //READ NAME
     fread(name1,sizeof(char),30,last_game);
     fread(name2,sizeof(char),30,last_game);
    //READ SIGN
    fread(&sign,sizeof(char),1,last_game);
    if(sign == 't'){
        sign_1=2;
    }
    if(sign == 'o'){
        sign_1=1;
    }

    //READ MAPS
    fread(first1,sizeof(char),100,last_game);
    fread(first2,sizeof(char),100,last_game);
    fread(second1,sizeof(char),100,last_game);
    fread(second2,sizeof(char),100,last_game);
    //READ NUMBER OF COINS
    fread(coin1,sizeof(int),1,last_game);
    fread(coin2,sizeof(int),1,last_game);
    //READ NUMBER OF SHIPS
    fread(counter_ships1,sizeof(int),1,last_game);
    fread(counter_ships2,sizeof(int),1,last_game);
    //READ INFORMATION OF SHIPS
    int i=1;
    //FIRST LINKED LIST
    //CREATE HEAD OF LINKED LIST
     fread(&tmp1,sizeof(int),1,last_game);
     fread(&tmp2,sizeof(int),1,last_game);
     fread(&tmp3,sizeof(int),1,last_game);
     fread(&tmp4,sizeof(int),1,last_game);
     fread(&tmp5,sizeof(int),1,last_game);
     fread(&tmp6,sizeof(int),1,last_game);
     *head1=create_new(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6);
     current=*head1;
     //
    while(i < (*counter_ships1)){

            //READ FROM FILE
         fread(&tmp1,sizeof(int),1,last_game);
         fread(&tmp2,sizeof(int),1,last_game);
         fread(&tmp3,sizeof(int),1,last_game);
         fread(&tmp4,sizeof(int),1,last_game);
         fread(&tmp5,sizeof(int),1,last_game);
         fread(&tmp6,sizeof(int),1,last_game);
         new_node=create_new(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6);
         current->next=new_node;
         current=new_node;
        //UPDATE WHILE
        i++;
    }

    i=1;
      //SECOND LINKED LIST
      //CREATE HEAD OF LINKED LIST
     fread(&tmp1,sizeof(int),1,last_game);
     fread(&tmp2,sizeof(int),1,last_game);
     fread(&tmp3,sizeof(int),1,last_game);
     fread(&tmp4,sizeof(int),1,last_game);
     fread(&tmp5,sizeof(int),1,last_game);
     fread(&tmp6,sizeof(int),1,last_game);
     *head2=create_new(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6);
     current=*head2;
     //
    while(i < (*counter_ships2)){

            //READ FROM FILE
          fread(&tmp1,sizeof(int),1,last_game);
          fread(&tmp2,sizeof(int),1,last_game);
          fread(&tmp3,sizeof(int),1,last_game);
          fread(&tmp4,sizeof(int),1,last_game);
          fread(&tmp5,sizeof(int),1,last_game);
          fread(&tmp6,sizeof(int),1,last_game);
          new_node=create_new(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6);
          current->next=new_node;
          current=new_node;
        //UPDATE WHILE
        i++;
    }

    //CLOSE FILE
    fclose(last_game);
    return sign_1;

}

int load_game(char first1[10][10],char first2[10][10],char second1[10][10],char second2[10][10],struct ships **head1,struct ships **head2,int *coin1,int *coin2,char name1[30],char name2[30],int *counter_ships1,int *counter_ships2){
    char help_name1[30];char help_name2[30];
    int c_ship1,c_ship2,i,j=0;
    int tmp1,tmp2,tmp3,tmp4,tmp5,tmp6;
    int help;struct ships *current;struct ships *new_node;
    int sign_1;char sign;
    int counter_file;
    //OPEN FILE[NUMBER OF SAVE] & READ NUMBER OF SAVE
    FILE *number_of_save=fopen("D:\\counter_save.txt","r");
    fscanf(number_of_save,"%d",&counter_file);
    fclose(number_of_save);
    //OPEN FILE
    FILE *game=fopen("D:\\game.data","rb");
    //PRINT NAMES
    while(j<counter_file){


        help=(1*sizeof(char)) + (4*(100 * sizeof(char))) + (2*sizeof(int));
        fread(help_name1,sizeof(char),30,game);
        fread(help_name2,sizeof(char),30,game);
        printf("%s\t%s\n",help_name1,help_name2);
        fseek(game,help,SEEK_CUR);
        fread(&c_ship1,sizeof(int),1,game);
        fread(&c_ship2,sizeof(int),1,game);
        help= (6*sizeof(int)) * (c_ship1+c_ship2);
        fseek(game,help,SEEK_CUR);
        j++;
    }
    //RETURN TO THE BEGINNING OF THE FILE
    fseek(game,0,SEEK_SET);
    //GET NAME PLAYERS
    printf("ENTER THE NAMES OF TWO PLAYERS IN THE GAME\n");
    scanf("%s",name1);
    fflush(stdin);
    scanf("%s",name2);
    j=0;


    //LOAD GAME
    while(j<counter_file){

        fread(help_name1,sizeof(char),30,game);
        fread(help_name2,sizeof(char),30,game);
        //IF WE HAVE REACHED THE DESIRED GAME
        if((strcmp(help_name1,name1) == 0) && (strcmp(help_name2,name2) == 0)){
              //READ SIGN
                fread(&sign,sizeof(char),1,game);
                if(sign == 't'){
                sign_1=2;
                }
                if(sign == 'o'){
                sign_1=1;
                }

            //READ MAPS
            fread(first1,sizeof(char),100,game);
            fread(first2,sizeof(char),100,game);
            fread(second1,sizeof(char),100,game);
            fread(second2,sizeof(char),100,game);
            //READ NUMBER OF COINS
            fread(coin1,sizeof(int),1,game);
            fread(coin2,sizeof(int),1,game);
            //READ NUMBER OF SHIPS
            fread(counter_ships1,sizeof(int),1,game);
            fread(counter_ships2,sizeof(int),1,game);
            //READ INFORMATION OF SHIPS
            int i=1;
            //CREATE HEAD OF LINKED LIST
            fread(&tmp1,sizeof(int),1,game);
            fread(&tmp2,sizeof(int),1,game);
            fread(&tmp3,sizeof(int),1,game);
            fread(&tmp4,sizeof(int),1,game);
            fread(&tmp5,sizeof(int),1,game);
            fread(&tmp6,sizeof(int),1,game);
            *head1=create_new(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6);
            current=*head1;
            //
            while(i < (*counter_ships1)){

            //READ FROM FILE
            fread(&tmp1,sizeof(int),1,game);
            fread(&tmp2,sizeof(int),1,game);
            fread(&tmp3,sizeof(int),1,game);
            fread(&tmp4,sizeof(int),1,game);
            fread(&tmp5,sizeof(int),1,game);
            fread(&tmp6,sizeof(int),1,game);
            new_node=create_new(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6);
            current->next=new_node;
            current=new_node;
            //UPDATE WHILE
            i++;
            }

            i=1;
            //CREATE HEAD OF LINKED LIST
            fread(&tmp1,sizeof(int),1,game);
            fread(&tmp2,sizeof(int),1,game);
            fread(&tmp3,sizeof(int),1,game);
            fread(&tmp4,sizeof(int),1,game);
            fread(&tmp5,sizeof(int),1,game);
            fread(&tmp6,sizeof(int),1,game);
            *head2=create_new(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6);
            current=*head2;
            //
            while(i < (*counter_ships2)){

            //READ FROM FILE
            fread(&tmp1,sizeof(int),1,game);
            fread(&tmp2,sizeof(int),1,game);
            fread(&tmp3,sizeof(int),1,game);
            fread(&tmp4,sizeof(int),1,game);
            fread(&tmp5,sizeof(int),1,game);
            fread(&tmp6,sizeof(int),1,game);
            new_node=create_new(tmp1,tmp2,tmp3,tmp4,tmp5,tmp6);
            current->next=new_node;
            current=new_node;
            //UPDATE WHILE
            i++;
            }
            fclose(game);
            return sign_1;

}
        //IF YOU HAVE NOT YET REACHED THE DESIRED GAME
        help=(1*sizeof(char)) + (4*(100 * sizeof(char))) + (2*sizeof(int));
        fseek(game,help,SEEK_CUR);
        fread(&c_ship1,sizeof(int),1,game);
        fread(&c_ship2,sizeof(int),1,game);
        help= (6*sizeof(int)) * (c_ship1+c_ship2);
        fseek(game,help,SEEK_CUR);
        j++;
    }
    fclose(game);
    return 0;
}

void save_game(char sign,char first1[10][10],char second1[10][10],char first2[10][10],char second2[10][10],struct ships *head1,struct ships *head2,int coin1,int coin2,char name1[30],char name2[30],int c_ship1,int c_ship2){
    int counter_file;
    struct ships *current;
    //OPEN FILE[COUNTER FILE]
    FILE *number_of_save=fopen("D:\\counter_save.txt","r");
    fscanf(number_of_save,"%d",&counter_file);
    counter_file+=1;
    fclose(number_of_save);
    FILE *number_save=fopen("D:\\counter_save.txt","w");
    fprintf(number_save,"%d",counter_file);
    fclose(number_save);
    //THIS FILE SAVE ALL GAME
        //OPEN FILE
    FILE *game=fopen("D:\\game.data","ab");
          //SAVE NAME OF PLAYERS
    fwrite(name1,sizeof(char),30,game);
    fwrite(name2,sizeof(char),30,game);

    //SAVE SIGN GAME
    fwrite(&sign,sizeof(char),1,game);
    //SAVE MAPS OF PLAYERS
    fwrite(first1,sizeof(char),100,game);
    fwrite(first2,sizeof(char),100,game);
    fwrite(second1,sizeof(char),100,game);
    fwrite(second2,sizeof(char),100,game);
    //SAVE NUMBER OF COINS
    fwrite(&coin1,sizeof(int),1,game);
    fwrite(&coin2,sizeof(int),1,game);
    //SAVE THE NUMBER OF SHIPS
    fwrite(&c_ship1,sizeof(int),1,game);
    fwrite(&c_ship2,sizeof(int),1,game);

        //SAVE SHIPS INFORMATION
    current=head1;
    while(current != NULL){
        fwrite(&current->length,sizeof(int),1,game);
        fwrite(&current->mode,sizeof(int),1,game);
        fwrite(&current->x_start,sizeof(int),1,game);
        fwrite(&current->y_start,sizeof(int),1,game);
        fwrite(&current->x_end,sizeof(int),1,game);
        fwrite(&current->y_end,sizeof(int),1,game);
        current=current->next;
    }
    current=head2;
   while(current!= NULL){
        fwrite(&current->length,sizeof(int),1,game);
        fwrite(&current->mode,sizeof(int),1,game);
        fwrite(&current->x_start,sizeof(int),1,game);
        fwrite(&current->y_start,sizeof(int),1,game);
        fwrite(&current->x_end,sizeof(int),1,game);
        fwrite(&current->y_end,sizeof(int),1,game);
        current=current->next;
    }
    //CLOSE FILE
    fclose(game);


    //FILE [LOAD LAST GAME]
        //OPEN FILE
    FILE *last_game=fopen("D:\\lastgame.data","wb");
        //SAVE NAME OF PLAYERS
    fwrite(name1,sizeof(char),30,last_game);
    fwrite(name2,sizeof(char),30,last_game);

        //SAVE SIGN GAME
    fwrite(&sign,sizeof(char),1,last_game);
            //SAVE MAPS OF PLAYERS
    fwrite(first1,sizeof(char),100,last_game);
    fwrite(first2,sizeof(char),100,last_game);
    fwrite(second1,sizeof(char),100,last_game);
    fwrite(second2,sizeof(char),100,last_game);
   //SAVE NUMBER OF COINS
    fwrite(&coin1,sizeof(int),1,last_game);
    fwrite(&coin2,sizeof(int),1,last_game);
          //SAVE THE NUMBER OF SHIPS
    fwrite(&c_ship1,sizeof(int),1,last_game);
    fwrite(&c_ship2,sizeof(int),1,last_game);

        //SAVE SHIPS INFORMATION
    current=head1;
    while(current != NULL){
        fwrite(&current->length,sizeof(int),1,last_game);
        fwrite(&current->mode,sizeof(int),1,last_game);
        fwrite(&current->x_start,sizeof(int),1,last_game);
        fwrite(&current->y_start,sizeof(int),1,last_game);
        fwrite(&current->x_end,sizeof(int),1,last_game);
        fwrite(&current->y_end,sizeof(int),1,last_game);
        current=current->next;
    }
    current=head2;
   while(current!= NULL){
        fwrite(&current->length,sizeof(int),1,last_game);
        fwrite(&current->mode,sizeof(int),1,last_game);
        fwrite(&current->x_start,sizeof(int),1,last_game);
        fwrite(&current->y_start,sizeof(int),1,last_game);
        fwrite(&current->x_end,sizeof(int),1,last_game);
        fwrite(&current->y_end,sizeof(int),1,last_game);
        current=current->next;
    }

    //CLOSE FILE
    fclose(last_game);


    //END OF FUNCTION
}

int search_update_name(char names[MAX][30],char name[30],int counter){
    int i=0;
    while(i<counter){
        if(strcmp(name,names[i]) == 0){
            return -1;
        }
        i++;
    }
    return 0;
}

void save_scoreboard(char sign,char name1[30],char name2[30],int coin1,int coin2){
         int res1,res2;
        //FILE [SCOREBOARD]
    char names[MAX][30];int coins[MAX];int counter_member=0;

    //FIRST WE OPEN THE FILE AND KEEP THE PREVIOUS INFORMATION TOGETHER
        //OPEN FILE
    FILE *coin=fopen("D:\\scoreboard.txt","r");
        //READ FROM FILE
    while(1){
        if(feof(coin))
            break;
        fscanf(coin,"%s %d",names[counter_member],&coins[counter_member]);
        counter_member++;
    }
        //CLOSE FILE
    fclose(coin);
    //CHECK IF THIS USER ALREADY EXISTS
    res1=search_update_name(names,name1,counter_member);
    res2=search_update_name(names,name2,counter_member);
    //THEN WE UPDATE THE FILE
    FILE *scoreboard=fopen("D:\\scoreboard.txt","w");
    //WRITING IN THE FILE
    int i=0;
    while(i<counter_member){
            //IF THE FIRST NAME ALREADY EXISTS
        if(res1 == -1){
            if(strcmp(names[i],name1) == 0){
                coins[i]=coin1;
                }
}
        //IF THE SECOND NAME ALREADY EXISTS
        if(sign == 't'){
                if(res2 == -1){
                if(strcmp(names[i],name2) == 0){
                        coins[i]=coin2;
                                     }
                }
    }

        fprintf(scoreboard,"%s %d",names[i],coins[i]);
        i++;
    }
     //IF THE FIRST NAME DID NOT ALREADY EXISTS
     if(res1 == 0){
     fprintf(scoreboard,"%s %d",name1,coin1);
     }
     //IF THE SECOND PLAYER DID NOT ALREADY EXIST
     if(sign == 't'){
     if(res2 == 0){
        fprintf(scoreboard,"%s %d",name2,coin2);
     }
}
    //CLOSE FILE
    fclose(scoreboard);


}

void swap_1(char names[MAX][30],int coins[MAX],int i,int j){
    //SWAP NUMBER OF COINS
    int tmp=coins[j];
    coins[j]=coins[i];
    coins[i]=tmp;
    //SWAP NAMES
    char help[30];
    strcpy(help,names[j]);
    strcpy(names[j],names[i]);
    strcpy(names[i],help);
}

void score_board(void){
       SetColor(3);
      //DECLARE VARIABLES
      char names[MAX][30];
      int coins[MAX];
      int i=0,counter=0;
     //OPEN FILE
     FILE *scoreboard=fopen("D:\\scoreboard.txt","r+");
     //
     while(1){
         //IF IT REACHES THE END OF THE FILE,THE PROGRAM ENDS
        if(feof(scoreboard))
            break;
         //READ FROM FILE AND SAVE INFORMATION IN ARRAY
         fscanf(scoreboard,"%s %d",names[i],&coins[i]);
         i++;
         counter++;
     }
    //CLOSE FILE
    fclose(scoreboard);

    //SORT
    int j;
    for(i=0;i<counter-1;i++){
            for(j=i+1;j<counter;j++){
                if(coins[i]<coins[j]){
                    swap_1(names,coins,i,j);
                    }
        }
}
    //PRINT THE NUMBER OF COINS PER PERSON ALONG WITH THE NAME IN ORDER
    for(i=0;i<counter;i++){
        printf("NAME=%s\tNUMBER OF COINS=%d\n",names[i],coins[i]);
        }

}

void original_menu(void){
    SetColor(10);
    printf("CHOOSE ONE:\n\n");
    printf("1. Play with a Friend\n");
    printf("2. Play with Bot\n");
    printf("3. load game\n");
    printf("4. Load last game\n");
    printf("5. Settings\n");
    printf("\t1. Ships\n");
    printf("\t2. Map size\n");
    printf("\t3. Theme(bonus)\n");
    printf("6. Scorecoard\n");
    printf("7. Exit\n");
}

void initialization_first_data(char arr[10][10]){
    int i,j;
    for(i=0;i<10;i++){
        for(j=0;j<10;j++){
            arr[i][j]='w';
        }
    }

}

int search_1(char arr1[10][10],int x1,int y1,int x2,int y2){
           int i;
            //IF IT WANTS TO BE A HORIZONTAL SHIP
        if(x1 == x2){
            for(i=y1;i<=y2;i++){
                if(arr1[x1][i] != 'w')
                    return -1;
                if(x1>0){
                    if(arr1[x1-1][i] == 's')
                    return -1;}
                    if(x1<9){
                        if(arr1[x1+1][i] == 's')
                                  return -1;}
        }
}

            //IF IT WANTS TO BE A VERTICAL SHIP
            if(y1==y2){
                for(i=x1;i<=x2;i++){
                    if(arr1[i][y1] != 'w')
                        return -1;
                    if(y1>0){
                        if(arr1[i][y1-1] == 's')
                            return -1;}
                    if(y1<9){
                        if(arr1[i][y1+1] == 's')
                            return -1;}
    }
}

            return 0;
}


//THIS FUNCTION GET FIRST DATA FROM PLAYER
void get_first_data(struct ships **head,char arr1[10][10]){
    int i,counter=0,res=0;
    struct ships *new_node;struct ships *current;
    SetColor(11);
        //X = LENGTH & Y = ACCIDENT
    int x1,y1,x2,y2;
    printf("PLEASE ENTER THE LOCATIONS OF YOUR SHIPS AS DESCRIBED\n");
    printf("INPUTS MUST BE NUMBERS BETWEEN 0 AND 9\n\n");

       //GET LOCATION SHIP WITH A LENGTH OF FIVE
    while(1){
    printf("please enter the location of the ship with a length of five\n");
    scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
    res=search_1(arr1,x1,y1,x2,y2);

    //IF INVALID INPUT
    if(((x1 != x2) && (y1 != y2)) || ((x2-x1 != 4) && (y2-y1 != 4)))
            printf("INVALID INPUT PLEASE TRY AGAIN\n");
    else if(res == -1)
            printf("INVALID INPUT BECAUSE THIS HOUSE HAS BEEN USED BEFORE\n");
        //IF VALID INPUT TERMINATED LOOP
    if((((x1 == x2) || (y1==y2)) && ((x2-x1 == 4)||(y2-y1 == 4))) && (res == 0)){
            //CHECK THAT IT IS NOT OUT OF RANGE
        if(((x1>=0) && (x2<=9)) && ((y1>=0) && (y2<=9))){
            break;
        }
    }

    }

        //IF THE SHIP IS IN THE ROW
    if(x1 == x2){
       //CREATE LINKED LIST
       *head=create_new(5,-1,x1,y1,x2,y2);
       current=*head;
       //
       for(i=y1;i<=y2;i++){
            arr1[x1][i]='s';
            if(x1>0)
                arr1[x1-1][i]='n';
            if(x1<9)
                arr1[x1+1][i]='n';
        }
        if(y1>0)
            arr1[x1][y1-1]='n';
        if(y2<9)
            arr1[x1][y2+1]='n';
    }
        //IF THE SHIP IS IN THE COLOUMN
        if(y1 == y2){
            //CREATE A HOUSE FROM THE LINK LIST
             *head=create_new(5,1,x1,y1,x2,y2);
             current=*head;
            //
            for(i=x1;i<=x2;i++){
                arr1[i][y1]='s';
                if(y1>0)
                    arr1[i][y1-1]='n';
                if(y1<9)
                    arr1[i][y1+1]='n';
            }
        if(x1>0)
            arr1[x1-1][y1]='n';
        if(x2<9)
            arr1[x2+1][y1]='n';
    }
        //GET LOCATION SHIPS WITH A LENGTH OF THREE
    while(counter<2){
            while(1){
                printf("please enter the location of the ship with a length of three\n");
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                res=search_1(arr1,x1,y1,x2,y2);
                //IF INVALID INPUT
                if(((x1 != x2) && (y1 != y2)) || ((x2-x1 != 2) && (y2-y1 != 2)))
                        printf("INVALID INPUT PLEASE TRY AGAIN\n");
                else if(res == -1)
                        printf("INVALID INPUT BECAUSE THIS HOUSE HAS BEEN USED BEFORE\n");
                    //IF VALID INPUT
                if((((x1 == x2) || (y1 == y2)) && ((x2-x1 == 2) || (y2-y1 == 2))) && (res == 0)){
                         //CHECK THAT IT IS NOT OUT OF RANGE
                    if(((x1>=0) && (x2<=9)) && ((y1>=0) && (y2<=9))){
                        break;
                            }
                }


                }

              //IF THE SHIP IS IN THE ROW
              if(x1==x2){
                //BUILD A HOUSE FROM THE LINKED LIST
                new_node=create_new(3,-1,x1,y1,x2,y2);
                current->next=new_node;
                current=new_node;
                //
                for(i=y1;i<=y2;i++){
                    arr1[x1][i]='s';
                    if(x1>0)
                        arr1[x1-1][i]='n';
                    if(x1<9)
                        arr1[x1+1][i]='n';
                                }
                if(y1>0)
                    arr1[x1][y1-1]='n';
                if(y2<9)
                    arr1[x1][y2+1]='n';
              }
              //IF THE SHIP IS IN THE COLOUMN
              if(y1==y2){
                     //BUILD A HOUSE FROM THE LINKED LIST
                new_node=create_new(3,1,x1,y1,x2,y2);
                current->next=new_node;
                current=new_node;
                //
                for(i=x1;i<=x2;i++){
                    arr1[i][y1]='s';
                    if(y1>0)
                        arr1[i][y1-1]='n';
                    if(y1<9)
                        arr1[i][y1+1]='n';
                }
                if(x1>0)
                    arr1[x1-1][y1]='n';
                if(x2<9)
                    arr1[x2+1][y1]='n';
              }
            //UPDATE FIRST WHILE
            counter++;
        }

        //GET LOCATION SHIPS WITH A LENGTH OF TWO
        counter=0;
        while(counter<3){
            while(1){
                printf("please enter the location of the ship with a length of two\n");
                scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
                res=search_1(arr1,x1,y1,x2,y2);
                    //IF INVALID INPUT
                if(((x1 != x2) && (y1 != y2)) || ((x2-x1 != 1) && (y2-y1 != 1)))
                    printf("INVALID INPUT PLEASE TRY AGAIN\n");
                 else if(res == -1)
                    printf("INVALID INPUT BECAUSE THIS HOUSE HAS BEEN USED BEFORE\n");
                    //IF VALID INPUT
                if((((x1 == x2) || (y1 == y2)) && ((x2-x1 == 1) || (y2-y1 == 1))) && (res == 0)){
                         //CHECK THAT IT IS NOT OUT OF RANGE
                    if(((x1>=0) && (x2<=9)) && ((y1>=0) && (y2<=9))){
                        break;
                            }
                }

                }

                //IF THE SHIP IS IN THE ROW
                if(x1==x2){
                //BUILD A HOUSE FROM THE LINKED LIST
                new_node=create_new(2,-1,x1,y1,x2,y2);
                current->next=new_node;
                current=new_node;
                //
                    for(i=y1;i<=y2;i++){
                        arr1[x1][i]='s';
                        if(x1>0)
                            arr1[x1-1][i]='n';
                        if(x1<9)
                            arr1[x1+1][i]='n';
                    }
                    if(y1>0)
                        arr1[x1][y1-1]='n';
                    if(y2<9)
                        arr1[x1][y2+1]='n';
                }
                //IF THE SHIP IS IN THE COLOUMN
                if(y1==y2){
                //BUILD A HOUSE FROM THE LINKED LIST
                new_node=create_new(2,1,x1,y1,x2,y2);
                current->next=new_node;
                current=new_node;
                //
                    for(i=x1;i<=x2;i++){
                        arr1[i][y1]='s';
                        if(y1>0)
                            arr1[i][y1-1]='n';
                        if(y1<9)
                            arr1[i][y1+1]='n';
                    }
                    if(x1>0)
                        arr1[x1-1][y1]='n';
                    if(x2<9)
                        arr1[x2+1][y1]='n';
                }
            //UPDATE FIRST WHILE
            counter++;
        }

            //GET LOCATION SHIPS WITH A LENGTH OF ONE
            counter=0;
            while(counter<4){
                while(1){
                printf("please enter the location of the ship with a length of one\n");
                scanf("%d %d",&x1,&y1);
                x2=x1;y2=y1;
                res=search_1(arr1,x1,y1,x2,y2);
                //IF INVALID INPUT
                if(((x1<0) || (x1>9)) || ((y1<0) || (y1>9)))
                        printf("INVALID INPUT PLEASE TRY AGAIN\n");
                else if(res == -1)
                        printf("INVALID INPUT BECAUSE THIS HOUSE HAS BEEN USED BEFORE\n");
                //IF VALID INPUT
                if((((x1>=0) && (x1<=9)) && ((y1>=0) && (y1<=9))) && (res == 0))
                    break;

                }
                  //BUILD A HOUSE FROM THE LINKED LIST
                new_node=create_new(1,1,x1,y1,x2,y2);
                current->next=new_node;
                current=new_node;
                  //
                arr1[x1][y1]='s';
                if(x1>0)
                    arr1[x1-1][y1]='n';
                if(x1<9)
                    arr1[x1+1][y1]='n';
                if(y1>0)
                    arr1[x1][y1-1]='n';
                if(y1<9)
                    arr1[x1][y1+1]='n';

                //UPDATE FIRST WHILE
                counter++;
            }

    }

void print_result_map(char arr1[10][10]){
    int i,j;

    SetColor(2);
    printf("    ");
    for(i=0;i<10;i++){
        printf("%d | ",i);
    }
    printf("\n");

    for(i=0;i<10;i++){
            SetColor(2);
            printf("%d   ",i);
        for(j=0;j<10;j++){
            if((arr1[i][j] == 'P') || (arr1[i][j] == 'C')){
            SetColor(4);}
            else{
            SetColor(14);}
            printf("%c | ",arr1[i][j]);
        }
        SetColor(2);
        printf("\n------------------------------------------\n");
    }
}




int search_2(char arr[10][10],int x,int y){
    if(arr[x][y] == 'w')
        return 0;
    else
        return -1;
}
//THIS FUNCTION TURN HOUSES INTO FULL BLAST CHARACTERS & DEFINE THE BOUNDARY OF A ROW OF WATER
void change_houses(char player_game[10][10],int mode_1,int x1,int y1,int x2,int y2){
    int i,j;
    //FIRST CONDITION
    //IF THE SHIP WAS HORIZONTAL
    if(mode_1 == -1){
        //INIT
        i=x1;j=y1;
        //
        if(y1>0){
        player_game[x1][y1-1]='E';
        }
        while(j<=y2){

            player_game[i][j]='C';
            if(i>0){
                player_game[i-1][j]='E';
            }
            if(i<9){
                player_game[i+1][j]='E';
            }
            j++;
        }
        if(j<=9){
            player_game[x1][j]='E';
        }
    }
    //SECOND CONDITION
    //IF THE SHIP WAS VERTICAL
    if(mode_1 == 1){
            //INIT
        i=x1;j=y1;
        //
        if(x1>0){
            player_game[x1-1][y1]='E';
        }
        while(i<=x2){

            player_game[i][j]='C';
            if(j<9){
                player_game[i][j+1]='E';
            }
            if(j>0){
                player_game[i][j-1]='E';
            }

            i++;
        }
        if(i<=9){
            player_game[i][j]='E';
        }
        //END OF VERTICAL
    }

}

int check(struct ships **head,char player_game[10][10],int *counter_ships){
    struct ships *current=*head;
    int i,j,counter;
    int tmp;
    SetColor(4);
    while(current != NULL){
            counter=0;
        //FIRST CONDITION
        //IF THE SHIP IS HORIZONTAL
        if(current->mode == -1){

        i=current->x_start;j=current->y_start;
        while(j <= current->y_end ){
            if(player_game[i][j] == 'P'){
                          counter++ ;
            }
            j++;
        }
        //IF ALL PARTS OF A SHIP TARGETED
        if(counter == current->length ){
            change_houses(player_game,current->mode,current->x_start,current->y_start,current->x_end,current->y_end);
            printf("YOU HAVE DESTROYED A SHIP OF THIS LENGTH=%d\n\a",current->length);
            tmp=current->length;
            *counter_ships-=1;
            printf("NUMBER OF SHIPS REMAINING=%d\n",(*counter_ships));
            delete_ship(head,current->x_start,current->y_start);
            return tmp;
        }
        //END OF HORIZONTAL
        }
        counter=0;
        //IF THE SHIP IS VERTICAL
            if(current->mode == 1){

            i=current->x_start;j=current->y_start;
            while(i <= current->x_end){
                if(player_game[i][j] == 'P'){
                        counter++;
                }
                i++;
            }
             //IF ALL PARTS OF A SHIP TARGETED
             if(counter == current->length){
                  change_houses(player_game,current->mode,current->x_start,current->y_start,current->x_end,current->y_end);
                  printf("YOU HAVE DESTROYED A SHIP OF THIS LENGTH=%d\n\a",current->length);
                  tmp=current->length;
                  *counter_ships-=1;
                   printf("NUMBER OF SHIPS REMAINING=%d\n",(*counter_ships));
                  delete_ship(head,current->x_start,current->y_start);
                  return tmp;
             }
            //END OF VERTICAL
        }
        current=current->next;
        if(current == NULL){break;}
        //END OF WHILE
    }
    return -1;
}

int turn(char player[10][10],char player_game[10][10]){
            int x1,y1,res,i;
            printf("THIS IS YOUR ENEMY MAP\n");
            print_result_map(player_game);

            //GET THE LOCATION OF THE TARGET HOUSE
            while(1){
            printf("please enter the location of the house you want to destroy\n");
            scanf("%d %d",&x1,&y1);
            res=search_2(player_game,x1,y1);
                //IF INVALID INPUT
            if(((x1<0) || (x1>9)) || ((y1<0) || (y1>9))){
                printf("INVALID INPUT PLEASE TRY AGAIN\n");}
            if(res == -1){
                printf("INVALID INPUT BECAUSE THIS HOUSE HAS ALREADY BEEN SELECTED\n");}
                //IF VALID INPUT
            if(((x1>=0) && (x1<=9))  && ((y1>=0) && (y1<=9)) && (res==0)){
                break;}
            }

            //FIRST CONDITION
            //IF THE SELECTED HOUSE WAS EMPTY
            if(player[x1][y1] != 's'){
                printf("THERE WAS NO SHIP IN THE HOUSE YOU CHOOSE\n");
                player_game[x1][y1]='E';
                //E = EMPTY
                return 0;
            }
            //SECOND CONDITION
            //IF IT TARGETS PART OF THE SHIP
            if(player[x1][y1] == 's'){
                //P = PART
                player_game[x1][y1]='P';
                return 1;
            }

}

int search_name(char name_8[30]){
    int tmp;char help_name[30];
    //OPEN FILE
    FILE *p_name=fopen("D:\\scoreboard.txt","r");
    //SEARCH IN THE FILE
    while(1){

        if(feof(p_name)){
            break;}
        fscanf(p_name,"%s %d",help_name,&tmp);
        if(strcmp(help_name,name_8) == 0){
            fclose(p_name);
            return -1;
        }
    }

    fclose(p_name);
    return 0;
}

int previous_names(char name_10[30]){
    int tmp;char help_name[30];
    //OPEN FILE
    FILE *p_name=fopen("D:\\scoreboard.txt","r");
    //PRINT PRE_SAVED INFORMATION
    while(1){

        if(feof(p_name)){
            break;}
        fscanf(p_name,"%s %d",help_name,&tmp);
        printf("%s\t%d\n",help_name,tmp);
        }
    //RETUTN TO BEGINNING OF THE FILE
    fseek(p_name,0,SEEK_SET);

    //GET THE DESIRED NAME FROM THE USER
    printf("WHICH NAME DO YOU MEAN?\n");
    scanf("%s", name_10);

    //FILE SEARCH
    while(1){

        if(feof(p_name))
            break;

        fscanf(p_name,"%s %d",help_name,&tmp);
        if(strcmp(name_10,help_name) == 0){
            fclose(p_name);
            return tmp;
        }
        }

    fclose(p_name);
    return -1;
}

int two_player_game_menu(char name_10[30],int *coin){
    int code,res;
    SetColor(12);
    //GET A VALID NAME
    printf("1.CHOOSE USER\n");
    printf("\t1.choose from available users\n");
    printf("\t2.new user\n");
    scanf("%d",&code);
    //FIRST CONDITION
    //CHOOSE FROM AVAILABLE USERS
    if(code == 1){
        printf("CHOOSE FROM PREVIOUS NAMES\n");
        while(1){

            *coin=previous_names(name_10);
            if(*coin != -1)
                break;
            //IF INVALID INPUT
            if(*coin == -1)
                printf("INVALID INPUT\n");
        }
}
    //SECOND CONDITION
    //NEW USER
    if(code == 2){

        while(1){
        printf("please enter name\n");
        scanf("%s",name_10);
        *coin=0;
        res=search_name(name_10);
        //IF VALID INPUT
        if(res == 0)
            break;
        //IF INVALID INPUT
        if(res == -1){
            printf("THIS NAME HAS ALREADY BEEN SELECTED\n");
        }
        //END OF WHILE
        }
    }
        //CHOOSE HOW TO ARRANGE THE SHIPS
        printf("2.PUT SHIPS\n");
        printf("\t1.auto\n");
        printf("\t2.manual\n");
        scanf("%d",&code);


        if(code == 1){
            return 1;
        }
        if(code == 2){
            return 2;
        }
 //END OF FUNCTION


}
void prev_coin(char name[30],int *prev_coin){
        char help_name[30];int tmp;
        //OPEN FILE
        FILE *coin=fopen("D:\\scoreboard.txt","r");
        //READ FROM FILE
        while(1){
            //CHECK END OF FILE
            if(feof(coin))
                break;
        fscanf(coin,"%s %d",help_name,&tmp);
        if(strcmp(help_name,name) == 0){
            *prev_coin=tmp;
             break;
        }
        }
        fclose(coin);
}

void play_in_two_player_mode(int sign,char first_player[10][10],char first_player_game[10][10],char second_player[10][10],char second_player_game[10][10],struct ships *head1,struct ships *head2,int coin_1,int coin_2,char first_player_name[30],char second_player_name[30],int counter_ships1,int counter_ships2){
    //DECLARE VARIABLES
    int prev_coin_1=0,prev_coin_2=0;
    SetColor(11);
    //IF NEW GAME
    if(sign == 10){
        coin_1=0;coin_2=0;counter_ships1=10;counter_ships2=10;

    //GET THE NAME AND ARRANGMENT OF THE SHIPS
        //FIRST PLAYER
        printf("FIRST PLAYER\n");
        int tmp_10=two_player_game_menu(first_player_name,&prev_coin_1);
        if(tmp_10 == 2){
                printf("FIRST PLAYER:%s\n",first_player_name);
                initialization_first_data(first_player);
                get_first_data(&head1,first_player);
                        }
        if(tmp_10 == 1){
                initialization_first_data(first_player);
                random_map(&head1,first_player);
        }
          system("cls");
        //SECOND PLAYER
        printf("SECOND PLAYER\n");
        tmp_10=two_player_game_menu(second_player_name,&prev_coin_2);
        if(tmp_10 == 2){
                printf("SECOND PLAYER:%s\n",second_player_name);
                initialization_first_data(second_player);
                get_first_data(&head2,second_player);
        }
        if(tmp_10 == 1){
            initialization_first_data(second_player);
            random_map(&head2,second_player);
        }
        system("cls");
        initialization_first_data(first_player_game);initialization_first_data(second_player_game);
    }
    if(sign == 20){
        prev_coin(first_player_name,&prev_coin_1);
        prev_coin(second_player_name,&prev_coin_2);
    }

     //START MAIN GAME
    int counter_train=2;int res,code,tmp;
    int coin_tmp1,coin_tmp2;
    //INITIALIZATION


    while((head1 != NULL) || (head2 != NULL)){

        //IF IT IS THE TURN OF THE FIRST PLAYER
        if(counter_train % 2 == 0){

                //SAVE GAME
                printf("DO YOU WANT TO SAVE THE GAME?ENTER -1 \n");
                scanf("%d",&code);
                if(code == -1){
save_game('t',first_player,second_player,first_player_game,second_player_game,head1,head2,coin_1,coin_2,first_player_name,second_player_name,counter_ships1,counter_ships2);
                printf("ENTER KEY 2 IF YOW WANT THE GAME TO END\n");
                scanf("%d",&code);
                if(code == 2)
                    break;
}
                 system("cls");
                //THE FIRST PLAYER TURNS
                printf("IT IS TURN OF THE FIRST PLAYER:%s\n",first_player_name);
                res=turn(second_player,second_player_game);

                if(res==0){
                    counter_train++;
                    printf("NUMBER OF COINS COLLECTED=%d\n",coin_1);
                    printf("THIS IS YOUR ENEMY MAP\n");
                    print_result_map(second_player_game);
                    }
                //AGAIN , IT IS THE TURN OF THE FIRST PERSON
                    if(res == 1){
                    coin_1++;
                    tmp=check(&head2,second_player_game,&counter_ships2);
                    if(tmp == 5){coin_1+=5;}
                    if(tmp == 3){coin_1+=8;}
                    if(tmp == 2){coin_1+=12;}
                    if(tmp == 1){coin_1+=25;}
                    printf("NUMBER OF COINS COLLECTED=%d\n",coin_1);
                    printf("THIS IS YOUR ENEMY MAP\n");
                    print_result_map(second_player_game);
                }
                //END
        }
            //CHECK END OF GAME
            if((head1 == NULL) || (head2 == NULL)){
            printf("END OF GAME\n");
            Beep(355,8000);
            coin_tmp1=prev_coin_1+coin_1;coin_tmp2=prev_coin_2+coin_2;
            //IF THE FIRST PLAYER WINS
            if(head2 == NULL){
                printf("%s won\n",first_player_name);
                coin_tmp2/=2;
            }
            //IF THE SECOND PLAYER WINS
            if(head1 == NULL){
                printf("%s won\n",second_player_name);
                coin_tmp1/=2;
            }
            save_scoreboard('t',first_player_name,second_player_name,coin_tmp1,coin_tmp2);
            break;
            }
          //IF IT IS THE TURN OF THE SECOND PLAYER
          if(counter_train %2 == 1){

             //SAVE GAME
                printf("DO YOU WANT TO SAVE THE GAME? ENTER -1 \n");
                scanf("%d",&code);
                if(code == -1){
save_game('t',first_player,second_player,first_player_game,second_player_game,head1,head2,coin_1,coin_2,first_player_name,second_player_name,counter_ships1,counter_ships2);
              printf("ENTER KEY 2 IF YOW WANT THE GAME TO END\n");
              scanf("%d",&code);
              if(code == 2)
                    break;
}
             system("cls");
            //THE SECOND PLAYER TURNS
            printf("IT IS TURN OF THE SECOND PLAYER:%s\n",second_player_name);
            res=turn(first_player,first_player_game);
            //THE SECOND PLAYER TURNS
            if(res == 0){
                counter_train++;
                printf("NUMBER OF COINS COLLECTED=%d\n",coin_2);
                printf("THIS IS YOUR ENEMY MAP\n");
                print_result_map(first_player_game);
                }
            //AGAIN , IT IS THE TURN OF THE SECOND PERSON
            if(res == 1){
                coin_2++;
                tmp=check(&head1,first_player_game,&counter_ships1);
                if(tmp == 5){coin_2+=5;}
                if(tmp == 3){coin_2+=8;}
                if(tmp == 2){coin_2+=12;}
                if(tmp == 1){coin_2+=25;}
                printf("NUMBER OF COINS COLLECTED=%d\n",coin_2);
                printf("THIS IS YOUR ENEMY MAP\n");
                print_result_map(first_player_game);
            }
            //END
          }
          //CHECK END OF GAME
          if((head1 == NULL) || (head2 == NULL)){
            printf("END OF GAME\n");
            Beep(355,8000);
            coin_tmp1=prev_coin_1+coin_1;coin_tmp2=prev_coin_2+coin_2;
             //IF THE FIRST PLAYER WINS
            if(head2 == NULL){
                printf("%s won\n",first_player_name);
                coin_tmp2/=2;
            }
            //IF THE SECOND PLAYER WINS
            if(head1 == NULL){
                printf("%s won\n",second_player_name);
                coin_tmp1/=2;
            }
            save_scoreboard('t',first_player_name,second_player_name,coin_tmp1,coin_tmp2);
            break;
            }
//END OF WHILE
}
//END OF FUNCTION
}


int robot_turn(char player[10][10],char player_game[10][10]){
    int x1,y1,res;
    //GENERATE VALID LOCATION
    while(1){
    srand(time(0));
    x1=rand();x1=x1%10;
    y1=rand();y1=y1%10;
    res=search_2(player_game,x1,y1);
    if(res == 0){
        break;
    }

}
    //IF THE TARGET HOUSE IS EMPTY
    if(player[x1][y1] != 's'){
        player_game[x1][y1]='E';
        //E = EMPTY
        return 0;
    }
    //IF THE TARGET HOUSE IS A PIECE OF SHIP
    if(player[x1][y1] == 's'){
        player_game[x1][y1]='P';
        //P = PART
        return 1;
    }

}

void solitary_game(int sign,char first_player[10][10],char first_player_game[10][10],char bot[10][10],char bot_game[10][10],struct ships *head,struct ships *head_bot,int coin_player,int coin_bot,char first_player_name[30][30],int counter_ships1,int counter_ships2){
    SetColor(13);
    int prev_coin_player=0;
    //IF NEW GAME
    if(sign == 10){
    coin_bot=0;coin_player=0;counter_ships1=10;counter_ships2=10;
    //GET NAME AND ARRANGMENT OF THE SHIPS
    int tmp_10=two_player_game_menu(first_player_name,&prev_coin_player);
    if(tmp_10 == 2){
         initialization_first_data(first_player);
         get_first_data(&head,first_player);
    }
    if(tmp_10 == 1){
        initialization_first_data(first_player);
        random_map(&head,first_player);
    }
    system("cls");
    //GET BASIC INFORMATION FROM USER & PICKING THE INITIAL MAP OF THE ROBOT

    initialization_first_data(bot);
    random_map(&head_bot,bot);
    initialization_first_data(first_player_game);initialization_first_data(bot_game);
    }

    if(sign == 20){
        prev_coin(first_player_name,&prev_coin_player);
    }
    //START MAIN GAME
    int counter_train=2;int res,code,tmp,coin_tmp_player=0;
    //INITIALIZATION



    while((head_bot != NULL) || (head != NULL)){
    //IF IT IS THE PLAYER'S TURN
    if(counter_train%2 == 0){

                //SAVE GAME
                printf("DO YOU WANT TO SAVE THE GAME? ENTER -1 \n");
                scanf("%d",&code);
                if(code == -1){
save_game('o',first_player,bot,first_player_game,bot_game,head,head_bot,coin_player,coin_bot,first_player_name,"bot",counter_ships1,counter_ships2);
                printf("ENTER KEY 2 IF YOW WANT THE GAME TO END\n");
                scanf("%d",&code);
                if(code == 2)
                    break;
}
                 system("cls");
                //TURN OF PLAYER
                printf("IT IS YOUR TURN:%s\n",first_player_name);
                res=turn(bot,bot_game);
                //THE FIRST PLAYER TURNS
                if(res==0){
                    counter_train++;
                    printf("NUMBER OF COINS COLLECTED=%d\n",coin_player);
                    printf("THIS IS YOUR ENEMY MAP\n");
                    print_result_map(bot_game);
                    }
                //AGAIN , IT IS THE TURN OF THE FIRST PERSON
                else if(res == 1){
                    coin_player++;
                    tmp=check(&head_bot,bot_game,&counter_ships2);
                    if(tmp == 5){coin_player+=5;}
                    if(tmp == 3){coin_player+=8;}
                    if(tmp == 2){coin_player+=12;}
                    if(tmp == 1){coin_player+=25;}
                    printf("NUMBER OF COINS COLLECTED=%d\n",coin_player);
                    printf("THIS IS YOUR ENEMY MAP\n");
                    print_result_map(bot_game);
                }
                //END OF TURN PLAYER
        }
            //CHECK END OF GAME
            if((head == NULL) || (head_bot == NULL)){
                Beep(600,8000);
                printf("END OF GAME\n");
                coin_tmp_player=prev_coin_player+coin_player;
                //IF THE PLAYER WINS
                if(head_bot == NULL){
                    printf("YOU WON\n");
                }
                //IF THE PLAYER IS DEFEATED
                if(head == NULL){
                    printf("YOU LOST\n");
                    coin_tmp_player/=2;
                }
                save_scoreboard('o',first_player_name,"bot",coin_tmp_player,coin_bot);
                break;
            }
            //IF IT IS THE COMPUTER TURN
            if(counter_train%2 == 1){
                printf("ENTER 1 TO SEE YOUR MAP\n");
                scanf("%d",&code);
                res=robot_turn(first_player,first_player_game);
                if(res == 0){
                    counter_train++;
                    printf("NUMBER OF COINS COLLECTED BY THE COMPUTER=%d\n",coin_bot);
                    printf("THIS IS YOUR MAP\n");
                    print_result_map(first_player_game);

                }
                if(res == 1){
                    coin_bot++;
                    tmp=check(&head,first_player_game,&counter_ships1);
                    if(tmp == 5){coin_bot+=5;}
                    if(tmp == 3){coin_bot+=8;}
                    if(tmp == 2){coin_bot+=12;}
                    if(tmp == 1){coin_bot+=25;}
                    printf("NUMBER OF COINS COLLECTED BY THE COMPUTER=%d\n",coin_bot);
                    printf("THIS IS YOUR MAP\n");
                    print_result_map(first_player_game);
                      //CLEAR THE CONSOLE
                    printf("PRESS TO KEY ONE TO CONTINUE THE GAME\n");
                    scanf("%d",&code);
                    system("cls");
                }

            }
              //CHECK END OF GAME
              if((head == NULL) || (head_bot == NULL)){
                printf("END OF GAME\n");
                Beep(600,8000);
                coin_tmp_player=prev_coin_player+coin_player;
                //IF THE PLAYER WINS
                if(head_bot == NULL){
                    printf("YOU WON\n");
                }
                //IF THE PLAYER IS DEFEATED
                if(head == NULL){
                    printf("YOU LOST\n");
                    coin_tmp_player/=2;
                }
                save_scoreboard('o',first_player_name,"bot",coin_tmp_player,coin_bot);
                break;
              }
    }

    //END OF FUNCTION
}
int main()
{
    int code;
    while(1){
    original_menu();
    scanf("%d",&code);

    //DECLARE VARIABLES
    char first_player[10][10];char first_player_game[10][10];char second_player[10][10];char second_player_game[10][10];
    struct ships *head1=NULL;struct ships *head2=NULL;
    int coin1;int coin2;int counter_ships1,counter_ships2;
    char first_player_name[30];char second_player_name[30];
    int sign;

    if(code == 1){
        play_in_two_player_mode(10,first_player,first_player_game,second_player,second_player_game,head1,head2,coin1,coin2,first_player_name,second_player_name,counter_ships1,counter_ships2);
    }
    //PLAY WITH BOT
    if(code == 2){
      solitary_game(10,first_player,first_player_game,second_player,second_player_game,head1,head2,coin1,coin2,first_player_name,counter_ships1,counter_ships2);
    }
    //LOAD GAME
    if(code == 3){
        sign=load_game(first_player,first_player_game,second_player,second_player_game,&head1,&head2,&coin1,&coin2,first_player_name,second_player_name,&counter_ships1,&counter_ships2);


        //IF SINGLE PLAYER GAME
        if(sign == 1){
            solitary_game(20,first_player,first_player_game,second_player,second_player_game,head1,head2,coin1,coin2,first_player_name,counter_ships1,counter_ships2);
        }
      //IF MULTY PLAYER GAME
      if(sign == 2){
            play_in_two_player_mode(20,first_player,first_player_game,second_player,second_player_game,head1,head2,coin1,coin2,first_player_name,second_player_name,counter_ships1,counter_ships2);
        }
}
    //LOAD LAST GAME
    if(code == 4){

      sign=load_last_game(first_player,first_player_game,second_player,second_player_game,&head1,&head2,&coin1,&coin2,first_player_name,second_player_name,&counter_ships1,&counter_ships2);

      //IF SINGLE PLAYER GAME
      if(sign == 1){
        solitary_game(20,first_player,first_player_game,second_player,second_player_game,head1,head2,coin1,coin2,first_player_name,counter_ships1,counter_ships2);
      }
      //IF MULTY PLAYER GAME
      if(sign == 2){
        play_in_two_player_mode(20,first_player,first_player_game,second_player,second_player_game,head1,head2,coin1,coin2,first_player_name,second_player_name,counter_ships1,counter_ships2);
      }

    }
    //SCOREBOARD
    if(code == 6){
        score_board();
    }
    if(code == 7){
        break;
    }
    }
    return 0;
}
