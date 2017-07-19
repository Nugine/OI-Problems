#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	unsigned int n,a,b,tmp;
	cin>>n;
	a=8;b=1;
	for(int i=2;i<=n;i++){
		tmp=a;
		a=(9*a+b)%12345;
		b=(tmp+9*b)%12345;
	}
	cout<<a<<endl;
	system("pause");
}

