
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <iostream>

#include "type_cube_3D.h"
#include "../Solve_Cube/type_cube.h"

using namespace std;

int main()
{
    int i, j, k;
    int rotateX = 0;
    int rotateY = 0;
    int rotateZ = 0;
    
    // Request a 24-bits depth buffer when creating the window
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

    // Create the main window
    sf::Window window(sf::VideoMode(640, 480), "SFML window with OpenGL", sf::Style::Default, contextSettings);

    // Make it the active window for OpenGL calls
    window.setActive();

    // Set the color and depth clear values
    glClearDepth(1.f);
    glClearColor(0.f, 0.f, 0.f, 1.f);

    // Enable Z-buffer read and write
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);

    // Disable lighting and texturing
    glDisable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);

    // Configure the viewport (the same size as the window)
    glViewport(0, 0, window.getSize().x, window.getSize().y);

    // Setup a perspective projection
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
    glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

    GLfloat cube3X3_location[27][108];
    init_cube3x3_location(cube3X3_location);

    GLfloat cube3x3_color[27][144];
    init_cube3x3_color(cube3x3_color);

    Cube input_Cube;
    freopen("../Project/Solve_Cube/test_case/testcase4.txt", "r", stdin);
    for (i=0; i<6; i++)
    {
        for (j=0; j<8; j++)
        {
            cin >> input_Cube.color[i][j];
        }
    }

    Spray_Cube3D(cube3x3_color, input_Cube);

    // Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Disable normal and texture coordinates vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    // Draw the cube
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), cube);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), &cube[3]);

    // Create a clock for measuring the time elapsed
    sf::Clock clock;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        // rotateX = 0.0f;
        // rotateY = 0.0f;
        // rotateZ = 0.0f;
        while (window.pollEvent(event))
        {
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

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || 
                     sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                {
                    if (event.key.code == sf::Keyboard::U)
                        input_Cube = Rotate_Anti_Clockwise(input_Cube, 0);
                    if (event.key.code == sf::Keyboard::L)
                        input_Cube = Rotate_Anti_Clockwise(input_Cube, 1);
                    if (event.key.code == sf::Keyboard::F)
                        input_Cube = Rotate_Anti_Clockwise(input_Cube, 2);
                    if (event.key.code == sf::Keyboard::R)
                        input_Cube = Rotate_Anti_Clockwise(input_Cube, 3);
                    if (event.key.code == sf::Keyboard::B)
                        input_Cube = Rotate_Anti_Clockwise(input_Cube, 4);
                    if (event.key.code == sf::Keyboard::D)
                        input_Cube = Rotate_Anti_Clockwise(input_Cube, 5);
                }     
                
                if (event.key.code == sf::Keyboard::U)
                    input_Cube = Rotate_Clockwise(input_Cube, 0);
                if (event.key.code == sf::Keyboard::L)
                    input_Cube = Rotate_Clockwise(input_Cube, 1);
                if (event.key.code == sf::Keyboard::F)
                    input_Cube = Rotate_Clockwise(input_Cube, 2);
                if (event.key.code == sf::Keyboard::R)
                    input_Cube = Rotate_Clockwise(input_Cube, 3);
                if (event.key.code == sf::Keyboard::B)
                    input_Cube = Rotate_Clockwise(input_Cube, 4);
                if (event.key.code == sf::Keyboard::D)
                    input_Cube = Rotate_Clockwise(input_Cube, 5);
                    
                Spray_Cube3D(cube3x3_color, input_Cube);
            }
        }

        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Apply some transformations to rotate the cube
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
        // glRotatef(clock.getElapsedTime().asSeconds() * 50, 1.f, 0.f, 0.f);
        // glRotatef(clock.getElapsedTime().asSeconds() * 30, 0.f, 1.f, 0.f);
        // glRotatef(clock.getElapsedTime().asSeconds() * 90, 0.f, 0.f, 1.f);
        glRotatef(rotateX, 1.f, 0.f, 0.f);
        glRotatef(rotateY, 0.f, 1.f, 0.f);
        
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

        // Finally, display the rendered frame on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
