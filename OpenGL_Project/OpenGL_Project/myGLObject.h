#pragma once
#include <gl/GL.h>

class myGLObject
{
public:
	myGLObject();
	~myGLObject();
protected:
	//Domy�lny kolor obiektu
	GLfloat objectDefaultColor[4];

	//Domy�lne w�a�ciwo�ci materia�u do o�wietlenia
	

	// Rysuje obiekt na podstawie wewn�trznego stanu klasy
	virtual void Draw() = 0;
public:
	//Settery i Gettery tablicy kolor�w
	void setObjectDefaultColor(GLfloat colorR, GLfloat colorG, GLfloat colorB, GLfloat colorA);
	void setObjDefColorR(GLfloat colorR);
	void setObjDefColorG(GLfloat colorG);
	void setObjDefColorB(GLfloat colorB);
	void setObjDefColorA(GLfloat colorA);
	void getObjectDefaultColor(GLfloat *colorTAB) const;
	GLfloat getObjDefColorR() const;
	GLfloat getObjDefColorG() const;
	GLfloat getObjDefColorB() const;
	GLfloat getObjDefColorA() const;


};

