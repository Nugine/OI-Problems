#include<cstdio>
#include<iostream>
using namespace std;

int board[9][9]={0};
int result=0;
int count=0;

void coutBoard(){
	for(int i=1;i<=8;i++){
		for(int j=1;j<=8;j++){
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}
void putQueen(int i,int j){
	for(int t=1;t<=8;t++){
		board[t][j]+=1;
		board[i][t]+=1;
		if(t+j-i>=1 && t+j-i<=8)board[t][t+j-i]+=1;
		if(i+j-t>=1 && i+j-t<=8)board[t][i+j-t]+=1;
	}
}
void removeQueen(int i,int j){
	for(int t=1;t<=8;t++){
		board[t][j]-=1;
		board[i][t]-=1;
		if(t+j-i>=1 && t+j-i<=8)board[t][t+j-i]-=1;
		if(i+j-t>=1 && i+j-t<=8)board[t][i+j-t]-=1;
	}
}
void search(int i){
	for(int j=1;j<=8;j++){			//����ĳһ�е������� 
		if(board[i][j]==0){
			putQueen(i,j);result=result*10+j;	//���ûʺ󣬼�¼λ�� 
			if(i==8){count++;cout<<result<<endl;}				//������ϣ�������
			else search(i+1);					//��������һ�е����� 
			removeQueen(i,j);result/=10;		//������ϣ��Ƴ��ʺ󣬻��� 
		}
	}
}

int main(){
	search(1);
	cout<<count<<endl;
	system("pause");
}

