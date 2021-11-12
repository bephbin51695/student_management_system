#include <iostream>
#include <cstring>

using namespace std;
#define Len 100 //�������鳤��

void menu() //�˵�����
{
	cout << "           ��ӭ����ѧ����Ϣ����ϵͳ           " << endl;
	cout << "**********************�˵�********************" << endl;
	cout << "                1.���ѧ����Ϣ                 " << endl;
	cout << "                2.ɾ��ѧ����Ϣ                 " << endl;
	cout << "                3.����ѧ����Ϣ                 " << endl;
	cout << "                4.�޸�ѧ����Ϣ                 " << endl;
	cout << "                5.��ʾ����ѧ����Ϣ             " << endl;
	cout << "                0.�˳�ѧ����Ϣ����ϵͳ         " << endl;
	cout << "**********************************************" << endl;
}

//ѧ����Ϣ��
class stuInfo
{
public:
	int stuID;													  //ѧ��ѧ��
	char stuName[10];											  //ѧ������
	int stuAge;													  //ѧ������
	char stuSex[10];											  //ѧ���Ա�
	char stuAddress[100];										  //ѧ��סַ
	char stuPhone[20];											  //ѧ���绰����
	double stuScore;											  //ѧ������
	friend int compare(const stuInfo &stu1, const stuInfo &stu2); //��Ԫ��������
};

stuInfo stuArray[Len]; //ѧ����������
int currentStuNum = 0; //��ǰѧ������

//���ѧ����Ϣ��
class insertStu
{
public:
	insertStu() {}					  //���캯��
	insertStu(const insertStu &in) {} //�������캯��
	void insertStuInfo();			  //���ѧ����Ϣ����
};

void insertStu::insertStuInfo()
{
	stuInfo s1;
	int i; //����λ��
	cout << "���������ѧ����Ϣ��λ�ã�" << endl;
	while (1)
	{
		cin >> i;
		if (i > 0 && i <= currentStuNum + 1)
			break;
		else
		{
			cout << "�����������������롣" << endl;
			cout << "���������ѧ����Ϣ��λ�ã�" << endl;
		}
	}
	cout << "==================================" << endl;
	cout << "��" << i << "��ѧ����Ϣ��" << endl;
	cout << "ѧ�ţ�";
	cin >> s1.stuID;
	cout << "������";
	cin >> s1.stuName;
	cout << "���䣺";
	cin >> s1.stuAge;
	cout << "�Ա�: ";
	cin >> s1.stuSex;
	cout << "��ͥסַ��";
	cin >> s1.stuAddress;
	cout << "�绰���룺";
	cin >> s1.stuPhone;
	cout << "���㣺";
	cin >> s1.stuScore;
	cout << "==================================" << endl;
	//˳���ָ��λ�ò������
	int j;
	for (j = currentStuNum; j > i - 1; j--)
	{
		stuArray[j].stuID = stuArray[j - 1].stuID;
		strcpy(stuArray[j].stuName, stuArray[j - 1].stuName);
		stuArray[j].stuAge = stuArray[j - 1].stuAge;
		strcpy(stuArray[j].stuSex, stuArray[j - 1].stuSex);
		strcpy(stuArray[j].stuAddress, stuArray[j - 1].stuAddress);
		strcpy(stuArray[j].stuPhone, stuArray[j - 1].stuPhone);
		stuArray[j].stuScore = stuArray[j - 1].stuScore;
	}
	stuArray[j].stuID = s1.stuID;
	strcpy(stuArray[j].stuName, s1.stuName);
	stuArray[j].stuAge = s1.stuAge;
	strcpy(stuArray[j].stuSex, s1.stuSex);
	strcpy(stuArray[j].stuAddress, s1.stuAddress);
	strcpy(stuArray[j].stuPhone, s1.stuPhone);
	stuArray[j].stuScore = s1.stuScore;
	//���ӵ�ǰѧ����
	currentStuNum++;
	cout << "����ɹ���" << endl;
	cout << "==================================" << endl;
}

//ɾ��ѧ����Ϣ��
class deleteStu
{
public:
	deleteStu() {}
	deleteStu(const deleteStu &del) {}
	void deleteStuInfo();
};
void deleteStu::deleteStuInfo()
{
	if (currentStuNum == 0)
	{
		cout << "����ѧ����Ϣ��������ӣ�" << endl;
		return;
	}
	char name[10];
	char select; //ѡ��
	cout << "��������Ҫɾ����ѧ��������" << endl;
	cin >> name;
	int tag = 0; //��־λ
	for (int i = 0; i < currentStuNum; i++)
	{
		if (strcmp(stuArray[i].stuName, name) == 0)
		{
			cout << "==================================" << endl;
			cout << "��ѧ������ϢΪ��" << endl;
			cout << "ѧ�ţ�";
			cout << stuArray[i].stuID << endl;
			cout << "������";
			cout << stuArray[i].stuName << endl;
			cout << "���䣺";
			cout << stuArray[i].stuAge << endl;
			cout << "�Ա�";
			cout << stuArray[i].stuSex << endl;
			cout << "��ͥסַ��";
			cout << stuArray[i].stuAddress << endl;
			cout << "�绰���룺";
			cout << stuArray[i].stuPhone << endl;
			cout << "���㣺";
			cout << stuArray[i].stuScore << endl;
			cout << "==================================" << endl;
			cout << "�Ƿ�ɾ����ѧ������Ϣ��(Y/N)" << endl;
			while (1)
			{
				cin >> select;
				if (select == 'Y' || select == 'y' || select == 'N' || select == 'n')
					break;
				else
				{
					cout << "�����������������룡��" << endl;
					cout << "�Ƿ�ɾ����ѧ������Ϣ��(Y/N)" << endl;
				}
			}
			if (select == 'Y' || select == 'y')
			{
				for (int j = i; j < currentStuNum; j++)
				{
					stuArray[j].stuID = stuArray[j + 1].stuID;
					strcpy(stuArray[j].stuName, stuArray[j + 1].stuName);
					stuArray[j].stuAge = stuArray[j + 1].stuAge;
					strcpy(stuArray[j].stuSex, stuArray[j + 1].stuSex);
					strcpy(stuArray[j].stuAddress, stuArray[j + 1].stuAddress);
					strcpy(stuArray[j].stuPhone, stuArray[j + 1].stuPhone);
				}
				cout << "==================================" << endl;
				cout << "ɾ���ɹ���" << endl;
				cout << "==================================" << endl;
				currentStuNum--;
				tag = 1;
			}
			break;
		}
	}
	if (tag == 0)
	{
		cout << "==================================" << endl;
		cout << "���޴��ˣ�" << endl;
		cout << "==================================" << endl;
	}
}

class Time
{
protected:
	int h, m;

public:
	Time(int &h, int &m)
	{
		this->h = h;
		this->m = m;
	}
	void display()
	{
		cout << this->h << ":" << this->m << endl;
	}
};
class Date
{
protected:
	int m, d, y;

public:
	Date(int &m, int &d, int &y)
	{
		this->m = m;
		this->d = d;
		this->y = y;
	}
	void display()
	{
		cout << m << "/" << d << "/" << y;
	}
};
class dateTime : public Time, public Date //���ؼ̳�
{
protected:
	char *n;

public:
	dateTime(char *nn, int mm, int dd, int yy, int hh, int mms) : Time(hh, mms), Date(mm, dd, yy)
	{
		n = new char(strlen(nn) + 1);
		n = nn;
	}
	void display()
	{
		cout << n << "��ѧʱ���ǣ�";
		Date::display();
		cout << ' ';
		Time::display();
	}
};
//����ѧ����Ϣ��
class findStu
{
public:
	findStu() {}
	findStu(const findStu &s) {}
	void findStuInfo();
};

void findStu::findStuInfo()
{
	if (currentStuNum == 0)
	{
		cout << "����ѧ����Ϣ��������ӣ�" << endl;
		return;
	}
	char name[10];
	cout << "��������Ҫ��ѯ��ѧ��������" << endl;
	cin >> name;
	cout << "��ѯ�����" << endl;
	int tag = 0; //��־λ
	for (int i = 0; i < currentStuNum; i++)
	{
		if (strcmp(stuArray[i].stuName, name) == 0)
		{
			cout << "==================================" << endl;
			cout << "ѧ�ţ�";
			cout << stuArray[i].stuID << endl;
			cout << "������";
			cout << stuArray[i].stuName << endl;
			cout << "���䣺";
			cout << stuArray[i].stuAge << endl;
			cout << "�Ա�";
			cout << stuArray[i].stuSex << endl;
			cout << "��ͥסַ��";
			cout << stuArray[i].stuAddress << endl;
			cout << "�绰���룺";
			cout << stuArray[i].stuPhone << endl;
			cout << "���㣺";
			cout << stuArray[i].stuScore << endl;
			dateTime dt(name, 9, 30, 2020, 11, 11);
			dt.display();
			tag = 1;
			break;
		}
	}
	if (tag == 0)
	{
		cout << "==================================" << endl;
		cout << "���޴��ˣ�" << endl;
	}
	cout << "==================================" << endl;
}

//�޸�ѧ����Ϣ��
class updateStu
{
public:
	updateStu() {}
	updateStu(const updateStu &up) {}
	void updateStuInfo();
};
void updateStu::updateStuInfo() //�޸�ѧ����Ϣ
{
	if (currentStuNum == 0)
	{
		cout << "����ѧ����Ϣ��������ӣ�" << endl;
		return;
	}
	int tag = 0; //��־λ
	char name[10];
	char select;
	cout << "��������Ҫ�޸ĵ�ѧ��������" << endl;
	cin >> name;
	for (int i = 0; i < currentStuNum; i++)
	{
		if (strcmp(stuArray[i].stuName, name) == 0)
		{
			cout << "==================================" << endl;
			cout << "��ѧ������ϢΪ��" << endl;
			cout << "ѧ�ţ�";
			cout << stuArray[i].stuID << endl;
			cout << "������";
			cout << stuArray[i].stuName << endl;
			cout << "���䣺";
			cout << stuArray[i].stuAge << endl;
			cout << "�Ա�";
			cout << stuArray[i].stuSex << endl;
			cout << "��ͥסַ��";
			cout << stuArray[i].stuAddress << endl;
			cout << "�绰���룺";
			cout << stuArray[i].stuPhone << endl;
			cout << "���㣺";
			cout << stuArray[i].stuScore << endl;
			cout << "==================================" << endl;
			cout << "�Ƿ��޸Ĵ�ѧ������Ϣ��(Y/N)" << endl;
			while (1)
			{
				cin >> select;
				if (select == 'Y' || select == 'y' || select == 'N' || select == 'n')
					break;
				else
				{
					cout << "�����������������룡��" << endl;
					cout << "�Ƿ��޸Ĵ�ѧ������Ϣ��(Y/N)" << endl;
				}
			}
			if (select == 'Y' || select == 'y')
			{
				cout << "======================================" << endl;
				cout << "ѧ�ţ�";
				cin >> stuArray[i].stuID;
				cout << "������";
				cin >> stuArray[i].stuName;
				cout << "���䣺";
				cin >> stuArray[i].stuAge;
				cout << "�Ա�: ";
				cin >> stuArray[i].stuSex;
				cout << "��ͥסַ��";
				cin >> stuArray[i].stuAddress;
				cout << "�绰���룺";
				cin >> stuArray[i].stuPhone;
				cout << "���㣺";
				cin >> stuArray[i].stuScore;
				cout << "======================================" << endl;
				cout << "�޸ĳɹ���" << endl;
				cout << "======================================" << endl;
			}
			tag = 1;
		}
	}
	if (tag == 0)
	{
		cout << "======================================" << endl;
		cout << "���޴��ˣ�" << endl;
		cout << "======================================" << endl;
	}
}

//��ʾ����ѧ����Ϣ��
class showStu
{
public:
	showStu() {}
	showStu(const showStu &s) {}
	void showStuInfo();
	void showCompare();
};
void showStu::showStuInfo()
{
	if (currentStuNum == 0)
	{
		cout << "����ѧ����Ϣ��������ӣ�" << endl;
		return;
	}
	cout << "���ȫ��ѧ����Ϣ:" << endl;
	for (int i = 0; i < currentStuNum; i++)
	{
		cout << "==================================" << endl;
		cout << "��" << i + 1 << "��ѧ����Ϣ��" << endl;
		cout << "ѧ�ţ�";
		cout << stuArray[i].stuID << endl;
		cout << "������";
		cout << stuArray[i].stuName << endl;
		cout << "���䣺";
		cout << stuArray[i].stuAge << endl;
		cout << "�Ա�";
		cout << stuArray[i].stuSex << endl;
		cout << "��ͥסַ��";
		cout << stuArray[i].stuAddress << endl;
		cout << "�绰���룺";
		cout << stuArray[i].stuPhone << endl;
		cout << "���㣺";
		cout << stuArray[i].stuScore << endl;
	}
	cout << "==================================" << endl;
	cout << "����һ����" << currentStuNum << "λѧ����Ϣ��" << endl;
	if (currentStuNum != 0)
		showCompare();
}

int compare(const stuInfo &stu1, const stuInfo &stu2) //��Ԫ����
{
	if (stu1.stuScore >= stu2.stuScore)
		return 1;
	else
		return -1;
}
void showStu::showCompare()
{
	int i = 0, min = 0, max = 0;
	for (i = 0; i < currentStuNum; i++)
	{
		if (compare(stuArray[max], stuArray[i]) == -1)
			max = i;
		else if (compare(stuArray[min], stuArray[i]) == 1)
			min = i;
	}
	cout << "ѧ��������" << stuArray[min].stuScore << "-" << stuArray[max].stuScore << "֮�䡣" << endl;
}

int main()
{
	//��ʼ�������˸������������
	insertStu I1;
	deleteStu D1;
	findStu F1;
	updateStu U1;
	showStu S1;

	//���ò˵�
	while (1)
	{
		system("cls");
		menu();
		int s;
		cout << "������0-5ѡ����Ӧ�Ĳ˵���" << endl;
		cin >> s;
		try //�쳣����
		{
			if (s >= 0 && s < 6)
			{
				switch (s)
				{
				case 1:
					I1.insertStuInfo();
					system("pause");
					system("cls");
					break;
				case 2:
					D1.deleteStuInfo();
					system("pause");
					system("cls");
					break;
				case 3:
					F1.findStuInfo();
					system("pause");
					system("cls");
					break;
				case 4:
					U1.updateStuInfo();
					system("pause");
					system("cls");
					break;
				case 5:
					S1.showStuInfo();
					system("pause");
					system("cls");
					break;
				case 0:
					cout << "��лʹ�ñ�ϵͳ���������˳���" << endl;
					exit(0);
				}
			}
			else
			{
				throw s;
			}
		}
		catch (int)
		{
			cout << "�����������������롣" << endl;
			system("pause");
			system("cls");
		}
	}
}