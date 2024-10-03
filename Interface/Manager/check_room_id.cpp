#include <SFML/Window.hpp>
#include <SFML/OpenGL.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio.hpp>
#include <array>

#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include "../Button.hpp"
#include "../TextBox.hpp"
#include "check_room_id.h"
#include "room_manage.h"
#include "../../Interface/User/main3.h"
#include "../../Interface/User/main4.h"
#include "../../Interface/User/main5.h"

int Check_Room(sf::RenderWindow &window, int position) 
{
    
    // Load a font (Make sure you have a font file like "arial.ttf")
    sf::Font font;
    if (!font.loadFromFile("Font/Arial.ttf")) {
        std::cout << "Error loading font!" << std::endl;
        return -1;
    }

    // Create an instance of TextBox
    TextBox textBox(font);

    Button myButton_BACK(100, 50, 900, 25, sf::Color::Blue, "BACK");
    myButton_BACK.setTextColor(sf::Color::White);
    myButton_BACK.setButtonColor(sf::Color::Red);

    Button myButton_SUBMIT(100, 50, 900, 100, sf::Color::Blue, "SUBMIT");

    char room_id[7] = "000000";

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            // Close the window if the user presses the close button
            if (event.type == sf::Event::Closed)
                window.close();
            
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

                if (myButton_SUBMIT.isClicked(sf::Mouse::getPosition(window)))
                {
                    if (position == 0)
                    {
                        if (room_id[0] == '0')
                        {
                            Open_Cube3X3(window);
                        }
                        else if (room_id[0] == '1')
                        {
                            Open_Cube4X4(window);
                        }
                        else if (room_id[0] == '2')
                        {
                            Open_Cube5X5(window);
                        }
                    }
                    else
                    {
                        Manage_Room(window, room_id, 3);

                    }
                }
            }
            // Pass the event to the text box for input handling
            textBox.handleEvent(event);

            // Check if the user presses Enter (confirm input)
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                textBox.getInput(room_id);  // Store the input in the roomID variable
                std::cout << "Room ID: " << room_id << std::endl;  // Print to console for debugging
            }
        }

        // Clear the window with black color
        window.clear(sf::Color::Black);

        // Draw the text box
        window.pushGLStates();
        textBox.draw(window);
        window.popGLStates();

        window.pushGLStates();
        myButton_BACK.draw(window);
        window.popGLStates();
        window.pushGLStates();
        myButton_SUBMIT.draw(window);
        window.popGLStates();

        // Display the contents on the screen
        window.display();
    }
    
    return 0;
}
