using namespace std;
#include <iostream>
#include <cmath>
#include <ctime>
#define _USE_MATH_DEFINES
class Figure{
	private:
		static Figure* heirs;
		double* geometry;
	public:
		double* getGeometry(){
			return geometry; 
		}
		Figure* getHeirs(){
			return heirs; 
		}
		void setHeirs(Figure* data){
			heirs = data;
		}
		void setGeometry(double* data){
			geometry = data;
		}
		void freeMemory(){
			delete geometry;
			delete heirs;
		}
		virtual double square() = 0;
		
};

class Circle : Figure{
	public:
		double square(){
			double radius = getGeometry()[2];
			double square = M_PI * (radius * radius);
			return square;
		}
		Circle(double* data){
			setGeometry(data);
		}
		~Circle(){
			freeMemory();
		}

};
class Rectangle : Figure{
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
		}
		~Rectangle(){
			freeMemory();
		}
};

int main(){
	srand(time(0));
	cout << "Input R value " << endl;
	int R;
	cin >> R;
	// watch random generate of random values between a and b
	double metrics = (double)rand() * (0,5 * R - 0,1 * R) / (RAND_MAX + 0,1 * R); // radius or side of square between 0.1 R and 0.5 R
	double allowedY = (double)rand() * (9,5 * R - 0,5 * R) / (RAND_MAX + 0,5 * R); 
	double allowedX = (double)rand() * (9,5 * R - 0,5 * R) / (RAND_MAX + 0,5 * R); 
	for(int  i = 0; i < 28; i++){
		if(rand() < 5){
			//double* data  {new double[] {allowedX,allowedY,metrics,metrics}};
			double* data = new double[] {1,1,1,1};
			//Circle circle = Circle(data);
			new Circle(data);
		}
		else{
			double* data  {new double[] {allowedX,allowedY,metrics,metrics}};
			//Rectangle rectangle =  Rectangle(data);
			new Rectangle(data);
		}		
	}
	return 0;
}





