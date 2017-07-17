#include<cstdio>
#include<iostream>
#include<cstring>
#include<fstream>
#include<ostream> 
#include<time.h>
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
	
	cout<<"\tdata:\n";
	for(int i=1;i<=len;i++){
		cout<<a[i]<<endl;
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
	bool ifSwapped=true;
	while(ifSwapped){
		ifSwapped=false;
		for(int i=1;i<=len-1;i++){
			if(r[i]<r[i+1]){
				swc(r[i],r[i+1]);
				ifSwapped=true;
			}
		}	
	}
}

//插入排序 
void insertSort(int r[]){
	int len=r[0];
	for(int i=2;i<=len;i++){
		int preVal=r[i];
		int j=i-1;
		while(preVal>r[j]&&j>=1){
			r[j+1]=r[j];
			j--;
		}
		r[j+1]=preVal; 
	}
}

//递归归并排序 
void mergeSort(int r[],int st,int ed){
	if(st==ed)return;
	
	int m=(st+ed)/2;
	mergeSort(r,st,m);mergeSort(r,m+1,ed);
	
	int i=st,j=m+1,k=0,t[ed-st+1];
	while(i<=m && j<=ed){
		if(r[i]>r[j]){
			t[k]=r[i];i++;
		}
		else{
			t[k]=r[j];j++;
		}
		k++;
	}
	while(i<=m){
		t[k]=r[i];i++;k++;
	}
	while(j<=ed){
		t[k]=r[j];j++;k++;
	}
	for(k=st;k<=ed;k++){
		r[k]=t[k-st];
	}
}
//================================


int main(){
	ifstream fin("sort_input.txt");
	//ofstream fout("sort_output.txt");
	streambuf *cinbackup=cin.rdbuf(fin.rdbuf());
	//streambuf *coutbackup=cout.rdbuf(fout.rdbuf());
	
	
	int *o=initArray();
	cout<<"origin:"<<endl;coutArray(o);cout<<endl;
	
	int *b=new int[o[0]+1];
	double time[4];clock_t st,ed;
	
	
	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		selectSort(b);
	ed=clock();time[0]=(double)(ed-st);
	cout<<"selectSorted:"<<endl;coutArray(b);cout<<endl;
	
	
	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		bubbleSort(b);
	ed=clock();time[1]=(double)(ed-st);
	cout<<"bubbleSorted:"<<endl;coutArray(b);cout<<endl;
	
	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		insertSort(b);
	ed=clock();time[2]=(double)(ed-st);
	cout<<"insertSorted:"<<endl;coutArray(b);cout<<endl;

	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		mergeSort(b,1,b[0]);
	ed=clock();time[3]=(double)(ed-st);
	cout<<"mergeSorted:"<<endl;coutArray(b);cout<<endl;
	
	cout<<"selectSort Time:"<<time[0]<<endl;
	cout<<"bubbleSort Time:"<<time[1]<<endl;
	cout<<"insertSort Time:"<<time[2]<<endl;
	cout<<"mergeSort Time:"<<time[3]<<endl;
	
	cin.rdbuf(cinbackup);
	//cout.rdbuf(coutbackup);
	
	system("pause");
}

