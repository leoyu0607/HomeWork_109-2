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
		cout<<"�~��Ы�'1'�A�����Ы�'0'�G";
		cin>>m;
	}while(m);
}
void Delete(){
    int del_number=0;
    cout<<"�п�J���R�����y���G";
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
            cout<<"�������ǥ͸�ơI�I"<<endl;
        }
    }
}
void Search(){
    int sear_num=0;
    cout<<"�п�J���d�ߤ��ǥͮy���G";
    cin>>sear_num;
    st *current=head->next;
    while(current!=NULL&&current->no!=sear_num){
        current=current->next;
    }
    if(current==NULL){
        cout<<"�������ǥ͸�ơI"<<endl;
    }
    else if(current->no==sear_num){
        cout<<"�����ǥ͸��"<<endl;
        int ans=0;
        cout<<"�аݬO�_�C�L(1.�O/2.�_)";
        cin>>ans;
        if(ans==1){
            cout<<"�s���G"<<current->no<<endl<<"�m�W�G"<<current->name<<endl<<"���ɡF"<<current->normal<<endl<<"�����G"<<current->mid<<endl<<"�����G"<<current->fin<<endl<<endl;
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
		cout<<"�s���G"<<now->no<<endl<<"�m�W�G"<<now->name<<endl<<"���ɡF"<<now->normal<<endl<<"�����G"<<now->mid<<endl<<"�����G"<<now->fin<<endl<<endl;
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
