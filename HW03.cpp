#include<iostream>
#include<cstring>
#include<iomanip> 
using namespace std;

class st{
	public:
		int no;
		char name[10];
		int normal;
		int mid;
		int final;
};
int main(){
	st data[3];
	for(int i=0;i<3;i++){
		cout<<"請輸入編號：";
		cin>>data[i].no;
		cin.ignore();
		cout<<"請輸入姓名：";
		cin.getline(data[i].name,10);
		cout<<"請輸入平時成績：";
		cin>>data[i].normal;
		cout<<"請輸入期中成績：";
		cin>>data[i].mid;
		cout<<"請輸入期末成績：";
		cin>>data[i].final;
		cout<<endl;
	}
	system("pause");
	for(int i=0;i<3;i++){
		for(int j=i+1;j<3;j++){
			if(data[i].final<data[j].final){
				int t=0;
				swap(data[i],data[j]);
			}
		}
	}
	cout<<"｜  名次  ｜"<<" Number ｜"<<"  Name  ｜"<<"  平時  ｜"<<"  期中  ｜"<<"  期末  ｜"<<endl; 
	for(int i=0;i<3;i++){
		cout<<"｜  "<<"第"<<i+1<<"名 ｜"<<setw(8)<<data[i].no<<"｜"<<setw(8)<<data[i].name<<"｜"
		<<setw(8)<<data[i].normal<<"｜"<<setw(8)<<data[i].mid<<"｜"<<setw(8)<<data[i].final<<"｜"<<endl;
	}
}
