#include<iostream>
#include<cstring>
#include<iomanip> 
using namespace std;
int main(){
	char name[5][10];
	int data[5][4];
	for(int i=0;i<5;i++){
		cout<<"�п�J�s���G";
		cin>>data[i][0];
		cin.ignore();
		cout<<"�п�J�m�W�G";
		cin.getline(name[i],10);
		cout<<"�п�J���ɦ��Z�G";
		cin>>data[i][1];
		cout<<"�п�J�������Z�G";
		cin>>data[i][2];
		cout<<"�п�J�������Z�G";
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
	cout<<"�U  �W��  �U"<<" Number �U"<<"  Name  �U"<<"  ����  �U"<<"  ����  �U"<<"  ����  �U"<<endl; 
	for(int i=0;i<5;i++){
		cout<<"�U  "<<"��"<<i+1<<"�W �U"<<setw(8)<<data[i][0]<<"�U"<<setw(8)<<name[i]<<"�U"
		<<setw(8)<<data[i][1]<<"�U"<<setw(8)<<data[i][2]<<"�U"<<setw(8)<<data[i][3]<<"�U"<<endl;
	}
}
