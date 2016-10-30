#include<iostream>
using namespace std;

long power_of_10(const int n){
	long result = 1;
	if(n==0) return 1;
	for(int i=1; i<=n; i++)
	result *= 10;
	return result;
}

int main(){
	
	for(int n=0; n<=10; n++)
		cout<<power_of_10(n)<<endl;
	cout<<endl;
	
	return 0;
}

