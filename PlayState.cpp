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
cgf::Sprite bala1;
cgf::Sprite bala2;
cgf::Sprite bala3;
sf::Text PontuacaoTxt;
sf::Font fonte;

cgf::Sprite other1,other2,other3,other4,other5,other6,other7,other8,other9,other10,other11,other12;


void PlayState::setSprites(){

    switch(aux){
        case 1 :{
            alvo1.load("data/img/Char14s.png");
            alvo2.load("data/img/Char14s.png");
            break;
        }case 2 :{
            alvo1.load("data/img/Char21.png");
            alvo2.load("data/img/Char21.png");
            break;
        }case 3 :{
            alvo1.load("data/img/Char31.png");
            alvo2.load("data/img/Char31.png");
            break;
        }case 4 :{
            alvo1.load("data/img/Char33.png");
            alvo2.load("data/img/Char33.png");
            break;
        }case 5 :{
            alvo1.load("data/img/Char35.png");
            alvo2.load("data/img/Char35.png");
            break;
        }default:{
            alvo1.load("data/img/Char14s.png");
            alvo2.load("data/img/Char14s.png");
            break;
        }
    }

    bala1.load("data/img/bala.png");
    bala1.setPosition(0.f,0.f);
    bala2.load("data/img/bala.png");
    bala2.setPosition(40.f,0.f);
    bala3.load("data/img/bala.png");
    bala3.setPosition(80.f,0.f);
    fonte.loadFromFile("data/fonts/arial.ttf");
    PontuacaoTxt.setFont(fonte);

    PontuacaoTxt.setColor(sf::Color::Red);
    PontuacaoTxt.setCharacterSize(20);
    std::stringstream pont;
    pont << "Pontuacao Atual: " << MenuState::getPontuacaoAtualizada();
    PontuacaoTxt.setString(pont.str());
    PontuacaoTxt.setPosition({ 440.f, 0.f });

    f = rand_FloatRange(70.f,500.f);
    g = rand_FloatRange(70.f,500.f);
    SPRITE1_X = 1 + MenuState::getFaseAtual();
    SPRITE1_Y = 0;
    SPRITE2_X = -1 - MenuState::getFaseAtual();
    SPRITE2_Y = 0;
    qtdHits = 3;
    qtdTargets = 2;
    alvo1Down = 0;
    alvo2Down = 0;

    alvo1.setPosition(0.f,f);
    alvo2.setPosition(700.f,g);

    if(MenuState::getInsano() == 1){
        other1.load("data/img/Char26.png");
        other2.load("data/img/Char25.png");
        other3.load("data/img/Char24.png");
        other4.load("data/img/Char23.png");
        other5.load("data/img/Char28.png");
        other6.load("data/img/Char32.png");
        other7.load("data/img/Char26.png");
        other8.load("data/img/Char25.png");
        other9.load("data/img/Char24.png");
        other10.load("data/img/Char23.png");
        other11.load("data/img/Char28.png");
        other12.load("data/img/Char32.png");

        other1.setPosition(0.f,rand_FloatRange(70.f,500.f));
        other2.setPosition(0.f,rand_FloatRange(70.f,500.f));
        other3.setPosition(0.f,rand_FloatRange(70.f,500.f));
        other7.setPosition(0.f,rand_FloatRange(70.f,500.f));
        other8.setPosition(0.f,rand_FloatRange(70.f,500.f));
        other9.setPosition(0.f,rand_FloatRange(70.f,500.f));

        other4.setPosition(700.f,rand_FloatRange(70.f,500.f));
        other5.setPosition(700.f,rand_FloatRange(70.f,500.f));
        other6.setPosition(700.f,rand_FloatRange(70.f,500.f));
        other10.setPosition(700.f,rand_FloatRange(70.f,500.f));
        other11.setPosition(700.f,rand_FloatRange(70.f,500.f));
        other12.setPosition(700.f,rand_FloatRange(70.f,500.f));

    }
}

void PlayState::init()
{
    srand (static_cast <unsigned> (time(0)));
    background = MenuState::getBackGroundSelecionado();
    background.setPosition(0,0);
    aux = MenuState::getSpriteSelecionado();
    setSprites();
    gunSoundBuffer.loadFromFile("data/audio/fire.wav");
    gunSound.setBuffer(gunSoundBuffer);
    gunSound.setAttenuation(0);
    gunSound.setLoop(false);
	cout << "PlayState: Init" << endl;
}

float PlayState::rand_FloatRange(float min, float max) {
    return  (max - min) * ((((float) rand()) / (float) RAND_MAX)) + min ;
}

void PlayState::cleanup(){
	cout << "PlayState: Clean" << endl;
}

void PlayState::pause(){
	cout << "PlayState: Paused" << endl;
}

void PlayState::resume(){
	cout << "PlayState: Resumed" << endl;
}

void PlayState::handleEvents(cgf::Game* game){
    sf::Event event;
    while (screen->pollEvent(event)){
        if(event.type == sf::Event::Closed)
            game->quit();
        if(event.type == sf::Event::MouseButtonPressed){
            if (event.mouseButton.button == sf::Mouse::Left){
                handleClick(event,game);
            }
        }
    }
}
void PlayState::handleClick(sf::Event clique,cgf::Game* game){
    gunSound.play();
    if(qtdHits > 0){
        qtdHits--;
        if(alvo1.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
            qtdTargets--;
            alvo1Down = 1;
            cout << "target 1 down" << endl;
            SPRITE1_Y = 10;
        }else if(alvo2.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
            qtdTargets--;
            alvo2Down = 1;
            cout << "target 2 down" << endl;
            SPRITE2_Y = 10;
        }else{
        }
    }else{
        cout << "Out of Ammo" << endl;
    }
    cout << "aquiii " << endl;
}

void PlayState::update(cgf::Game* game){

    alvo1.move(SPRITE1_X,SPRITE1_Y);
    alvo2.move(SPRITE2_X,SPRITE2_Y);

    if(MenuState::getInsano()){

        other1.move(SPRITE1_X+4,0);
        other2.move(SPRITE1_X+1,SPRITE1_X);
        other3.move(SPRITE1_X,0);
        other4.move(SPRITE2_X+6,SPRITE1_X);
        other5.move(SPRITE2_X-9,0);
        other6.move(SPRITE2_X,SPRITE1_X);
        other7.move(SPRITE1_X+7,0);
        other8.move(SPRITE1_X+8,SPRITE1_X);
        other9.move(SPRITE1_X+10,0);
        other10.move(SPRITE2_X,SPRITE1_X);
        other11.move(SPRITE2_X-11,0);
        other12.move(SPRITE2_X,SPRITE1_X);
    }


    if(qtdTargets == 0){
        cout << "All targets down" << endl;
        if(gunSound.getStatus() == sf::Sound::Stopped) {
            if(qtdHits == 1){
                MenuState::updatePontuacao(700);
            }else{
                MenuState::updatePontuacao(200);
            }
            MenuState::updateFase();
            game->changeState(MenuState::instance());
        }

    }else if(qtdTargets == 1 && qtdHits == 0){
        MenuState::updatePontuacao(100);
        MenuState::updateFase();
        game->changeState(MenuState::instance());
    }else if(qtdTargets == 2 && qtdHits == 0){
        MenuState::gameOver();
        game->changeState(MenuState::instance());
    } else if(alvo1.getPosition().x > 700 && alvo2Down == 1){
        MenuState::updatePontuacao(100);
        MenuState::updateFase();
        game->changeState(MenuState::instance());
    } else if(alvo2.getPosition().x < 0 && alvo1Down == 1){
        MenuState::updatePontuacao(100);
        MenuState::updateFase();
        game->changeState(MenuState::instance());
    } else if(alvo1.getPosition().x > 700 && alvo2.getPosition().x < 0){
        MenuState::gameOver();
        game->changeState(MenuState::instance());
    }

}

void PlayState::draw(cgf::Game* game){
    screen = game->getScreen();
    screen->draw(background);
    screen->draw(alvo1);
    screen->draw(alvo2);
    screen->draw(PontuacaoTxt);

    if(MenuState::getInsano() == 1){
        screen->draw(other1);
        screen->draw(other2);
        screen->draw(other3);
        screen->draw(other4);
        screen->draw(other5);
        screen->draw(other6);
        screen->draw(other7);
        screen->draw(other8);
        screen->draw(other9);
        screen->draw(other10);
        screen->draw(other11);
        screen->draw(other12);
    }

    if(qtdHits == 3){
        screen->draw(bala1);
        screen->draw(bala2);
        screen->draw(bala3);
    }else if( qtdHits == 2){
        screen->draw(bala1);
        screen->draw(bala2);
    }else if( qtdHits == 1){
        screen->draw(bala1);
    }
}
