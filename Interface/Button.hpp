#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>

class Button {
public:
    Button(float width, float height, float xPos, float yPos, const sf::Color& color, const std::string& textString);
    
    void draw(sf::RenderWindow &window);
    bool isClicked(sf::Vector2i mousePos);
    void setTextColor(const sf::Color& color);
    void setButtonColor(const sf::Color& color);

private:
    sf::RectangleShape buttonShape;
    sf::Text buttonText;
    sf::Font font;
};

#endif // BUTTON_HPP
