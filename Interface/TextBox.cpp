// TextBox.cpp
#include "TextBox.hpp"
#include <string>
#include <cstring>

TextBox::TextBox(sf::Font& font, unsigned int characterSize) {
    // Set up the text object
    text.setFont(font);
    text.setCharacterSize(characterSize);
    text.setPosition(50, 50);  // Position of the text box
    text.setFillColor(sf::Color::White);

    // Optional: Set up the background rectangle (text box)
    box.setSize(sf::Vector2f(300, characterSize + 10));  // Define the box size
    box.setFillColor(sf::Color(50, 50, 50));  // Dark background
    box.setPosition(50, 50);  // Same position as the text
    box.setOutlineThickness(2);
    box.setOutlineColor(sf::Color::White);  // Border color
}

void TextBox::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::TextEntered) {
        // Handle backspace separately
        if (event.text.unicode == 8) {
            if (!inputString.empty()) {
                inputString.pop_back();
            }
        } else if (event.text.unicode < 128 && event.text.unicode >= 32) {
            // Append valid characters, but limit to 6 characters
            if (inputString.size() < 6) {
                inputString += static_cast<char>(event.text.unicode);
            }
        }

        // Update the displayed text
        text.setString(inputString);
    }
}

void TextBox::draw(sf::RenderWindow& window) const {
    window.draw(box);   // Draw the background box
    window.draw(text);  // Draw the text
}

void TextBox::getInput(char inputBuffer[7]) {
    // Copy inputString to the buffer, ensuring it's null-terminated
    std::strncpy(inputBuffer, inputString.c_str(), 6);
    inputBuffer[6] = '\0';  // Ensure the string is null-terminated
}
