#include "pch.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <windows.h>

using namespace std;

struct item //vag
{
	string name;
	int stell;
};

typedef list<item> item_list;
auto lst_item = list <item>();

struct stellah//train
{
	string name;
	item_list* stell;// Список вагонов
};
auto lst_stellah = list <stellah>();

void readFile()
{
	ifstream out("items", ios::binary | ios::app);
	out.seekg(0);
	item *tmp_R = new item;
	while (!out.eof())
	{
		out.read((char*)&tmp_R->name, sizeof(tmp_R->name));
		lst_item.push_back(*tmp_R);
	}
	lst_item.pop_back();
}

void add_items()
{
	system("cls");
	fstream out("items", ios::binary | ios::app);
	item *tmp_R = new item;

	cout << "Имя товара" << endl;
	cin >> tmp_R->name;
	out.write((char*)&tmp_R->name, sizeof(tmp_R->name));

	lst_item.push_back(*tmp_R);
	out.close();
	cout << "Успешно!\n";
}

void coutItems()
{
	int count = 1;
	readFile();

	for (list<item>::iterator i1 = lst_item.begin(); i1 != lst_item.end(); i1++, count++ )
	{
		cout << count;
		cout <<" Наименование: ";
		cout << i1->name << " "<<endl;
		cout << endl;
	}
}

void delItem()
{
	system("cls");
	
	int count = 1, buf;
	cout << "Введите номер товара" << endl;
	cin >> buf;
	for (list<item>::iterator i1 = lst_item.begin(); i1 != lst_item.end(); i1++, count++)
		if (count == buf)
		{
			i1 = lst_item.erase(i1);
			cout << "Товар удален!" << endl;
			break;
		}
}

void editStell()
{
	string newname;
	int buf, count=1;
	cout << "Введите номер поезда для дальнейшего редактирования" << endl;
	cin >> buf;
	for (list<item>::iterator i1 = lst_item.begin(); i1 != lst_item.end(); i1++, count++)
		if ( count == buf)
		{
			int k;
			string buf;
			cout << "1 изменить название " << endl;
			/*cin >> k;
			switch (k)
			{
			case 1:
			{
			cin >> newname;
			i1->name = newname;
			break;
			}
			}
			*/
			cin >> newname;
			i1->name = newname;
			break;
		}
}

int main()
{
	setlocale(0, "rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int k;
	while (1)
	{
		cin >> k;
		switch (k)
		{
		case 1:add_items();
			break;
		case 2:readFile();
			break;
		case 3:coutItems();
			break;
		case 4:delItem();
			break;
		case 5:editStell();
			break;
		}
	}
	system("pause");
}