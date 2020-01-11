#include <stdio.h>
#include<stdlib.h>


void printboard(char board[3][3]){
    int i,j;
    printf("\n-----------------\n");
    for(i=0; i<3; i++){
        printf("|| ");
        for(j=0; j<3; j++){
            printf("%c || ", board[i][j]);
        }
        printf("\n-----------------\n");
    }
}

int filled(char board[3][3]){
  int i, j;
  for(i=0; i<3; i++){
    for(j=0; j<3; j++){
      if(board[i][j] == '_'){
        return 0;
      }
    }
  }
  return 1;
}

int evaluate(char board[3][3]){
  int i;
  int j = 0;
  // Rows
  for(i=0; i<3; i++){
    if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){
      if(board[i][0]=='X'){return 10;}
      if(board[i][0]=='O'){return -10;}
    }
  }
  // Columns
  for(i=0; i<3; i++){
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
      if(board[i][0]=='X'){return 10;}
      if(board[i][0]=='O'){return -10;}     
    }
  }
  // Diagonals
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
    if(board[0][0]=='X'){return 10;}
    if(board[0][0]=='O'){return -10;}    
  }
  if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
    if(board[1][1]=='X'){return 10;}
    if(board[1][1]=='O'){return -10;}    
  }
  // No win
  return 0;
}


int main(){
    char board[3][3]=
    {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };

    // printboard(board);
    // board[1][0] = 'X';
    // printboard(board);
    // board[2][2] = 'O';
    // printboard(board);
    // board[1][1] = 'X';
    // printboard(board);
    // printf("%d", filled(board));
    // X- 10 Y- -10
    // printf("%d", evaluate(board));
    // board[0][0] = 'O';
    // board[2][2] = 'O';
    // board[1][1] = 'O';
    // printboard(board);
    // printf("%d", evaluate(board));
    return 0;
}