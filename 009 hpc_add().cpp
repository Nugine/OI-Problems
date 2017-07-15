#include<cstdio>
#include<iostream>
#include<cstring>>
using namespace std;

void reverseStr(string &str){
	int l=str.length();
	for(int pos=0;pos<l/2;pos++){
		char tmp=str[pos];
		str[pos]=str[l-1-pos];
		str[l-1-pos]=tmp;
	}
}

bool hpc_ifNum(string str){
	int l=str.length();
	for(int i=0;i<=l-1;i++){
		if(str[i]-'0'<0 || str[i]-'0'>9){
			return false;
		}
	}
	return true;
}

void hpc_fixNum(string &str){
	int l=str.length();
	int l2;
	for(int i=0;i<=l-1;i++){
		if(str[i]!='0'){l2=i;break;}
	}
	string str2="";
	for(int i=l2;i<=l-1;i++){
		str2+=str[i];
	}
	str=str2;
}


string hpc_add(string a,string b){
	int l1=a.length();reverseStr(a);
	int l2=b.length();reverseStr(b);
	
	string str="";
	for(int i=0;i<=max(l1,l2)-1;i++){
		int t1=a[i];int t2=b[i];
		if(i>=l1){t1=48;}
		if(i>=l2){t2=48;}
		str+=t1+t2-'0';
	}
	for(int i=0;i<=max(l1,l2)-2;i++){
		if(str[i]-'0'>=10){
			str[i]-=10;
			str[i+1]+=1;
		}
	}
	if(str[max(l1,l2)-1]-'0'>=10){
		str[max(l1,l2)-1]-=10;
		str+="1";
	}
	
	reverseStr(str);
	return str;
}


int main(){
	string a;
	cin>>a;
	if(!hpc_ifNum(a)){cout<<"非法字符！";return 0;}
	hpc_fixNum(a);
	string b;
	cin>>b;
	if(!hpc_ifNum(b)){cout<<"非法字符！";return 0;}
	hpc_fixNum(b);
	
	cout<<hpc_add(a,b)<<endl;

	system("pause");
}

