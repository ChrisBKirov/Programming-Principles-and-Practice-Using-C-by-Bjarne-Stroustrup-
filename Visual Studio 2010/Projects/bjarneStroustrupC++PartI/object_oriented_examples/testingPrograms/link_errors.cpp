/* 
   TITLE	       Link-time Errors	     comp_errors.cpp
   COMMENT
 		Objective: Test compiler response to link errors.
 			Input: -
 		   Output: Compile error response.
		   Author: Chris B. Kirov
		     Date: 01.01.2015
*/
#include "../../std_lib_facilities.h"

// calculates the area of rectangle;
int area(int lenght, int width) {
	if (lenght <= 0 || width <= 0) return -1;
	return lenght*width;
}

// calculates a framed area
int framed_area(int x, int y){
	const int frame_width = 2;
	if (x - frame_width <= 0 || y - frame_width <= 0) return -1;
		return area(x - frame_width, y - frame_width);
}
// wrong declaration: same name, different types(returning and parameter)
// double area(double x, double y); 
// wrong declararion: same name, more parameters than defined
// int area(int x, int y, char z);	 
 
int main(){
	// If the function: area is not defined in other file and the code generated by it not linked to this file => LINK ERROR
	// Function call with wrong return type: double
	//int x = area(2, 3);		
	//double y = area(2, 3);	
	int area1 = area(1, -1);	                    // Error: invalid input values 
	double ratio = double(area(2, 2)) / area(0, 4);	// Error: invalid input values
	int area2 = framed_area(4, 4);
	
	if (area1 == -1 || area2 == -1){
		cout << "Invalid input values!" << endl;
	}else{
		cout << "Area1 = " << area1 << endl;
		cout << "Area2 = " << area2 << endl;
		cout << "Ratio = " << ratio << endl;
	}
	return 0;
}