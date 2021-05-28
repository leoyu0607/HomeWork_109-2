#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class student{
protected:
    int num;
    string name;
};

class psnode:private student{
private:
    int ps;
    psnode* next;
};

class stnode:private student{
private:
    int cs,math,total;
    stnode* next;
public:
    int get_num(){
        return num;
    }
    int get_cs(){
        return cs;
    }
    int get_math(){
        return math;
    }
    int get_total(){
        return total;
    }
    string get_name(){
        return name;
    }
    stnode* get_next(){
        return next;
    }
    void set_num(int number){
        num = number;
    }
    void set_cs(float score){
        cs = score;
    }
    void set_math(float score){
        math = score;
    }
    void set_total(float score){
        total = score;
    }
    void set_name(string name2){
        name = name2;
    }
    void set_next(stnode* n){
        next = n;
    }
};

int main(){
    int check = 1;
    int choice;
    stnode* head = new stnode();
    head->set_next(NULL);
    head->set_num(-1);
    while(check){
        cout<<"1. 新增學生資料"<<endl;
        cout<<"2. 刪除學生資料"<<endl;
        cout<<"3. 查詢學生資料"<<endl;
        cout<<"4. 列印串列資料"<<endl;
        cout<<"0. 離開"<<endl;
        cin>>choice;
        system("cls");
        switch(choice){
            case 0:
                check = 0;
                break;
            case 1://新增資料
                {
                stnode* now = new stnode;
                now->set_next(NULL);
                now->set_num(-1);
                stnode* prev = head;
                stnode* curr = head;
                bool e = true,e2 = true;
                int n = 0;
                string s;
                cout<<"請輸入座號"<<endl;
                while(e){
                    cin>>n;
                    now->set_num(n);
                    if(n <= 0){
                        cout<<"座號需大於0，請重新輸入"<<endl;
                        e = true;
                        e2 = false;
                    }
                    while(e2){
                        if(curr->get_num() == now->get_num()){
                            cout<<"座號重複，請重新輸入"<<endl;
                            e = true;
                            break;
                        }
                        if(curr->get_next() == NULL){
                            e = false;
                            break;
                        }
                        curr = curr->get_next();
                    }
                    e2 = true;
                }
                e = true;
                cin.get();
                cout<<"請輸入姓名：";
                getline(cin,s);
                now->set_name(s);
                cout<<"請輸入計概成績："<<endl;
                while(e){
                    cin>>n;
                    if(n > 100 || n < 0){
                        cout<<"成績需在0到100之間，請重新輸入"<<endl;
                        e = true;
                    }
                    else{
                        e = false;
                    }
                }
                e = true;
                now->set_cs(n);
                cout<<"請輸入數學成績："<<endl;
                while(e){
                    cin>>n;
                    if(n > 100 || n < 0){
                        cout<<"成績需在0到100之間，請重新輸入"<<endl;
                        e = true;
                    }
                    else{
                        e = false;
                    }
                }
                e = true;
                now->set_math(n);
                now->set_total((now->get_cs() + now->get_math()) / 2);
                curr = head;
                while(e){
                    if(curr->get_num() >= now->get_num()){
                        prev->set_next(now);
                        prev->get_next()->set_next(curr);
                        cout<<"資料已加入"<<endl;
                        break;
                    }
                    if(curr->get_next() == NULL){
                        curr->set_next(now);
                        cout<<"資料已加入"<<endl;
                        break;
                    }
                    if(curr != head){
                        prev = prev->get_next();
                    }
                    curr = curr->get_next();
                }
                break;
                }
            case 2://delete
                {
                stnode* prev = head;
                stnode* curr = head;
                int del_num;
                system("cls");
                cout<<"請輸入想刪除資料的座號：";
                cin>>del_num;
                while(1){
                    if(curr->get_num() == del_num){
                        prev->set_next(curr->get_next());
                        delete curr;
                        system("cls");
                        cout<<"該筆資料已刪除"<<endl;
                        break;
                    }
                    if(curr->get_next() == NULL){
                        system("cls");
                        cout<<"該筆資料不存在，無法刪除"<<endl;
                        break;
                    }
                    if(curr != head){
                        prev = prev->get_next();
                    }
                    curr = curr->get_next();
                }
                break;
                }
            case 3://查詢資料
                {
                stnode* curr = head;
                string find_name;
                system("cls");
                cin.get();
                cout<<"請輸入想找的學生之姓名"<<endl;
                getline(cin,find_name);
                while(1){
                    if(curr->get_name() == find_name){
                        system("cls");
                        cout<<"該學生存在"<<endl;
                        cout<<"座號："<< curr->get_num() <<endl<<"姓名："<< curr->get_name() <<endl<<"計概成績："<< curr->get_cs() <<endl<<"數學成績："<< curr->get_math() <<endl<<"總成績："<< curr->get_total() <<endl<<endl;
                        break;
                    }
                    if(curr->get_next() == NULL){
                        system("cls");
                        cout<<"該學生不存在"<<endl;
                        break;
                    }
                    curr = curr->get_next();
                }
                break;
                }
            case 4://列印資料
                {
                bool e = true;
                stnode* now2 = new stnode();
                if(head->get_next() != NULL){
                    now2 = head->get_next();
                }
                else{
                    system("cls");
                    cout<<"串列內無資料"<<endl;
                    e = false;
                }
                if(e){
                    system("cls");
                    cout<<"|  座號  |"<<"|  姓名  |"<<"|  計概  |"<<"|  數學  |"<<"| 總成績 |"<<endl;
                    do{
                        cout<<"|"<<setw(5)<<now2->get_num()<<"   |";
                        cout<<"|"<<setw(7)<<now2->get_name()<<" |";
                        cout<<"|"<<setw(5)<<now2->get_cs()<<"   |";
                        cout<<"|"<<setw(5)<<now2->get_math()<<"   |";
                        cout<<"|"<<setw(5)<<now2->get_total()<<"   |"<<endl;
                        now2 = now2->get_next();
                    }while(now2);
                }
                break;
                }
            default:
                cout<<"Wrong Input!"<<endl<<"Input Again,Please!"<<endl;
                break;
        }
        cout<<endl<<endl;
        system("pause");
        system("cls");
    }
    return 0;
}
