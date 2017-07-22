#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

//Pell数列
//a1=1
//a2=2
//an=2*a(n-1)+a(n-2)   n>=3

//输入：数据组数n k1 k2 k3 ... kn
//输出：第k1项%32767=? 第k2项%32767=? 第k3项%32767=? ... 第kn项%32767=?
// 1<=k<1000000 

int pell(unsigned int k,unsigned int mem[]){
//	if(mem[k]==0&&k>=3){
//		mem[k]=(2*pell(k-1,mem)+pell(k-2,mem))%32767;
//	}
	if(mem[k]==0){
		unsigned int i;
		for(i=1;mem[i]!=0;i++){}
		for(;i<=k;i++)mem[i]=(2*mem[i-1]+mem[i-2])%32767;
	}
	return mem[k];
}


int main(){
	int n=0;unsigned int k;
	unsigned int *mem=new unsigned int[1000000];
	
	memset(mem,0,4*1000000);mem[1]=1;mem[2]=2;
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>k;
		cout<<pell(k,mem)<<endl;
	}
	
	system("pause");
}

