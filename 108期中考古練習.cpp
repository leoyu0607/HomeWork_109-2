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
		cout<<"(1).�s�W�ǥ͸��"<<endl;
		cout<<"(2).�R���ǥ͸��"<<endl;
		cout<<"(3).�C�L��C���"<<endl;
		cout<<"(4).���}"<<endl;
		cout<<"�п�J��ܶ��ءH";
		cin>>s;
		switch(s){
			case 1:
				do{
					now=new stnode;
					int n=0;
					char na[10];
					current=head->get_ptr();
					cout<<"�п�J�y���G";
					cin>>n;
					do{
                        while(current!=NULL&&current->get_no()!=n){
                            current=current->get_ptr();
                        }
                        if(current==NULL){
                            i=0;
                        }
                        else if(current->get_no()==n){
                            cout<<"�y�����o���ơA�Э��s��J�G";
                            cin>>n;
                            i=1;
                        }
					}while(i);
					now->set_no(n);
					cin.ignore();
					cout<<"�п�J�m�W�G";
					cin.getline(na,10);
					now->set_name(na);
					cout<<"�п�J�p�����Z�G";
					cin>>n;
					now->set_cs(n);
					cout<<"�п�J�ƾǦ��Z�G";
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
					cout<<"�~��Ы�'1'�A�����Ы�'0'�G";
					cin>>m;
				}while(m);
				break;
			case 2:
			    cout<<"�п�J���R�����y���G";
			    cin>>del_number;
			    current=head->get_ptr();
			    previous=head;
			    while(current!=NULL&&current->get_no()!=del_number){
			        current=current->get_ptr();
			        previous=previous->get_ptr();
			    }
			    if(current==NULL){
			        cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
			    }
			    else if(current->get_no()==del_number){
			        if(current==head->get_ptr()){
			            head=head->get_ptr();
			            current=NULL;
			            cout<<"�ӵ���Ƥw���\�R��"<<endl;
			        }
			        else{
			            previous->set_ptr(current->get_ptr());
			            current=NULL;
			            cout<<"�ӵ���Ƥw���\�R��"<<endl;
			        }
			    }
				break;
			case 3:
				now=head->get_ptr();
				if(now==NULL){
			        cout<<"�|�����ǥ͸��"<<endl;
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
