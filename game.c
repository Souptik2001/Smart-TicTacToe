#include <stdio.h>
#include<stdlib.h>
#include<math.h>

struct Move{
  int row;
  int col;
};

// Computer playing as 'O' and is maximizing
// Player playing as 'X' and is minimizing

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
      if(board[i][0]=='X'){return -10;}
      if(board[i][0]=='O'){return 10;}
    }
  }
  // Columns
  for(i=0; i<3; i++){
    if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
      if(board[0][i]=='X'){return -10;}
      if(board[0][i]=='O'){return 10;}     
    }
  }
  // Diagonals
  if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
    if(board[0][0]=='X'){return -10;}
    if(board[0][0]=='O'){return 10;}    
  }
  if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
    if(board[1][1]=='X'){return -10;}
    if(board[1][1]=='O'){return 10;}    
  }
  // No win
  return 0;
}

int min(int a, int b){
  if(a<b){return a;}
  else{return b;}
}

int max(int a, int b){
  if(a>b){return a;}
  else{return b;}
}

int minimax(char board[3][3], int depth, int ismax){
  int i, j;
  int score = evaluate(board);

  if(score == 10){
    return score-depth;
  }
  if(score == -10){
    return score+depth;
  }
  if(filled(board) == 1){
    return 0;
  }
  if(ismax == 1){
    int best = -1000;
    for(i=0; i<3; i++){
      for(j=0; j<3; j++){
        if(board[i][j] == '_'){
          board[i][j] = 'O';
          best = max(best, minimax(board, depth+1, 0));
          board[i][j] = '_';
        }
      }
    }
    return best;
  }
  else{
    int best = 1000;
    for(i=0; i<3; i++){
      for(j=0; j<3; j++){
        if(board[i][j] == '_'){
          board[i][j] = 'X';
          best = min(best, minimax(board, depth+1, 1));
          board[i][j] = '_';
        }
      }
    }
    return best;
  }
}

struct Move bestMove(char board[3][3]){
  int move_score;
  int best_move_score = -1000;
  struct Move move;
  move.row = -1;
  move.col = -1;
  int i,j;
  for(i=0; i<3; i++){
    for(j=0;j<3;j++){
      if(board[i][j] == '_'){
        board[i][j] = 'O';
        move_score = minimax(board, 0, 0);
        board[i][j] = '_';
        if(move_score>best_move_score){
          move.row = i;
          move.col = j;
          best_move_score = move_score;
        }
      }
    }
  }
  return move;
}


int main(){
    char board[3][3]=
    {
        {'_', '_', '_'},
        {'_', '_', '_'},
        {'_', '_', '_'}
    };
    printf("\n    ----UNBEATABLE TIC-TAC-TOE GAME -_- ----    \n");
    printf("\n    You are playing as 'X'    \n");
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
    int a;
    int x;
    int y;
    printboard(board);
    while(filled(board) == 0){
      // printf("%d\n", evaluate(board));
      printf("\nEnter the position 1-9 : ");
      scanf("%d", &a);
      if(a<=3){y=a-1;x=0;}
      if(a>3 && a<=6){y=a-3-1;x=1;}
      if(a>6){y=a-6-1;x=2;}
      if(board[x][y] != '_' || x>2 || y>2){printf("ENTER A VALID MOVE.");continue;}
      board[x][y] = 'X';
      printboard(board);
      if(evaluate(board) == -10){
        printf("\nYou win Computer loose.\n");
        return 0;
      }
      struct Move move = bestMove(board);
      printf("\nComp plays....Row : %d Column : %d\n", move.row, move.col);
      board[move.row][move.col] = 'O';
      printboard(board);
      if(evaluate(board) == 10){
        printf("\nComputer Wins You loose.\n");
        return 0;
      }
    }
    if(evaluate(board) == 10){
      printf("\nComputer Wins You loose.\n");
      return 0;
    }
    if(evaluate(board) == -10){
      printf("\nYou Wins Computer loose.\n");
      return 0;
    }
    printf("\nDraw match ! \n");
    return 0;
}