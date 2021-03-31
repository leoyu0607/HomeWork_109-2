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
		cout<<"繼續請按'1'，結束請按'0'：";
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
		cout<<"編號："<<now->no<<endl<<"姓名："<<now->name<<endl<<"平時；"<<now->normal<<endl<<"期中："<<now->mid<<endl<<"期末："<<now->final<<endl<<endl;
		now=now->next; 
	}
}
void menu(int n){
	if(n == 1){
		return Push();
	}
	if(n == 2){
		cout<<"功能建設中，敬請期待!!"<<endl;
	}
	if(n == 3){
		cout<<"功能建設中，敬請期待!!"<<endl;
	}
	if(n == 4){
		return PrintList();
	}
}
int main(){
	int s = 1;
	while(s){
		cout<<"請選擇："<<endl;
		cout<<"1.新增學生資料"<<endl;
		cout<<"2.刪除資料"<<endl;
		cout<<"3.查詢資料"<<endl;
		cout<<"4.列印資料："; 
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
