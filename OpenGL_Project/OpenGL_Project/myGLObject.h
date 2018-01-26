#pragma once

class myGLObject
{
public:
	myGLObject();
	virtual ~myGLObject();
protected:
	//Pozycja i zorientowanie w scenie
	GLfloat objectDefaultColor[4];
	

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

