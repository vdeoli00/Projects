/*
	Name: vhbattonya42_A.cpp
	Class: CSC2400
	Author: Victor Hugo Battonyai
	Date: 02/07/2022
    Purpose: GCD (Euclids Algorithm)
*/
#include <iostream>
#include <cstdlib>

using namespace std;


//FunctionName: main
//FunctionPurpose: main function
int main(int argc, char *argv[]) {

	//Checks number of inputs || If not appropriate, display message
	if(argc != 3) {
		cout<<"\n\n\nUsage:   CommandLine.exe m n\n \t(Where m & n are non-zero, non-negative integers)"<<endl;
		return 0;
	}

	int m=stoi(argv[1]);//Assign m equal to first input
	int n=stoi(argv[2]);//Assign n equal to second input


	//Checks If m or n is less then or equal to 0
	if (m <= 0 || n <= 0) {
		cout<<"gcd("<<m<<", "<<n<<")"<<"is undefined"<<endl;
	}
	//If not, Continue...
	else {
		cout << "gcd("<< m <<", "<< n << ") ="<<endl;
		int answer = gcd(n, m);

		//Display the last line
		cout << "\n\n\ngcd(" << m << ", " << n << ") is " << answer << endl;
	}
	

	return 0;
}


//FunctionName: gcd
//FunctionPurpose: Recursive function using Euclids algorithm to find greatest common divisor.
int gcd (int m, int n) {

	//Checks if recursive function is done (Exit statement within)
	if (m == 0) {
	//Exit recursive function
		return n;
	}

	//Check if inputs are equal (If so, n or m =GCD)
	else if (m == n) {
		return n;
	}

	//Recursive function not yet complete, cycle through it once again
	else {
		//Displays Euclids algorithm in motion
		cout<<"gcd("<< m <<", ("<< n << "%"<< m <<")) ="<<endl;
		//Calls recursive function once again
		return gcd(n % m, m);
	}
}
