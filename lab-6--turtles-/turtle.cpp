//This file also starts out empty.
//Implement the Turtle class here.

#include "turtle.h"
// #include "draw.h"
#include <cmath>

Turtle::Turtle(double x1, double y1, double dir1)
{
  x0 = x1;
  y0 = y1;
  dir0 = dir1;
  c0 = draw::BLACK;
  start = true;
}

void Turtle::turn(double deg)
{
  dir0 += deg;
}

void Turtle::move(double dist)
{
  double x1, y1;
  x1 = x0;
  y1 = y0;

  x1 += dist * cos(dir0 * (M_PI/180));
  y1 += dist * sin(dir0 * (M_PI/180));
  if (start == true)
  {
    draw::setcolor(c0);
    draw::line(x0, y0, x1, y1);
  }
  x0 = x1;
  y0 = y1;
}

void Turtle::setColor(Color c)
{
  c0 = c;
}

void Turtle::off()
{
  start = false;
}

void Turtle::on()
{
  start = true;
}