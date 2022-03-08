/*
	Name: vhbattonya42_B.cpp
	Class: CSC2400
	Author: Victor Hugo Battonyai
	Date: 02/07/2022
    Purpose: GCD (Brute Force)
*/
#include <iostream>
#include <cstdlib>

using namespace std;


//FunctionName: main
//FunctionPurpose: main function
int main(int argc, char *argv[]){

	//Checks number of inputs || If not appropriate, display message
	if(argc!=3){
		cout<<"\n\n\nUsage:   CommandLine.exe m n\n \t(Where m & n are non-zero, non-negative integers)"<<endl;
		return 0;
	}

	int m = atoi(argv[1]); //Assign m equal to first input
	int n = atoi(argv[2]); //Assign n equal to second input
	int originaln; //Define originaln to remember the smaller input

	//Checks If m or n is less then or equal to 0
	if(n<=0 || m<=0) {
		cout<<"\n\ngcd("<<m<<", "<<n<<")"<<"is undefined"<<endl;
	}
	
	//if not, continue...
	else {
		//Checks for the smaller number so that it assignes originaln to it, and flip the variable spots in the function
		if (n<=m) {
			originaln = n;
			gcd(m, n, originaln);
		}
		else {
			originaln = m;
			gcd(n, m, originaln);
		}
	}
	return 0;
}

//FunctionName: gcd
//FunctionPurpose: Recursive function using brute force algorithm to find greatest common divisor.
int gcd(int m, int n, int originaln) {

	//Check if inputs are equal (If so, n or m =GCD)
	if (n == m){
		cout<<"gcd("<< m << ", "<< n <<") = "<< m%n << endl;

		cout << "\n\n\ngcd(" << m << ", " << n << ") is " << n << endl;
		return n;
	}

	//Decrement n
	n= n-1;

	//Displays GCD process
	cout<<"gcd("<< m << ", "<< n <<") = "<< m%n << endl;

	//First GCD check
	if (m % n == 0) {
		//Second GCD check
		if (originaln % n == 0) {
			cout << "\n\n\ngcd(" << m << ", " << n << ") is " << n << endl;
			return n;
		}
		else { 
			cout << "Checked n:";
			cout<<" gcd("<< originaln << ", "<< n <<") is "<< originaln %n << endl;

			//Re-call function
			return gcd(m, n, originaln);
		}
	}
	else {
		//Re-call function
		return gcd(m, n, originaln);
	}

}