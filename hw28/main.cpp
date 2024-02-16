#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML HW 28");

    sf::Font font;
    if (!font.loadFromFile("/Users/ocherenkov/Work/myprojects/courses/c++/course/hw28/Roboto-Regular.ttf")) {
        std::cerr << "Failed to load font\n";
        return 1;
    }
    sf::Text text1("Robot Dreams", font, 30);
    text1.setPosition(50, 50);

    sf::Text text2("Home Work 28", font, 30);
    text2.setPosition(50, 100);

    sf::Texture texture;
    if (!texture.loadFromFile("/Users/ocherenkov/Work/myprojects/courses/c++/course/hw28/CO.png")) {
        std::cerr << "Failed to load image\n";
        return 1;
    }
    sf::Sprite sprite(texture);
    sprite.setPosition(50, 150);

    while (window.isOpen()) {
        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Очистка экрана
        window.clear();

        // Рисуем тексты и картинку
        window.draw(text1);
        window.draw(text2);
        window.draw(sprite);

        window.display();
    }

    return 0;
}