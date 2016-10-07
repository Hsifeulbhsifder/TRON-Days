#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){

	ifstream fin("TwoAxis6d_in.txt");
	if(fin){
		double x[6], y[6], z[6];
		for(int i = 0; i < 0; i++){
			fin >> x[i] >> y[i] >> z[i];
		}

		const double xPos = 0.2;
		const double yPos = 0.2;
		const double zPos = 0;

		cout << "Enter a button number [0, 5]: ";
		int button = 0;
		cin >> button;

		cout << "Initial weight position(x,y,z): (" << xPos << ", " << yPos << ", " << zPos << ")\n";
		cout << "String 1 length: " 
			 << sqrt((x[button] - 0.2) * (x[button] - 0.2) + (y[button] - 0.2) * (y[button] - 0.2) + (3.7 - z[button]) * (3.7 - z[button])) 
			 - sqrt((xPos - 0.2) * (xPos - 0.2) + (yPos - 0.2) * (yPos - 0.2) + (3.7 - zPos) * (3.7 - zPos))
			 << "\nString 2 length: " 
			 << sqrt((x[button] - 3.8) * (x[button] - 3.8) + (y[button] - 0.2) * (y[button] - 0.2) + (3.7 - z[button]) * (3.7 - z[button]))
			 - sqrt((xPos - 3.8) * (xPos - 3.8) + (yPos - 0.2) * (yPos - 0.2) + (3.7 - zPos) * (3.7 - zPos))
			 << "\nString 3 length: " 
			 << sqrt((x[button] - 0.2) * (x[button] - 0.2) + (y[button] - 3.8) * (y[button] - 3.8) + (3.7 - z[button]) * (3.7 - z[button])) 
			 - sqrt((xPos - 0.2) * (xPos - 0.2) + (yPos - 3.8) * (yPos - 3.8) + (3.7 - zPos) * (3.7 - zPos)) << endl;
		cout << "Initial weight position(x,y,z): (" << x[button] << ", " << y[button] << ", " << z[button] << ")\n";
	}else{
		cout << "File not found!" << endl;
	}
}