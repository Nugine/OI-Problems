#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

//输入中文时无法正确输出，应该与编码有关

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
