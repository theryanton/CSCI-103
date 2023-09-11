//This file starts out empty!
//Define the Turtle class here.

#include "draw.h"

class Turtle {
  double x0, y0, dir0;
  Color c0;
  bool start;
  public:
  Turtle(double x1, double y1, double dir1);
  void move(double dist);
  void turn(double deg);
  void setColor(Color c); // change line color that this Turtle draws from now on
  void off(); // make this Turtle stop drawing lines when it moves
  void on(); // make this Turtle resume drawing lines when it moves
};