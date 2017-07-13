#include<cstdio>
#include<iostream>
using namespace std;

long getMin(long x,long y){
	if(x<=y){
		return x;
	}
	else{
		return y;
	}
	
}

int main(){
	long x,y;
	cin>>x;cin>>y;
	cout<<getMin(x,y);	
}
