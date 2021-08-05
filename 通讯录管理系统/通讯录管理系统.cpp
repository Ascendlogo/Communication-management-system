#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
//联系人结构体
struct Person
{
	string Name;//姓名
	int Sex;//姓名
	int Age;//年龄
	string Phone;//电话
	string Addr;//住址
};
//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];//通讯录中保存的联系人数组
	int Size;//通讯录当前联系人个数
};

//菜单界面
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1-添加联系人  *****" << endl;
	cout << "*****  2-显示联系人  *****" << endl;
	cout << "*****  3-删除联系人  *****" << endl;
	cout << "*****  4-查找联系人  *****" << endl;
	cout << "*****  5-修改联系人  *****" << endl;
	cout << "*****  6-清空联系人  *****" << endl;
	cout << "*****  0-退出通讯录  *****" << endl;
	cout << "**************************" << endl;
}
//1-添加联系人
void addPerson(Addressbooks *abs)
{
	if (abs->Size == MAX) 
	{
		cout << "通讯录已满，无法添加！" << endl;
	}
	else 
	{
		//姓名
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArray[abs->Size].Name = name;
		//性别
		cout << "请输入性别：" << endl;
		cout << "1---男" << endl;
		cout << "2---女" << endl;
		int sex = 0;
		while(true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->Size].Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		//年龄
		cout << "请输入年龄：" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 120)
			{
				abs->personArray[abs->Size].Age = age;
				break;
			}
			cout << "输入有误，请重新输入！" << endl;
		}
		//电话
		cout << "请输入联系电话：" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->Size].Phone = phone;
		//住址
		cout << "请输入住址：" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->Size].Addr = address;
		//更新通讯录人数
		abs->Size++;
		cout << "*** 添加成功 ***" << endl;
		
		system("pause");
		system("cls");
	}
}
//2-显示联系人
void showPerson(Addressbooks *abs)
{
	if (abs->Size == 0)cout << "当前通讯录记录为空！" << endl;
	else 
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].Name << "\t";
			cout << "性别：" << (abs->personArray[i].Sex==1?"男":"女") << "\t";
			cout << "年龄：" << abs->personArray[i].Age << "\t";
			cout << "*电话：" << abs->personArray[i].Phone << "\t";
			cout << "住址：" << abs->personArray[i].Addr << endl;
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}
int main()
{
	//通讯录结构体变量
	Addressbooks abs;
	//初始化通讯录当前人员个数
	abs.Size = 0;

	while (true)
	{
		int select = -1;//初始选择变量
		showMenu();//菜单调用
		cin >> select;
		if (!cin.good())
		{
			cout << "未选择功能!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			system("pause");
			system("cls");
			continue;
		}
		switch (select)
		{
		case 1://添加联系人
			addPerson(&abs);
			break;
		case 2://显示联系人
			showPerson(&abs);
			break;
		case 3://删除联系人
			break;
		case 4://查找联系人
			break;
		case 5://修改联系人
			break;
		case 6://清空联系人
			break;
		case 0://退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "未选择功能!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}