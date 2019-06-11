#include <iostream>
using namespace std;

int getMax(int* arr, int n){
    if(n==1){
        return arr[0];
    }
    int max = -1;
    for(int i=0;i<n;i++){
        if(i==0){
            int score = arr[1] + getMax(arr+1,n-1);
            if(score > max){
                max = score;
            }
        }else if(i==n-1){
            int score = arr[n-2] + getMax(arr,n-1);
            if(score > max){
                max = score;
            }
        }else{
            int score = arr[i-1]*arr[i+1];
            int* narr = new int[n-1];
            int k = 0;
            for(int j=0;j<n;j++){
                if(i!=j){
                    narr[k]=arr[j];
                    k++;
                }
            }
            int s = score + getMax(narr,n-1);
            if(s>max){
                max = s;
            }
        }
    }
    return max;
}

int main() {
    int t,m;
    cin >> t;
    m=t;
    while(t--){
        int n;
        cin >> n;
        int* arr = new int[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }
        cout << '#' << m-t << " " << getMax(arr,n) << endl;
    }
}
