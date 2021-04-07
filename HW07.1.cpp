#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class st{
	public:
		void set_no(int n){
			no = n;
		}
		int get_no(){
			return no;
		}
		void set_name(char na[]){
			for(int i=0;i<10;i++){
				name[i] = na[i];
			}
		}
		char* get_name(){
			return name;
		}
		void set_normal(int n){
			normal = n;
		}
		int get_normal(){
			return normal;
		}
		void set_mid(int n){
			mid = n;
		}
		int get_mid(){
			return mid;
		}
		void set_fin(int n){
			fin = n;
		}
		int get_fin(){
			return fin;
		}
		void set_next(st *p){
			next = p; 
		}
		st* get_next(){
			return next;
		}
	private:
		int no = -1;
		char name[10];
		int normal = 0;
		int mid = 0;
		int fin = 0;
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
		int n=0;
		char na[10];
		cout<<"請輸入編號：";
		cin>>n;
		now->set_no(n);
		cin.ignore();
		cout<<"請輸入姓名：";
		cin.getline(na,10);
		now->set_name(na);
		cout<<"請輸入平時成績：";
		cin>>n;
		now->set_normal(n);
		cout<<"請輸入期中成績：";
		cin>>n;
		now->set_mid(n);
		cout<<"請輸入期末成績：";
		cin>>n;
		now->set_fin(n);
		while(x->get_no()!=0){
			if(now->get_no()<=x->get_no()){
				y->set_next(now);
				y->get_next()->set_next(x);
				break;
			}
			if(x->get_next()==NULL){
				x->set_next(now);
				break;
			}
			if(x!=head){
				y=y->get_next();
			}
			x=x->get_next();
		}
		cout<<"繼續請按'1'，結束請按'0'：";
		cin>>m;
	}while(m);
}
void Delete(){
    int del_number=0;
    cout<<"請輸入欲刪除之座號：";
    cin>>del_number;
    st *current=head->get_next();
    st *previous=head;
    while(current!=NULL){
        if(current!=head){
            previous=previous->get_next();
        }
        current=current->get_next();
        if(current->get_no()==del_number){
            if(head->get_next()->get_no()==del_number){
                head=head->get_next();
                current=NULL;
                cout<<"已刪除"<<endl; 
                break;
            }
            else{
                previous->set_next(current->get_next());
                current=NULL;
                cout<<"已刪除"<<endl;
                break;
            }
        }
        else if(current->get_next()==NULL){
            cout<<"未有此學生資料！！"<<endl;
        }
    }
}
void Search(){
    int sear_num=0;
    cout<<"請輸入欲查詢之學生座號：";
    cin>>sear_num;
    st *current;
	current=head->get_next();
    while(current!=NULL&&current->get_no()!=sear_num){
        current=current->get_next();
    }
    if(current==NULL){
        cout<<"未有此學生資料！"<<endl;
    }
    else if(current->get_no()==sear_num){
        cout<<"有此學生資料"<<endl;
        int ans=0;
        cout<<"請問是否列印(1.是/2.否)";
        cin>>ans;
        if(ans==1){
            cout<<"編號："<<current->get_no()<<endl<<"姓名："<<current->get_name()<<endl<<"平時；"<<current->get_normal()<<endl<<"期中："<<current->get_mid()<<endl<<"期末："<<current->get_fin()<<endl<<endl;
        }
    }
}
void PrintList(){
	now=head->get_next();
	while(now!=NULL){
		cout<<"編號："<<now->get_no()<<endl<<"姓名："<<now->get_name()<<endl<<"平時；"<<now->get_normal()<<endl<<"期中："<<now->get_mid()<<endl<<"期末："<<now->get_fin()<<endl<<endl;
		now=now->get_next();
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
