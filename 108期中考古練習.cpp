#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;

class stnode{
	public:
		void set_no(int n){
			no = n;
		}
		int get_no(){
			return no;
		}
		void set_name(char na[]){
			for(int i=0;i<20;i++){
				name[i] = na[i];
			}
		}
		char* get_name(){
			return name;
		}
		void set_cs(int n){
			cs = n;
		}
		int get_cs(){
			return cs;
		}
		void set_math(int n){
			math = n;
		}
		int get_math(){
			return math;
		}
		void set_ptr(stnode *p){
			ptr = p;
		}
		stnode* get_ptr(){
			return ptr;
		}
	private:
		int no = 0;
		char name[20];
		int cs = 0;
		int math = 0;
		stnode *ptr = NULL;
};
int main(){
	stnode *head = new stnode;
	stnode *ptr;
	stnode *y = head;
	stnode *x = head;
	stnode *now;
	stnode *current=NULL;
	stnode *previous=NULL;
	int s = 1;
	int m=1;
	int i=1;
	int del_number=0;
	int sear_num=0;
	while(s){
		cout<<"(1).新增學生資料"<<endl;
		cout<<"(2).刪除學生資料"<<endl;
		cout<<"(3).列印串列資料"<<endl;
		cout<<"(4).離開"<<endl;
		cout<<"請輸入選擇項目？";
		cin>>s;
		switch(s){
			case 1:
				do{
					now=new stnode;
					int n=0;
					char na[10];
					current=head->get_ptr();
					cout<<"請輸入座號：";
					cin>>n;
					do{
                        			while(current!=NULL&&current->get_no()!=n){
                            				current=current->get_ptr();
                        			}
                        			if(current==NULL){
                           				i=0;
                        			}
                        			else if(current->get_no()==n){
                            				cout<<"座號不得重複，請重新輸入：";
                            				cin>>n;
                            				i=1;
                        			}
					}while(i);
					now->set_no(n);
					cin.ignore();
					cout<<"請輸入姓名：";
					cin.getline(na,10);
					now->set_name(na);
					cout<<"請輸入計概成績：";
					cin>>n;
					now->set_cs(n);
					cout<<"請輸入數學成績：";
					cin>>n;
					now->set_math(n);
					while(now->get_no()!=0){
						if(now->get_no()<=x->get_no()){
							y->set_ptr(now);
							y->get_ptr()->set_ptr(x);
							break;
						}
						if(x->get_ptr()==NULL){
							x->set_ptr(now);
							break;
						}
						if(x!=head){
							y=y->get_ptr();
						}
						x=x->get_ptr();
					}
					cout<<"繼續請按'1'，結束請按'0'：";
					cin>>m;
				}while(m);
				break;
			case 2:
			    cout<<"請輸入欲刪除之座號：";
			    cin>>del_number;
			    current=head->get_ptr();
			    previous=head;
			    while(current!=NULL&&current->get_no()!=del_number){
			        current=current->get_ptr();
			        previous=previous->get_ptr();
			    }
			    if(current==NULL){
			        cout<<"該筆資料不存在，無法刪除"<<endl;
			    }
			    else if(current->get_no()==del_number){
			        if(current==head->get_ptr()){
			            head=head->get_ptr();
			            current=NULL;
			            cout<<"該筆資料已成功刪除"<<endl;
			        }
			        else{
			            previous->set_ptr(current->get_ptr());
			            current=NULL;
			            cout<<"該筆資料已成功刪除"<<endl;
			        }
			    }
				break;
			case 3:
				now=head->get_ptr();
				if(now==NULL){
			        cout<<"尚未有學生資料"<<endl;
				}
				if(now!=NULL){
                    cout<<"head->";
				}
				while(now!=NULL){
					cout<<now->get_no()<<"->";
					now=now->get_ptr();
				}
				cout<<"||"<<endl;
				break;
			case 4:s=0;break;
			default:
				cout<<"Wrong Input"<<endl;
		}
	}
	cout<<"Thanks For Using!Bye~~"<<endl;
	return 0;
}
