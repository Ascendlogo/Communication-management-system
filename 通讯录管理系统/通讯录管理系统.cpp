#include<iostream>
#include<string>
#define MAX 1000
using namespace std;
//��ϵ�˽ṹ��
struct Person
{
	string Name;//����
	int Sex;//����
	int Age;//����
	string Phone;//�绰
	string Addr;//סַ
};
//ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];//ͨѶ¼�б������ϵ������
	int Size;//ͨѶ¼��ǰ��ϵ�˸���
};

//�˵�����
void showMenu()
{
	cout << "**************************" << endl;
	cout << "*****  1-�����ϵ��  *****" << endl;
	cout << "*****  2-��ʾ��ϵ��  *****" << endl;
	cout << "*****  3-ɾ����ϵ��  *****" << endl;
	cout << "*****  4-������ϵ��  *****" << endl;
	cout << "*****  5-�޸���ϵ��  *****" << endl;
	cout << "*****  6-�����ϵ��  *****" << endl;
	cout << "*****  0-�˳�ͨѶ¼  *****" << endl;
	cout << "**************************" << endl;
}
//1-�����ϵ��
void addPerson(Addressbooks *abs)
{
	if (abs->Size == MAX) 
	{
		cout << "ͨѶ¼�������޷���ӣ�" << endl;
	}
	else 
	{
		//����
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArray[abs->Size].Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1---��" << endl;
		cout << "2---Ů" << endl;
		int sex = 0;
		while(true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->Size].Sex = sex;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//����
		cout << "���������䣺" << endl;
		int age = 0;
		while (true)
		{
			cin >> age;
			if (age > 0 && age < 120)
			{
				abs->personArray[abs->Size].Age = age;
				break;
			}
			cout << "�����������������룡" << endl;
		}
		//�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->Size].Phone = phone;
		//סַ
		cout << "������סַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->Size].Addr = address;
		//����ͨѶ¼����
		abs->Size++;
		cout << "*** ��ӳɹ� ***" << endl;
		
		system("pause");
		system("cls");
	}
}
//2-��ʾ��ϵ��
void showPerson(Addressbooks *abs)
{
	if (abs->Size == 0)cout << "��ǰͨѶ¼��¼Ϊ�գ�" << endl;
	else 
	{
		for (int i = 0; i < abs->Size; i++)
		{
			cout << "������" << abs->personArray[i].Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].Sex==1?"��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].Age << "\t";
			cout << "*�绰��" << abs->personArray[i].Phone << "\t";
			cout << "סַ��" << abs->personArray[i].Addr << endl;
			cout << endl;
		}
	}
	system("pause");
	system("cls");
}
int main()
{
	//ͨѶ¼�ṹ�����
	Addressbooks abs;
	//��ʼ��ͨѶ¼��ǰ��Ա����
	abs.Size = 0;

	while (true)
	{
		int select = -1;//��ʼѡ�����
		showMenu();//�˵�����
		cin >> select;
		if (!cin.good())
		{
			cout << "δѡ����!" << endl;
			cin.clear();
			cin.ignore(10000, '\n');
			system("pause");
			system("cls");
			continue;
		}
		switch (select)
		{
		case 1://�����ϵ��
			addPerson(&abs);
			break;
		case 2://��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3://ɾ����ϵ��
			break;
		case 4://������ϵ��
			break;
		case 5://�޸���ϵ��
			break;
		case 6://�����ϵ��
			break;
		case 0://�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "δѡ����!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}