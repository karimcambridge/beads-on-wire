
#include <stdio.h>
#include <stdlib.h>

#define maxBeads 50
#define maxBoxes 100

int aesthectic();	
void printOrder(int, int);

FILE *in,*out;
int beads, boxes;
int A[maxBeads+1][maxBoxes+1];

int main()
{

	in = fopen("input.txt","r");
	out = fopen("output.txt", "w");
	if(in == NULL || out == NULL){
		printf("Error Reading Files!\n");
		return 0;
	}

	fscanf(in, "%d %d", &beads, &boxes);
	int i, j;
	/*
		The first row represent no beads
		The first column represents no box
	*/
	for(i=0; i<=beads; i++){
		A[i][0] = 0; // fill first colum with 0
		for(j = 0;j <= boxes; j++){
			A[0][j] = 0; // fill first row with 0
			if(i >0 && j > 0){
				fscanf(in,"%d", &A[i][j]);		
			}			
		}		
	}
	int a = aesthectic();
	printf("Best aesthectic Value: %d\n", a);
	printf("Beads go in these boxes:\n");
	printOrder(beads, boxes);
	fclose(in);
	fclose(out);
	return 0;
}



int aesthectic(){
	int i, j;
	for(i=1; i<=beads; i++){		
		for(j = 1;j <= boxes; j++){						
			if(i == j){ 
				A[i][j] = A[i-1][j-1] + A[i][j];
			}else if(j > i){
				if(A[i][j - 1] > A[i - 1][j] + A[i][j]){
					A[i][j] = A[i][j - 1];
				}else{
					A[i][j] = A[i - 1][j-1] + A[i][j];
				}
			}				
		}		
	}
	return A[beads][boxes];
}

void printOrder(int i, int j){
	if(i ==0 || j == 0)return;
	else if(A[i][j] > A[i][j-1] && A[i][j] > A[i-1][j]){
		printOrder(i-1,j-1);
		printf("box[%d] = bead %d \n", j, i);		
	}else if(A[i][j] == A[i][j-1])printOrder(i,j-1);
}