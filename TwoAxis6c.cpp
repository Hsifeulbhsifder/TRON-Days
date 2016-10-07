#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

int main(){

	ifstream fin("TwoAxis6c_in.txt");

	if(fin){
		double x1, y1, x2, y2;
		fin >> x1 >> y1;
		cout << "Initial left string length: " 
			 << sqrt((x1 - 0.2) * (x1 - 0.2) + (2.7 - y1) * (2.7 - y1)) 
			 << "\nInitial right string length: " 
			 << sqrt((3.8 - x1) * (3.8 - x1) + (2.7 - y1) * (2.7 - y1)) << endl;
		while(fin >> x2 >> y2){
			cout << "\nLeft string extension: " 
				 << sqrt((x2 - 0.2) * (x2 - 0.2) + (2.7 - y2) * (2.7 - y2)) 
				 - sqrt((x1 - 0.2) * (x1 - 0.2) + (2.7 - y1) * (2.7 - y1)) 
				 << "\nRight string extension: " 
				 << sqrt((3.8 - x2) * (3.8 - x2) + (2.7 - y2) * (2.7 - y2)) 
				 - sqrt((3.8 - x1) * (3.8 - x1) + (2.7 - y1) * (2.7 - y1)) 
				 << "\nNew left string length: " 
				 << sqrt((x2 - 0.2) * (x2 - 0.2) + (2.7 - y2) * (2.7 - y2)) 
				 << "\nInitial right string length: " 
				 << sqrt((3.8 - x2) * (3.8 - x2) + (2.7 - y2) * (2.7 - y2)) << endl;
			fin >> x1 >> x2;
		}
	} else{
		cout << "File not found!" << endl;
	}
}