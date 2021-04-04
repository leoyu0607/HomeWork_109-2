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
		int fin;
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
		cin>>now->fin;
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
    int del_number=0;
    cout<<"請輸入欲刪除之座號：";
    cin>>del_number;
    st *current=head->next;
    st *previous=head;
    while(current!=NULL){
        if(current!=head){
            previous=previous->next;
        }
        current=current->next;
        else if(current->no==del_number){
            if(head->next->no==del_number){
                head=head->next;
                current=NULL;
                break;
            }
            else{
                previous->next=current->next;
                current=NULL;
                break;
            }
        }
        else if(current->next==NULL){
            cout<<"未有此學生資料！！"<<endl;
        }
    }
}
void Search(){
    int sear_num=0;
    cout<<"請輸入欲查詢之學生座號：";
    cin>>sear_num;
    st *current=head->next;
    while(current!=NULL&&current->no!=sear_num){
        current=current->next;
    }
    if(current==NULL){
        cout<<"未有此學生資料！"<<endl;
    }
    else if(current->no==sear_num){
        cout<<"有此學生資料"<<endl;
        int ans=0;
        cout<<"請問是否列印(1.是/2.否)";
        cin>>ans;
        if(ans==1){
            cout<<"編號："<<current->no<<endl<<"姓名："<<current->name<<endl<<"平時；"<<current->normal<<endl<<"期中："<<current->mid<<endl<<"期末："<<current->fin<<endl<<endl;
            break;
        }
        else if(ans==2){
            break;
        }
    }
}
void PrintList(){
	now=head->next;
	while(now!=NULL){
		cout<<"編號："<<now->no<<endl<<"姓名："<<now->name<<endl<<"平時；"<<now->normal<<endl<<"期中："<<now->mid<<endl<<"期末："<<now->fin<<endl<<endl;
		now=now->next;
	}
}
void menu(int n){
	if(n == 1){
		return Push();
	}
	if(n == 2){
		return Delete();
	}
	if(n == 3){
		return Search();
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
