#include <iostream>
#include <cstdio>
#include <fstream>
#pragma warning (disable: 4996)
using namespace std;

int main() {
	
	/*
	File Open for Input:
	*/
	freopen("input.txt","r",stdin);
	
	// your code goes here
	float f = 3.12345;
	float a = 4;
	cout.precision(10);
	cout << fixed;
	cout << f << endl;
	cout << a << endl;
	
	/*
	
	float f = 3.12345;
	float a = 4;
	cout.precision(10);
	cout << f << endl;
	cout << a << endl;
	
	Output:
	3.144500017
	4
	
	*/
	
	return 0;
}
