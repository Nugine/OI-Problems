#include<cstdio>
#include<iostream>
using namespace std;

void swc(int &a,int &b){int c=a;a=b;b=c;}

//int array [0]为数据个数，[1]~[len]为数据 
int* initArray(){
	int len=0;
	cin>>len;
	
	int *a=new int[len+1];
	a[0]=len;
	for(int i=1;i<=len;i++){
		cin>>a[i];
	}
	return a;
}

void coutArray(int a[]){
	int len=a[0];
	cout<<"\tlen:"<<len<<endl;
	
	cout<<"\tdata:";
	for(int i=1;i<=len;i++){
		cout<<a[i]<<",";
	}
	cout<<endl;
}

//===============================
//选择排序 
void selectSort(int r[]){
	int len=r[0];
	for(int i=1;i<=len;i++){
		int max_k=i;
		for(int j=i;j<=len;j++){
			if(r[j]>r[max_k]){
				max_k=j;
			}
		}
		swc(r[i],r[max_k]);
	}
}

//冒泡排序 
void bubbleSort(int r[]){
	int len=r[0];
	bool ifSwc=false;
	while(ifSwc){
		for(int i=1;i<=len-1;i++){
			if(r[i]<r[i+1]){
				swc(r[i],r[i+1]);
				ifSwc=true;
			}
		}	
	}
}

//插入排序 
void insertSort(int r[]){
	int len=r[0];
	
	for(int i=2;i<=len;i++){
		int preVal=r[i];				//抽出待插入的数据,留下一个空位 
		 
		int j=i-1;
		while(preVal>r[j]&&j>=1){		//将数据后移，找到正确空位 
			r[j+1]=r[j];
			j--;
		}
		r[j+1]=preVal;					//将待插入数据放入空位 
	}
}
//================================


int main(){
	int *o=initArray();
	cout<<endl;
	cout<<"origin:"<<endl;coutArray(o);cout<<endl;
	
	int *b=new int[o[0]];
	
	b=o;
	selectSort(b);
	cout<<"selectSorted:"<<endl;coutArray(b);cout<<endl;
	
	b=o;
	bubbleSort(b);
	cout<<"bubbleSorted:"<<endl;coutArray(b);cout<<endl;
	
	b=o;
	insertSort(b);
	cout<<"insertSorted:"<<endl;coutArray(b);cout<<endl;
	
	system("pause");
}

