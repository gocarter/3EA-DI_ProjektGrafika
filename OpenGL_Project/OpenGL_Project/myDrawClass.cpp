#include "stdafx.h"
#include "myDrawClass.h"
#include <math.h>
#include <stdio.h>



myDrawClass::myDrawClass()
{
}


myDrawClass::~myDrawClass()
{
}


/* MyCode
Function:
Reduces a normal vector specified as a set of three coordinates,
to a unit normal vector of length one.
*/
void myDrawClass::reduceToUnit(GLfloat vector[3])
{
	float length;

	// Calculate the length of the vector		
	length = (float)sqrt((vector[0] * vector[0]) +
		(vector[1] * vector[1]) +
		(vector[2] * vector[2]));

	// Keep the program from blowing up by providing an exceptable
	// value for vectors that may calculated too close to zero.
	if (length == 0.0f)
		length = 1.0f;

	// Dividing each element by the length will result in a
	// unit normal vector.
	vector[0] /= length;
	vector[1] /= length;
	vector[2] /= length;
}
//=====================================================================

/* MyCode
Function is calculating Normal Vector for 3 points surface.
Points p1, p2, p3 specified in counter clock-wise order.
*/
void myDrawClass::calcNormal(GLfloat v[3][3], GLfloat out[3])
{
	float v1[3], v2[3];
	static const int x = 0;
	static const int y = 1;
	static const int z = 2;

	// Calculate two vectors from the three points
	v1[x] = v[0][x] - v[1][x];
	v1[y] = v[0][y] - v[1][y];
	v1[z] = v[0][z] - v[1][z];

	v2[x] = v[1][x] - v[2][x];
	v2[y] = v[1][y] - v[2][y];
	v2[z] = v[1][z] - v[2][z];

	// Take the cross product of the two vectors to get
	// the normal vector which will be stored in out
	out[x] = v1[y] * v2[z] - v1[z] * v2[y];
	out[y] = v1[z] * v2[x] - v1[x] * v2[z];
	out[z] = v1[x] * v2[y] - v1[y] * v2[x];

	// Normalize the vector (shorten length to one)
	this->reduceToUnit(out);
}
//====================================================================

/* My Code
Function:
Change viewing volume and viewport.  Called when window is resized
*/
void myDrawClass::changeSize(GLsizei w, GLsizei h)
{
	GLfloat nRange = 100.0f;
	GLfloat fAspect;
	// Prevent a divide by zero
	if (h == 0)
		h = 1;

	lastWidth = w;
	lastHeight = h;

	fAspect = (GLfloat)w / (GLfloat)h;
	// Set Viewport to window dimensions
	glViewport(0, 0, w, h);

	// Reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)
	if (w <= h)
		glOrtho(-nRange, nRange, -nRange * h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange * w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);

	// Establish perspective: 
	/*
	gluPerspective(60.0f,fAspect,1.0,400);
	*/

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void myDrawClass::startAnimation()
{
}
void myDrawClass::stopAnimation()
{
}
void myDrawClass::cameraApi(char KEY)
{
}
void myDrawClass::animationTick()
{
}
//============================================================================

/* MyCode
This function does any needed initialization on the rendering
context and class specific things.  Here it sets up and initializes the lighting for
the scene.
*/
void myDrawClass::initDrawClass(HWND hWnd)
{
	// Store the device context
	hDC = GetDC(hWnd);

	// Select the pixel format
	setDCPixelFormat(hDC);

	// Create palette if needed
	hPalette = getOpenGLPalette(hDC);

	// Create the rendering context and make it current
	hRC = wglCreateContext(hDC);
	wglMakeCurrent(hDC, hRC);

/*
Inicjalizacja parametrów renderowania OpenGL
*/
// Light values and coordinates
	//GLfloat  ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
	//GLfloat  diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
	//GLfloat  specular[] = { 1.0f, 1.0f, 1.0f, 1.0f};
	//GLfloat	 lightPos[] = { 0.0f, 150.0f, 150.0f, 1.0f };
	//GLfloat  specref[] =  { 1.0f, 1.0f, 1.0f, 1.0f };


	glEnable(GL_DEPTH_TEST);	// Hidden surface removal
	glFrontFace(GL_CCW);		// Counter clock-wise polygons face out
	//glEnable(GL_CULL_FACE);		// Do not calculate inside of jet

// Enable lighting
	//glEnable(GL_LIGHTING);

// Setup and enable light 0
	//glLightfv(GL_LIGHT0,GL_AMBIENT,ambientLight);
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,diffuseLight);
	//glLightfv(GL_LIGHT0,GL_SPECULAR,specular);
	//glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
	//glEnable(GL_LIGHT0);

// Enable color tracking
	//glEnable(GL_COLOR_MATERIAL);

// Set Material properties to follow glColor values
	//glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

// All materials hereafter have full specular reflectivity with a high shine
	//glMaterialfv(GL_FRONT, GL_SPECULAR,specref);
	//glMateriali(GL_FRONT,GL_SHININESS,128);


// White background
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

// Black brush
	glColor3f(0.0, 0.0, 0.0);

/*
Wczytywanie tekstur
*/
	glGenTextures(2, &texture[0]);                  // tworzy obiekt tekstury			

	SetTimer(hWnd, 101, 200, NULL);
	// ³aduje pierwszy obraz tekstury:
	bitmapData = loadBitmapFile("Bitmapy\\checker.bmp", &bitmapInfoHeader);

	glBindTexture(GL_TEXTURE_2D, texture[0]);       // aktywuje obiekt tekstury

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// tworzy obraz tekstury
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

	if (bitmapData)
		free(bitmapData);

	// ³aduje drugi obraz tekstury:
	bitmapData = loadBitmapFile("Bitmapy\\crate.bmp", &bitmapInfoHeader);
	glBindTexture(GL_TEXTURE_2D, texture[1]);       // aktywuje obiekt tekstury

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// tworzy obraz tekstury
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, bitmapInfoHeader.biWidth,
		bitmapInfoHeader.biHeight, 0, GL_RGB, GL_UNSIGNED_BYTE, bitmapData);

	if (bitmapData)
		free(bitmapData);

	// ustalenie sposobu mieszania tekstury z t³em
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	SetTimer(hWnd, 101, 40, NULL);

}
//==========================================================================

/* MyCode
Function is loading bitmap and return pointer to it.
It is also fills headings stucture.
Does not support 8-bit bitmaps.
*/
unsigned char *myDrawClass::loadBitmapFile(char *filename, BITMAPINFOHEADER *bitmapInfoHeader)
{
	FILE **filePtr = NULL;						// wskaźnik pozycji pliku
	BITMAPFILEHEADER	bitmapFileHeader;		// nagłówek pliku
	unsigned char		*bitmapImage;			// dane obrazu
	int					imageIdx = 0;			// licznik pikseli
	unsigned char		tempRGB;				// zmienna zamiany składowych

// Otwiera plik w trybie "read binary"
	if (fopen_s(filePtr, filename, "rb")) return NULL;

// Wczytuje nagłówek pliku
	fread(&bitmapFileHeader, sizeof(BITMAPFILEHEADER), 1, *filePtr);

// Sprawdza, czy jest to plik formatu BMP
	if (bitmapFileHeader.bfType != BITMAP_ID)
	{
		fclose(*filePtr);
		return NULL;
	}

// Wczytuje nagłówek obrazu
	fread(bitmapInfoHeader, sizeof(BITMAPINFOHEADER), 1, *filePtr);

// ustawia wskaŸnik pozycji pliku na pocz¹tku danych obrazu
	fseek(*filePtr, bitmapFileHeader.bfOffBits, SEEK_SET);

// przydziela pamiêæ buforowi obrazu
	bitmapImage = (unsigned char*)malloc(bitmapInfoHeader->biSizeImage);

// sprawdza, czy uda³o siê przydzieliæ pamiêæ
	if (!bitmapImage)
	{
		free(bitmapImage);
		fclose(*filePtr);
		return NULL;
	}

// wczytuje dane obrazu
	fread(bitmapImage, 1, bitmapInfoHeader->biSizeImage, *filePtr);

// sprawdza, czy dane zosta³y wczytane
	if (bitmapImage == NULL)
	{
		fclose(*filePtr);
		return NULL;
	}

// zamienia miejscami sk³adowe R i B 
	for (imageIdx = 0; imageIdx < bitmapInfoHeader->biSizeImage; imageIdx += 3)
	{
		tempRGB = bitmapImage[imageIdx];
		bitmapImage[imageIdx] = bitmapImage[imageIdx + 2];
		bitmapImage[imageIdx + 2] = tempRGB;
	}

// zamyka plik i zwraca wskaŸnik bufora zawieraj¹cego wczytany obraz
	fclose(*filePtr);
	return bitmapImage;
}
//=============================================================================

/* MyCode
Called to draw scene
*/
void myDrawClass::renderScene(void)
{
	//float normal[3];	// Storeage for calculated surface normal

	// Clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Save the matrix state and do the rotations
	glPushMatrix();
	glRotatef(xRot, 1.0f, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	/////////////////////////////////////////////////////////////////
	// MIEJSCE NA KOD OPENGL DO TWORZENIA WLASNYCH SCEN:		   //
	/////////////////////////////////////////////////////////////////

	//Sposób na odróŸnienie "przedniej" i "tylniej" œciany wielok¹ta:
	//glPolygonMode(GL_BACK,GL_LINE);

	//Uzyskanie siatki:
	glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	//Wyrysowanie prostokata:
	//glRectd(-10.0,-10.0,20.0,20.0);
	//ramie(30, 15, 10, 30);
	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);

	// Flush drawing commands
	glFlush();
}
//==========================================================================

/* MyCode
Select the pixel format for a given device context
*/
void myDrawClass::setDCPixelFormat(HDC hDC)
{
	int nPixelFormat;

	static PIXELFORMATDESCRIPTOR pfd = {
		sizeof(PIXELFORMATDESCRIPTOR),			// Size of this structure
		1,                                      // Version of this structure    
		PFD_DRAW_TO_WINDOW |                    // Draw to Window (not to bitmap)
		PFD_SUPPORT_OPENGL |					// Support OpenGL calls in window
		PFD_DOUBLEBUFFER,                       // Double buffered
		PFD_TYPE_RGBA,                          // RGBA Color mode
		24,                                     // Want 24bit color 
		0,0,0,0,0,0,                            // Not used to select mode
		0,0,                                    // Not used to select mode
		0,0,0,0,0,                              // Not used to select mode
		32,                                     // Size of depth buffer
		0,                                      // Not used to select mode
		0,                                      // Not used to select mode
		PFD_MAIN_PLANE,                         // Draw in main plane
		0,                                      // Not used to select mode
		0,0,0 };                                // Not used to select mode

// Choose a pixel format that best matches that described in pfd
	nPixelFormat = ChoosePixelFormat(hDC, &pfd);

// Set the pixel format for the device context
	SetPixelFormat(hDC, nPixelFormat, &pfd);
}
//=======================================================================

/* MyCode
If necessary, creates a 3-3-2 palette for the device context listed.
*/
HPALETTE myDrawClass::getOpenGLPalette(HDC hDC)
{
	HPALETTE hRetPal = NULL;	// Handle to palette to be created
	PIXELFORMATDESCRIPTOR pfd;	// Pixel Format Descriptor
	LOGPALETTE *pPal;			// Pointer to memory for logical palette
	int nPixelFormat;			// Pixel format index
	int nColors;				// Number of entries in palette
	int i;						// Counting variable
	BYTE RedRange, GreenRange, BlueRange;
	// Range for each color entry (7,7,and 3)


	// Get the pixel format index and retrieve the pixel format description
	nPixelFormat = GetPixelFormat(hDC);
	DescribePixelFormat(hDC, nPixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pfd);

	// Does this pixel format require a palette?  If not, do not create a
	// palette and just return NULL
	if (!(pfd.dwFlags & PFD_NEED_PALETTE))
		return NULL;

	// Number of entries in palette.  8 bits yeilds 256 entries
	nColors = 1 << pfd.cColorBits;

	// Allocate space for a logical palette structure plus all the palette entries
	pPal = (LOGPALETTE*)malloc(sizeof(LOGPALETTE) + nColors * sizeof(PALETTEENTRY));

	// Fill in palette header 
	pPal->palVersion = 0x300;		// Windows 3.0
	pPal->palNumEntries = nColors; // table size

								   // Build mask of all 1's.  This creates a number represented by having
								   // the low order x bits set, where x = pfd.cRedBits, pfd.cGreenBits, and
								   // pfd.cBlueBits.  
	RedRange = (1 << pfd.cRedBits) - 1;
	GreenRange = (1 << pfd.cGreenBits) - 1;
	BlueRange = (1 << pfd.cBlueBits) - 1;

	// Loop through all the palette entries
	for (i = 0; i < nColors; i++)
	{
		// Fill in the 8-bit equivalents for each component
		pPal->palPalEntry[i].peRed = (i >> pfd.cRedShift) & RedRange;
		pPal->palPalEntry[i].peRed = (unsigned char)(
			(double)pPal->palPalEntry[i].peRed * 255.0 / RedRange);

		pPal->palPalEntry[i].peGreen = (i >> pfd.cGreenShift) & GreenRange;
		pPal->palPalEntry[i].peGreen = (unsigned char)(
			(double)pPal->palPalEntry[i].peGreen * 255.0 / GreenRange);

		pPal->palPalEntry[i].peBlue = (i >> pfd.cBlueShift) & BlueRange;
		pPal->palPalEntry[i].peBlue = (unsigned char)(
			(double)pPal->palPalEntry[i].peBlue * 255.0 / BlueRange);

		pPal->palPalEntry[i].peFlags = (unsigned char)NULL;
	}


	// Create the palette
	hRetPal = CreatePalette(pPal);

	// Go ahead and select and realize the palette for this device context
	SelectPalette(hDC, hRetPal, FALSE);
	RealizePalette(hDC);

	// Free the memory used for the logical palette structure
	free(pPal);

	// Return the handle to the new palette
	return hRetPal;
}
//==========================================================================
