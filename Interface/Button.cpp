#include "Button.hpp"
#include <iostream>

Button::Button(float width, float height, float xPos, float yPos, const sf::Color& color, const std::string& textString) {
    // Set up the button's rectangle shape
    buttonShape.setSize(sf::Vector2f(width, height));
    buttonShape.setPosition(xPos, yPos);
    buttonShape.setFillColor(color);

    // Set up the button's text
    if (!font.loadFromFile("../Project/Font/Arial.ttf")) { // Make sure the font is available or change the path
        std::cerr << "Error loading font\n";
    }
    buttonText.setFont(font);
    buttonText.setString(textString);
    buttonText.setCharacterSize(24);
    buttonText.setFillColor(sf::Color::White);

    // Center the text within the button
    sf::FloatRect textRect = buttonText.getLocalBounds();
    buttonText.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    buttonText.setPosition(xPos + width / 2.0f, yPos + height / 2.0f);
}

void Button::draw(sf::RenderWindow &window) {
    window.draw(buttonShape);
    window.draw(buttonText);
}

bool Button::isClicked(sf::Vector2i mousePos) {
    sf::FloatRect buttonBounds = buttonShape.getGlobalBounds();
    return buttonBounds.contains(static_cast<sf::Vector2f>(mousePos));
}

void Button::setTextColor(const sf::Color& color) {
    buttonText.setFillColor(color);
}

void Button::setButtonColor(const sf::Color& color) {
    buttonShape.setFillColor(color);
}
