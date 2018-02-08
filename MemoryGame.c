/**  Memory Game, Author: Michelle Kim 


data: 00 02, 10 11, 23 20, 01 13, 03 22, 12 21

**/


#include <stdio.h>
#include <stdlib.h>


void getUserInputs(int *row, int *col, int *row2, int *col2);
void printMatrix(char mat[3][4]);
int compareTiles(char A, char B); //return 1 if true


int main() {
  
  //fill matrix
  char matrix[3][4];
  int i,j;
  for(i=0;i<3;i++) {
    for(j=0;j<4;j++) {
      matrix[i][j] = 'X';
      printf("%c",matrix[i][j]);

      if(j==3) {
	printf("\n");
      }
    }
  }

  //shuffle string
  char filestr[] = "AABBCCDDEEFF";  
  int ind, r, temp;
  srand(3);

  for(ind=0;ind<12;ind++) {
    r = rand() % 11;
    temp = filestr[ind]; filestr[ind]=filestr[r]; filestr[r] = temp;
  }
  //printf("string: %s\n", filestr);

  //play game
  int correct, failed;
  correct = 0;
  failed = 0;
  while(correct<6 && failed<5) {
    int input1_row, input1_col, input2_row, input2_col;
    getUserInputs(&input1_row, &input1_col, &input2_row, &input2_col); //ask user for 2 sets of rows and cols

    //reveal selected tiles
    int index1, index2;
    index1 = (input1_row * 4) + input1_col;
    index2 = (input2_row * 4) + input2_col;
    //printf("index1: %d, index2: %d\n", index1, index2);
    printf("\n");

    //protects against repeat selections
    if(matrix[input1_row][input1_col]==' ') {
      printf("1 or more tiles have already been chosen. Try Again\n\n");
      continue;
    }
    matrix[input1_row][input1_col] = filestr[index1];
    matrix[input2_row][input2_col] = filestr[index2];

    //print updated matrix 
    printMatrix(matrix);

    //if tiles match, set tile to ' ', redraw, and add 1 to # correct
    if(compareTiles(filestr[index1],filestr[index2])==1) {
      printf("You matched %c!\n", filestr[index1]);
      matrix[input1_row][input1_col] = ' ';
      matrix[input2_row][input2_col] = ' ';
      
      printMatrix(matrix);
      correct++;
    }
    
    //if tiles do not match, set tiles back to 'X', redraw, and add 1 to # failed
    else{
      printf("no match, try again\n");
      matrix[input1_row][input1_col] = 'X';
      matrix[input2_row][input2_col] = 'X';
      
      printMatrix(matrix);
      failed++;
    }
    
    printf("Correct: %d, Failed: %d\n", correct, failed);
    printf("\n\n");
  }
  
  //once out of the while loop, check if player won or lost, then exit program
  if(correct==6) {
    printf("You won!!!\n\n");
    exit(0);
  }
  if(failed==5) {
    printf("You lose :(\n\n");
    exit(0);
  }
  return 0;


}

int compareTiles(char A, char B) {
  if(A == B) {
    return 1;
  }
  else {
    return 0;
  }
}


void getUserInputs(int *row, int *col, int *row2, int *col2) {
  printf("Enter a row 0-2 and col 0-3, separated by a space: ");
  scanf("%d %d", &*row, &*col);
  printf("Enter another row 0-2 and col 0-3, separated by a space: ");
  scanf("%d %d", &*row2, &*col2);
  //printf("First Input: %d and %d \n",*row,*col);                                                        //printf("Second Input: %d and %d \n", *row2, *col2); 

}

void printMatrix(char mat[3][4]){
  int m, n;
  for(m=0; m<3; m++) {
    for(n=0; n<4; n++) {
      printf("%c",mat[m][n]);

      if(n==3) {
	printf("\n");
      }
    }
  }
  printf("\n");

}
