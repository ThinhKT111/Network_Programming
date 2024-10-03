
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include <iostream>

#include "../Button.hpp"
#include "room_manage.h"

#include "../../Interface/Handle_3D/type_cube_3D.h"
#include "../../Interface/Handle_3D/type_cube_4X4.h"
#include "../../Interface/Handle_3D/type_cube_5X5.h"
#include "../../../Project/Solve_Cube/type_cube.h"
#include "../../../Project/Solve_Cube/cube_5x5_2D.h"
#include "../../../Project/Solve_Cube/cube_4x4_2D.h"


using namespace std;

int Manage_Room(sf::RenderWindow &window, char room_id[], int status_of_room)
{
    int i, j, k;
    int rotateX = 0;
    int rotateY = 0;
    int rotateZ = 0;
    
    Button myButton_BACK(100, 50, 900, 25, sf::Color::Blue, "BACK");
    myButton_BACK.setTextColor(sf::Color::White);
    myButton_BACK.setButtonColor(sf::Color::Red);

    GLfloat cube3X3_location[27][108];
    init_cube3x3_location(cube3X3_location);

    GLfloat cube3x3_color[27][144];
    init_cube3x3_color(cube3x3_color);

    Cube input_Cube_3;

    GLfloat cube4X4_location[64][108];
    init_cube4X4_location(cube4X4_location);

    GLfloat cube4X4_color[64][144];
    init_cube4X4_color(cube4X4_color);

    Cube4X4 input_Cube_4;

    GLfloat cube5X5_location[125][108];
    init_cube5X5_location(cube5X5_location);

    GLfloat cube5X5_color[125][144];
    init_cube5X5_color(cube5X5_color);

    Cube5X5 input_Cube_5;
    

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;

        while (window.pollEvent(event))
        {
            // Clear the window with a black color
            window.clear(sf::Color::Black);
            
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            // Escape key: exit
            if ((event.type == sf::Event::KeyPressed) && (event.key.code == sf::Keyboard::Escape))
                window.close();

            // Resize event: adjust the viewport
            if (event.type == sf::Event::Resized)
                glViewport(0, 0, event.size.width, event.size.height);

            //Rotate the perpective
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                rotateX += 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                rotateX -= 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            {
                rotateY += 1.f;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            {
                rotateY -= 1.f;
            }

            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (myButton_BACK.isClicked(sf::Mouse::getPosition(window)))
                {
                    return EXIT_SUCCESS;
                }
            }
            // if (status_of_room == 3)
            //     Spray_Cube3D(cube3x3_color, input_Cube_3);
            // else if (status_of_room == 4)
            //     Spray_Cube_4X4(cube4X4_color, input_Cube_4);
            // else if (status_of_room == 5)
            //     Spray_Cube_5X5(cube5X5_color, input_Cube_5);
        }    

        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Apply some transformations to rotate the cube
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        glRotatef(rotateX, 1.f, 0.f, 0.f);
        glRotatef(rotateY, 0.f, 1.f, 0.f);

        if (status_of_room == 3)
        {
            // Draw the cube
            // Loop through each of the 27 cubes in the 3x3 cube
            for (i = 0; i < 27; i++)
            {
                // Push the matrix so each cube transformation is independent
                glPushMatrix();

                // Set up vertex and color pointers for the cube
                glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), &cube3X3_location[i]);
                glColorPointer(4, GL_FLOAT, 4 * sizeof(GLfloat), &cube3x3_color[i]);
                glDrawArrays(GL_TRIANGLES, 0, 36);
                // Pop the matrix to undo the translation for the next cube
                glPopMatrix();
            } 
        }
        else if (status_of_room == 4)
        {
            // Draw the cube
            // Loop through each of the 64 cubes in the 4x4 cube
            for (i = 0; i < 64; i++)
            {
                // Push the matrix so each cube transformation is independent
                glPushMatrix();

                // Set up vertex and color pointers for the cube
                glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), &cube4X4_location[i]);
                glColorPointer(4, GL_FLOAT, 4 * sizeof(GLfloat), &cube4X4_color[i]);
                glDrawArrays(GL_TRIANGLES, 0, 36);
                // Pop the matrix to undo the translation for the next cube
                glPopMatrix();
            }
        }  
        else if (status_of_room == 5)
        {
            // Draw the cube
            // Loop through each of the 125 cubes in the 5x5 cube
            for (i = 0; i < 125; i++)
            {
                // Push the matrix so each cube transformation is independent
                glPushMatrix();

                // Set up vertex and color pointers for the cube
                glVertexPointer(3, GL_FLOAT, 3 * sizeof(GLfloat), &cube5X5_location[i]);
                glColorPointer(4, GL_FLOAT, 4 * sizeof(GLfloat), &cube5X5_color[i]);
                glDrawArrays(GL_TRIANGLES, 0, 36);
                // Pop the matrix to undo the translation for the next cube
                glPopMatrix();
            }
        } 

        // Draw the 2D button using SFML
        window.pushGLStates();
        myButton_BACK.draw(window);
        window.popGLStates();

        // Finally, display the rendered frame on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
