#include <SFML/Graphics.hpp>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "MicroEngine");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Texture texture;
    texture.loadFromFile("media/img/backgroundEmpty.png");

    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::View view(sf::FloatRect(0.f, 0.f, window.getSize().x, window.getSize().y));

    window.setView(view);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        window.clear();
        window.draw(sprite);
        window.draw(shape);
        window.display();
    }

    return 0;
}