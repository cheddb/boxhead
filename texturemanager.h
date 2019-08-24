#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "includes.h"

class TextureManager{
public:
    enum {
        Character,///texture of the character
        Log,

        NbTexture
    };

    TextureManager();


    Texture const& getTexture(int texId) const{
        return atlas[texId];
    }
private:
    Texture atlas[NbTexture];

};

extern TextureManager g_tex;

#endif // TEXTUREMANAGER_H
