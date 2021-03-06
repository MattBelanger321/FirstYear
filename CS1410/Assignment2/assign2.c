#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define WORD_COUNT 101
#define MAX_LETTER 101

int arrlen;//stores number of words in word list
int groupLength = 0; 
int numSets;
int duplicates;

/*this function will find the size of a list of words
input: a list of words
output: size of list*/
int findRowsize(char arr[][MAX_LETTER]);
int findRowsize(char arr[][MAX_LETTER]){
	int i;
	duplicates = 0;
	for(i =1;strcmp(arr[i],"")!=0;i++){
		if(strcmp(arr[i],arr[i-1])==0){
			duplicates++;
		}
	}
	return i-1;
}

/*this function will sort the contents of a list of words alphabetically
input: an array of strings
output: alphabetically sorted array of character arrays*/
void SortSet(char A[][MAX_LETTER]);
void SortSet(char A[][MAX_LETTER]){
	char temp[WORD_COUNT];
	int i;
	for(i=0;strcmp(A[i],"")!=0;i++){
		if(strcmp(A[i],A[i+1])>0){
			strcpy(temp ,A[i+1]);
			strcpy(A[i+1] ,A[i]);
			strcpy(A[i] ,temp);
			i=-1;
		}
	}
}

/*removes duplicate sets of coordinates
input 2 integer arrays
output: sets the elements of the second array to -1 if they are equal and returns 1 or returns 0  if not equal*/
int isEqual(int rowA[],int rowB[]);
int isEqual(int rowA[],int rowB[]){
	int i;
	for(i = 0;rowA[i]!= -1&&rowB[i]!=-1;i++){
		if(rowA[i]!=rowB[i]){
			return 0;
		}
	}
	if( (rowA[i] == -1 || rowB[i]==-1) && rowA[i] != rowB[i]){
		return 0;
	}
	
	for(int j=0;j<i;j++){
		rowB[j] = -1;
	}
	return 1;
}

/*this function will organize an array of words into sets
input: an array of words an array of sets of words and an array of integer indexs
output: saves the sets into a 3d char array*/
	
void SaveSets(int sets[][WORD_COUNT],char arr[][MAX_LETTER],char group[][WORD_COUNT][MAX_LETTER]);
void SaveSets(int sets[][WORD_COUNT],char arr[][MAX_LETTER],char group[][WORD_COUNT][MAX_LETTER]){
	int a=-1;
	int j;
	for(int i=0;i<arrlen;i++){
		
		if(sets[i][0]!=-1){
			numSets=++a;
		}else{
			continue;
		}//if
		
		for(j = 0; sets[i][j]!=-1;j++){
			
			if(strcmp(arr[j] ,"-1")!=0){
				strcpy(group[a][j],arr[sets[i][j]]);
			}//if
		
		}//for j
		
		while(sets[i][j]!=-1){//replaces checked words with -1;
			j=0;
			strcpy(arr[sets[i][j]] ,"-1");
			j++;
		}//while
	}//for i
}

/*Description: This function will print an array
Input: a 2d array the size of rows of the array and the size of the columns
Output: prints the contents of the array in a tabular format*/
void displayArray2D(const int mat[][WORD_COUNT],unsigned int rowsize,unsigned int colsize);
void displayArray2D(const int mat[][WORD_COUNT],unsigned int rowsize,unsigned int colsize){
	printf("\n");
	for(int i = 0; i<rowsize;i++){
		for(int j =0;j<colsize;j++){
			printf("\t%d, ", mat[i][j]);
		}
		printf("\n");
	} 
}

/*this function will print the elements of an array
it takes the array and the size of the array as input
it will display the elements */
void PrintArray(char array [][MAX_LETTER]);
void PrintArray(char array [][MAX_LETTER]){
	for(int i=1;strcmp(array[i],"")!=0; i++){
		if(strcmp(array[i],array[i+1])!=0){
			printf("%s, ",array[i]);
		}
	}
	printf("\n");
}
/*this function will store the indexs of duplicate words in an list and store the indexs in an integer array
input: an array of words and a 2d integer array
output: saves indexs in an integer array*/
void findDuplicateSets(char words[][MAX_LETTER],int sets[][WORD_COUNT]);
void findDuplicateSets(char words[][MAX_LETTER],int sets[][WORD_COUNT]){
	int a;
	for(int i = 0;i<arrlen;i++){
		a=0;
		if((strcmp(words[i],"-1")!=0)){
			for(int j = 0;j<arrlen;j++){
				if(strcmp(words[i],words[j])==0){
					sets[i][a] = j;
					a++;
				}
			}
		}
	}
}
/*takes a character array and sorts the characters alphabetically
input: character array
output: sorts array aplhabetically*/
void SortWord(char A[]);
void SortWord(char A[]){
	char temp;
	for(int i=0;A[i]!='\0';i++){
		if(A[i+1]>A[i]){
			temp = A[i];
			A[i] = A[i+1];
			A[i+1] = temp;
			i=-1;
		}
	}
}


/*Description: This function will copy an array into another array
Input: 2 2d arrays the size of rows of the arrays and the size of the columns
Output: returns 0 is copy is sucessful*/

int CopyArray2D(char A[][MAX_LETTER], char B[][MAX_LETTER]);
int CopyArray2D(char A[][MAX_LETTER], char B[][MAX_LETTER]){
	for(int i = 0; i<WORD_COUNT-1;i++){
		for(int j =0;'\0'!=A[i][j]&&j<MAX_LETTER;j++){
			B[i][j]=A[i][j];
		}
	} 
	return 0;
}
void SortGroups(char groups[][WORD_COUNT][MAX_LETTER]);
void SortGroups(char groups[][WORD_COUNT][MAX_LETTER]){
	char temp[MAX_LETTER];
	int length;
	//sort by rowsize
	for(int i=0;strcmp(groups[i+1][0],"");i++){
		if( findRowsize(groups[i])-duplicates < findRowsize(groups[i+1])-duplicates ){
			length = findRowsize(groups[i+1]);
			for(int j=0;j<=length;j++){
				strcpy(temp , groups[i+1][j]);
				strcpy(groups[i+1][j],groups[i][j]);
				strcpy(groups[i][j],temp);
			}//for j
			i=-1;
		}else if(findRowsize(groups[i]) == findRowsize(groups[i+1]) ){
			if(strcmp(groups[i][0],groups[i+1][0])>0){
				length = findRowsize(groups[i+1]);
				for(int j=0;j<=length;j++){
					strcpy(temp , groups[i+1][j]);
					strcpy(groups[i+1][j],groups[i][j]);
					strcpy(groups[i][j],temp);
				}//for j
				i=-1;
			}
		}
	}//for i
}



int main(){
	char words[WORD_COUNT][MAX_LETTER];//holds words entered by user
	char wordscpy[WORD_COUNT][MAX_LETTER];//used to reagange words contents alphabetically
	char groups[WORD_COUNT][WORD_COUNT][MAX_LETTER];//
	int anagramSet[WORD_COUNT][WORD_COUNT];
	
	//populates anagram set with -1
	for(int i = 0;i<WORD_COUNT;i++){
		for(int j = 0;j<WORD_COUNT;j++){
			anagramSet[i][j]=-1;
		}
	}
	
	int i=0;
	//populates array
	for(i=0;1;i++){
		scanf("%s",words[i]);
		if(strcmp(words[i],"STOP")==0||i>WORD_COUNT){
			arrlen = i;
			break;
		}
	}
	
	//populates the copy
	CopyArray2D(words,wordscpy);
	
	//reaganges the letters of the words in the copy to be alphabetical
	for(int i = 0;strcmp(wordscpy[i],"STOP")!=-10&&i<WORD_COUNT;i++){
		SortWord(wordscpy[i]);
	}
	//populates anagramSet with locations of anagrams 
	findDuplicateSets(wordscpy,anagramSet);
	
	//removes duplice lists of locations from anagramSet
	for(int j =0;j<arrlen;j++){
		for(int k = j+1; k<arrlen;k++){
			isEqual(anagramSet[j],anagramSet[k]);
		}
	}
	
	//populates groups with the sets of anagrams
	SaveSets(anagramSet,words,groups);
	
	SortGroups(groups);
	for(int j = 0;j<WORD_COUNT;j++){
		SortSet(groups[j]);
	}
	
	for(int j = 0;j<5;j++){
		if(findRowsize(groups[j])==0){break;}
		printf("Group of size %d:  ",findRowsize(groups[j])-duplicates);
		PrintArray(groups[j]);
	}
	return 0;
}