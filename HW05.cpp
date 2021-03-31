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
		cout<<"請輸入編號：";
		cin>>now->no;
		cin.ignore();
		cout<<"請輸入姓名：";
		cin.getline(now->name,10);
		cout<<"請輸入平時成績：";
		cin>>now->normal;
		cout<<"請輸入期中成績：";
		cin>>now->mid;
		cout<<"請輸入期末成績：";
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
		cout<<"繼續請按'1'，結束請按'0'：";
		cin>>m;
	}while(m);
	now=head->next;
	while(now!=NULL){
		cout<<"編號："<<now->no<<endl<<"姓名："<<now->name<<endl<<"平時；"<<now->normal<<endl<<"期中："<<now->mid<<endl<<"期末："<<now->final<<endl<<endl;
		now=now->next; 
	}
}
