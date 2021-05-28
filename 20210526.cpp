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
        cout<<"1. �s�W�ǥ͸��"<<endl;
        cout<<"2. �R���ǥ͸��"<<endl;
        cout<<"3. �d�߾ǥ͸��"<<endl;
        cout<<"4. �C�L��C���"<<endl;
        cout<<"0. ���}"<<endl;
        cin>>choice;
        system("cls");
        switch(choice){
            case 0:
                check = 0;
                break;
            case 1://�s�W���
                {
                stnode* now = new stnode;
                now->set_next(NULL);
                now->set_num(-1);
                stnode* prev = head;
                stnode* curr = head;
                bool e = true,e2 = true;
                int n = 0;
                string s;
                cout<<"�п�J�y��"<<endl;
                while(e){
                    cin>>n;
                    now->set_num(n);
                    if(n <= 0){
                        cout<<"�y���ݤj��0�A�Э��s��J"<<endl;
                        e = true;
                        e2 = false;
                    }
                    while(e2){
                        if(curr->get_num() == now->get_num()){
                            cout<<"�y�����ơA�Э��s��J"<<endl;
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
                cout<<"�п�J�m�W�G";
                getline(cin,s);
                now->set_name(s);
                cout<<"�п�J�p�����Z�G"<<endl;
                while(e){
                    cin>>n;
                    if(n > 100 || n < 0){
                        cout<<"���Z�ݦb0��100�����A�Э��s��J"<<endl;
                        e = true;
                    }
                    else{
                        e = false;
                    }
                }
                e = true;
                now->set_cs(n);
                cout<<"�п�J�ƾǦ��Z�G"<<endl;
                while(e){
                    cin>>n;
                    if(n > 100 || n < 0){
                        cout<<"���Z�ݦb0��100�����A�Э��s��J"<<endl;
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
                        cout<<"��Ƥw�[�J"<<endl;
                        break;
                    }
                    if(curr->get_next() == NULL){
                        curr->set_next(now);
                        cout<<"��Ƥw�[�J"<<endl;
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
                cout<<"�п�J�Q�R����ƪ��y���G";
                cin>>del_num;
                while(1){
                    if(curr->get_num() == del_num){
                        prev->set_next(curr->get_next());
                        delete curr;
                        system("cls");
                        cout<<"�ӵ���Ƥw�R��"<<endl;
                        break;
                    }
                    if(curr->get_next() == NULL){
                        system("cls");
                        cout<<"�ӵ���Ƥ��s�b�A�L�k�R��"<<endl;
                        break;
                    }
                    if(curr != head){
                        prev = prev->get_next();
                    }
                    curr = curr->get_next();
                }
                break;
                }
            case 3://�d�߸��
                {
                stnode* curr = head;
                string find_name;
                system("cls");
                cin.get();
                cout<<"�п�J�Q�䪺�ǥͤ��m�W"<<endl;
                getline(cin,find_name);
                while(1){
                    if(curr->get_name() == find_name){
                        system("cls");
                        cout<<"�Ӿǥͦs�b"<<endl;
                        cout<<"�y���G"<< curr->get_num() <<endl<<"�m�W�G"<< curr->get_name() <<endl<<"�p�����Z�G"<< curr->get_cs() <<endl<<"�ƾǦ��Z�G"<< curr->get_math() <<endl<<"�`���Z�G"<< curr->get_total() <<endl<<endl;
                        break;
                    }
                    if(curr->get_next() == NULL){
                        system("cls");
                        cout<<"�Ӿǥͤ��s�b"<<endl;
                        break;
                    }
                    curr = curr->get_next();
                }
                break;
                }
            case 4://�C�L���
                {
                bool e = true;
                stnode* now2 = new stnode();
                if(head->get_next() != NULL){
                    now2 = head->get_next();
                }
                else{
                    system("cls");
                    cout<<"��C���L���"<<endl;
                    e = false;
                }
                if(e){
                    system("cls");
                    cout<<"|  �y��  |"<<"|  �m�W  |"<<"|  �p��  |"<<"|  �ƾ�  |"<<"| �`���Z |"<<endl;
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
