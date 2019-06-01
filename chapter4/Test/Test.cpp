// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream.h>


class Point
{
public:
	void output()
	{
		init(); 
        //x = y = 0; 
	}

	static void init()
	{
        //x = y = 0; 
	}

private:
	static int x, y; 
}; 

//int Point::x = 0; 
//int Point::y = 0; 

int main(int argc, char* argv[])
{
	Point pt; 
    pt.init(); 
    pt.output(); 

    //Point::init(); 
    //Point::output(); 

	//Point::init(); 
	return 0;
}
