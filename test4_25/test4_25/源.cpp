#define _CRT_SECURE_NO_WARNINGS 1

#include<cstdio>
#include<iostream>
#include<cstdlib>
using namespace std;
#include<string.h>
#include<assert.h>

template<class T>
class  Vector{
public:
	Vector(size_t capacity = 10)
	:_pData(new T[capacity])
	, _size(0)
	, _capacity(capacity)
	{}
	~Vector();

	void PushBack(const T& data){
		assert(_size < _capacity);
		_pData[_size++] = data;
	}

	void PopBack(){
		assert(_size>0);
		_size--;
	}

	size_t Size(){ return _size; }

	T& operator[](size_t pos){
		assert(pos < _size);
		return _pData[pos];
	}

private:
	T *_pData;
	size_t _size;
	size_t _capacity;
};

template<class T>
Vector<T>::~Vector()
{
	if (_pData)
		delete[] _pData;
	_size = _capacity = 0;
}

int main(){
	Vector<int> v1;
	Vector<double> V2;
	v1.PushBack(1);
	v1.PushBack(2);
	v1.PushBack(3);
	v1.PopBack();
	system("pause");
	return 0;
}


#if 0
template<typename T1>
void Swap(T1& left, T1& right){
	T1 tmp = left;
	left = right;
	right = tmp;
}
template<class T1>
T1 sum(T1 left, T1 right){
	return left + right;
}

int main(){
	int a1 = 10, a2 = 20;
	double d1 = 12.34, d2 = 56.78;
	Swap(a1, a2);
	Swap(d1, d2);
	cout << a1 << " " << a2 << endl;
	cout << d1 << " " << d2 << endl;
	cout << sum(a1, a2) << endl;
	cout << sum(d1, d2) << endl;
	cout << sum<int>(a1, d2) << endl;

	system("pause");
	return 0;
}


using namespace std;
int main()
{
	void* p = new char[0xfffffffful];
	cout << "new:" << p << endl;
	return 0;
}
#endif
#if 0
class Date{
	friend ostream& operator<<(ostream& _cout, const Date& d);
public:
	Date(){}
	Date(int year, int month, int day)
		:_year(year),
		_month(month),
		_day(day)
	{
		_count++;}

	static int _count;
	static int GetCount(){
		return _count;
	}
	void print(){
		cout << _year << "-" << _month << "-" << _day << endl;
		cout << GetCount() << endl;
	}
	
private:
	int _year=4;
	int _month=5;
	int _day=6;
}d2;
int Date::_count = 0;

ostream& operator<<(ostream& _cout,const Date& d){
	_cout << d._year << "-" << d._month << "-" <<d._day;
	return _cout;
}
int main(){
	int a = 0, b = 0, c = 0;
	a = 1;
	b = 2;
	c = 3;
	Date d1(2020,4,26);
	cout << d1 << endl;
	d2.print();
	//cout << d1._count << endl;
	//cout << Date::_count << endl;
	//cout << Date::GetCount() << endl;
	//cout << d1.GetCount() << endl;
	system("pause");
	return 0;
}

#endif
#if 0
class String{
public:
	String(const char *str = "xxxx"){
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}

	String(const String& s){
		assert(&s != this);
		_str = (char*)malloc(strlen(s._str) + 1);
		assert(_str != nullptr);
		strcpy(_str, s._str);
	}

	String operator=(const String& s){
		assert(this != &s);
		_str = (char*)malloc(strlen(s._str) + 1);
		strcpy(_str, s._str);
		return *this;
	}

	~String(){
		cout << "~String()" << endl;
		free(_str);
	}

private:
	char *_str;
};

class Date{
public:
	Date(int year = 2020, int month = 4, int day = 25)
		:_year(year),
		_month(month),
		_day(day)
	{}
	Date(const Date& d){
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	bool operator==(const Date& d1){
		return _year == d1._year
			&& _month == d1._month
			&& _day == d1._day;
	}
	Date operator=(const Date& d){
		if (this != &d){
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
	Date d2(d1);
	if (d1 == d2){
		cout << "xiangdeng" << endl;
	}

	else 
		cout<<"不相等"<<endl;
	system("pause");
	return 0;
}

#endif
#if 0
class String{
public:
	String(const char *str = "xxxx"){
		_str = (char*)malloc(strlen(str)+1);
		strcpy(_str, str);
	}

	String(const String& s)
	{
		assert(&s != this);
		_str = (char*)malloc(strlen(s._str) + 1);
		assert(_str != nullptr);
		strcpy(_str, s._str);
	}
	~String(){
		cout << "~String()" << endl;
		free(_str);
	}

private:
	char *_str;
};

int main(){
	String s1("hello");
	String s2;
	String s3(s1);
	String s4(s2);
	
	return 0;
}

#endif
#if 0
class Date{
public:
	Date(int year = 2020, int month = 4, int day = 25)
		:_year(year),
		_month(month),
		_day(day)
	{}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
 	Date d2(111, 2, 22);
	Date d3(d1);
	Date d4(d2);

	return 0;
}



class String{
public:
	String(const char *str = "jack"){
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~String(){
		cout << "~String()" << endl;
		free(_str);
	}

private:
	char *_str;
};
class person{

private:
	String _name;
	int _age;
};
int main()
{
	person p;

	return 0;
}


\
typedef int DataType;

class SeqList{
public:
	SeqList(int capacity = 10)
	{
		_pData = (int*)malloc(sizeof(DataType)*capacity);
		assert(_pData);
		_size = 0;
		_capacity = capacity;
		cout << "构造完成" << endl;
	}

	~SeqList()
	{
		if (_pData)
		{
			free(_pData);
			_pData = nullptr;
			_capacity = 0;
			_size = 0;
			cout << "析构完成" << endl;
		}
	}
	void print()
	{
		printf("%p\n", _pData);
		printf("%p\n", &_pData);
	}
private:
	int* _pData;
	size_t _size;
	size_t _capacity;
};


int main(){
	SeqList s1;
	s1.print();
	s1.~SeqList();
	system("pause");
	return 0;
}

class Date{
public:
	Date()
	{}
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1;
	Date d2(2020, 4, 25);

	system("pause");
 return 0;
}



class Date
{
public:
	void Display()
	{
		cout <<_year<< "-" <<_month << "-"<< _day <<endl;
 }
 
 void SetDate(int year , int month , int day)
 {
 _year = year;
 _month = month;
 _day = day;
 }
private :
 int _year ; // 年
 int _month ; // 月
 int _day ; // 日
};


class A
{ 
public:
	void PrintA() 
	{
		cout<<"PrintA()"<<endl;
	}

	void Show()
	{
		cout<<"Show()"<<endl;
	}
private:
	//int _a;
};
int main()
{
	A* p = NULL;
	/*A a;
	p = &a;*/
	p->PrintA(); 
	p->Show();

	system("pause");
	return 0;
}

#include"Student.h"



int main()
{
	cout << sizeof(Student) << endl;
	Student s1("zhangsan","man",18);
	s1.PrintStudentInfo();
	s1.SetStudentInfo("lisi", "woman", 20);
	s1.PrintStudentInfo();
	system("pause");
	return 0;
}


int main()
{
	int array[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < sizeof(array) / sizeof(array[0]); ++i)
		cout << array[i]<<" ";
	cout << endl;
	for (const int *p = array; p < array + sizeof(array)/sizeof(array[0]); ++p)
		cout << *p<<" ";
	cout << endl;
	for (auto& a : array)
		cout << a <<" ";
	cout << endl;

	system("pause");
	return 0;
}


int TestAuto()
{
	return 11;
}
int main()
{
	int a = 10;
	auto b = a;
	auto c = 'a';
	auto d = TestAuto();

	cout << typeid(a).name() << endl;
	cout << typeid(b).name() << endl;
	cout << typeid(c).name() << endl;
	cout << typeid(d).name() << endl;
	system("pause");
	return 0;
}


int& Add(int a, int b) {
	int c = a + b;
	return c;
}
int main()
{
	int& ret = Add(1, 2);
	Add(3, 4);
	cout << "Add(1, 2) is :"<< ret <<endl;
	system("pause"); return 0;
}


int main(){
	const int a = 10;
	const int& ra = a;
	double d = 12.34;
	const int& rd = d;
	cout <<a<<" "<< &a << endl;
	cout <<ra<<" "<< &ra << endl;
	cout << rd << " " << &rd << endl;
	cout << d << " " << &d << endl;

	system("pause");
	return 0;
}




int Add(int left, int right)
{
	return left + right;
}

char Add(char left, char right)
{
	return left + right;
}
extern "C" int Add(int left, char right);
int main()
{
	cout << Add(1, 2) << endl;
	cout << Add(2,'a') << endl;
	system("pause");
	return 0;

}


namespace N1
{
	int a;
	int Add(int left, int right)
	{
		return left + right;
	}

}

namespace N2
{
	int a=1;
	int b;
	int Add(int left, int right)
	{
		return left + right;
	}
	namespace N3
	{
		int a;
		int b;
		int c;
		int Add(int left, int right)
		{
			return left + right;
		}
	}
}


int main(){
	//int a=5;
	using namespace N1;
	using N2::a;

	cout << a << endl;

	system("pause");
	return 0;
}

#endif