#include<string>
#include<iostream>
using namespace std;
class STNODE {
private:
	string name;
	int num, total, cs, math;
	STNODE* next;
public:
	int get_num() {
		return num;
	}
	int get_cs() {
		return cs;
	}
	int get_math() {
		return math;
	}
	int get_total() {
		return total;
	}
	string get_name() {
		return name;
	}
	STNODE* get_next() {
		return next;
	}
	void set_num(int number) {
		num = number;
	}
	void set_cs(float score) {
		cs = score;
	}
	void set_math(float score) {
		math = score;
	}
	void set_total(float score) {
		total = score;
	}
	void set_name(string name2) {
		name = name2;
	}
	void set_next(STNODE* n) {
		next = n;
	}
	void find(STNODE* node) {
		STNODE* curr = node;
		string find_name;
		system("cls");
		cin.get();
		cout << "請輸入想找的學生之姓名\n";
		getline(cin, find_name);
		while (1) {
			if (curr->get_name() == find_name) {
				system("cls");
				cout << "該學生存在\n";
				cout << "座號:" << curr->get_num() << "\n" << "姓名:" << curr->get_name() << "\n" << "計概成績:" << curr->get_cs() << "\n" << "數學成績:" << curr->get_math() << "\n" << "總成績:" << curr->get_total() << "\n\n";
				break;
			}
			if (curr->get_next() == NULL) {
				system("cls");
				cout << "該學生不存在\n";
				break;
			}
			curr = curr->get_next();
		}
	}
	void del(STNODE* node) {
		STNODE* prev = node;
		STNODE* curr = node;
		int del_num;
		system("cls");
		cout << "請輸入想刪除的資料的座號\n";
		cin >> del_num;
		while (1) {
			if (curr->get_num() == del_num) {
				prev->set_next(curr->get_next());
				delete curr;
				system("cls");
				cout << "該筆資料已成功刪除\n";
				break;
			}
			if (curr->get_next() == NULL) {
				system("cls");
				cout << "該筆資料不存在，無法刪除\n";
				break;
			}
			if (curr != node) {
				prev = prev->get_next();
			}
			curr = curr->get_next();
		}
	}
	void print(STNODE* node) {
		bool check = true;
		STNODE* now2 = new STNODE();
		if (node->get_next() != NULL) {
			now2 = node->get_next();
		}
		else {
			system("cls");
			cout << "head->||\n";
			check = false;
		}
		if (check) {
			system("cls");
			cout << "head->";
			do {
				cout << now2->get_num() << "->";
				now2 = now2->get_next();
			} while (now2);
			cout << "||";
		}
	}
	void add(STNODE* node) {
		STNODE* now = new STNODE;
		now->set_next(NULL);
		now->set_num(-1);
		STNODE* prev = node;
		STNODE* curr = node;
		bool check = true;
		bool check2 = true;
		int n;
		string s;
		cout << "請輸入座號\n";
		while (check) {
			cin >> n;
			now->set_num(n);
			if (n <= 0) {
				cout << "座號需大於零 請重新輸入\n";
				check = true;
				check2 = false;
			}
			while (check2) {
				if (curr->get_num() == now->get_num()) {
					cout << "座號重複 請重新輸入\n";
					check = true;
					break;
				}
				if (curr->get_next() == NULL) {
					check = false;
					break;
				}
				curr = curr->get_next();
			}
			check2 = true;
		}
		check = true;
		cin.get();
		cout << "請輸入姓名\n";
		getline(cin, s);
		now->set_name(s);
		cout << "請輸入計概成績\n";
		while (check) {
			cin >> n;
			if (n > 100 || n < 0) {
				cout << "成績需在0到100之間 請重新輸入\n";
				check = true;
			}
			else {
				check = false;
			}
		}
		check = true;
		now->set_cs(n);
		cout << "請輸入數學成績\n";
		while (check) {
			cin >> n;
			if (n > 100 || n < 0) {
				cout << "成績需在0到100之間 請重新輸入\n";
				check = true;
			}
			else {
				check = false;
			}
		}
		now->set_math(n);
		now->set_total((now->get_cs() + now->get_math()) / 2);
		curr = node;
		check = true;
		while (check) {
			if (curr->get_num() >= now->get_num()) {
				prev->set_next(now);
				prev->get_next()->set_next(curr);
				cout << "資料成功加入\n";
				break;
			}
			if (curr->get_next() == NULL) {
				curr->set_next(now);
				cout << "資料成功加入\n";
				break;
			}
			if (curr != node) {
				prev = prev->get_next();
			}
			curr = curr->get_next();
		}
	}
};
int menu() {
	int i;
	cout << "(1). 新增學生資料" << endl;
	cout << "(2). 刪除學生資料" << endl;
	cout << "(3). 查詢學生資料" << endl;
	cout << "(4). 列印串列資料" << endl;
	cout << "(0). 離開" << endl;
	cout << "請輸入選擇項目？\n";
	cin >> i;
	return i;
}
int main() {
	STNODE* head = new STNODE();
	int num;
	int choice;
	int check = true;
	head->set_next(NULL);
	head->set_num(-1);
	while (check) {
		choice = menu();
		system("cls");
		switch (choice) {
		case 0:
			check = false;
			break;
		case 1:
			head->add(head);
			break;
		case 2:
			head->del(head);
			break;
		case 3:
			head->find(head);
			break;
		case 4:
			head->print(head);
			break;
		default:
			cout << "請輸入合理的數字\n";
			break;
		}
		cout << "\n\n";
		system("pause");
		system("cls");
	}
	return 0;
}
