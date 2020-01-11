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
    return 0;
}