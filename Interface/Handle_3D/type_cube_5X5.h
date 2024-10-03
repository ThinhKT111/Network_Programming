#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "type_cube_3D.h"
#include "../../Solve_Cube/cube_5x5_2D.h"

using namespace std;

// type_cube_5X5.h
#ifndef TYPE_CUBE_5X5_3D_H
#define TYPE_CUBE_5X5_3D_H

// Your declarations here
extern GLfloat range_of_center_5X5;
extern GLfloat length_cube_5X5;

extern GLfloat center_location_5X5[125][3];

void init_center_location_5X5();
void init_cube5X5_location(GLfloat cube5X5_location[125][108]);
void init_cube5X5_color(GLfloat cube5X5_color[125][144]);
void Spray_Cube_5X5(GLfloat cube5x5_color[125][144], Cube5X5 bcube);

#endif // TYPE_CUBE_5X5_3D_H