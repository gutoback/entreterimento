/*
 *  MenuState.cpp
 *  Example "menu" state
 *
 *  Created by Marcelo Cohen on 04/11.
 *  Copyright 2011 PUCRS. All rights reserved.
 *
 */


#include <iostream>
#include "Game.h"
#include "InputManager.h"
#include "MenuState.h"
#include "PlayState.h"

MenuState MenuState::m_MenuState;

using namespace std;
sf::Font Font;

sf::Text Menu1;
sf::Text Menu2;
sf::Text Menu3;

cgf::Sprite option1;
cgf::Sprite option2;
cgf::Sprite option3;
cgf::Sprite option4;
cgf::Sprite option5;
cgf::Sprite background1s;
cgf::Sprite background2s;
cgf::Sprite background1l;
cgf::Sprite background2l;

cgf::Sprite check1;
cgf::Sprite check2;
int menu;
int showAvatar = 0;
int avatarSelecionado = -1;
int showBackgrounds = 0;
int backgroundSelecionado = -1;

void MenuState::init()
{
    if (!Font.loadFromFile("C:/Users/gutob_000/Downloads/mflash-cgf-884aeccc8129/bin/data/fonts/arial.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
    }

    Menu1.setFont(Font);
    Menu1.setCharacterSize(20);
    Menu1.setString("Escolher Alvos");
    Menu1.setPosition({ 180.f, 60.f });
    Menu2.setFont(Font);
    Menu2.setCharacterSize(20);
    Menu2.setString("Escolher Fundo");
    Menu2.setPosition({ 180.f, 100.f });
    Menu3.setFont(Font);
    Menu3.setCharacterSize(20);
    Menu3.setString("Iniciar Jogo");
    Menu3.setPosition({ 180.f, 140.f });
    check1.load("data/img/check.png");
    check2.load("data/img/check.png");
    option1.load("data/img/Char14s.png");
    option1.setPosition({ 180.f, 180.f });
    option2.load("data/img/Char21.png");
    option2.setPosition({ 220.f, 180.f });
	option3.load("data/img/Char31.png");
	option3.setPosition({ 260.f, 180.f });
	option4.load("data/img/Char33.png");
	option4.setPosition({ 300.f, 180.f });
	option5.load("data/img/Char35.png");
    option5.setPosition({ 340.f, 180.f });
    background1s.load("data/img/haas.jpg");
    background1s.setPosition({ 180.f, 220.f });
    background2s.load("data/img/haa2s.jpg");
    background2s.setPosition({ 350.f, 220.f });
    cout << "MenuState Init Successful" << endl;

}
cgf::Sprite MenuState::getBackGroundSelecionadoPr(){
    if(backgroundSelecionado == 1){
        background1l.load("data/img/haa.jpg");
        return background1l;
    }else{
        background2l.load("data/img/haa2.jpg");
        return background2l;
    }
}

int MenuState::getSpriteSelecionadoPr(){
    cout << "avatar selecionadp " << avatarSelecionado << endl;
    return avatarSelecionado;
}
void MenuState::cleanup()
{
    cout << "MenuState Cleanup Successful" << endl;
}

void MenuState::pause()
{
    cout << "MenuState Paused" << endl;
}

void MenuState::resume()
{
    cout << "MenuState Resumed" << endl;
}

void MenuState::handleMenu(cgf::Game* game){
    switch(menu){
        case 1:{
            showAvatar = 1;
            break;
        }case 2:{
            showBackgrounds = 1;
            break;
        }case 3:{
            game->changeState(PlayState::instance());
            break;
        }
        default:
            showAvatar = 0;
            showBackgrounds = 0;
            break;
    }

}

void MenuState::handleEvents(cgf::Game* game)
{
    sf::Event event;
    sf::RenderWindow* screen = game->getScreen();
    while (screen->pollEvent(event)){
    // check the type of the event...
        switch (event.type){
        // window closed
            case sf::Event::Closed:
                game->quit();
                break;

            case sf::Event::KeyPressed:
                if(event.key.code == sf::Keyboard::Escape)
                    game->quit();
                break;

            case sf::Event::MouseButtonPressed:
                if (event.mouseButton.button == sf::Mouse::Left){
                    handleClick(event,game);
                }
                break;
            default:
                break;
            }
    }

}

void MenuState::handleClick(sf::Event clique,cgf::Game* game){

    if(Menu1.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        menu = 1;
        handleMenu(game);
    }else if(Menu2.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        menu = 2;
        handleMenu(game);
    }else if(Menu3.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        menu = 3;
        handleMenu(game);
    }else if (option1.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 1;
        check1.setPosition(option1.getPosition());
    }else if (option2.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 2;
        check1.setPosition(option2.getPosition());
    }else if (option3.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 3;
        check1.setPosition(option3.getPosition());
    }else if (option4.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 4;
        check1.setPosition(option4.getPosition());
    }else if (option5.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 5;
        check1.setPosition(option5.getPosition());
    }else if (background1s.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showBackgrounds = 1;
        backgroundSelecionado = 1;
        check2.setPosition(background1s.getPosition());
    }else if (background2s.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showBackgrounds = 1;
        backgroundSelecionado = 2;
        check2.setPosition(background2s.getPosition());
    }else{
        menu = -1;
    }
}

void MenuState::update(cgf::Game* game)
{
}

void MenuState::draw(cgf::Game *game)
{
    game->getScreen()->draw(Menu1);
    game->getScreen()->draw(Menu2);
    game->getScreen()->draw(Menu3);
    if(showAvatar){
        game->getScreen()->draw(option1);
        game->getScreen()->draw(option2);
        game->getScreen()->draw(option3);
        game->getScreen()->draw(option4);
        game->getScreen()->draw(option5);
        if(avatarSelecionado != -1){
            game->getScreen()->draw(check1);
        }
    }
    if(showBackgrounds){
        game->getScreen()->draw(background1s);
        game->getScreen()->draw(background2s);
        if(backgroundSelecionado != -1){
            game->getScreen()->draw(check2);
        }
    }

}


