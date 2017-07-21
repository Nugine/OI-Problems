#include<cstdio>
#include<iostream>
using namespace std;

void func(unsigned int n){
	if(n==0){
		cout<<"0";
		return;
	}
	bool first=true;
	for(unsigned int i=32;i>=1;i--){
		if((n<<(32-i))>>31==1){
			if(first){cout<<"2";first=false;}else{cout<<"+2";}
			if(i-1!=1){
				cout<<"(";
				func(i-1);
				cout<<")";
			}
		}
	}
}

int main(){
	unsigned int n=0;
	cin>>n;
	func(n);
	system("pause");
}

