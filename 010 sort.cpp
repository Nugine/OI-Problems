#include<cstdio>
#include<iostream>
#include<cstring>
#include<fstream>
#include<ostream> 
#include<time.h>
using namespace std;
void swc(int &a,int &b){int c=a;a=b;b=c;}

//int array [0]Œ™ ˝æ›∏ˆ ˝£¨[1]~[len]Œ™ ˝æ› 
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
		cout<<a[i]<<"\t\t\t\t";
	}
	cout<<endl;
}


//===============================
//—°‘Ò≈≈–Ú 
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

//√∞≈›≈≈–Ú 
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

//≤Â»Î≈≈–Ú 
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

//µ›πÈπÈ≤¢≈≈–Ú 
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

//øÏÀŸ≈≈–Ú 
void quickSort(int r[],int st,int ed){
	int mid=r[(st+ed)/2];
	int i=st,j=ed;
	while(i<=j){
		while(r[i]>mid)i++;
		while(r[j]<mid)j--;
		if(i<=j){
			swc(r[i],r[j]);
			i++;j--;
		}
	}
	if(st<j)quickSort(r,st,j);
	if(i<ed)quickSort(r,i,ed);
}

//œ£∂˚≈≈–Ú
void shellSort(int r[]){
	int len=r[0];
	for(int delta=len/2;delta>=1;delta/=2){
		for(int i=delta+1;i<=len;i++){
			int val=r[i];int j;
			for(j=i-delta;j>=1&&r[j]<val;j-=delta){
				r[j+delta]=r[j];
			}
			r[j+delta]=val;
		}
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
	int time[6];clock_t st,ed;
	
	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		selectSort(b);
	ed=clock();time[0]=ed-st;
	cout<<"selectSorted:"<<endl;coutArray(b);cout<<endl;
	
	
	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		bubbleSort(b);
	ed=clock();time[1]=ed-st;
	cout<<"bubbleSorted:"<<endl;coutArray(b);cout<<endl;
	
	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		insertSort(b);
	ed=clock();time[2]=ed-st;
	cout<<"insertSorted:"<<endl;coutArray(b);cout<<endl;

	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		mergeSort(b,1,b[0]);
	ed=clock();time[3]=ed-st;
	cout<<"mergeSorted:"<<endl;coutArray(b);cout<<endl;
	
	
	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		quickSort(b,1,b[0]);
	ed=clock();time[4]=ed-st;
	cout<<"quickSorted:"<<endl;coutArray(b);cout<<endl;
	
	memcpy(b,o,sizeof(int)*(o[0]+1));
	st=clock();
		shellSort(b);
	ed=clock();time[5]=ed-st;
	cout<<"shellSorted:"<<endl;coutArray(b);cout<<endl;
	
	cout<<"selectSort Time:"<<time[0]<<"ms"<<endl;
	cout<<"bubbleSort Time:"<<time[1]<<"ms"<<endl;
	cout<<"insertSort Time:"<<time[2]<<"ms"<<endl;
	cout<<"mergeSort Time:"<<time[3]<<"ms"<<endl;
	cout<<"quickSort Time:"<<time[4]<<"ms"<<endl;
	cout<<"shellSort Time:"<<time[5]<<"ms"<<endl;
	
	cin.rdbuf(cinbackup);
	//cout.rdbuf(coutbackup);
	
	system("pause");
}

