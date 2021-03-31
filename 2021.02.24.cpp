#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char name[6][10];
	cout<<"請輸入五個英文名字："<<endl;
	for(int i=0;i<5;i++){
		cin>>name[i];
	}
	cout<<"五個名字分別為："<<endl;
	for(int i=0;i<5;i++){
		cout<<name[i]<<" ";
	} 
	cout<<endl<<"請輸入欲查詢之名字：";
	cin>>name[5];
	for(int i=0;i<5;i++){
		if(strcmp(name[i],name[5])==0){
			cout<<"same"<<endl;
			break;
		}
		else if(i==4){
			cout<<"no same";
		}
	}
} 
