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
		void set_total(int n){
			total = n;
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
	private:
		int no = 0;
		char name[20];
		int cs = 0;
		int math = 0;
		int total = 0;
		stnode *ptr = NULL;
};
int main(){
	int s=1;
	while(s){
		cout<<"(1). 新增學生資料"<<endl;
		cout<<"(2). 刪除學生資料"<<endl;
		cout<<"(3). 查詢學生資料"<<endl;
		cout<<"(4). 列印串列資料"<<endl;
		cout<<"(0). 離開"<<endl;
		cout<<"請輸入選擇項目？";
		cin>>s;
		switch(s){
			case 1:
				cout<<"新增學生資料執行中"<<endl<<endl;
				break;
			case 2:
				cout<<"刪除學生資料執行中"<<endl<<endl;
				break;
			case 3:
				cout<<"查詢學生資料執行中"<<endl<<endl;
				break;
			case 4:
				cout<<"列印串列資料執行中"<<endl<<endl;
				break;
			case 0:break; 
			default:
				cout<<"Wrong Input"<<endl<<endl;
				s=1;
		}
		
	}
}
