#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define data_size 28
#define data_thrs 10

int * generate_rand_data(int rand_threshold){
	static int data_array[data_size];

	for(int i = 0; i < data_size; i++){
		data_array[i] = rand() % rand_threshold;
	}
	return data_array;
}

void insertion_sort(int *x){

	for(int i = 1; i < data_size; i++){
		if(x[i] < x[i-1]){
			int swp = x[i];
			x[i] = x[i-1];
			x[i-1] = swp;
			i -= 2;
		}
		for(int j = 0; j < data_size; j++){
			printf("%i%s", x[j], " ");
		}
		printf("\n");
	}
}

void bubble_sort(int *x){

	int n_swps = 1;
	while(n_swps != 0){
		n_swps = 0;

		for(int i = 0; i < data_size; i++){
			printf("%i%s", x[i], " ");
		}
		printf("\n");

		for(int i = 1; i < data_size; i++){
			if(x[i] < x[i-1]){
				int swp = x[i];
				x[i] = x[i-1];
				x[i-1] = swp;
				n_swps++;
			}
		}
	}
}

int * merge(int *a, int *b){

}

void merge_sort(int *x){

	int n_swps = 1;

	int sec_array[data_size];
	for(int i = 0; i < data_size; i++){
		sec_array[i] = x[i];
	}

	int A[], B[];

	//while(n_swps != 0){	//n_swps = 0;
/*
		A[0] = x[0];
		B[0] = x[1];
		merge(A, B) -> write in sec_array
		A[0] = x[2];
		B[0] = x[3];
		merge... p/ todos os valores de x
		A[0] = x[0];
		A[1] = x[1];
		B[0] = x[2];
		B[1] = x[3];
		merge... p/ todos os valores
		A[0] = x[0];
		A[1] = x[1];
		A[2] = x[2];
		A[3] = x[3];
		B[0] = x[4];
		B[1] = x[5];
		B[2] = x[6];
		B[3] = x[7];
		merge(A, B) -> write in sec_array
		...
*/

		for(int i = 0; i < data_size; i++){
			printf("%i%s", x[i], " ");
		}
		printf("\n");
		}
	//}
}

/*
0 1 2 3 4 7 8 9 9 9
1 9 8 2 9 3 0 9 7 4
19  82  93  09  74
19  28  39  09  47
12 89  03 99  47
1289  0399  47
01238999  47
0123478999

*/
//void quicksort(int *x){}

void main(){
	srand(time(NULL));

	int *data;
	data = generate_rand_data(data_thrs);

	for(int i = 0; i < data_size; i++){
		printf("%i%s", data[i], " ");
	}
	printf("\n");

	merge_sort(data);
}
