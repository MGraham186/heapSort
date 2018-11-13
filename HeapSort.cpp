

#include <iostream>
using namespace std;
//#include<vector>
void printArray(int x[], int n);
int left(int i);
int right(int i);
void maxHeapify(int x[], int n, int i);
void buildMaxHeap(int x[],int n);
void heapSort(int x[], int n);
// ****** min heap
void Heaper(int x[], int i, int n);
void minHeaper(int x[], int n);
// *****
int main() {
	int x[] = {4,10,3,5,1,5,7,1,2,5,1,35,2,8853,35,12,53123,512,35,1235,123,65,123,6123,523,123,651,236,123,612,36,123};
	int n = sizeof(x)/sizeof(x[0]);
	heapSort(x,n);
	printArray(x,n);
}

void printArray(int x[], int n){
	for(size_t i = 0; i<n; i++)
		cout<<x[i]<<" ";
	cout<<endl;

}
void maxHeapify(int x[], int n, int i){
	i++; int Largest;
	int L = left(i), R = right(i);
	if(L<(n+1) and x[L-1]>x[i-1]){
		Largest = L;
	}else{
		Largest = i;
	}
	if(R<(n+1) and x[R-1]>x[Largest-1]){
		Largest = R;
	}
	if(Largest!=i){
		swap(x[i-1],x[Largest-1]);
		maxHeapify(x,n,Largest-1);
	}
}
void buildMaxHeap(int x[], int n){
	for(int i = n/2-1; i>=0; i--){
		maxHeapify(x,n,i);
	}
}
void heapSort(int x[], int n){
	if((n-1)>0){


	int parent = n/2-1;
	for(int i = parent; i>=0; i--){
		maxHeapify(x,n,i);
	}

	swap(x[0],x[n-1]);
	n--;
	heapSort(x,n);

	}
}

void Heaper(int x[], int i, int n){
	i++;int child1 = left(i), child2 = right(i);
	int smallest = i;  // trying 2 find the smallest of the 3 variables wrt to their indices;
	if(child1<n+1 and x[child1-1]<x[smallest-1])
		smallest = child1;
	if(child2<n+1 and x[child2-1] < x[smallest-1])
		smallest = child2;
	if(smallest!=i){
		swap(x[i-1],x[smallest-1]);
		Heaper(x,smallest-1 ,n);
	}
}
void minHeaper(int x[], int n){
	for(int i = n/2-1; i>=0; i--){
		Heaper(x,i,n);
		cout<<"i is: "<<i<<endl;
		printArray(x,n);
	}
}
int left(int i){
	return 2*i;
}
int right(int i){
	return 2*i+1;
}

