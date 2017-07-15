#include<cstdio>
#include<iostream>
using namespace std;

void swc(int &a,int &b){int c=a;a=b;b=c;}

int main(){
	int a,b;
	cout<<"ÇëÊäÈëÕûÊý£º";cin>>a;cin>>b;
	swc(a,b);
	cout<<a<<" "<<b<<endl;
	system("pause");
}

