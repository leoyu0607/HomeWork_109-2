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
st *head = new st;
st *ptr;
st *y = head;
st *x = head;
st *now;
void Push(){
	int m=1;
	do{
		now=new st;
		y=head;
		x=head;
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
		while(x->no!=NULL){
			if(now->no<=x->no){
				y->next=now;
				y->next->next=x;
				break;
			}
			if(x->next==NULL){
				x->next=now;
				break;
			}
			if(x!=head){
				y=y->next;
			}
			x=x->next;
		}
		cout<<"�~��Ы�'1'�A�����Ы�'0'�G";
		cin>>m;
	}while(m);
}
void Delete(){
}
void Search(){
}
void PrintList(){
	now=head->next;
	while(now!=NULL){
		cout<<"�s���G"<<now->no<<endl<<"�m�W�G"<<now->name<<endl<<"���ɡF"<<now->normal<<endl<<"�����G"<<now->mid<<endl<<"�����G"<<now->final<<endl<<endl;
		now=now->next; 
	}
}
void menu(int n){
	if(n == 1){
		return Push();
	}
	if(n == 2){
		cout<<"�\��س]���A�q�д���!!"<<endl;
	}
	if(n == 3){
		cout<<"�\��س]���A�q�д���!!"<<endl;
	}
	if(n == 4){
		return PrintList();
	}
}
int main(){
	int s = 1;
	while(s){
		cout<<"�п�ܡG"<<endl;
		cout<<"1.�s�W�ǥ͸��"<<endl;
		cout<<"2.�R�����"<<endl;
		cout<<"3.�d�߸��"<<endl;
		cout<<"4.�C�L��ơG"; 
		cin>>s;
		switch(s){
			case 1:menu(1);break;
			case 2:menu(2);break;
			case 3:menu(3);break;
			case 4:menu(4);break;
			case 0:break;
			default:
				cout<<"Wrong Input"<<endl;
		}
	}
	cout<<"Thanks For Using!Bye~~"<<endl;
	return 0;
}
