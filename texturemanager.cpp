#include "texturemanager.h"

TextureManager::TextureManager(){
    atlas[Character].loadFromFile("gfx/character.png");
    atlas[Log].loadFromFile("gfx/log.png");
}



TextureManager g_tex;
