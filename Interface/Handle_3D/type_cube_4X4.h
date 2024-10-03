#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "type_cube_3D.h"
#include "../../Solve_Cube/cube_4x4_2D.h"

using namespace std;

// type_cube_4X4.h
#ifndef TYPE_CUBE_4X4_3D_H
#define TYPE_CUBE_4X4_3D_H

// Your declarations here
extern GLfloat range_of_center_4X4;
extern GLfloat length_cube_4X4;

extern GLfloat center_location_4X4[64][3];

void init_center_location_4X4();
void init_cube4X4_location(GLfloat cube4X4_location[64][108]);
void init_cube4X4_color(GLfloat cube4X4_color[64][144]);
void Spray_Cube_4X4(GLfloat cube4x4_color[64][144], Cube4X4 bcube);

#endif // TYPE_CUBE_4X4_3D_H