#include<iostream>
#include<cstring>
#include<iomanip> 
using namespace std;
int main(){
	char name[5][10];
	int data[5][4];
	for(int i=0;i<5;i++){
		cout<<"請輸入編號：";
		cin>>data[i][0];
		cin.ignore();
		cout<<"請輸入姓名：";
		cin.getline(name[i],10);
		cout<<"請輸入平時成績：";
		cin>>data[i][1];
		cout<<"請輸入期中成績：";
		cin>>data[i][2];
		cout<<"請輸入期末成績：";
		cin>>data[i][3];
		cout<<endl;
	}
	system("pause");
	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			if(data[i][3]<data[j][3]){
				int t=0;
				t=data[i][3];data[i][3]=data[j][3];data[j][3]=t;
				t=data[i][2];data[i][2]=data[j][2];data[j][2]=t;
				t=data[i][1];data[i][1]=data[j][1];data[j][1]=t;
				t=data[i][0];data[i][0]=data[j][0];data[j][0]=t;
				for(int x=0;x<10;x++){
					char t;
					t=name[i][x];
					name[i][x]=name[j][x];
					name[j][x]=t;
				}
			}
		}
	}
	cout<<"｜  名次  ｜"<<" Number ｜"<<"  Name  ｜"<<"  平時  ｜"<<"  期中  ｜"<<"  期末  ｜"<<endl; 
	for(int i=0;i<5;i++){
		cout<<"｜  "<<"第"<<i+1<<"名 ｜"<<setw(8)<<data[i][0]<<"｜"<<setw(8)<<name[i]<<"｜"
		<<setw(8)<<data[i][1]<<"｜"<<setw(8)<<data[i][2]<<"｜"<<setw(8)<<data[i][3]<<"｜"<<endl;
	}
}
