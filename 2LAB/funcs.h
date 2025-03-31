using namespace std;
#include <iostream>
#include <array>
#include <cmath>
#include <bitset>
#include <cstdint>
#include <cstring>
#include <map>
#include <stdlib.h>

#ifndef funcs_h
#define funcs_h

void printAsortement();
void showAr(int* ar,int lenght);
int funccmp(const void * val1, const void * val2);
void demonstrationOfQsort();
map <int,double> TableOfConst();
pair <pair<int,double>, pair<int,double>> getInterval (int height,map <int,double> heightByDensity);
double densityByHeight(int height);
template <typename T> double average(int num, T ar);
template <typename T> double sigma(int num, T ar);
double* makeAr(int num,double* ar);
void fibonacci(int num, int nBegin);
template <typename T> void bitInt(T val);
void bitDouble(double val);
void choise();

#endif
