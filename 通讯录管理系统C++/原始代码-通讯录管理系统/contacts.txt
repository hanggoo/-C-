#include<string>
using namespace std;
//通讯录最大容纳1000条信息
#define max 1000
//联系人
struct Person {
	string name;
	int age;
	char sex;
	string phone;
	string address;

};
//通讯录结构体
struct Addressbooks
{
	struct Person personArray[max];

	//通讯录当前记录联系人条数
	int m_size;
};
