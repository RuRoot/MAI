using namespace std;
#include <iostream>
#include <cmath>
#include <ctime>
#include <typeinfo>
#define _USE_MATH_DEFINES

#ifndef lab3_h
#define lab3_h
class Figure{
	private:
		int sizeOfGeometry;
		static inline Figure** heirs;
		double* geometry = nullptr;
		static inline int sizeHeirs;
	public:
		int getSizeOfGeometry();
		void setSizeOfGeometry(int size);double* getGeometry();
		static Figure** getHeirs();
		void setHeirs(Figure** data);
		static int getSizeHeirs();
		void setGeometry(double* data);
		static void addElToHeirs(Figure* el);
		void freeMemory();
		virtual double square() = 0;
};
class Circle : public Figure{
	public:
		double square();
		Circle(double* data);
		~Circle();
};
class Rectangle : public Figure{
	public: 
		double square();
		Rectangle(double* data);
		~Rectangle();
};

istream& operator >> (std::istream& in, Figure* figure);
ostream& operator << (std::ostream& os, Figure* input);
template <typename T,typename P>  Figure* operator + (T figure1,P figure2);
template <typename T> Figure* operator * (int number,T figure);
template <typename T> Figure* operator * (T figure,int number);

void task1();
void task2();
void task3();

#endif
