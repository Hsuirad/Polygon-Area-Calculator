#include <cstdlib> // this is for the screen clearing
#include <iostream> // basic input output of program
#include <array> // this is for .size()

using namespace std;

// function declration
int calcArea(int matrix[][2], int rows);

int main(){

	int side_num; //will hold the value for number of sides of the polygon

	cout << "~~~~~~~~~~~~ POLYGON SOlVER v1.0 ~~~~~~~~~~~~" << endl << "Please input the number of sides of your polygon: "; // just words
	cin >> side_num; // filling side length variable with a value
	cout << "Now please enter " << side_num * 2 << " space-separated clockwise ordered pairs of the polygon \n"; // more words

	int matrix[side_num][2]; //this will hold the matrices of the polygon with side_num number of rows and 2 columns each

	// filling the 2d array with input values
	for(int i = 0; i < side_num; i++){
		for(int j = 0; j < 2; j++){
			cin >> matrix[i][j];
		}
	}

	// filling the area variable by calling a offsite calcArea function below
	int area = calcArea(matrix, side_num);

	// the only useful part of the program
	cout << "\nThe area of the polygon is: " << area << endl;

	// returns 0
	return 0;
}

// pass by reference to easily mutate the two dimensional array
int calcArea(int matrix[][2], int rows){
	// initializing a variable that will be filled and returned
	int area = 0;

	// this is where the matrix multiplication will take place, sizeof... finds row numbers of size
	for(int i = 0; i < rows; i++){
		// matrix multiplication
		// ternary operator which does the work of the normal if else statement
		i == (rows - 1) ? area += (matrix[i][0] * matrix[0][1] - matrix[i][1] * matrix[0][0]) :
						  area += (matrix[i][0] * matrix[i + 1][1]) - (matrix[i][1] * matrix[i + 1][0]);
	}

	// returns the variable filled above, with the last part of the polygon side math
	return (area / 2);
}
