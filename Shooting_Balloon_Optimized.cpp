#include <iostream> 
using namespace std; 

int getmaxscore(int arr[], int l, int r, int n) 
{ 
	int mscore = 0; 
	for (int i = l + 1; i < r; i++) { 

		// to permute through all cases 
		int cs = getmaxscore(arr, l, i, n) + getmaxscore(arr, i, r, n); 
		if (l == 0 && r == n) 
			cs = cs + arr[i]; 
		else
			cs = cs + (arr[l] * arr[r]); 

		if (cs > mscore) 
			mscore = cs; 
	} 
	return mscore; 
} 

int main()
{ 
	int n = 4;
	int arr[] = { 1, 1, 2, 3, 4, 1 }; 
	cout << getmaxscore(arr, 0, n + 1, n + 1) << "\n";
	return 0; 
} 

