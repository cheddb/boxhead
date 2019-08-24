#include "player.h"
#include "texturemanager.h"
#include "world.h"
#include "projectile.h"

Player::Player() : Entity()
{
    life = 100;
    sprite.setTexture(g_tex.getTexture(TextureManager::Character));
    sprite.setTextureRect(IntRect(0, 0, 16, 29));

    shotgunSound.loadFromFile("gfx/shotgun.ogg");
    dryGunSound.loadFromFile("gfx/gun-dry.wav");
    amo[Shotgun] = 10;
}
Player::~Player()
{

}


void Player::frame()
{
    int oldX = pos.x;
    int oldY = pos.y;

    Vector2i m_pixelPos = sf::Mouse::getPosition(g_window);
    Vector2f m_worldPos = g_window.mapPixelToCoords(m_pixelPos);
    float delta_y = (m_worldPos.y - pos.y);
    float delta_x = (m_worldPos.x - pos.x);
    if(delta_y>abs(delta_x))
      anim_dir = 0;
    else if(delta_x>abs(delta_y))
      anim_dir = 33;
    else if(delta_y < -abs(delta_x))
      anim_dir = 64;
    else
      anim_dir = 97;


    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        pos.x --;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        pos.x ++;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        pos.y --;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        pos.y ++;
    }
    if(!g_world.isFree(getRect(), this))
    {
      pos.x = oldX;
      pos.y = oldY;
    }

    if(anim_counter++ > 10){
        ++anim_step %= 4;
        if(oldX == pos.x && oldY == pos.y)
            anim_step = 0;
        anim_counter = 0;
    }


    static int counter = 0;
    counter++;

    if(Mouse::isButtonPressed(Mouse::Left))
        shoot(Pos(delta_x, delta_y));
}


void Player::draw()
{
    int s_pos_x = anim_step*16;
    int s_pos_y = anim_dir;

    sprite.setPosition(float(pos.x-8), float(pos.y-15));

    sprite.setTextureRect( IntRect(s_pos_x, s_pos_y, 16, 29));
    g_window.draw(sprite);

    char buffer[500];
    sprintf(buffer, "Shotgun : %d", amo[weapon]);

    sf::Text text(buffer, g_font, 7);

    text.setPosition(getRect().left, getRect().top-5);

    g_window.draw(text);


    if(life!=100){//print life bar
        //background
        RectangleShape rect;
        rect.setSize(sf::Vector2f(32, 3));
        rect.setOutlineColor(sf::Color::Green);
        rect.setFillColor(sf::Color::Transparent);
        rect.setOutlineThickness(1.f);
        rect.setPosition(getRect().left, getRect().top-5);
        g_window.draw(rect);


        rect.setSize(sf::Vector2f(32*life/100, 3));
        rect.setFillColor(sf::Color::Green);
        rect.setOutlineThickness(0.f);
        g_window.draw(rect);
    }
}

bool Player::mustRemove() const
{
    return life<=0;
}

IntRect Player::getRect() const{
    return IntRect(pos.x-8, pos.y-15, 16, 29);
}

void Player::shoot(Pos viewDir){
    //4 shot / sec
    static Clock clock;
    if(clock.getElapsedTime().asMilliseconds() < 250)
        return;
    clock.restart();



    //check amo
    if(amo[weapon] == 0){
        sound.setBuffer(dryGunSound);
        sound.play();

        return;
    }

    //ok, shot
    amo[weapon]--;


    Pos initial_pos=pos;

    Pos dir = viewDir.normalize()*8.f;
    Projectile* created = new Projectile(initial_pos+dir*2.f);
    created->dir = dir;
    g_world.addEntity(created);

    sound.setBuffer(shotgunSound);
    sound.play();

}
