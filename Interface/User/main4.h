
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include <iostream>

#include "../../Interface/Handle_3D/type_cube_3D.h"
#include "../Button.hpp"
#include "../../Solve_Cube/type_cube.h"
#include "../../Interface/Handle_3D/type_cube_4X4.h"
#include "../../Solve_Cube/cube_4x4_2D.h"

using namespace std;

// MAIN_4.h
#ifndef MAIN_4_H
#define MAIN_4_H

int Open_Cube4X4(sf::RenderWindow &window);

#endif // MAIN_4_H