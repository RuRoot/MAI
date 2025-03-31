using namespace std;
#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

double lenght(pair<int,int> firstDot , pair <int,int> secondDot){
	double lenght = pow(pow(firstDot.first - secondDot.first,2) + pow (secondDot.second - firstDot.second,2),0.5);
	return lenght;
}

double getSquare(pair<int,int> firstDot , pair <int,int> secondDot , pair <int,int> thirdDot){
	double semiperimeter = (lenght(firstDot,secondDot) + lenght (secondDot,thirdDot) + lenght (thirdDot,firstDot))/2;
	double square = pow(semiperimeter * (semiperimeter - lenght(firstDot,secondDot)) * (semiperimeter - lenght(secondDot,thirdDot)) * (semiperimeter - lenght(thirdDot,firstDot)),0.5);
	return square;

} 

void testLenght(){
	assert(lenght(make_pair(1,1),make_pair(1,2)) == 1.0);
	assert(lenght(make_pair(1,1),make_pair(1,2)) == 1.0);
	assert(lenght(make_pair(1,1),make_pair(2,1)) == 1);
	assert(lenght(make_pair(-1,1),make_pair(2,1)) == 3);
	assert(lenght(make_pair(1,-1),make_pair(1,1)) == 2);
	assert(lenght(make_pair(1,1),make_pair(2,2)) == pow(2,0.5));
	assert(lenght(make_pair(0,0),make_pair(1,3)) == pow(10,0.5));
	assert(lenght(make_pair(-3,12),make_pair(6,8)) == pow(97,0.5));
	cout << "LENGHT IS OK" << endl;
}

void testGetSquare(){
	cout << (0.5 == 0.5) << endl;
	cout << getSquare(make_pair(1,1),make_pair(2,2),make_pair(1,2)) << endl;
	cout << getSquare(make_pair(-1,1),make_pair(8,2),make_pair(1,2)) << endl;
	assert(getSquare(make_pair(1,1),make_pair(2,2),make_pair(1,2)) - 0.5 == 0);
	assert(getSquare(make_pair(-1,1),make_pair(8,2),make_pair(1,2)) == 3.5);
	assert(getSquare(make_pair(1,1),make_pair(2,2),make_pair(1,2)) == 0.5);
	assert(getSquare(make_pair(1,1),make_pair(1,1),make_pair(1,1)) == 0);
	cout << "GETSQUARE IS OK" << endl;
}


int main(){
	//testLenght();
	//testGetSquare();
	vector <pair<int,int>> inputData{4};
	for(int i = 0; i < 4; i++){
		int firstCoord;
		cout << "Input x coord for dot " << i << endl;
		cin >> firstCoord;
		inputData[i].first = firstCoord;
		int secondCoord;
		cout << "Input y coord for dot " << i << endl;
		cin >> secondCoord;
		inputData[i].second = secondCoord;

	}
	pair<int,int> inputDot;
	int firstCoord;
	cout << "Input x coord for single dot" <<endl; 
	cin >> firstCoord;
	inputDot.first = firstCoord;
	int secondCoord;
	cout << "Input y coord for single dot" << endl;
	cin >> secondCoord;
	inputDot.second = secondCoord;
	
	double areaThroughDot = getSquare(inputData[0],inputData[1],inputDot) + getSquare(inputData[1],inputData[2],inputDot) + 
		getSquare(inputData[2],inputData[3],inputDot) + getSquare(inputData[0],inputData[3],inputDot);
	double realArea = getSquare(inputData[0],inputData[1],inputData[2]) + getSquare(inputData[0],inputData[2],inputData[3]);
	
	if(areaThroughDot > realArea){
	    cout << "false" << endl;
	    cout << areaThroughDot << " > " << realArea << endl;
	}
	else{
	    cout << "true" << endl;
	    cout << areaThroughDot << " <= " << realArea << endl;
	}

}
