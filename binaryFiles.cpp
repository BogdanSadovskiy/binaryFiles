using namespace std;
# include <fstream>
#include <iostream>
#include <vector>
#include <Windows.h>
#include <stdio.h>
#include <string>

class Goods {
	char*  nameOfGood = new char[30] ;
	int numberOfGood;
	int price;
	char* nameOfStoreForSell = new char[30];
	bool edited;
public:
	Goods() {
		this->nameOfGood[0] = '\0';
		this->price = 0;
		this->numberOfGood = 0;
		this->nameOfStoreForSell[0] = '\0';
		this->edited = 0;
	}
	Goods(char* nameOFGood, int price, int numberOfGood, char* nameOfStoreForSell) {
		this->nameOfGood = nameOFGood;
		this->price = price;
		this->numberOfGood = numberOfGood;
		this->nameOfStoreForSell = nameOfStoreForSell;
		this->edited = false;
	}
	char* getNameOfGood() {
		return nameOfGood;
	}
	char* getNameOfStoreForSell() {
		return nameOfStoreForSell;
	}
	int getPrice() {
		return price;
	}
	int getNumberOfGood() {
		return numberOfGood;
	}
	void setEdited() {
		this->edited = true;
	}
};
void newGood(char*& nameOfGood, int& price, int& numberOfGood, char*& nameOFStore) {

	cout << "Input name of good\n"; cin >> nameOfGood;
	cout << "Input price\n"; cin >> price;
	cout << "Input number of good\n"; cin >> numberOfGood;
	cout << "Input name of store for sell\n"; cin >> nameOFStore;

}

void Menu(string& menu) {
	system("cls");
	cout << "Add good ----------- 1\n";
	cout << "Sort --------------- 2\n";
	cout << "Print goods -------- 3\n";
	cout << "Print edited goods - 4\n";
	cout << "Edit good ---------- 5\n";
	cout << "e - exit\n";
	cin >> menu;
}

 vector<Goods> readGoods() {
		vector<Goods>goods;
		goods.clear();
		ifstream tmp("Goods", std::ios::binary);
		Goods g;
		int i = 1;
		while (tmp.read(reinterpret_cast<char*>(&g), sizeof(Goods))){
			goods.push_back(g);
		}
	
		cout << "ReadGods " << goods.size() << endl;
		tmp.close();
		return goods;
	
}

int main()
{
	char* nameOfGood = new char[30];
	char* nameOFStore = new char[30];
	int price = 0;
	int numberOfGood = 0;

	if (remove("Goods") == 0) {};
	bool isFileExist = false;

	vector<Goods> goods;
	string menu;
	while (true) {
		Menu(menu);
		if (!isFileExist && menu != "1") {
			cerr << "You dont have any goods\n";
			Sleep(800);
		}
		if (menu == "1") {
			newGood(nameOfGood, price, numberOfGood, nameOFStore);
			Goods tmp(nameOfGood, price, numberOfGood, nameOFStore);
			ofstream str;
			str.open("Goods", ios::app | ios::binary);
			str.write((char*)&tmp, sizeof(Goods));
			str.close();
			isFileExist = true;
			cout << "Successfully added\n"; Sleep(800);
		}
		else if (menu == "2") {

		}
		else if (menu == "3") {
			goods = readGoods();
			cout << "Menu" << goods.size() << endl;
			for (Goods g : goods) {
				cout << "\nName: " << g.getNameOfGood() << endl;
				cout << "Price: " << g.getPrice() << endl;
				cout << "Number: " << g.getNumberOfGood() << endl;
				cout << "Store: " << g.getNameOfStoreForSell() << endl << endl;
			}
			string tapsomething; cin >> tapsomething;

		}

	}
	

}

