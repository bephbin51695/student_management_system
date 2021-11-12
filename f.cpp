#include <iostream>
#include <cstring>

using namespace std;
#define Len 100 //定义数组长度

void menu() //菜单界面
{
	cout << "           欢迎进入学生信息管理系统           " << endl;
	cout << "**********************菜单********************" << endl;
	cout << "                1.添加学生信息                 " << endl;
	cout << "                2.删除学生信息                 " << endl;
	cout << "                3.查找学生信息                 " << endl;
	cout << "                4.修改学生信息                 " << endl;
	cout << "                5.显示所有学生信息             " << endl;
	cout << "                0.退出学生信息管理系统         " << endl;
	cout << "**********************************************" << endl;
}

//学生信息类
class stuInfo
{
public:
	int stuID;													  //学生学号
	char stuName[10];											  //学生姓名
	int stuAge;													  //学生年龄
	char stuSex[10];											  //学生性别
	char stuAddress[100];										  //学生住址
	char stuPhone[20];											  //学生电话号码
	double stuScore;											  //学生绩点
	friend int compare(const stuInfo &stu1, const stuInfo &stu2); //友元函数声明
};

stuInfo stuArray[Len]; //学生对象数组
int currentStuNum = 0; //当前学生人数

//添加学生信息类
class insertStu
{
public:
	insertStu() {}					  //构造函数
	insertStu(const insertStu &in) {} //拷贝构造函数
	void insertStuInfo();			  //添加学生信息函数
};

void insertStu::insertStuInfo()
{
	stuInfo s1;
	int i; //插入位置
	cout << "请输入添加学生信息的位置：" << endl;
	while (1)
	{
		cin >> i;
		if (i > 0 && i <= currentStuNum + 1)
			break;
		else
		{
			cout << "输入有误！请重新输入。" << endl;
			cout << "请输入添加学生信息的位置：" << endl;
		}
	}
	cout << "==================================" << endl;
	cout << "第" << i << "个学生信息：" << endl;
	cout << "学号：";
	cin >> s1.stuID;
	cout << "姓名：";
	cin >> s1.stuName;
	cout << "年龄：";
	cin >> s1.stuAge;
	cout << "性别: ";
	cin >> s1.stuSex;
	cout << "家庭住址：";
	cin >> s1.stuAddress;
	cout << "电话号码：";
	cin >> s1.stuPhone;
	cout << "绩点：";
	cin >> s1.stuScore;
	cout << "==================================" << endl;
	//顺序表指定位置插入操作
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
	//增加当前学生数
	currentStuNum++;
	cout << "插入成功！" << endl;
	cout << "==================================" << endl;
}

//删除学生信息类
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
		cout << "暂无学生信息，请先添加！" << endl;
		return;
	}
	char name[10];
	char select; //选择
	cout << "请输入你要删除的学生姓名：" << endl;
	cin >> name;
	int tag = 0; //标志位
	for (int i = 0; i < currentStuNum; i++)
	{
		if (strcmp(stuArray[i].stuName, name) == 0)
		{
			cout << "==================================" << endl;
			cout << "此学生的信息为：" << endl;
			cout << "学号：";
			cout << stuArray[i].stuID << endl;
			cout << "姓名：";
			cout << stuArray[i].stuName << endl;
			cout << "年龄：";
			cout << stuArray[i].stuAge << endl;
			cout << "性别：";
			cout << stuArray[i].stuSex << endl;
			cout << "家庭住址：";
			cout << stuArray[i].stuAddress << endl;
			cout << "电话号码：";
			cout << stuArray[i].stuPhone << endl;
			cout << "绩点：";
			cout << stuArray[i].stuScore << endl;
			cout << "==================================" << endl;
			cout << "是否删除此学生的信息？(Y/N)" << endl;
			while (1)
			{
				cin >> select;
				if (select == 'Y' || select == 'y' || select == 'N' || select == 'n')
					break;
				else
				{
					cout << "输入有误，请重新输入！！" << endl;
					cout << "是否删除此学生的信息？(Y/N)" << endl;
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
				cout << "删除成功。" << endl;
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
		cout << "查无此人！" << endl;
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
class dateTime : public Time, public Date //多重继承
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
		cout << n << "入学时间是：";
		Date::display();
		cout << ' ';
		Time::display();
	}
};
//查找学生信息类
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
		cout << "暂无学生信息，请先添加！" << endl;
		return;
	}
	char name[10];
	cout << "请输入你要查询的学生姓名：" << endl;
	cin >> name;
	cout << "查询结果：" << endl;
	int tag = 0; //标志位
	for (int i = 0; i < currentStuNum; i++)
	{
		if (strcmp(stuArray[i].stuName, name) == 0)
		{
			cout << "==================================" << endl;
			cout << "学号：";
			cout << stuArray[i].stuID << endl;
			cout << "姓名：";
			cout << stuArray[i].stuName << endl;
			cout << "年龄：";
			cout << stuArray[i].stuAge << endl;
			cout << "性别：";
			cout << stuArray[i].stuSex << endl;
			cout << "家庭住址：";
			cout << stuArray[i].stuAddress << endl;
			cout << "电话号码：";
			cout << stuArray[i].stuPhone << endl;
			cout << "绩点：";
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
		cout << "查无此人！" << endl;
	}
	cout << "==================================" << endl;
}

//修改学生信息类
class updateStu
{
public:
	updateStu() {}
	updateStu(const updateStu &up) {}
	void updateStuInfo();
};
void updateStu::updateStuInfo() //修改学生信息
{
	if (currentStuNum == 0)
	{
		cout << "暂无学生信息，请先添加！" << endl;
		return;
	}
	int tag = 0; //标志位
	char name[10];
	char select;
	cout << "请输入你要修改的学生姓名：" << endl;
	cin >> name;
	for (int i = 0; i < currentStuNum; i++)
	{
		if (strcmp(stuArray[i].stuName, name) == 0)
		{
			cout << "==================================" << endl;
			cout << "此学生的信息为：" << endl;
			cout << "学号：";
			cout << stuArray[i].stuID << endl;
			cout << "姓名：";
			cout << stuArray[i].stuName << endl;
			cout << "年龄：";
			cout << stuArray[i].stuAge << endl;
			cout << "性别：";
			cout << stuArray[i].stuSex << endl;
			cout << "家庭住址：";
			cout << stuArray[i].stuAddress << endl;
			cout << "电话号码：";
			cout << stuArray[i].stuPhone << endl;
			cout << "绩点：";
			cout << stuArray[i].stuScore << endl;
			cout << "==================================" << endl;
			cout << "是否修改此学生的信息？(Y/N)" << endl;
			while (1)
			{
				cin >> select;
				if (select == 'Y' || select == 'y' || select == 'N' || select == 'n')
					break;
				else
				{
					cout << "输入有误，请重新输入！！" << endl;
					cout << "是否修改此学生的信息？(Y/N)" << endl;
				}
			}
			if (select == 'Y' || select == 'y')
			{
				cout << "======================================" << endl;
				cout << "学号：";
				cin >> stuArray[i].stuID;
				cout << "姓名：";
				cin >> stuArray[i].stuName;
				cout << "年龄：";
				cin >> stuArray[i].stuAge;
				cout << "性别: ";
				cin >> stuArray[i].stuSex;
				cout << "家庭住址：";
				cin >> stuArray[i].stuAddress;
				cout << "电话号码：";
				cin >> stuArray[i].stuPhone;
				cout << "绩点：";
				cin >> stuArray[i].stuScore;
				cout << "======================================" << endl;
				cout << "修改成功。" << endl;
				cout << "======================================" << endl;
			}
			tag = 1;
		}
	}
	if (tag == 0)
	{
		cout << "======================================" << endl;
		cout << "查无此人！" << endl;
		cout << "======================================" << endl;
	}
}

//显示所有学生信息类
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
		cout << "暂无学生信息，请先添加！" << endl;
		return;
	}
	cout << "输出全部学生信息:" << endl;
	for (int i = 0; i < currentStuNum; i++)
	{
		cout << "==================================" << endl;
		cout << "第" << i + 1 << "个学生信息：" << endl;
		cout << "学号：";
		cout << stuArray[i].stuID << endl;
		cout << "姓名：";
		cout << stuArray[i].stuName << endl;
		cout << "年龄：";
		cout << stuArray[i].stuAge << endl;
		cout << "性别：";
		cout << stuArray[i].stuSex << endl;
		cout << "家庭住址：";
		cout << stuArray[i].stuAddress << endl;
		cout << "电话号码：";
		cout << stuArray[i].stuPhone << endl;
		cout << "绩点：";
		cout << stuArray[i].stuScore << endl;
	}
	cout << "==================================" << endl;
	cout << "以上一共有" << currentStuNum << "位学生信息。" << endl;
	if (currentStuNum != 0)
		showCompare();
}

int compare(const stuInfo &stu1, const stuInfo &stu2) //友元函数
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
	cout << "学生绩点在" << stuArray[min].stuScore << "-" << stuArray[max].stuScore << "之间。" << endl;
}

int main()
{
	//初始化创建菜各单功能类对象
	insertStu I1;
	deleteStu D1;
	findStu F1;
	updateStu U1;
	showStu S1;

	//调用菜单
	while (1)
	{
		system("cls");
		menu();
		int s;
		cout << "请输入0-5选择相应的菜单：" << endl;
		cin >> s;
		try //异常处理
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
					cout << "感谢使用本系统！程序已退出。" << endl;
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
			cout << "输入有误！请重新输入。" << endl;
			system("pause");
			system("cls");
		}
	}
}