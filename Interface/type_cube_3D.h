#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "../Solve_Cube/type_cube.h"

using namespace std;

// type_cube_3D.h
#ifndef TYPE_CUBE_3D_H
#define TYPE_CUBE_3D_H

// Your declarations here
extern GLfloat range_of_center;  
extern GLfloat length_cube;      
extern GLfloat center_location[27][3]; 
extern GLfloat cube[];  

void init_cube3x3_location(GLfloat cube3X3_location[27][108]);
void init_cube3x3_color(GLfloat cube3x3_color[27][144]);
void Transfer_3D_Color(char color, GLfloat color3D[4]);
void Spray_Cube3D(GLfloat cube3x3_color[27][144], Cube bcube);

#endif // TYPE_CUBE_3D_H