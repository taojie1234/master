#include<iostream>
using namespace std;

class Link
{
public:
	int i;
	Link(){
		i = 0;
		cout<<"���캯��"<<endl;
	}
	Link(const Link &L){
		i = L.i;
		cout<<"�������캯��"<<endl;
	}
	Link operator = (const Link &L){
		i = L.i;
		cout<<"��ֵ���캯��"<<endl;
	}
	Link operator + (const Link &L){
		Link tmp;
		tmp.i = L.i + i;
		cout<<"�Ӳ���"<<endl;
		return tmp;
	}
	~Link(){
		cout<<"��������"<<endl;
	}
	void test(){
		cout<<"����"<<endl;
	}
};

int main()
{
	Link l;
	Link link1;
	link1.i = 10;
    Link link2(link1);
	cout<<"link2="<<link2.i<<endl;
	Link link3 = link1;
	cout<<"link3="<<link3.i<<endl;
	//link3 = link1;
	cout<<"l="<<l.i<<endl;
	l = link2 + link3;
	cout<<"l="<<l.i<<endl;
}