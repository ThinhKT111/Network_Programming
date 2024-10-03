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
#include "../../Interface/Handle_3D/type_cube_5X5.h"
#include "../../Solve_Cube/cube_5x5_2D.h"

using namespace std;

int Open_Cube5X5(sf::RenderWindow &window);