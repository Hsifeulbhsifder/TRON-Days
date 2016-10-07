#include <iostream>
#include <cmath>

using namespace std;

int main(){
	double x, y, z;

	do{
		cout << "Enter x coordinate [0.2, 3.8], then y coordinate [0.2, 3.8], then z coordinate [0, 3.7]: ";
		cin >> x >> y >> z;
	} while(x < 0.2 || x > 3.8 || y < 0.2 || y > 3.8 || z < 0 || z > 3.7 || (x + y) > 4.0);

	cout << "String 1 length: " 
		 << sqrt((x - 0.2) * (x - 0.2) + (y - 0.2) * (y - 0.2) + (3.7 - z) * (3.7 - z)) 
		 << "\nString 2 length: " 
		 << sqrt((x - 3.8) * (x - 3.8) + (y - 0.2) * (y - 0.2) + (3.7 - z) * (3.7 - z))
		 << "\nString 3 length: " 
		 << sqrt((x - 0.2) * (x - 0.2) + (y - 3.8) * (y - 3.8) + (3.7 - z) * (3.7 - z)) << endl;

}