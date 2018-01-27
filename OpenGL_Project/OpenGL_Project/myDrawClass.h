#pragma once
#include <gl/GL.h>
#include <gl/GLU.h>

#define BITMAP_ID 0x4D42		// identyfikator formatu BMP
#define GL_PI 3.14159


class myDrawClass
{
private:
	HPALETTE hPalette = NULL;						// Color Palette handle

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
	void ReduceToUnit(float vector[3]);
	void calcNormal(float v[3][3], float out[3]);
	void ChangeSize(GLsizei w, GLsizei h);
	void SetupRC();
	unsigned char *LoadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader);
	void SetDCPixelFormat(HDC hDC);
	HPALETTE GetOpenGLPalette(HDC hDC);
	void RenderScene(void);

public:
	myDrawClass();
	~myDrawClass();
};

