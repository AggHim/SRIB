#include <iostream>
using namespace std;

template <typename T>
class queue{
	
	T* data;
	int nextIndex;
	int frontIndex;
	int size;
	int capacity;
	
	public:
	queue(int s){
		data = new T[s];
		size = 0;
		nextIndex = 0;
		frontIndex = -1;
		capacity = s;
	}
	
	int getSize(){
		return size;
	}
	
	bool empty(){
		return size==0;
	}
	
	void push(T x){
		
		if(size==capacity){
			T* n_data = new T[2*capacity];
			int k = 0;
			for(int i= frontIndex; i<capacity; i++){
				n_data[k] = data[i];
				k+=1;
			}
			for(int i= 0; i<frontIndex; i++){
				n_data[k] = data[i];
				k+=1;
			}
			delete [] data;
			data = n_data;
			frontIndex = 0;
			nextIndex = capacity;
			capacity = 2*capacity;
		}
		
		data[nextIndex] = x;
		nextIndex = (nextIndex+1)%capacity;
		if(frontIndex==-1){
			frontIndex = 0;
		}
		size+=1;
	}
	
	T front(){
		if(size==0){
			return 0;
		}
		return data[frontIndex];
	}
	
	void pop(){
		if(size==0){
			return;
		}
		frontIndex = (frontIndex+1)%capacity;
		size-=1;
		if(size==0){
			frontIndex = 0;
			frontIndex = -1;
		}
	}
	
};

int main() {
	// your code goes here
	queue<int> q(1);
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	cout << q.getSize() << endl;
	cout << q.front() << endl;
	q.pop();
	return 0;
}
