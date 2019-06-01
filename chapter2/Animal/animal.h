
#ifndef ANIMAL_H
#define ANIMAL_H

class animal
{
public:
	animal(); 
	~animal(); 
	void eat(); 
	void sleep(); 
	virtual void breathe(); 
}; 

#endif