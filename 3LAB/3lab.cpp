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
			 /*for(int i = 0; i < sizeHeirs; i++){
			 	cout << "##" << heirs[i]->getGeometry()[0] << endl;
			 }*/
		}
		void freeMemory(){
			delete [] geometry;
			delete [] heirs;
			geometry = nullptr;
			heirs = nullptr;
			
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
			cout << "создан объект круг" << endl;
			
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
			//geometry = new double [sizeof(data)];
			setGeometry(data);
			cout << "создан объект прямоугольник" << endl;
			
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
Figure& operator + (Figure& figure1,Figure& figure2){
			if(figure1.square() > figure2.square()){
				delete &figure2;
				return figure1;
			}
			else{
				delete &figure1;
				return figure2;
			}
}

int main(){
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
			//double* data  {new double[] {allowedX,allowedY,metrics,metrics}};
			double* data  {new double[] {allowedX,allowedY,metrics}};
			//Circle circle = Circle(data);
			Circle* circle = new Circle(data);
			double* test = circle->getGeometry();
			for(int i = 0; i < sizeof(test)/sizeof(test[0]); i++){
				cout << test[i] <<" ";
			}
			cout << endl <<  "конец вывода" << endl;
			Figure::addElToHeirs(circle);
			//cout << "++" << circle << endl;
		}
		else{
			double* data  {new double[] {allowedX,allowedY,metrics,metrics}};
			//Rectangle rectangle =  Rectangle(data);
			//new Rectangle(data);
			Rectangle* rectangle = new Rectangle(data);
			double* test = rectangle->getGeometry();
			for(int i = 0; i < sizeof(test)/sizeof(test[0]); i++){
				cout << test[i] <<" ";
			}
			cout << endl <<  "конец вывода" << endl;
			Figure::addElToHeirs(rectangle);
			//cout  << "++" << rectangle << endl;
		}
	}
	
	cout << Figure:: getSizeHeirs()<<  endl;
	
	for(int  i = 0; i < Figure:: getSizeHeirs(); i++){
		//cout <<"--" << Figure:: getHeirs()[i]->getGeometry()[0] << "--" << endl;
		//cout << Figure:: getHeirs()[i]->getGeometry()[0];
		cout << Figure:: getHeirs()[i] << endl;
	}
	
	return 0;
}





