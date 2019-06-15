#include <iostream>
#include <climits>
#define MAXN 100
using namespace std;

void BubbleSort(int arr[], int n){
    for(int j=0;j<n-1;j++){
        for(int i=0;i<n-1-j;i++){
            if(arr[i]>arr[i+1]){
                int temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
            }
        }
    }
}

void SelectionSort(int arr[], int n){
    int i=0;
    while(i<n){
        int minIndex = -1;
        int min = INT_MAX;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                minIndex=j;
                min=arr[j];
            }
        }
        if(minIndex!=i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex]=temp;
        }
        i++;
    }
}

void CountingSort(int arr[], int n){
	int aux[MAXN] = {0};
	for(int i=0;i<n;i++){
		aux[arr[i]]+=1;
	}
	int k = 0;
	for(int i=0;i<MAXN;i++){
		int c = aux[i];
		for(int j=0;j<c;j++){
			arr[k] = i;
			k+=1;
		}
	}
}

int main(){
	int n;
	cin >> n;
	int arr[MAXN];
	for(int i=0;i<n;i++){
		cin >> arr[i];
	}
	CountingSort(arr,n);
	for(int i=0;i<n;i++){
		cout << arr[i] << " ";
	}
}
