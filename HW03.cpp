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
		cout<<"�п�J�s���G";
		cin>>data[i].no;
		cin.ignore();
		cout<<"�п�J�m�W�G";
		cin.getline(data[i].name,10);
		cout<<"�п�J���ɦ��Z�G";
		cin>>data[i].normal;
		cout<<"�п�J�������Z�G";
		cin>>data[i].mid;
		cout<<"�п�J�������Z�G";
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
	cout<<"�U  �W��  �U"<<" Number �U"<<"  Name  �U"<<"  ����  �U"<<"  ����  �U"<<"  ����  �U"<<endl; 
	for(int i=0;i<3;i++){
		cout<<"�U  "<<"��"<<i+1<<"�W �U"<<setw(8)<<data[i].no<<"�U"<<setw(8)<<data[i].name<<"�U"
		<<setw(8)<<data[i].normal<<"�U"<<setw(8)<<data[i].mid<<"�U"<<setw(8)<<data[i].final<<"�U"<<endl;
	}
}
