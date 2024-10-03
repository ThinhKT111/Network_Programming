
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
#include "main3.h"

using namespace std;

int Open_Cube3X3(sf::RenderWindow &window)
{
    int i, j, k;
    int rotateX = 0;
    int rotateY = 0;
    int rotateZ = 0;

    // Create an array of sf::Keyboard::Key values
    std::array<sf::Keyboard::Key, 6> keys = {
        sf::Keyboard::U,
        sf::Keyboard::L,
        sf::Keyboard::F,
        sf::Keyboard::R,
        sf::Keyboard::B,
        sf::Keyboard::D
    };
    
    // // Request a 24-bits depth buffer when creating the window
    // sf::ContextSettings contextSettings;
    // contextSettings.depthBits = 24;

    // // Create the main window
    // sf::RenderWindow window(sf::VideoMode(1040, 780), "SFML window with OpenGL", sf::Style::Default, contextSettings);

    // // Make it the active window for OpenGL calls
    // window.setActive();

    // // Set the color and depth clear values
    // glClearDepth(1.f);
    // glClearColor(0.f, 0.f, 0.f, 1.f);

    // // Enable Z-buffer read and write
    // glEnable(GL_DEPTH_TEST);
    // glDepthMask(GL_TRUE);

    // // Disable lighting and texturing
    // glDisable(GL_LIGHTING);
    // glDisable(GL_TEXTURE_2D);

    // // Configure the viewport (the same size as the window)
    // glViewport(0, 0, window.getSize().x, window.getSize().y);

    // // Setup a perspective projection
    // glMatrixMode(GL_PROJECTION);
    // glLoadIdentity();
    // GLfloat ratio = static_cast<float>(window.getSize().x) / window.getSize().y;
    // glFrustum(-ratio, ratio, -1.f, 1.f, 1.f, 500.f);

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

    //Spray_Cube3D(cube3x3_color, input_Cube);

    // Load a sound buffer from a file
    sf::SoundBuffer buffer;
    if (!buffer.loadFromFile("../Project/Sound/Rubiks-cube-rotating-solving-312.wav")) {
        std::cerr << "Error loading sound file!" << std::endl;
        return -1;
    }

    // Create a sound instance and set the buffer
    sf::Sound sound;
    sound.setBuffer(buffer);

    // // Enable position and color vertex components
    // glEnableClientState(GL_VERTEX_ARRAY);
    // glEnableClientState(GL_COLOR_ARRAY);

    // // Disable normal and texture coordinates vertex components
    // glDisableClientState(GL_NORMAL_ARRAY);
    // glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    // Draw the cube
    glVertexPointer(3, GL_FLOAT, 7 * sizeof(GLfloat), cube);
    glColorPointer(4, GL_FLOAT, 7 * sizeof(GLfloat), &cube[3]);

    // Create a clock for measuring the time elapsed
    sf::Clock clock;

    // Create a button using the reusable library
    Button myButton_EXIT(100, 50, 900, 25, sf::Color::Blue, "EXIT");
    myButton_EXIT.setTextColor(sf::Color::White);
    myButton_EXIT.setButtonColor(sf::Color::Red);

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

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (myButton_EXIT.isClicked(sf::Mouse::getPosition(window)))
                {
                    return EXIT_SUCCESS;
                }
            }

            if (event.type == sf::Event::KeyPressed)
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || 
                     sf::Keyboard::isKeyPressed(sf::Keyboard::RShift))
                {
                    for (i = 0; i < 6; i++) 
                    {
                        if (event.key.code == keys[i]) 
                        {
                            // Rotate the corresponding face of the 3x3 cube
                            input_Cube = Rotate_Anti_Clockwise(input_Cube, i);
                            sound.play();
                            break; // Break after the correct key is found
                        }
                    }
                }    

                else 
                {
                    for (i = 0; i < 6; i++) 
                    {
                        if (event.key.code == keys[i]) 
                        {
                            // Rotate the corresponding face of the 3x3 cube
                            input_Cube = Rotate_Clockwise(input_Cube, i);
                            sound.play();
                            break; // Break after the correct key is found
                        }
                    }
                }   
                    
                Spray_Cube3D(cube3x3_color, input_Cube);
            }
        }

        // Clear the color and depth buffers
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Apply some transformations to rotate the cube
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.f, 0.f, -200.f);
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

        // Draw the 2D button using SFML
        window.pushGLStates();
        myButton_EXIT.draw(window);
        window.popGLStates();

        // Finally, display the rendered frame on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
