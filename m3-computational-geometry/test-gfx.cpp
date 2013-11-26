#include "gfx.hpp"
#include <iostream>
#include <cmath>

using namespace std;
using namespace gfx;


static double mx0, my0, mx1, my1;


void cb_draw ()
{
  set_pen (1.0, 0.0, 0.0, 0.0, 1.0); // width, red, green, blue, alpha
  draw_arc (1.0, 0.0, 1.0, 0.0, 2 * M_PI);
  
  set_pen (1.0, 0.5, 0.5, 0.5, 1.0);
  fill_arc (-1.0, 0.0, 1.0, 0.0, 2 * M_PI);
  
  set_pen (1.0, 1.0, 0.0, 0.0, 1.0);
  draw_line (0.0, 0.0, 1.0, 0.0);
  
  set_pen (1.0, 0.0, 1.0, 0.0, 1.0);
  draw_line (0.0, 0.0, 0.0, 1.0);
  
  set_pen (1.0, 0.0, 0.0, 1.0, 1.0);
  draw_line (0.0, 0.0, 1.0, 1.0);
  draw_line (1.0, 0.0, 0.0, 1.0);
  
  set_pen (3.0, 0.5, 0.0, 0.0, 1.0);
  draw_line (mx0, my0, mx1, my1);
}


void cb_mouse (double px, double py, int flags)
{
  if (flags & MOUSE_PRESS) {
    mx0 = px;
    my0 = py;
  }
  else if (flags & MOUSE_DRAG) {
    mx1 = px;
    my1 = py;
  }
}


void cb_click ()
{
  static int count = 0;
  switch (++count % 4) {
  case 0:
    set_view (-1.0, -1.0, 2.0, 2.0);
    break;
  case 1:
    set_view (-2.0, -1.0, 1.0, 2.0);
    break;
  case 2:
    set_view (-2.0, -2.0, 1.0, 1.0);
    break;
  default:
    set_view (-1.0, -2.0, 2.0, 1.0);
  }
}


int main (int argc, char ** argv)
{
  mx0 =  0.0;
  my0 =  0.0;
  mx1 =  0.5;
  my1 = -0.5;
  debug (&cout);
  add_button ("click", cb_click);
  main ("test-gfx", cb_draw, cb_mouse);
}
