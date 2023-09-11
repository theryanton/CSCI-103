#ifndef BMPLIB_H
#define BMPLIB_H

const int SIZE = 256;
const int RGB = 3;
const int THRESHOLD = 40;
// Note: the read-write functions return 0 on success, 1 on error.

// read grayscale image from the file specified by filename, into inputImage
int readGSBMP(const char filename[], unsigned char image[][SIZE]);

// write grayscale image to the file specified by filename, from outputImage
int writeGSBMP(const char filename[], unsigned char outputImage[][SIZE]);

int writeGSBMP(const char filename[], unsigned char **outputImage,int height,int width);

// display grayscale image with eog, pause 0.2 seconds. (uses a temp file)
void showGSBMP(unsigned char inputImage[][SIZE]);

// read full-color image from the file specified by filename, into inputImage
int readRGBBMP(const char filename[], unsigned char inputImage[][SIZE][RGB]);

// read full-color image from the file specified by filename, into inputImage
unsigned char ***readRGBBMP(const char filename[],int *height,int *width);

// write full-color image to the file specified by filename, from outputImage
int writeRGBBMP(const char filename[], unsigned char outputImage[][SIZE][RGB]);

int writeRGBBMP(const char filename[], unsigned char ***outputImage,int height,int width);

// display full-color image with eog, pause 0.2 seconds. (uses a temp file)
void showRGBBMP(unsigned char inputImage[][SIZE][RGB]);

int writeBinary(const char filename[], unsigned char **outputImage,int height,int width);




#endif