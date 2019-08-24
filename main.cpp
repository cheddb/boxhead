#include "includes.h"
#include "world.h"
#include "texturemanager.h"

World g_world;

RenderWindow g_window(sf::VideoMode(800, 600), "SFML window");


int main(){
    // Create the main window
    sf::View view(sf::FloatRect(0, 0, 1000, 600));




//    // Load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile("cute_image.jpg"))
//        return EXIT_FAILURE;
//    sf::Sprite sprite(g_tex.getTexture(TextureManager::Character));
//    // Create a graphical text to display
//    sf::Font font;
//    if (!font.loadFromFile("arial.ttf"))
//        return EXIT_FAILURE;
//    sf::Text text("Hello SFML", font, 50);
//    // Load a music to play
//    sf::Music music;
//    if (!music.openFromFile("nice_music.ogg"))
//        return EXIT_FAILURE;
//    // Play the music
//    music.play();
    // Start the game loop
    while (g_window.isOpen())
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
