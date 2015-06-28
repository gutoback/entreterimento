/*
 *  PlayState.h
 *  Normal "play" state
 *
 *  Created by Marcelo Cohen on 08/13.
 *  Copyright 2013 PUCRS. All rights reserved.
 *
 */

#ifndef PLAY_STATE_H_
#define PLAY_STATE_H_

#include "GameState.h"
#include "Sprite.h"
#include "InputManager.h"

class PlayState : public cgf::GameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(cgf::Game* game);
    void update(cgf::Game* game);
    void draw(cgf::Game* game);

    // Implement Singleton Pattern
    static PlayState* instance()
    {
        return &m_PlayState;
    }

    protected:

    PlayState() {}

    private:

    static PlayState m_PlayState;

    int qtdHits = 3;
    int qtdTargets = 2;
    int SPRITE1_X = 5;
    int SPRITE1_Y = 0;
    int SPRITE2_X = -5;
    int SPRITE2_Y = 0;
    int aux;
    int alvo1Down = 0;
    int alvo2Down = 0;
    float f,g;
    int x, y;
    int dirx, diry;
    cgf::Sprite alvo1;
    cgf::Sprite alvo2;
    sf::SoundBuffer gunSoundBuffer;
    sf::Sound gunSound;

    sf::RenderWindow* screen;
    cgf::InputManager* im;
    float rand_FloatRange(float a, float b);
    void setSprites();
    void handleClick(sf::Event clique,cgf::Game* game);
};

#endif
