using namespace std;
#include <iostream>
#include <cmath>
#include <ctime>
#define _USE_MATH_DEFINES
class Figure{
	private:
		static inline Figure** heirs;
		double* geometry = nullptr;
		static inline int sizeHeirs;
	public:
		double* getGeometry(){
			return geometry; 
		}
		static Figure** getHeirs(){
			return heirs; 
		}
		void setHeirs(Figure** data){
			heirs = data;
		}
		static int getSizeHeirs(){
			return sizeHeirs;
		}
		void setGeometry(double* data){
			geometry = data;
		}
		static void addElToHeirs(Figure* el){
			 sizeHeirs++;
			 heirs = (Figure**) realloc (heirs, sizeHeirs * sizeof(Figure*));
			 heirs[sizeHeirs - 1] = el;
		}
		void freeMemory(){
		 	sizeHeirs--;
			//delete [] geometry;
			//delete [] heirs;
			//geometry = nullptr;
			//heirs = nullptr;
			
		}
		virtual double square() = 0;
};

class Circle : public Figure{
	public:
		double square(){
			double radius = getGeometry()[2];
			double square = M_PI * (radius * radius);
			return square;
		}
		Circle(double* data){
			setGeometry(data);
			cout << "+circle" << endl;
			
		}
		~Circle(){
			freeMemory();
		}

};
class Rectangle : public Figure{
	public:
		double square(){
			double height = getGeometry()[2];
			double width = getGeometry()[3];
			double square = height * width;
			return square;
		}
		Rectangle(double* data){
			setGeometry(data);
			cout << "+rectangle" << endl;
			
		}
		~Rectangle(){
			freeMemory();
		}
};
//How about make the type of figure how field of Figure class? How aboute once calculate input->getGeometry() ?
ostream& operator << (std::ostream &os, Figure* input){
	int lenghtGeometry = sizeof( input->getGeometry() ) / sizeof( input->getGeometry()[0] );
	string output = "";
	if (lenghtGeometry == 3){
		output = output + "объект circle ";
		output = output + "центр по х " + to_string(input->getGeometry()[0]) + " ";
		output = output + "центр по y " + to_string(input->getGeometry()[1]) + " ";
		output = output + "радиус " + to_string(input->getGeometry()[2]) + " ";
	}
	else{
		output = output + "объект rectangle ";
		output = output + "центр по х " + to_string(input->getGeometry()[0]) + " ";
		output = output + "центр по y " + to_string(input->getGeometry()[1]) + " ";
		output = output + "длина одной стороны " + to_string(input->getGeometry()[2]) + " ";
		output = output + "длина второй стороны " + to_string(input->getGeometry()[3]) + " ";
	}
	return os << output;
}
template <typename T,typename P>  Figure* operator +(T figure1,P figure2){
			if(figure1.square() > figure2.square()){
				T* figure3 = new T(figure1.getGeometry());
				Figure::addElToHeirs(figure3);
				
			}
			else{
				P* figure3 = new P(figure2.getGeometry());
				Figure::addElToHeirs(figure3);
			}
			cout << "--------------------in function --------------------------"<< endl;
			for(int  i = 0; i < Figure:: getSizeHeirs(); i++){
				cout << Figure:: getHeirs()[i] << endl;
			}//check
			cout << "--------------------end-----------------------------------"<<endl;
			int lastAdd = (Figure:: getSizeHeirs()) - 1;
			cout << Figure:: getHeirs()[lastAdd] << endl;
			Figure* output = Figure:: getHeirs()[lastAdd];
			return output;
			
}

void task1(){
	srand(time(0));
	cout << "Input R value " << endl;
	int R;
	cin >> R;
	for(int  i = 0; i < 3; i++){
		// watch random generate of random values between a and b
		double metrics = (double)rand() * (0,5 * R - 0,1 * R) / (RAND_MAX + 0,1 * R); // radius or side of square between 0.1 R and 0.5 R
		double allowedY = (double)rand() * (9,5 * R - 0,5 * R) / (RAND_MAX + 0,5 * R); 
		double allowedX = (double)rand() * (9,5 * R - 0,5 * R) / (RAND_MAX + 0,5 * R); 
		if( (rand()%10) < 5){
			double* data  {new double[] {allowedX,allowedY,metrics}};
			Circle* circle = new Circle(data);
			Figure::addElToHeirs(circle);
			
		}
		else{
			double* data  {new double[] {allowedX,allowedY,metrics,metrics}};
			Rectangle* rectangle = new Rectangle(data);
			Figure::addElToHeirs(rectangle);
			
		}
	}
	
	cout << Figure:: getSizeHeirs()<<  endl;
	//may to be function
	for(int  i = 0; i < Figure:: getSizeHeirs(); i++){
		cout << Figure:: getHeirs()[i] << endl;
	}


}

int main(){
	//task1();
	double* data1  {new double[] {12,123,11,11}};
	double* data2  {new double[] {10,9,5}}; 
	Circle* circle = new Circle(data2);
	Rectangle* rectangle = new Rectangle(data1);
	Figure::addElToHeirs(circle);
	Figure::addElToHeirs(rectangle);
	//cout << (*rectangle) + (*circle) ;
	cout << "______" << Figure:: getSizeHeirs() << endl;;
	*rectangle + *circle;
	cout << "старт" << endl;
	cout << Figure:: getSizeHeirs() << endl;
	cout << "--------------------in main --------------------------"<< endl;
	for(int  i = 0; i < Figure:: getSizeHeirs(); i++){
		cout << Figure:: getHeirs()[i] << endl;
	}
	cout << "--------------------end-----------------------------------"<<endl;
	cout << "конец" << endl;
	return 0;
}





