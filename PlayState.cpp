/*
 *  PlayState.cpp
 *  Normal "play" state
 *
 *  Created by Marcelo Cohen on 08/13.
 *  Copyright 2013 PUCRS. All rights reserved.
 *
 */

#include <iostream>
#include <cmath>
#include "Game.h"
#include "PlayState.h"
#include "InputManager.h"
#include "MenuState.h"

PlayState PlayState::m_PlayState;

using namespace std;

cgf::Sprite background;

int qtdHits = 3;
int qtdTargets = 2;

void PlayState::setSprites(){
    int aux = MenuState::getSpriteSelecionado();
    switch(aux){
        case 1 :{
            playSprite1.load("data/img/Char14s.png");
            playSprite2.load("data/img/Char14s.png");
            break;
        }case 2 :{
            playSprite1.load("data/img/Char21.png");
            playSprite2.load("data/img/Char21.png");
            break;
        }case 3 :{
            playSprite1.load("data/img/Char31.png");
            playSprite2.load("data/img/Char31.png");
            break;
        }case 4 :{
            playSprite1.load("data/img/Char33.png");
            playSprite2.load("data/img/Char33.png");
            break;
        }case 5 :{
            playSprite1.load("data/img/Char35.png");
            playSprite2.load("data/img/Char35.png");
            break;
        }default:{
            playSprite1.load("data/img/Char14s.png");
            playSprite2.load("data/img/Char14s.png");
            break;
        }
        playSprite1.setOrigin(rand() %500 ,rand() %500);
        playSprite2.setOrigin(rand() %500 ,rand() %500);
        playSprite1.setXspeed(5.0);
        playSprite1.setYspeed(5.0);

        playSprite2.setXspeed(5.0);
        playSprite2.setYspeed(5.0);

        cout << "aeee " << aux << endl;
    }
}

void PlayState::init()
{
    //fundo
    background = MenuState::getBackGroundSelecionado();
    background.setPosition(0,0);
    setSprites();

	cout << "PlayState: Init" << endl;
}


void PlayState::cleanup()
{
	cout << "PlayState: Clean" << endl;
}

void PlayState::pause()
{
	cout << "PlayState: Paused" << endl;
}

void PlayState::resume()
{
	cout << "PlayState: Resumed" << endl;
}

void PlayState::handleEvents(cgf::Game* game)
{
    sf::Event event;

    while (screen->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
            game->quit();
    }
}

void PlayState::update(cgf::Game* game)
{
        playSprite1.update(5.0,true);
        playSprite2.update(5.0,true);
}

void PlayState::draw(cgf::Game* game)
{
    screen = game->getScreen();
    screen->draw(background);
    screen->draw(playSprite1);
    screen->draw(playSprite2);

}
