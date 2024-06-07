#include<iostream>
#include"contacts.h"
using namespace std;

//显示菜单
void showManu() {
	cout << "********************************" << endl;
	cout << " *****  1.添加联系人   ********" << endl;
	cout << " *****  2.显示联系人   ********" << endl;
	cout << " *****  3.删除联系人   ********" << endl;
	cout << " *****  4.查找联系人   ********" << endl;
	cout << " *****  5.修改联系人   ********" << endl;
	cout << " *****  6.清空联系人   ********" << endl;
	cout << " *****  0.退出通讯录   ********" << endl;
	cout << "********************************" << endl;
	cout << endl;
}

//添加联系人到通讯录
void addperson(Addressbooks* abs) {
	//判断通讯录是否为满
	if (abs->m_size == max) {
		cout << "通讯录已满" << endl;
		return;
	}
	else {
		//添加联系人信息

		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[abs->m_size].name = name;
		//年龄
		cout << "请输入年龄" << endl;
		unsigned int age = 0;
		cin >> age;
		abs->personArray[abs->m_size].age = age;

		//性别
		cout << "请输入性别" << endl;
		cout << "1--男" << endl;
		cout << "0--女" << endl;
		char sex;
		while (1) {
			cin >> sex;
			if (sex == '1' || sex == '0') {
				abs->personArray[abs->m_size].sex = sex;
				break;
			}
			else
				cout << "输入有误，请重新输入" << endl;
		}
		//电话
		cout << "请输入电话" << endl;
		string phone = "0";
		cin >> phone;
		abs->personArray[abs->m_size].phone = phone;
		// 地址
		cout << "请输入地址" << endl;
		string address = "0";
		cin >> address;
		abs->personArray[abs->m_size].address = address;
		//通讯录人数+1
		abs->m_size++;
		cout << endl;
		cout << "联系人“" << name << "”信息添加成功！" << endl;
		cout << endl;
		system("pause");//任意键继续
		//system("cls");//清屏

	}
}

//打印通讯录中所有联系人
void showcontact(Addressbooks* abs) {
	if (abs->m_size == 0) {//判断联系人记录是否为空
		cout << "当前通讯录无联系人！" << endl;
	}
	else {
		for (int i = 0; i < abs->m_size; i++) {
			cout << "第" << i + 1 << "位联系人信息：" << endl;
			cout << "性名：" << abs->personArray[i].name << "\t";
			cout << "性别：" << (abs->personArray[i].sex == '1' ? "男" : "女") << "\t";
			cout << "年龄：" << abs->personArray[i].age << "\t";
			cout << "电话：" << abs->personArray[i].phone << "\t";
			cout << "地址：" << abs->personArray[i].address << endl;
			cout << endl;
		}
		system("pause");
	}
}

//检查通讯录中是否有该name的联系人，如果有，返回该联系人位置，如果没有，返回-1
int isExist(Addressbooks* abs, string name) {
	for (int i = 0; i < abs->m_size; i++) {
		if (abs->personArray[i].name == name) {
			return i;
		}
	}
	return -1;
}

//检查通讯录中是否有该name的联系人，如果有，删除该联系人信息并将后面联系人前移动，m_size--，如果没有，返回不存在
void deleteperson(Addressbooks* abs, string name) {
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		for (int i = ret; i < abs->m_size; i++) {
			//将该联系人信息空间释放并将后面联系人前移动
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_size--;
	}

}

//查找指定联系人，如果有，返回该联系人所有信息，如果没有，返回-1
void findperson(Addressbooks* abs) {
	cout << "请输入要查找联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人！" << endl;
	}
	else {
		cout << "性名：" << abs->personArray[ret].name << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "电话：" << abs->personArray[ret].phone << "\t";
		cout << "地址：" << abs->personArray[ret].address << endl;
		cout << endl;
	}
}

//修改指定联系人，如果有，依次修改该联系人所有信息，如果没有，返回查无此人
void fixperson(Addressbooks* abs) {
	cout << "请输入要修改联系人的姓名：" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret == -1) {
		cout << "查无此人！" << endl;
	}

	else {
		//添加联系人信息
		//姓名
		string name;
		cout << "请输入姓名" << endl;
		cin >> name;
		abs->personArray[ret].name = name;
		//年龄
		cout << "请输入年龄" << endl;
		unsigned int age = 0;
		cin >> age;
		abs->personArray[ret].age = age;

		//性别
		cout << "请输入性别" << endl;
		cout << "1--男" << endl;
		cout << "0--女" << endl;
		char sex = 0;
		while (1) {
			cin >> sex;
			if (sex == '1' || sex == '0') {
				abs->personArray[ret].sex = sex;
				break;
			}
			else
				cout << "输入有误，请重新输入" << endl;
		}
		//电话
		cout << "请输入电话" << endl;
		string phone = "0";
		cin >> phone;
		abs->personArray[ret].phone = phone;
		// 地址
		cout << "请输入地址" << endl;
		string address = "0";
		cin >> address;
		abs->personArray[ret].address = address;
		cout << endl;
		cout << "联系人“" << name << "”信息修改成功！" << endl;
		cout << endl;

		cout << "性名：" << abs->personArray[ret].name << "\t";
		cout << "性别：" << (abs->personArray[ret].sex == 1 ? "男" : "女") << "\t";
		cout << "年龄：" << abs->personArray[ret].age << "\t";
		cout << "电话：" << abs->personArray[ret].phone << "\t";
		cout << "地址：" << abs->personArray[ret].address << endl;
		cout << endl;
		system("pause");
	}
}

//清空通讯录
void cleancontacts(Addressbooks* abs) {
	abs->m_size = 0;
	cout << "已清空通讯录！" << endl;
}

int main() {

	Addressbooks abs;
	abs.m_size = 0;
	int chioce = 0;
	showManu();

	while (1) {
		cin >> chioce;
		switch (chioce) {
		case 1://添加联系人
			addperson(&abs);
			showManu();
			break;
		case 2://显示联系人
			showcontact(&abs);
			break;
		case 3: {//删除联系人
			string name;
			cin >> name;
			cout << "请输入要删除联系人的姓名：" << endl;
			deleteperson(&abs, name);
			cout << "找到联系人:" << name << endl;
			cout << "已删除联系人：" << name << endl;
		}
			  break;
		case 4: {//查找联系人
			findperson(&abs);
			break;
		}
		case 5: {//修改联系人
			fixperson(&abs);
		}
			  break;
		case 6: {//清空通讯录
			cout << "是否清空所有联系人？" << endl;
			cout << "是（1）" << "\t";
			cout << "否（0）" << "\t";
			char X;
			cin >> X;
			if (X == '1')
				cleancontacts(&abs);
			else
				cout << "放弃清空所有联系人！" << endl;
			break;
		}
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			return 0;
			break;
		default:
			break;
		}
	}
	return 0;
}