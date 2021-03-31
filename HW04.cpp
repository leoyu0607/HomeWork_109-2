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
		cout<<"請輸入編號：";
		cin>>p->no;
		cin.ignore();
		cout<<"請輸入姓名：";
		cin.getline(p->name,10);
		cout<<"請輸入平時成績：";
		cin>>p->normal;
		cout<<"請輸入期中成績：";
		cin>>p->mid;
		cout<<"請輸入期末成績：";
		cin>>p->final;
		cout<<"繼續請按'1'，結束請按'0'：";
		cin>>m;
	}while(m);
	while(p!=NULL){
		cout<<"編號："<<p->no<<endl<<"姓名："<<p->name<<endl<<"平時；"<<p->normal<<endl<<"期中："<<p->mid<<endl<<"期末："<<p->final<<endl<<endl;
		p=p->ptr; 
	}
}
