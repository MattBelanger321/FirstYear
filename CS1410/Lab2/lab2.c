#include <stdio.h>
#define MAX 100
/*Description: this function will allow a user to populate a 2d array
input: the size of the array and the array
output: instructions on how to input the contents
*/
void populateMatrix(int numOfRows,int mat[][numOfRows]){
	for(int i = 0; i<numOfRows;i++){
		for(int j = 0; j<numOfRows;j++){
			printf("What is element (%d,%d)\n",i,j);
			scanf("%d",&mat[i][j]);
		}
		printf("\n");
	}
}
/*Description: this function will print if a 2D matrix
input: the size of the array and the array
output: prints the contents of an array in a tabular format
*/
void printMatrix(int numOfRows, int mat[][numOfRows]);
void printMatrix(int numOfRows, int mat[][numOfRows]){
	printf("\n");
	for(int i = 0; i<numOfRows;i++){
		for(int j = 0; j<numOfRows;j++){
			printf("%d, ",mat[i][j]);
		}
		printf("\n");
	}
}

/*Description: this function will sum the row or collumn of an array
input: the size of the array and the array aswell as a 1 to sum a row or a 0 to sum a collumn and the index of what is being summed
output: returns an integer that is the sum of the row
*/
int sumRow(int numOfRows,int mat[][numOfRows],int choice,int row);
int sumRow(int numOfRows,int mat[][numOfRows],int choice,int row){
	int sum = 0;
	if(choice){
		for(int i = 0; i<numOfRows;i++){
			sum+=mat[row][i];
		}
	}else{
		for(int i = 0; i<numOfRows;i++){
			sum+=mat[i][row];
		}
	}
	return sum;
}
/*Description: this function will determine if a 2D matrix is a magic square
input: the size of the array and the array
output: returns an 1 if its a magic square and 0 if it is not
*/
int isMagicSquare(int numOfRows, int mat[][numOfRows]);
int isMagicSquare(int numOfRows, int mat[][numOfRows]){
	int x = sumRow(numOfRows,mat,1,0);
	int y = 0;
	for(int i = 0;i<numOfRows;i++){
		if(x != sumRow(numOfRows, mat, 1, i)||x!=sumRow(numOfRows, mat, 0, i)){
			printf("*");
			return 0;
		}
	}
	y=0;
	for(int i = 0;i<numOfRows;i++){
		y += mat[i][i];
	}
	if(x!=y){
		return 0;
	}
	y=0;
	for(int i = 0;i<numOfRows;i++){
		y+=mat[i][numOfRows-1-i];
	}
	if(x!=y){
		return 0;
	}
	return 1; // if the matrix is a magic square
}
/*Description: this function will determine if a 2D matrix is a magic square
input: the size of the array and the array
output: returns an 1 if its a distinct square and 0 if it is not
*/
int isDistinctSquare(int numOfRows, const int mat[][numOfRows]);
int isDistinctSquare(int numOfRows, const int mat[][numOfRows]){
	for(int i =0;i<numOfRows;i++){
		for(int j = 0; j<numOfRows;j++){
			for(int k =0; k<numOfRows; k++){
				for(int l =0; l<numOfRows;l++){
					if((i!=k||j!=l)&&(mat[i][j]==mat[k][l])){
						return 0;//matrix is not distinct
					}
				}
			}
		}
	}
	return 1; // if the matrix has no duplicates all values are unique
}
/*Description: this function will sort a 2D matrix in ascending order in rows
input: the size of the array and the array
output: n/a
*/
void SortRowWise(int numOfRows, int mat[][numOfRows]);
void SortRowWise(int numOfRows, int mat[][numOfRows]){
	int temp;//is a temperary place holder to move around elements
	for(int i=0;i<numOfRows;i++){
		for(int j = 0;j<numOfRows-1;j++){
			if(mat[i][j]>mat[i][j+1]){
				temp = mat[i][j+1];
				mat[i][j+1] = mat[i][j];
				mat[i][j] = temp;
				j=-1;
			}
		}
	}
	printMatrix(numOfRows,mat);
}
/*Description: this function will make a transpose of an array then print it
input: the size of the array and the array
output: prints out the transpose of a matrix using the print matrix function
*/
void GetTranspose(int numOfRows, int mat[][numOfRows]);
void GetTranspose(int numOfRows, int mat[][numOfRows]){
	int tran[numOfRows][numOfRows];
	for(int i = 0; i<numOfRows;i++){
		for(int j = 0; j<numOfRows;j++){
			tran[j][i] = mat[i][j];
		}
	}
	printMatrix(numOfRows,tran);
}
/*int menu();
int menu(){
int n; //holds the choice
	printf("\n1: GetTranspose\n2: SortRowWise\n3: isDistinctSquare\n4. isMagicSquare\n5: printMatrixData\n6: setMatrixData\n");
	scanf("%d",&n);
	return n;
}*/

int main(){
	int matrix[MAX][MAX] = {0};
	int numOfRows;
	printf("Enter the number of rows (<100)\n");
	scanf("%d",&numOfRows);
	while(numOfRows>MAX||0>numOfRows){
		printf("\nEnter the number of rows (<100)\n");
		scanf("%d",&numOfRows);
	}
	populateMatrix(numOfRows,matrix);
	printf("\nYour matrix is: ");
	printMatrix(numOfRows, matrix);
	printf("\nThe transpose is: ");
	GetTranspose(numOfRows, matrix);
	if(isDistinctSquare(numOfRows,matrix)){
		printf("\nYour matrix is a distinct square\n");
	}else{
		printf("\nYour matrix is not a distinct square\n");
	}
	if(isMagicSquare(numOfRows,matrix)){
		printf("Your matrix is a magic square\n");
	}else{
		printf("your matrix is not a magic square\n");
	}
	SortRowWise(numOfRows,matrix);
	return 0;
}