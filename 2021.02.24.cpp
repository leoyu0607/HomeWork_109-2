#include<iostream>
#include<cstring>
using namespace std;
int main(){
	char name[6][10];
	cout<<"�п�J���ӭ^��W�r�G"<<endl;
	for(int i=0;i<5;i++){
		cin>>name[i];
	}
	cout<<"���ӦW�r���O���G"<<endl;
	for(int i=0;i<5;i++){
		cout<<name[i]<<" ";
	} 
	cout<<endl<<"�п�J���d�ߤ��W�r�G";
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
