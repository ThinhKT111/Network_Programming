
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include <iostream>

#include "../Button.hpp"

#include "../../Interface/Handle_3D/type_cube_3D.h"
#include "../../Interface/Handle_3D/type_cube_4X4.h"
#include "../../Interface/Handle_3D/type_cube_5X5.h"
#include "../../../Project/Solve_Cube/type_cube.h"
#include "../../../Project/Solve_Cube/cube_5x5_2D.h"
#include "../../../Project/Solve_Cube/cube_4x4_2D.h"

using namespace std;

// ROOM_MANAGE.h
#ifndef ROOM_MANAGE_H
#define ROOM_MANAGE_H

int Manage_Room(sf::RenderWindow &window, char room_id[], int status_of_room);

#endif // ROOM_MANAGE_H