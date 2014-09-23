#ifndef MY_LINE
#define MY_LINE

#include <GL/glut.h>
#include <cmath>
#include <exception>

class myexception : public std::exception{
	const char* e;
public:
	myexception(const char* a)  throw(){
		e = a;
	}
	
	virtual const char* what() const throw()
	{
		return e;
	}
	virtual ~myexception() throw(){}
};

class myLine{
	GLint pontok[2][2];
	double length;

public:
	myLine(int x1, int y1, int x2, int y2){
		pontok[0][0] = x1;
		pontok[0][1] = y1;
		pontok[1][0] = x2;
		pontok[1][1] = y2;
	}

	GLint getPoints(int i){
		if (i >= 0 && i < 4){
			switch (i){
			case 0:
				return pontok[0][0];
				break;
			case 1:
				return pontok[0][1];
				break;
			case 2:
				return pontok[1][0];
				break;
			case 3:
				return pontok[1][1];
				break;
			}
		}
		else
			throw myexception("Wrong arraynumber");
	}

	void display(){
		glBegin(GL_LINES);
		glVertex2i(pontok[0][0], pontok[0][1]);
		glVertex2i(pontok[1][0], pontok[1][1]);
		glEnd();
	
	}

	double getLength(){
		length = std::pow(std::abs(pontok[1][0] - pontok[0][0]),2) + std::pow(std::abs(pontok[1][1] - pontok[0][1]),2);
		return std::sqrt(length);
	}

};


#endif