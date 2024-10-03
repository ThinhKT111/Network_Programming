
#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <array>
#include <iostream>

#include "../Button.hpp"
#include "room_create.h"
#include "room_manage.h"

using namespace std;

int Create_Room(sf::RenderWindow &window)
{
    int status_of_room = 0;
    char room_id[7] = "000000";
    
    Button myButton_BACK(100, 50, 900, 25, sf::Color::Blue, "BACK");
    myButton_BACK.setTextColor(sf::Color::White);
    myButton_BACK.setButtonColor(sf::Color::Red);

    Button myButton_3X3(100, 50, 900, 100, sf::Color::Blue, "3X3 ROOM");
    Button myButton_4X4(100, 50, 900, 175, sf::Color::Blue, "4X4 ROOM");
    Button myButton_5X5(100, 50, 900, 250, sf::Color::Blue, "5X5 ROOM");

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

            
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (myButton_BACK.isClicked(sf::Mouse::getPosition(window)))
                {
                    return EXIT_SUCCESS;
                }

                if (myButton_3X3.isClicked(sf::Mouse::getPosition(window)))
                {
                    Manage_Room(window, room_id, 3);
                }
                if (myButton_4X4.isClicked(sf::Mouse::getPosition(window)))
                {
                    Manage_Room(window, room_id, 4);
                }
                if (myButton_5X5.isClicked(sf::Mouse::getPosition(window)))
                {
                    Manage_Room(window, room_id, 5);
                }
            }

            
        }

        

        // Draw the 2D button using SFML
        window.pushGLStates();
        myButton_BACK.draw(window);
        window.popGLStates();
        window.pushGLStates();
        myButton_3X3.draw(window);
        window.popGLStates();
        window.pushGLStates();
        myButton_4X4.draw(window);
        window.popGLStates();
        window.pushGLStates();
        myButton_5X5.draw(window);
        window.popGLStates();

        // Finally, display the rendered frame on screen
        window.display();
    }

    return EXIT_SUCCESS;
}
