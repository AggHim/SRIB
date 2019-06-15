#include <iostream>
using namespace std;

int N, toll[22], men[22], minCost = 1000000;

void dfs(int index, int m1, int m2, int m3, int cost){
	
	if (index == N){
		if (cost < minCost){
			minCost = cost;
		}
		return;
	}
	int total_men = m1 + m2 + m3;
	/*
	if (index == N - 1){
		if (total_men < men[index]){
			cost += toll[index];
		}
		if (minCost > cost){
			minCost = cost;
		}
		return;
	}
	*/
	if (cost + toll[index] < minCost){
		dfs(index + 1, m1, m2, m3, cost + toll[index]);
	}
	
	if (cost + 2 * toll[index] < minCost){
		dfs(index + 1, m1, m2, m3 + men[index], cost + 2 * toll[index]);
	}
	

	if (total_men > men[index]){
		int remaining = m1 - men[index];
		if (remaining < 0){
			m1 = 0;
			if (m2 + remaining < 0){
				m2 = 0;
				m3 = m3 + remaining;
			}
			else{
				m2 = m2 + remaining;
			}
		}
		else{
			m1 = m1 - men[index];
		}
		/*
		if (men[index] > m1 + m2){
			m3 = total_men - men[index];
			m1 = 0;
			m2 = 0;
		}
		else if(men[index] > m1){
			m2 = (m1 + m2) - men[index];
			m1 = 0;
		}
		else{
			m1 = m1 - men[index];
		}
		*/
		dfs(index + 1, m2, m3, 0, cost);
	}
}

int main(){
	int t;
	cin >> t;
	while (t--){
		minCost = 1000000;
		cin >> N;
		for (int i = 0; i < N; i++){
			cin >> men[i] >> toll[i];
		}
		dfs(0, 0, 0, 0, 0);
		cout << minCost << endl;
	}
	return 0;
}
