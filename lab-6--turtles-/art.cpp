#include "turtle.h"
#include "draw.h"

int main() {
   draw::setpenwidth(10); // thick lines
   draw::setrange(-100, 100);
   // get in position

   Turtle t1(20, 40, 60);
   Turtle t2(10, 10, 10);
   Turtle t3(15, 7, 45);
   Turtle t4(1, 2, 3);

  t1.setColor(draw::ORANGE);
  for(int i=0; i<8; i++)
  {
      t1.turn(20+i);
      t1.move(i);
      draw::show(50);
      t1.turn(100-i);
      t1.move(65);
      draw::show(50);
   }
  t2.setColor(draw::MAGENTA);
  for(int i=0; i<4; i++)
  {
      t2.turn(20+i);
      t2.move(16);
      draw::show(50);
      t2.turn(60);
      t2.move(65);
      draw::show(50);
      t2.turn(25);
      t2.move(20);
      draw::show(50);
      t2.turn(30);
      t2.move(45);
      draw::show(50);
   }
   t3.setColor(draw::RED);
  t3.turn(15);
  t3.move(25);
  draw::show(50);
  t3.turn(30); 
  t3.move(70);
  draw::show(50);
t4.setColor(draw::BLACK);
  t4.turn(22);
  t4.move(33);
  draw::show(50);
  t4.turn(44); 
  t4.move(55); 
  draw::show(50);

   return 0;
}
