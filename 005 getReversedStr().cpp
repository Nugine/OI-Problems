#include<cstdio>
#include<iostream>
#include<string>
using namespace std;


string getReversedStr(string str);


int main(){
	string str;
	cout<<"请输入字符串："; cin>>str;
	cout<<getReversedStr(str)<<endl;
	system("pause");
}


string getReversedStr(string str){
	int l=str.length();
	for(int pos=0;pos<l/2;pos++){
		char tmp=str[pos];
		str[pos]=str[l-1-pos];
		str[l-1-pos]=tmp;
	}
	return str;
}
