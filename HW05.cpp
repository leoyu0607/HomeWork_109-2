#include<iostream>
#include<cstring>
#include<iomanip> 
using namespace std;

class st{
	public:
		int no = -1;
		char name[10];
		int normal;
		int mid;
		int final;
		st *next = NULL;
};
int main(){
	int m=1;
	st *head = new st;
	st *ptr;
	st *prev = head;
	st *curr = head;
	st *now;
	do{
		now=new st;
		prev=head;
		curr=head;
		cout<<"�п�J�s���G";
		cin>>now->no;
		cin.ignore();
		cout<<"�п�J�m�W�G";
		cin.getline(now->name,10);
		cout<<"�п�J���ɦ��Z�G";
		cin>>now->normal;
		cout<<"�п�J�������Z�G";
		cin>>now->mid;
		cout<<"�п�J�������Z�G";
		cin>>now->final;
		while(curr->no!=NULL){
			if(now->no<=curr->no){
				prev->next=now;
				prev->next->next=curr;
				break;
			}
			if(curr->next==NULL){
				curr->next=now;
				break;
			}
			if(curr!=head){
				prev=prev->next;
			}
			curr=curr->next;
		}
		cout<<"�~��Ы�'1'�A�����Ы�'0'�G";
		cin>>m;
	}while(m);
	now=head->next;
	while(now!=NULL){
		cout<<"�s���G"<<now->no<<endl<<"�m�W�G"<<now->name<<endl<<"���ɡF"<<now->normal<<endl<<"�����G"<<now->mid<<endl<<"�����G"<<now->final<<endl<<endl;
		now=now->next; 
	}
}
