#include "includes.h"
#include "world.h"
#include "texturemanager.h"

World g_world;

RenderWindow g_window(sf::VideoMode(800, 600), "SFML window");
Font g_font;


int main(){
    // Create the main window
    sf::View view(sf::FloatRect(0, 0, 1000, 600));

    g_font.loadFromFile("gfx/Gargi.ttf");


    // Start the game loop
    while (g_window.isOpen() && !sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        // Process events
        sf::Event event;
        while (g_window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                g_window.close();

        }
        // Clear screen
        g_window.clear();

        sf::sleep(sf::milliseconds(15));

        view.reset(sf::FloatRect(g_world.getPlayer()->getPos().x-400, g_world.getPlayer()->getPos().y-300, 800, 600));

        g_world.frame();

        g_world.draw();


        g_window.setView(view);

        // Update the window
        g_window.display();
    }
    return EXIT_SUCCESS;
}
