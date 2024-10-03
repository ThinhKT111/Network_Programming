// TextBox.hpp
#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class TextBox {
public:
    TextBox(sf::Font& font, unsigned int characterSize = 30);
    void handleEvent(const sf::Event& event);
    void draw(sf::RenderWindow& window) const;
    void getInput(char inputBuffer[7]);

private:
    sf::Text text;
    sf::RectangleShape box;  // Optional: to create a border around the text area
    std::string inputString;
};
