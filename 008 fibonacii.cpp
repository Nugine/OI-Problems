#include<cstdio>
#include<iostream>
using namespace std;

unsigned long long digui_fib(int n){
	if(n==1||n==2){
		return 1;
	}
	else{
		return digui_fib(n-1)+digui_fib(n-2);
	}
}

unsigned long long ditui_fib(int n){
	unsigned long long a=1;
	unsigned long long b=1;
	unsigned long long c;
	if(n==1||n==2){
		return 1;
	}
	for(int i=3;i<=n;i++){
		c=a+b;
		a=b;
		b=c;
	}
	return b;
}

int main(){
	for(int i=1;i<=100;i++){
		cout<<ditui_fib(i)<<endl;
	}
	for(int i=1;i<=100;i++){
		cout<<digui_fib(i)<<endl;
	}
	system("pause");
}

