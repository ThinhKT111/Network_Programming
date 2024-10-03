#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include <iostream>

#include "./Handle_3D/type_cube_3D.h"
#include "Button.hpp"
#include "../Solve_Cube/type_cube.h"

#include "./Manager/room_create.h"
#include "./Manager/check_room_id.h"

using namespace std;

int main()
{
    // Request a 24-bits depth buffer when creating the window
    sf::ContextSettings contextSettings;
    contextSettings.depthBits = 24;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1200, 900), "SFML window with OpenGL", sf::Style::Default, contextSettings);

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

    // Enable position and color vertex components
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Disable normal and texture coordinates vertex components
    glDisableClientState(GL_NORMAL_ARRAY);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);

    // Create a button using the reusable library
    Button myButton_NEW(200, 50, 25, 25, sf::Color::Blue, "NEW ROOM");
    Button myButton_JOIN(200, 50, 25, 100, sf::Color::Blue, "JOIN ROOM");
    Button myButton_MANAGE(200, 50, 25, 175, sf::Color::Blue, "MANAGE ROOM");
    Button myButton_QUIT(200, 50, 25, 250, sf::Color::Blue, "QUIT");

    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        // rotateX = 0.0f;
        // rotateY = 0.0f;
        // rotateZ = 0.0f;
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

            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (myButton_NEW.isClicked(sf::Mouse::getPosition(window)))
                {
                    Create_Room(window);
                }
                if (myButton_JOIN.isClicked(sf::Mouse::getPosition(window)))
                {
                    Check_Room(window, 0);
                }
                if (myButton_MANAGE.isClicked(sf::Mouse::getPosition(window)))
                {
                    Check_Room(window, 1);
                }
                if (myButton_QUIT.isClicked(sf::Mouse::getPosition(window)))
                {
                    return EXIT_SUCCESS;
                }
            }
            // Draw the 2D button using SFML
            window.pushGLStates();
            myButton_NEW.draw(window);
            window.popGLStates();
            window.pushGLStates();
            myButton_JOIN.draw(window);
            window.popGLStates();
            window.pushGLStates();
            myButton_MANAGE.draw(window);
            window.popGLStates();
            window.pushGLStates();
            myButton_QUIT.draw(window);
            window.popGLStates();

            // Finally, display the rendered frame on screen
            window.display();
        }
    }

    return EXIT_SUCCESS;
}