#include <stdio.h>

#define MAXSIZE 200001

int size;

int left(int i){
	return i*2+1;
}
int right(int i){
	return i*2+2;
}
int parent(int i){
	return (i-1)/2;
}
int min(int A[]){
	return A[0];
}
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}
void minHeapify(int A[], int i){
	int smallest =0;
	int l = left(i);
	int r = right(i);
	if (l<size && A[l]<A[i]){
		smallest = l;
	}
	else smallest = i;
	if(r<size && A[r] < A[smallest]){
		smallest = r;
	}
	if(smallest != i){
		swap(&A[smallest], &A[i]);
		minHeapify(A, smallest);
	}
}
void buildMinHeap(int A[]){
	int i;
	for(i = (size/2)-1; i >= 0; i--){
		minHeapify(A, i);
	}
}

void insertHeap(int A[], int x){
	size++;
	int i=size-1;
	A[i]=x;
	while ((i>0) && (A[i]<A[parent(i)])){
		swap(&A[i], &A[parent(i)]);
		i = parent(i);
	}
}

int main(){
	int A[MAXSIZE];
	int q,x,i;
	scanf("%d", &size);
	for(i=0;i<size;i++){
		scanf("%d", &A[i]);
	}
	buildMinHeap(A);
	scanf("%d", &q);
	for(i = 0; i< q; i++){
		int Qu;
		scanf("%d", &Qu);
		if(Qu == 1){
			scanf("%d", &x);
			insertHeap(A, x);
		}
		else {
			printf("%d\n", min(A));
		}
	}
}
