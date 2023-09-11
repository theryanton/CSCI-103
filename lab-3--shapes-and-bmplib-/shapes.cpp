#include <iostream>
#include <cmath>
#include "bmplib.h"

using namespace std;

// global variable. bad style but ok for this lab
unsigned char image[SIZE][SIZE];

// Fill in this function:
void draw_rectangle(int top, int left, int height, int width) 
{
  //This for loop draws left and right line of the rectangle
  for (int i=top; i<top+height; i++)
  {
    if (i>=0 && i<=255 && left>=0 && left <=255)
    {
      image[i][left]=0; // This draws the left line
    }
    if(i>=0 && i<=255 && left+width>=0 && left+width<=255) 
    {
      image[i][left+width]=0; //This draws the right line
    }
  }
  //This for loop draws top and bottom line of the rectangle
  for (int j=left; j<left+width; j++)
  {
    if (j>=0 && j<=255 && top>=0 && top<=255)
    {
      image[top][j]=0; // This draws the top line
    }
    if (j>=0 && j<= 255 && top+height>=0 && top+height<=255)
    {
      image[top+height][j]=0; // This draws the bottom line
    }
  }
}

// Fill in this function:
void draw_ellipse(int cy, int cx, int height, int width) 
{
  for (double i=0 ; i<2*M_PI; i+=0.01)
  {
    double x = width/2 * cos(i) + cx; // determines how wide and which x values the ellipse is drawn
    double y = height/2 * sin(i) + cy; // determines how long and which y values the ellipse is drawn
    if (x>=0 && x<=255 && y>=0 && y<=255)
    {
      image[(int)y][(int)x] = 0; // cast type as int and draw
    }
  }
}


int main() {
   // initialize the image to all white pixels
   for (int i=0; i < SIZE; i++) {
      for (int j=0; j < SIZE; j++) {
         image[i][j] = 255;
      }
   }
   
   // Main program loop here
    int userinput, x1, x2, x3, x4;
    cout << "To draw a rectangle, enter: 0 top left height width" << endl;
    cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
    cout << "To save your drawing as 'output.bmp' and quit, enter: 2" << endl;
    cin >> userinput;
    
    while (userinput < 2)
    {
      cin >> x1 >> x2 >> x3 >> x4;
      if (userinput == 0)
      {
          draw_rectangle(x1, x2, x3, x4);
      }
      else if (userinput == 1)
      {
        draw_ellipse(x1, x2, x3, x4); 
      }
      cout << "To draw a rectangle, enter: 0 top left height width" << endl;
      cout << "To draw an ellipse, enter: 1 cy cx height width" << endl;
      cout << "To save your drawing as 'output.bmp' and quit, enter: 2" << endl;
      cin >> userinput;
    }
   // Write the resulting image to the .bmp file
   writeGSBMP("output.bmp", image);
   
   return 0;
  }
