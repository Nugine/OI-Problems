#include<cstdio>
#include<iostream>
using namespace std;

//cout<<"alive";

//===========================================
struct num{
	//��������ڵ� 
	int n;
	struct num *next;
};


struct num* num_initLink(string str){
	//����߾��������ַ�������������ͷ�ڵ�ָ�� 
	//δ���Ǹ��š���ĸ���������ݵ���� 
	int l=str.length();
	struct num *head;
	struct num *pre;
										cout<<"alive";
	head->next=new struct num;
										cout<<"alive";
	pre=head->next;
										cout<<"alive";
	head->n=str[l-1]-'0';
										cout<<"alive";
	for(int i=l-2;i>=0;i--){
										cout<<"alive";
		pre->n=str[i]-'0';
										cout<<"alive";
		pre->next=new struct num;
		
		cout<<pre->n;
		pre=pre->next;
	}
	pre->n=str[0]-'0';
	pre->next=NULL;
	
	return head;
}

void num_coutAll(struct num *head){
	struct num *pre=head;
		 
	while(pre->next!=NULL){
		cout<<pre->n;
		pre=pre->next;
	}
}
//=====================================


string getStr(){
	string str;
	cin>>str;
	return str;
}


int main(){
	struct num *h1=num_initLink(getStr());
	num_coutAll(h1);
	system("pause");
	return 0;
}

