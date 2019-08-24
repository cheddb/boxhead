#include "includes.h"
#include "world.h"
#include "texturemanager.h"

World g_world;

int main(){
    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");
    sf::View view(sf::FloatRect(0, 0, 1000, 600));
    window.setView(view);

//    // Load a sprite to display
//    sf::Texture texture;
//    if (!texture.loadFromFile("cute_image.jpg"))
//        return EXIT_FAILURE;
//    sf::Sprite sprite(texture);
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
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // Clear screen
        window.clear();

        sf::sleep(sf::milliseconds(16));

        g_world.frame();

        g_world.draw();

        // Update the window
        window.display();
    }
    return EXIT_SUCCESS;
}
