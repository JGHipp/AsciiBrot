/*
	Mandelbrot Set Renderer
	Written by John G. Hippisley
	November 2020
*/

#include <iostream>
#include <cstdlib>
#include <cstring>

// Character buffer
int bufferWidth = 120, bufferHeight = 40;
double bufferScale = 1.0;
char* buffer;

inline void setCharacter(int x, int y, char c){ buffer[x + y * bufferWidth] = c; }
inline char getCharacter(int x, int y){ return buffer[x + y * bufferWidth]; }

void printBuffer()
{	
	for(int y = 0; y < bufferHeight; y++) 
	{
		for(int x = 0; x < bufferWidth; x++) std::cout << getCharacter(x, y);
		std::cout << std::endl;
	}
}

// Complex number implementation
typedef struct complexNumber
{
	double r, i;
} cnum;

void printInum(cnum num){ std::cout << "(" << num.r << (num.i < 0 ? " - " : " + ") << (num.i < 0 ? -num.i : num.i) << "i)"; }
cnum addInums(cnum a, cnum b) { return cnum { a.r + b.r, a.i + b.i }; }
cnum mulInums(cnum a, cnum b) { return cnum { a.r * b.r - a.i * b.i, a.r * b.i + b.r * a.i }; }

// Default values
cnum topLeft = {-2, 1}, bottomRight = {1, -1};
int maxIterations = 150;

// Determines how many iterations clx can be iterated through before escaping to > 2.0
int nIterations(int maxIterations, cnum clx)
{
	cnum z = {0, 0};
	int iterations;
	for(iterations = 0; iterations < maxIterations && z.r <= 2; iterations++) z = addInums(mulInums(z, z), clx);
	return iterations;
}

// Maps iterations to a gray-scale character map
char iterationToChar(int iterations, int maxIterations)
{
	const char charMap[] = " .'`^\",:;Il!i><~+_-?][}{1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao*#MW&8%B@$";
	const int nChars = 70;
	double ratio = (double) (nChars - 1) / (double) maxIterations;
	int index = (int) ((double) iterations * ratio);
	return charMap[index];
}

// Render the Mandelbrot set!
void renderSet(int maxIterations, cnum topLeft, cnum bottomRight)
{
	std::cout << "Top left corner: "; printInum(topLeft); 
	std::cout << ", bottom right corner: "; printInum(bottomRight); 
	std::cout << std::endl;
	double rStep = (bottomRight.r - topLeft.r) / bufferWidth;
	double iStep = (bottomRight.i - topLeft.i) / bufferHeight;
	for(int y = 0; y < bufferHeight; y++)
	{
		for(int x = 0; x < bufferWidth; x++)
		{
			cnum clx = {topLeft.r + (double) x * rStep, topLeft.i + (double) y * iStep};
			setCharacter(x, y, iterationToChar(nIterations(maxIterations, clx), maxIterations));
		}
	}
}

template <typename T>
inline void inputVar(const char* msg, T& ref) { std::cout << msg; std::cin >> ref; }

// Executed if '-D' option is specified
void dialogue()
{
	std::cout << "Running in dialogue mode." << std::endl;
	char yn;
	inputVar("Use pre-set view plane values (encompases the whole Mandelbrot set)? [Y/N]: ", yn);
	if(toupper(yn) == 'N')
	{
		double tlr, tli, brr, bri;
		std::cout << "Enter dimensions of view plane." << std::endl;
		inputVar("Top left corner:\n  Real: ", tlr);
		inputVar("  Imaginery: ", tli);
		inputVar("Bottom right corner:\n  Real: ", brr);
		inputVar("  Imaginery: ", bri);
		topLeft = {tlr, tli};
		bottomRight = {brr, bri};
		if(tlr > brr)
			std::cout << "The real component of the top-left corner is less than the bottom-right! Still rendering..." << std::endl;
		else if(tli < bri)
			std::cout << "The imaginary component of the top-left corner is less than the bottom-right! Still rendering..." 
				<< std::endl;
	}
	inputVar("Enter the maximum number of iterations: ", maxIterations);
	inputVar("Enter the bufferScale of the view, defaulted at 120x40 (Ex. 1.0): ", bufferScale);
}

void usage()
{
	std::cout << "Usage: ./mandelbrot [-h] [-D] [-i iterations] [-d width height] [-s bufferScale] min_real max_imaginary "
				 "max_real min_imaginary\n	Outputs the Mandelbrot set from the top-left corner [min_real + max_imaginary("
				 "i)] to [max_real + min_imaginary(i)].\n	Default: (-2 + 1i) to (1 -1i).\n	-h	Displays this usage.\n"
				 "	-D	Dialogue mode. All other arguments are ignored.\n	-i	Specifies the max number of iterations. De"
				 "fault is 150.\n	-d	Specifies the dimensions of the character view plane. Default is 120x40.\n	-s	Sp"
				 "ecifies a scale to be applied to the view (Ex. 1.0, 1.3).\n";
	exit(0);
}

int main(int argc, char* argv[])
{
	if(argc > 1 && !strcmp(argv[1], "-h")) usage();
	else if(argc > 1 && !strcmp(argv[1], "-D")) dialogue();
	else
	{
		// Parse command-line arguments
		int vdptr = 0;
		double viewData[4] = { topLeft.r, topLeft.i, bottomRight.r, bottomRight.i };
		for(int i = 1; i < argc; i++)
		{
			if(!strcmp(argv[i], "-i") && (i + 1) < argc) maxIterations = atoi(argv[i++ + 1]);
			else if(!strcmp(argv[i], "-s") && (i + 1) < argc) bufferScale = (double) atof(argv[i++ + 1]);
			else if(!strcmp(argv[i], "-d") && (i + 2) < argc)
			{
				bufferWidth = atoi(argv[i + 1]);
				bufferHeight = atoi(argv[i + 2]);
				i += 2;	
			}
			else
			{
				if(vdptr > 3) usage();
				else viewData[vdptr++] = (double) atof(argv[i]);
			}
		}
		topLeft = {viewData[0], viewData[1]};
		bottomRight = {viewData[2], viewData[3]};
		std::cout << "View dimensions: " << bufferWidth << "x" << bufferHeight << " chars (scale factor: " << bufferScale << ")" 
			<< std::endl;
		std::cout << "Max. iterations: " << maxIterations << std::endl;
	}
	bufferWidth *= bufferScale;
	bufferHeight *= bufferScale;
	buffer = new char[bufferWidth * bufferHeight]; 
	renderSet(maxIterations, topLeft, bottomRight);
	printBuffer();
	delete buffer;
}
