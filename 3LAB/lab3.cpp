#include "lab3.h"
int Figure :: getSizeOfGeometry(){
	return sizeOfGeometry;
}
void Figure :: setSizeOfGeometry(int size){
	sizeOfGeometry = size;
}
double*  Figure :: getGeometry(){
	return geometry; 
}
Figure** Figure :: getHeirs(){
	return heirs; 
}
void Figure :: setHeirs(Figure** data){
	heirs = data;
}
int Figure :: getSizeHeirs(){
	return sizeHeirs;
}
void Figure :: setGeometry(double* data){
	geometry = data;
}
void Figure :: addElToHeirs(Figure* el){
	sizeHeirs++;
	heirs = (Figure**) realloc (heirs, sizeHeirs * sizeof(Figure*));
	heirs[sizeHeirs - 1] = el;
}
void Figure :: freeMemory(){
	sizeHeirs--;
}


double Circle:: square(){
	double radius = getGeometry()[2];
	double square = M_PI * (radius * radius);
	return square;
}
Circle::Circle(double* data){
	cout << "добавлен обьект circle" << endl; 
	setSizeOfGeometry(3);
	setGeometry(data);
			
}
Circle::~Circle(){
	cout << "удален обьект circle" << endl; 
	freeMemory();
}
		
double Rectangle :: square(){
	double height = getGeometry()[2];
	double width = getGeometry()[3];
	double square = height * width;
	return square;
}
Rectangle :: Rectangle(double* data){
	cout << "добавлен обьект recctangle" << endl;
	setSizeOfGeometry(4);
	setGeometry(data);
}
Rectangle :: ~Rectangle(){
	cout << "удален обьект rectangle" << endl; 
	freeMemory();
}

//How about make the type of figure how field of Figure class? How aboute once calculate input->getGeometry() ?
ostream& operator << (std::ostream &os, Figure* input){
	int size =  input->getSizeOfGeometry();
	string output = "";
	if (size == 3){
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
istream& operator >> (std::istream& in, Figure* figure){
    double* geometry;
    double firstValue;
    double secondValue;
    double thirdValue;
    int size = figure -> getSizeOfGeometry();
    if (size == 4){ 
    	double fourthValue;
    	in >> firstValue >> secondValue >> thirdValue >> fourthValue;
    	double* data =  {new double[] {firstValue,secondValue,thirdValue,fourthValue}};
    	figure -> setGeometry(data);
    	return in;
    }
    
    else{
    	in >> firstValue >> secondValue >> thirdValue;
    	double* data =  {new double[] {firstValue,secondValue,thirdValue}};
    	figure -> setGeometry(data);
    	return in;
    }
}
template <typename T,typename P>  Figure* operator + (T figure1,P figure2){
			if(figure1.square() > figure2.square()){
				T* figure3 = new T(figure1.getGeometry());
				Figure::addElToHeirs(figure3);
				
			}
			else{
				P* figure3 = new P(figure2.getGeometry());
				Figure::addElToHeirs(figure3);
			}
			int lastAdd = (Figure:: getSizeHeirs()) - 1;
			Figure* output = Figure:: getHeirs()[lastAdd];
			return output;
			
}
template <typename T> Figure* operator * (int number,T figure){
				double* data = figure.getGeometry();
				int size = figure.getSizeOfGeometry();
				for(int  i = 0; i < size; i++){
					data[i] = data[i] * number;
				}
				//figure.setGeometry(data);
				//T answer = figure;
				Figure* output = new T(data);
				return output;
			
}
template <typename T> Figure* operator * (T figure,int number){
				double* data = figure.getGeometry();
				int size = figure.getSizeOfGeometry();
				for(int  i = 0; i < size; i++){
					data[i] = data[i] * number;
				}
				//figure.setGeometry(data);
				//T answer = figure;
				Figure* output = new T(data);
				return output;
			
}


void task1(){
	srand(time(0));
	cout << "Input R value " << endl;
	int R;
	cin >> R;
	for(int  i = 0; i < 3; i++){
		// watch random generate of random values between a and b
		double metrics = (double)rand() * (0.5 * R - 0.1 * R) / (RAND_MAX + 0.1 * R); // radius or side of square between 0.1 R and 0.5 R
		double allowedY = (double)rand() * (9.5 * R - 0.5 * R) / (RAND_MAX + 0.5 * R); 
		double allowedX = (double)rand() * (9.5 * R - 0.5 * R) / (RAND_MAX + 0.5 * R); 
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
	//may to be function
	cout << Figure:: getSizeHeirs()<<  endl;
	ofstream out;       
    	out.open("output.txt");      
    	
	//may to be function
	for(int  i = 0; i < Figure:: getSizeHeirs(); i++){
		cout << Figure:: getHeirs()[i] << endl;
		out << Figure:: getHeirs()[i] << endl;
	}
	out.close(); 

}

void task2(){

	double* data1  {new double[] {12,123,11,11}};
	double* data2  {new double[] {10,9,5}}; 
	Circle* circle = new Circle(data2);
	Rectangle* rectangle = new Rectangle(data1);
	Figure::addElToHeirs(circle);
	Figure::addElToHeirs(rectangle);
	*rectangle + *circle;
	for(int  i = 0; i < Figure:: getSizeHeirs(); i++){
		cout << Figure:: getHeirs()[i] << endl;
	}
}

void task3(){
	double* data1  {new double[] {12,123,11,11}};
	Rectangle* rectangle = new Rectangle(data1);
	auto p = 2 * *rectangle;
	cout << p << endl;
}






