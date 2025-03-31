using namespace std;
#include "funcs.h"

void printAsortement(){
	cout << " Press number to activate function " << endl;
	cout << "(1) How qsort work ? " << endl;
	cout << "(2) Density by height " << endl;
	cout << "(3) Sigma of data " << endl; 	
	cout << "(4) Average of data " << endl;
	cout << "(5) Numbers of Fibonaci  " << endl;
	cout << "(6) Print short int by bits  " << endl;
	cout << "(7) Print double by bits  " << endl;
	cout << "(0) Exit  " << endl;
}


void showAr(int* ar,int lenght){
	for(int i = 0; i < lenght; i++){
		cout << ar[i] << " ";		
	}
	cout << endl;
}

int funccmp(const void * val1, const void * val2 ){
	return ( *(int*)val1 - *(int*)val2);
}

void demonstrationOfQsort(){
	int ar[] {1,13,42,1,14,2};
	int sizeOfEl = sizeof(ar[0]);
	int lenght = sizeof(ar) / sizeOfEl;
	cout << "array before sort :" << endl;
	showAr(ar,lenght);
	qsort(ar,lenght,sizeOfEl,*funccmp);
	cout << "array after sort" << endl;	
	showAr(ar,lenght);				
}

map <int,double> TableOfConst(){
	map <int,double> heightByDensity;
	heightByDensity[0] = 1.2250;
	heightByDensity[500] = 1.1673;
	heightByDensity[1000] = 1.1117;
	heightByDensity[1500] = 1.0581;
	heightByDensity[2000] = 1.0065;
	heightByDensity[2500] = 0.9569;
	heightByDensity[3000] = 0.9093;
	heightByDensity[4000] = 0.8194;
	heightByDensity[5000] = 0.7365;
	heightByDensity[6000] = 0.6601;
	heightByDensity[7000] = 0.59;
	heightByDensity[8000] = 0.5258;
	heightByDensity[9000] = 0.4671;
	heightByDensity[10000] = 0.4135;
	return heightByDensity;
}

pair <pair<int,double>, pair<int,double>> getInterval (int height,map <int,double> heightByDensity){
	pair <int,double> firstPoint;
	pair <int,double> secondPoint;
	for(auto iter {heightByDensity.begin()}; iter != heightByDensity.end(); iter++){
		if (iter -> first >= height){
			secondPoint = {iter -> first, iter -> second};
			iter--;
			firstPoint = {iter -> first, iter -> second};
			break;
		}	
	}
	
	pair <pair<int,double>, pair<int,double>> output = {firstPoint,secondPoint};
	return output;
} 

double densityByHeight(int height){
	pair <pair<int,double>, pair<int,double>> interval = getInterval (height, TableOfConst());
	double answer = (height - interval.first.first) * (interval.second.second - interval.first.second) / (interval.second.first - interval.first.first) + interval.first.second;
	return answer;
}

template <typename T> double average(int num, T ar){//correct
	double summary = 0;
	for(int i = 0; i < num; i++){
		summary = summary + ar[i];	
	}
	return (summary / num);
}
template <typename T> double sigma(int num, T ar){//correct
	return (sqrt(average(num, ar))); 
}

double* makeAr(int num,double* ar){
	for(int i = 0; i < num; i++){
		double currentValue;
		cin >> currentValue;
		ar[i] = currentValue;
	}
	return ar;
}

void fibonacci(int num, int nBegin){//correct
	int first = 0;
	int second = 1;
	int current;
	for(int i = 0; i < nBegin; i++){
		current = first + second;
		first = second;
		second = current;
	}
	if(nBegin <=2){
		cout << 1 << " ";
		num = num - 1;
	}
	for(int i = 0; i < num ; i++){
		cout << current << " ";
		current = first + second;
		first = second;
		second = current;
	}
	cout << endl;
}

template <typename T> void bitInt(T val){
	string answer = "";
	for(int i = 0; i < sizeof(val) * 8; i++){
		int first = (val >> 1) * 2;
		if(val - first){
			answer = "1" + answer;
		}	
		else{
			answer = "0" + answer;
		}
		val = val >> 1;
	}
	cout << answer << endl;
}

void bitDouble(double val){
	uint64_t bits;
        memcpy(&bits, &val, sizeof( bits ) );
	bitInt(bits);
}

void choise(){
	while (true){
		printAsortement();
		int input ;
		cin >> input;
		if (input == 0){
			break;
		}
		switch(input){
			case 1:{
				demonstrationOfQsort();
				break;
			}
			case 2:{
				cout << "Input height" << endl;
				int height  = 0;
				cin >> height;
				cout << densityByHeight(height) << endl;
				break;
			}
			case 3:{
				int number;
				cout << "Input number of data elements" << endl;
				cin >> number;
				cout << "Input data elements" << endl;
				double ar[number];
				
				cout << sigma(number,makeAr(number,ar)) << endl;
				break;
			}
			case 4:{
				int number;
				cout << "Input number of data elements" << endl;
				cin >> number;
				cout << "Input data elements" << endl;
				double ar[number];
				cout << average(number,makeAr(number,ar)) << endl;
				break;
			}	
			case 5:{
				int start;
				int number;
				cout << "How much elements do you want? " << endl;
				cin >> number;
				cout << "Input number of first element" << endl;
				cin >> start;
				fibonacci(number,start);
				break;
			}
			case 6:{
				short int number;
				cout << "Input the number" << endl;
				cin >> number;
				bitInt(number);
				break;
			}	
			case 7:{
				short int number;
				cout << "Input the number" << endl;
				cin >> number;
				bitDouble(number);
				break;
			}
			default:
				cout << "Invalid input, try again " << endl;
				break;	
		}
	}


}



