#include "texturemanager.h"

TextureManager::TextureManager(){
    atlas[Character].loadFromFile("gfx/character.png");
}



TextureManager g_tex;
