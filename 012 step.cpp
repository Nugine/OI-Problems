#include<cstdio>
#include<iostream>
using namespace std;

//��̨��
//����������ݣ�һ��Ϊ̨����n�����һ��Ϊ0 
//0<n<100

//����һ����1�ף�Ҳ����һ����2�ף�������һ����3��
//n=1: 1; 1�� 
//n=2: 1,1;2; 2��
//n=3: 1,1,1;1,2;2,1;3; 4��
//n=4: 1111,112,121,211,22,13,31; 7��
//	����1�ף�n=3  4��
//  ����2�ף�n=2   2��
//  ����3�ף�n=1   1�� 

//  f(n)=f(n-1)+f(n-2)+f(n-3)  (n>=4,n����N*) 
//  f(1)=1;f(2)=2;f(3)=4;

//  f(4)=f1+f2+f3
//  f5=f2+f3+f4
//  ......
//  fn=

int getResult(int n,int mem[]){
	if(mem[n]!=-1)return mem[n];
	else{
		mem[1]=1;
		mem[2]=2;
		mem[3]=4;
		for(int i=4;i<=n;i++){
			mem[i]=mem[i-1]+mem[i-2]+mem[i-3];
		}
		return mem[n];
	}
}



int main(){
	int n=0;
	int mem[100];
	for(int i=0;i<=99;i++){
		mem[i]=-1;
	}
	
	while(true){
		cin>>n;
		if(n==0)break;
		else cout<<getResult(n,mem)<<endl;;
	}
	
	system("pause");
}

