/*
 *  MenuState.h
 *  Example "menu" state
 *
 *  Created by Marcelo Cohen on 04/11.
 *  Copyright 2011 PUCRS. All rights reserved.
 *
 */

#ifndef _MENU_STATE_H_
#define _MENU_STATE_H_

#include "GameState.h"
#include "Sprite.h"

class MenuState : public cgf::GameState
{
    public:

    void init();
    void cleanup();

    void pause();
    void resume();

    void handleEvents(cgf::Game* game);
    void update(cgf::Game* game);
    void draw(cgf::Game* game);

    static int getSpriteSelecionado(){
        return instance()->getSpriteSelecionadoPr();
    }

    static cgf::Sprite getBackGroundSelecionado(){
        return instance()->getBackGroundSelecionadoPr();
    }
    // Implement Singleton Pattern
    static MenuState* instance()
    {
        return &m_MenuState;
    }

    protected:

    MenuState() {}

    private:

    static MenuState m_MenuState;
    void handleClick(sf::Event clique,cgf::Game* game);
    void handleMenu(cgf::Game* game);
    int getSpriteSelecionadoPr();
    cgf::Sprite getBackGroundSelecionadoPr();

};

#endif

