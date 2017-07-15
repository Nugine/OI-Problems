#include<cstdio>
#include<iostream>
using namespace std;

struct num {
	int n;
	num *next;
};


struct num* num_initLink(string str){
	int l=str.length();

	num *head = new num();
	num *pre;

	head->next = new num();
	pre = head->next;
	head->n = str[l-1]-'0';

	for(int i = l-2; i >= 0;i--) {
		pre->n = str[i]-'0';
		pre->next = new num();
		
		cout << pre->n;
		pre = pre->next;
	}
	pre->n = str[0]-'0';
	pre->next = NULL;
	
	return head;
}

void num_coutAll(struct num *head){
	struct num *pre=head;
		 
	while(pre->next!=NULL){
		cout << pre->n << endl;
		pre = pre->next;
	}
}
//=====================================


string getStr(){
	string str;
	cin >> str;
	return str;
}


int main(){
	struct num *h1 = num_initLink(getStr());
	num_coutAll(h1);
	system("pause");
	return 0;
}

