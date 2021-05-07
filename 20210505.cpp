#include<iostream>
#include<string>
using namespace std;
class stnode{
    private:
		int no,cs,math,total;
		string name;
		stnode *ptr;
	public:
		void set_no(int n){
			no = n;
		}
		int get_no(){
			return no;
		}
		void set_name(string name2){
			name = name2;
		}
		string get_name(){
			return name;
		}
		void set_cs(float score){
			cs = score;
		}
		int get_cs(){
			return cs;
		}
		void set_math(float score){
			math = score;
		}
		int get_math(){
			return math;
		}
		void set_total(float score){
			total = score;
		}
		int get_total(){
			return total;
		}
		void set_ptr(stnode *p){
			ptr = p;
		}
		stnode* get_ptr(){
			return ptr;
		}
		void find_name(stnode* node){
            stnode* curr=node;
            string findName;
            system("cls");
            cin.get();
            cout<<"�п�J�Q�䪺�ǥͤ��m�W";
            getline(cin,findName);
            while(1){
                if(curr->get_name()==findName){
                    system("cls");
                    cout<<"�Ӿǥͦs�b"<<endl;
                    cout<<"�y���G"<<curr->get_no()<<endl<<"�m�W�G"<<curr->get_name()<<endl<<"�p�����Z�G"<<curr->get_cs()<<endl<<"�ƾǦ��Z�G"<<curr->get_math()<<endl<<"�`���Z�G"<<curr->get_total();
                    break;
                }
                if(curr->get_ptr()==NULL){
                    system("cls");
                    cout<<"���ǥͤ��s�b"<<endl;
                    break;
                }
                curr=curr->get_ptr;
            }
		}
		void del(stnode* node){
            stnode* prev = node;
            stnode* curr = node;
            int del_num = 0;
            system("cls");
            cout<<"�п�J���R�����ǥͮy���G";
            cin>>del_num;
            while(1){
                if(curr->get_no == del_num){
                    prev->set_ptr(curr->get_ptr());
                    delete curr;
                    system("cls");
                    cout<<"�ӵ���Ƥw���\�R��"<<endl;
                    break;
                }
                if(curr->get_ptr == NULL){
                    system("cls");
                    cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
                    break;
                }
                if(curr != node){
                    prev = prev->get_ptr();
                }
            }
		}
		void print(stnode* node){
            bool check = true;
            stnode* curr = new stnode();
            if(node->get_ptr != NULL){
                curr = node->get_ptr();
            }
            else{
                system("cls");
                cout<<"head->||"<<endl;
                check = false;
            }
            if(check){
                system("cls");
                cout<<"head->";
                do{
                    cout<<curr->get_no()<<"->";
                    curr = curr->get_ptr();
                }while(curr);
                cout<<"||";
            }
		}
		void add(stnode* node){
            stnode* now = new stnode;
            now->set_ptr(NULL);
            now->set_no(-1);
            stnode* prev = node;
            stnode* curr = node;
            bool check = true;
            bool check2 = true;
            int n = 0;
            string s;
            cout<<"�п�J�y���G";
            while(check){
                cin>>n;
                now->set_no(n);
                if(n <= 0){
                    cout<<"�y���ݤj��0�A�Э��s��J";
                    check = true;
                    check2 = false;
                }
                while(check2){
                    if(curr->get_no() == noe->get_no()){
                        cout<<"�y�����o���ơA�Э��s��J�G"
                    }
                    curr = curr->get_ptr();
                }
            }
		}
};
int menu(){
    int i=0;
    cout<<"(1). �s�W�ǥ͸��"<<endl;
	cout<<"(2). �R���ǥ͸��"<<endl;
	cout<<"(3). �d�߾ǥ͸��"<<endl;
	cout<<"(4). �C�L��C���"<<endl;
	cout<<"(0). ���}"<<endl;
	cout<<"�п�J��ܶ��ءH";
	cin>>i;
	return i;
}
int main(){
	stnode *head=new stnode;
	int num;
	int choice;
	bool check=true;
	while(check){
        choice=menu();
        system("cls");
		switch(choice){
        case 1:break;
        case 2:break;
        case 3:break;
        case 4:break;
        case 0:check=false;break;
        default:
            cout<<"Wrong Input"<<endl<<endl;
            break;
		}
		system("pause");
		system("cls");
	}
	return 0;
}
