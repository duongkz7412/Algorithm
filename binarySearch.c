#include<stdio.h>
void swap(int *a, int *b)
 {
 	int t;
 	t=*a;
 	*a=*b;
 	*b=t;
  } 
  
void merge(int A[], int start, int mid, int end){
    int p = start, q = mid+1;
    int B[end-start+1], k=0;
    int i;
    for (i=start; i<=end; i++){
        if (p > mid) B[k++] = A[q++];
        else if (q > end) B[k++] = A[p++];
        else if (A[p] < A[q]) B[k++] = A[p++];
        else B[k++] = A[q++];
    }
    for (i=0; i<k; i++)
        A[start++] = B[i];
 }
    
void mergeSort (int A[], int start, int end){
    if(start < end) {
      int mid = (start + end)/2;
      mergeSort (A, start, mid);
      mergeSort (A, mid+1, end);
      merge (A, start, mid, end);
    }
 } 
		
 int binarySearch( int a[], int left, int right, int target)
	{
		
		int mid = (left+right)/2;	
		if ( right - left < 0) {
			return -1;
		}		
		if ( target == a[mid] ) {
			return mid+1;
		}		
		else if ( target >= a[mid]) {
			return binarySearch(a, mid+1, right, target);
		}		
		else {
			return binarySearch(a, left, mid-1, target);
		}
	}
 
 
int main()
{
	int a[100001], n ,q, i;
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d ", &a[i]);
	}
	mergeSort(a, 0, n-1);
	int x=0;
	scanf("%d", &q);
	for(i=1; i<=q; i++)
	{
		
		scanf("%d",&x);
        printf("%d\n", binarySearch(a,0,n-1,x));
	}
    
	return 0;
}

