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
            cout<<"請輸入想找的學生之姓名";
            getline(cin,findName);
            while(1){
                if(curr->get_name()==findName){
                    system("cls");
                    cout<<"該學生存在"<<endl;
                    cout<<"座號："<<curr->get_no()<<endl<<"姓名："<<curr->get_name()<<endl<<"計概成績："<<curr->get_cs()<<endl<<"數學成績："<<curr->get_math()<<endl<<"總成績："<<curr->get_total();
                    break;
                }
                if(curr->get_ptr()==NULL){
                    system("cls");
                    cout<<"此學生不存在"<<endl;
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
            cout<<"請輸入欲刪除之學生座號：";
            cin>>del_num;
            while(1){
                if(curr->get_no == del_num){
                    prev->set_ptr(curr->get_ptr());
                    delete curr;
                    system("cls");
                    cout<<"該筆資料已成功刪除"<<endl;
                    break;
                }
                if(curr->get_ptr == NULL){
                    system("cls");
                    cout<<"該筆資料不存在，無法刪除"<<endl;
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
            cout<<"請輸入座號：";
            while(check){
                cin>>n;
                now->set_no(n);
                if(n <= 0){
                    cout<<"座號需大於0，請重新輸入";
                    check = true;
                    check2 = false;
                }
                while(check2){
                    if(curr->get_no() == noe->get_no()){
                        cout<<"座號不得重複，請重新輸入："
                    }
                    curr = curr->get_ptr();
                }
            }
		}
};
int menu(){
    int i=0;
    cout<<"(1). 新增學生資料"<<endl;
	cout<<"(2). 刪除學生資料"<<endl;
	cout<<"(3). 查詢學生資料"<<endl;
	cout<<"(4). 列印串列資料"<<endl;
	cout<<"(0). 離開"<<endl;
	cout<<"請輸入選擇項目？";
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
