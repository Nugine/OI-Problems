#include<cstdio>
#include<iostream>
using namespace std;

//===================================
struct num {
	short n;
	num *pre;
	num *next;
};

bool num_ifNum(string str);
num *num_initLink(string str);
void num_coutAll(struct num *head);
void num_fixNum(num *head);

num *num_initLink(string str){
	if(!num_ifNum(str)){return NULL;}
	
	int l=str.length();

	num *head = new num();
	num *pre=head;
	
	head->pre=NULL;
	head->next = new num();
	
	for(int i = l-1; i >= 1;i--) {
		pre->n = str[i]-'0';
		pre->next = new num();
		pre->next->pre=pre;
		pre = pre->next;
		
	}
	pre->n = str[0]-'0';
	pre->next = NULL;
	
	num_fixNum(head);
	
	return head;
}

void num_coutAll(struct num *head){
	num *tail=head;
	while(true){
		if(tail->next==NULL){break;}
		else{tail=tail->next;}
	}
	num *pre=tail;
	while(true){
		cout << pre->n;
		if(pre->pre==NULL){break;}
		pre = pre->pre;
	}
	cout<<endl;
}

bool num_ifNum(string str){
	int l=str.length();
	if(l<=0){return false;}
	else{
		int a;
		for(int i=0;i<=l-1;i++){
			a=str[i];
			if(a<48 || a>57){return false;}
		}
		return true;
	}
}

void num_fixNum(num *head){
	num *tail=head;
	while(true){
		if(tail->next==NULL){break;}
		else{tail=tail->next;}
	}
	while(true){
		if(tail==head){break;}
		if(tail->n==0){tail=tail->pre;delete tail->next;tail->next=NULL;}
		else{break;}
	}
}

num *num_add(num *head1,num *head2){
	num *head=new num();
	head->pre=NULL;
	head->next=NULL;
	
	num *zero=new num();
	zero->n=0;
	zero->next=NULL;
	
	num *tail=head;
	num *pre1=head1;
	num *pre2=head2;
	
	short t=0;
	
	while(true){
		short r=pre1->n+pre2->n;
		tail->n=r%10+t;
		if(r>=10){t=1;}else{t=0;}
		
		if(pre1->next==NULL && pre2->next==NULL){break;}
		else{
			tail->next=new num();
			tail->next->pre=tail;
			tail=tail->next;
			if(pre1->next!=NULL){pre1=pre1->next;}else{pre1=zero;}
			if(pre2->next!=NULL){pre2=pre2->next;}else{pre2=zero;}
		}
	}
	if(t==1){
			tail->next=new num();
			tail->next->pre=tail;
			tail->next->next=NULL;
			tail->next->n=1;
	}
	return head;
}
//=====================================


string getStr(){
	string str;
	cin >> str;
	return str;
}


int main(){
	num *h1 = num_initLink(getStr());
	if(h1==NULL){cout<<"非法字符！";return 0; }
	
	num *h2 = num_initLink(getStr());
	if(h2==NULL){cout<<"非法字符！";return 0; }
	
	num_coutAll(h1);
	num_coutAll(h2);
	
	num *r=num_add(h1,h2);
	num_coutAll(r);
	
	system("pause");
	return 0;
}
