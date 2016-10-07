#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double x, y;

	do{
		cout << "Enter x coordinate [0.2, 3.8], then y coordinate [0, 2.7]: ";
		cin >> x >> y;
	} while(x < 0.2 || x > 3.8 || y < 0 || y > 2.7);

	cout << "Left string length: " 
		 << sqrt((x - 0.2) * (x - 0.2) + (2.7 - y) * (2.7 - y)) 
		 << "\nRight string length: " 
		 << sqrt((3.8 - x) * (3.8 - x) + (2.7 - y) * (2.7 - y)) << endl;

}