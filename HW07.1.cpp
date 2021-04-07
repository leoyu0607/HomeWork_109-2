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
		cout<<"�п�J�s���G";
		cin>>n;
		now->set_no(n);
		cin.ignore();
		cout<<"�п�J�m�W�G";
		cin.getline(na,10);
		now->set_name(na);
		cout<<"�п�J���ɦ��Z�G";
		cin>>n;
		now->set_normal(n);
		cout<<"�п�J�������Z�G";
		cin>>n;
		now->set_mid(n);
		cout<<"�п�J�������Z�G";
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
		cout<<"�~��Ы�'1'�A�����Ы�'0'�G";
		cin>>m;
	}while(m);
}
void Delete(){
    int del_number=0;
    cout<<"�п�J���R�����y���G";
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
                cout<<"�w�R��"<<endl; 
                break;
            }
            else{
                previous->set_next(current->get_next());
                current=NULL;
                cout<<"�w�R��"<<endl;
                break;
            }
        }
        else if(current->get_next()==NULL){
            cout<<"�������ǥ͸�ơI�I"<<endl;
        }
    }
}
void Search(){
    int sear_num=0;
    cout<<"�п�J���d�ߤ��ǥͮy���G";
    cin>>sear_num;
    st *current;
	current=head->get_next();
    while(current!=NULL&&current->get_no()!=sear_num){
        current=current->get_next();
    }
    if(current==NULL){
        cout<<"�������ǥ͸�ơI"<<endl;
    }
    else if(current->get_no()==sear_num){
        cout<<"�����ǥ͸��"<<endl;
        int ans=0;
        cout<<"�аݬO�_�C�L(1.�O/2.�_)";
        cin>>ans;
        if(ans==1){
            cout<<"�s���G"<<current->get_no()<<endl<<"�m�W�G"<<current->get_name()<<endl<<"���ɡF"<<current->get_normal()<<endl<<"�����G"<<current->get_mid()<<endl<<"�����G"<<current->get_fin()<<endl<<endl;
        }
    }
}
void PrintList(){
	now=head->get_next();
	while(now!=NULL){
		cout<<"�s���G"<<now->get_no()<<endl<<"�m�W�G"<<now->get_name()<<endl<<"���ɡF"<<now->get_normal()<<endl<<"�����G"<<now->get_mid()<<endl<<"�����G"<<now->get_fin()<<endl<<endl;
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
