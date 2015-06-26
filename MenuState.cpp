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
sf::Text Menu1;
sf::Text Menu2;
sf::Font Font;
cgf::Sprite option1;
cgf::Sprite option2;
cgf::Sprite option3;
cgf::Sprite option4;
cgf::Sprite option5;

int menu;
int showAvatar = 0;
int avatarSelecionado = 1;

void MenuState::init()
{
    if (!Font.loadFromFile("C:/Users/gutob_000/Downloads/mflash-cgf-884aeccc8129/bin/data/fonts/arial.ttf"))
    {
        std::cerr << "Error loading verdanab.ttf" << std::endl;
    }

    Menu1.setFont(Font);
    Menu1.setCharacterSize(20);
    Menu1.setString("Escolher Avatares");
    Menu1.setPosition({ 280.f, 160.f });
    Menu2.setFont(Font);
    Menu2.setCharacterSize(20);
    Menu2.setString("Iniciar Jogo");
    Menu2.setPosition({ 280.f, 200.f });

    option1.load("data/img/Char14s.png");
    option1.setPosition({ 280.f, 280.f });
    option2.load("data/img/Char21.png");
    option2.setPosition({ 320.f, 280.f });
	option3.load("data/img/Char31.png");
	option3.setPosition({ 360.f, 280.f });
	option4.load("data/img/Char33.png");
	option4.setPosition({ 400.f, 280.f });
	option5.load("data/img/Char35.png");
    option5.setPosition({ 440.f, 280.f });
    cout << "MenuState Init Successful" << endl;

}

cgf::Sprite MenuState::getSpriteSelecionadoPr(){
    switch(avatarSelecionado){
        case 1:return option1;
        case 2:return option2;
        case 3:return option3;
        case 4:return option4;
        case 5:return option5;
        default: return option1;
    }

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
        }case 2:
            showAvatar = 0;
            game->changeState(PlayState::instance());
            break;
        default:
            showAvatar = 0;
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
        std::cout <<"menu 1!!!" << std::endl;
        menu = 1;
        handleMenu(game);
    }else if(Menu2.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        std::cout <<"menu 2!!!" << std::endl;
        menu = 2;
        handleMenu(game);
    }else if (option1.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 1;
    }else if (option2.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 2;
    }else if (option3.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 3;
    }else if (option4.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 4;
    }else if (option5.getGlobalBounds().contains(clique.mouseButton.x, clique.mouseButton.y)){
        showAvatar = 1;
        avatarSelecionado = 5;
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
    if(showAvatar){
        game->getScreen()->draw(option1);
        game->getScreen()->draw(option2);
        game->getScreen()->draw(option3);
        game->getScreen()->draw(option4);
        game->getScreen()->draw(option5);
    }

}

