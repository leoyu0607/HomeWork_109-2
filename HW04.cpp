#include<iostream>
#include<cstring>
#include<iomanip> 
using namespace std;

class st{
	public:
		int no;
		char name[10];
		int normal;
		int mid;
		int final;
		st *ptr;
};
int main(){
	int m=0;
	st *p;
	st *head;
	do{
		p=new st;
		p->ptr=head;
		head=p;
		cout<<"�п�J�s���G";
		cin>>p->no;
		cin.ignore();
		cout<<"�п�J�m�W�G";
		cin.getline(p->name,10);
		cout<<"�п�J���ɦ��Z�G";
		cin>>p->normal;
		cout<<"�п�J�������Z�G";
		cin>>p->mid;
		cout<<"�п�J�������Z�G";
		cin>>p->final;
		cout<<"�~��Ы�'1'�A�����Ы�'0'�G";
		cin>>m;
	}while(m);
	while(p!=NULL){
		cout<<"�s���G"<<p->no<<endl<<"�m�W�G"<<p->name<<endl<<"���ɡF"<<p->normal<<endl<<"�����G"<<p->mid<<endl<<"�����G"<<p->final<<endl<<endl;
		p=p->ptr; 
	}
}
