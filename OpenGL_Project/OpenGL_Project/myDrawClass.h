#pragma once
#include <gl/GL.h>
#include <gl/GLU.h>

#define BITMAP_ID 0x4D42		// identyfikator formatu BMP
#define GL_PI 3.1415926535898
#define glRGB(x, y, z)	glColor3f((GLfloat)x, (GLfloat)y, (GLfloat)z)
extern HPALETTE hPalette;					// Color Palette handle
extern HGLRC hRC;							// Permenant Rendering context
extern HDC hDC;								// Private GDI Device context

class myDrawClass
{
private:

// Rotation amounts
	GLfloat xRot; // = 0.0f;
	GLfloat yRot; // = 0.0f;

	GLsizei lastHeight;
	GLsizei lastWidth;


// Opis tekstury
	BITMAPINFOHEADER	bitmapInfoHeader;	// nag³ówek obrazu
	unsigned char*		bitmapData;			// dane tekstury
	unsigned int		texture[2];			// obiekt tekstury

//metody
	void reduceToUnit(GLfloat vector[3]);
	void calcNormal(GLfloat v[3][3], GLfloat out[3]);
	unsigned char *loadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
	void setDCPixelFormat(HDC hDC);
	HPALETTE getOpenGLPalette(HDC hDC);

public:
	void renderScene(void);
	void initDrawClass(HWND hWnd);
	void changeSize(GLsizei w, GLsizei h);
	void startAnimation();
	void stopAnimation();
	void cameraApi(char KEY);


	myDrawClass();
	~myDrawClass();
};

