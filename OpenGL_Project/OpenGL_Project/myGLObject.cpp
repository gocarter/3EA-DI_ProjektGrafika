#include "stdafx.h"
#include "myGLObject.h"


myGLObject::myGLObject()
{
}


myGLObject::~myGLObject()
{
}

void myGLObject::setObjectDefaultColor(GLfloat colorR, GLfloat colorG, GLfloat colorB, GLfloat colorA)
{
	if (colorR >= 0.0 && colorR <= 1.0) objectDefaultColor[0] = colorR;
	else if (colorR < 0.0) objectDefaultColor[0] = 0.0;
	else objectDefaultColor[0] = 1.0;

	if (colorG >= 0.0 && colorG <= 1.0) objectDefaultColor[1] = colorG;
	else if (colorG < 0.0) objectDefaultColor[1] = 0.0;
	else objectDefaultColor[1] = 1.0;

	if (colorB >= 0.0 && colorB <= 1.0) objectDefaultColor[2] = colorB;
	else if (colorB < 0.0) objectDefaultColor[2] = 0.0;
	else objectDefaultColor[2] = 1.0;

	if (colorA >= 0.0 && colorA <= 1.0) objectDefaultColor[3] = colorA;
	else if (colorA < 0.0) objectDefaultColor[3] = 0.0;
	else objectDefaultColor[3] = 1.0;

}

void myGLObject::setObjDefColorR(GLfloat colorR)
{
	if (colorR >= 0.0 && colorR <= 1.0) objectDefaultColor[0] = colorR;
	else if (colorR < 0.0) objectDefaultColor[0] = 0.0;
	else objectDefaultColor[0] = 1.0;
}

void myGLObject::setObjDefColorG(GLfloat colorG)
{
	if (colorG >= 0.0 && colorG <= 1.0) objectDefaultColor[1] = colorG;
	else if (colorG < 0.0) objectDefaultColor[1] = 0.0;
	else objectDefaultColor[1] = 1.0;
}

void myGLObject::setObjDefColorB(GLfloat colorB)
{
	if (colorB >= 0.0 && colorB <= 1.0) objectDefaultColor[2] = colorB;
	else if (colorB < 0.0) objectDefaultColor[2] = 0.0;
	else objectDefaultColor[2] = 1.0;
}

void myGLObject::setObjDefColorA(GLfloat colorA)
{
	if (colorA >= 0.0 && colorA <= 1.0) objectDefaultColor[3] = colorA;
	else if (colorA < 0.0) objectDefaultColor[3] = 0.0;
	else objectDefaultColor[3] = 1.0;
}

void myGLObject::getObjectDefaultColor(GLfloat * colorTAB) const
{
	for (int i = 0; i < 4; ++i) {
		*(colorTAB + i) = objectDefaultColor[i];
	}
}

GLfloat myGLObject::getObjDefColorR() const
{
	return objectDefaultColor[0];
}

GLfloat myGLObject::getObjDefColorG() const
{
	return objectDefaultColor[1];
}

GLfloat myGLObject::getObjDefColorB() const
{
	return objectDefaultColor[2];
}

GLfloat myGLObject::getObjDefColorA() const
{
	return objectDefaultColor[3];
}
