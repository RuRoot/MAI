
using namespace std;
#include <iostream>
#include <typeinfo>
template<typename T> void size (T variable){
    cout << "size of " << typeid(variable).name() << " " << sizeof(variable) << " byte" << endl;
}
template<typename T,typename P> void explicitConv(T variable1, P variable2){
	cout << typeid(variable1).name() << " " << variable1 << " to " << typeid(variable2).name() << " result: "<< static_cast<P>(variable1) << endl;
}
template<typename T,typename P> void implicitConv(T variable1, P variable2){
	variable2 = variable1;
	cout << typeid(variable1).name() << " " << variable1 << " to " << typeid(variable2).name() <<" result: " << variable2 << endl;
}

void task1(){
    short int a1;
    size(a1);
    int a2;
    size(a2);
    long int a3;
    size(a3);
    long long int a4;
    size(a4);
    float a5;
    size(a5);
    //size(long float a6);
    double a7;
    size(a7);
    long double a8;
    size(a8);
    bool a9;
    size(a9);
    char a10;
    size(a10);
    wchar_t a11;
    size(a11);
    unsigned short int a12;
    size(a12);
    unsigned int a13;
    size(a13);
    unsigned long int a14;
    size(a14);
    unsigned long long int a15;
    size(a15);
  /*unsigned float a16;
    size(a16);*/
  /*unsigned double a17;
    size(a17);*/
  /*unsigned long double a18;
    size(a18);*/
  /*unsigned bool a19;
    size(a19);*/
    unsigned char a20;
    size(a20);
  /*unsigned wchar_t a21;
    size(a21);*/
    
}

void task2(){
	float fl = 10.5f;
	int in = 0;
	double db = 13.2;
	bool bl = true;
	cout << "explicit convertion" << endl;
	explicitConv(fl,in);
	explicitConv(db,in);
	explicitConv(bl,in);
	explicitConv(in,bl);
	cout << "implicit convertion" << endl;
	implicitConv(fl,in);
	implicitConv(db,in);
	implicitConv(bl,in);
	implicitConv(in,bl);
	
}

int main()
{
    task1();	
    task2();
    return 0;
}
