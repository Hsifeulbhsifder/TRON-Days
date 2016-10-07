#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double x1, y1, x2, y2;

	do{
		cout << "Enter x coordinate [0.2, 3.8], then y coordinate [0, 2.7] for 2 points: ";
		cin >> x1 >> y1 >> x2 >> y2;
	} while(x1 < 0.2 || x1 > 3.8 || y1 < 0 || y1 > 2.7 || x2 < 0.2 || x2 > 3.8 || y2 < 0 || y2 > 2.7);

	cout << "Left string extension: " 
		 << sqrt((x2 - 0.2) * (x2 - 0.2) + (2.7 - y2) * (2.7 - y2)) 
		 - sqrt((x1 - 0.2) * (x1 - 0.2) + (2.7 - y1) * (2.7 - y1)) 
		 << "\nRight string extension: " 
		 << sqrt((3.8 - x2) * (3.8 - x2) + (2.7 - y2) * (2.7 - y2)) 
		 - sqrt((3.8 - x1) * (3.8 - x1) + (2.7 - y1) * (2.7 - y1)) << endl;

}