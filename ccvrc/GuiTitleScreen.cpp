#include "GuiTitleScreen.h"
#include "StateHandler.h"

GuiObject* titleScreenBg;
GuiObject* logo;
sf::Text * test;

bool transition = false;
float speed = 0.0f;

GuiTitleScreen::GuiTitleScreen(StateHandler* handler) : GameState("lua/main_menu.lua", handler){
	titleScreenBg = new GuiObject("title screen bg");
	titleScreenBg->setTexture(*stateHandler->getTexture(0));
	titleScreenBg->setPosition(0, 0);
	bgList.push_back(titleScreenBg);

	logo = new GuiObject("logo");
	logo->setTexture(*stateHandler->getTexture(1));
	logo->setPosition((*stateHandler->getWindowWidth() / 2) - (logo->getTexture()->getSize().x / 2), 
		(*stateHandler->getWindowHeight() / 2) - (logo->getTexture()->getSize().y / 2));
	guiList.push_back(logo);

	test = new sf::Text("sumoz", *stateHandler->getFont(), 128);
	test->setPosition(0, 0);
	test->setColor(sf::Color(255, 0, 255));

	fgList.push_back(test);
}

GuiTitleScreen::~GuiTitleScreen(void){
	
}

void GuiTitleScreen::update(double delta){

	if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
		transition = true;
	}else if(transition){
		speed += 0.0005f;
		logo->move(0, speed);

		if(logo->getPosition().y > *stateHandler->getWindowHeight()){
			stateHandler->setState(1);
		}
	}
}