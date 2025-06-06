#include <SFML/Graphics.hpp>

int main()
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "My window");

    // limit framerate to 60
    window.setFramerateLimit(60);

    // run the program as long as the window is open
    while (window.isOpen())
    {

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

    }

    return 0;
}