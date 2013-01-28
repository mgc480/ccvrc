#include "Sprite.h"

Sprite::Sprite(std::string _index, sf::Sprite * _sprite){
	index = _index;
	interpolate = false;

	sprite = _sprite;
	isSprite = true;
	isPoly = false;
	isText = false;

	xpos = _sprite->getPosition().x;
	ypos = _sprite->getPosition().y;
}

Sprite::Sprite(std::string _index, sf::Text * _sprite){
	index = _index;
	interpolate = false;

	text = _sprite;
	isSprite = false;
	isPoly = false;
	isText = true;

	xpos = _sprite->getPosition().x;
	ypos = _sprite->getPosition().y;
}

Sprite::Sprite(std::string _index, sf::ConvexShape * _sprite){
	index = _index;
	interpolate = false;

	poly = _sprite;
	isSprite = false;
	isPoly = true;
	isText = false;

	xpos = _sprite->getPosition().x;
	ypos = _sprite->getPosition().y;
}

Sprite::~Sprite(void){
	//delete drawable;
}

void Sprite::setInterpolate(int _destX, int _destY, float _speed){
	destX = _destX;
	destY = _destY;
	speed = _speed * .00001f;
	interpolate = true;
	progress = 0;
	if(isSprite){
		oldX = sprite->getPosition().x;
		oldY = sprite->getPosition().y;
	}
	if(isText){
		oldX = text->getPosition().x;
		oldY = text->getPosition().y;
	}
	if(isPoly){
		oldX = poly->getPosition().x;
		oldY = poly->getPosition().y;
	}
	distance = abs(destX - oldX) + abs(destY - oldY);
}

void Sprite::update(double delta){
	if(interpolate){
		progress += (speed * delta) / distance;
		if(isSprite){
			sprite->setPosition((oldX * (1 - progress) + destX * progress), (oldY * (1 - progress) + destY * progress));
			xpos = sprite->getPosition().x;
			ypos = sprite->getPosition().y;
		}
		if(isText){
			text->setPosition((oldX * (1 - progress) + destX * progress), (oldY * (1 - progress) + destY * progress));
			xpos = text->getPosition().x;
			ypos = text->getPosition().y;
		}
		if(isPoly){
			poly->setPosition((oldX * (1 - progress) + destX * progress), (oldY * (1 - progress) + destY * progress));
			xpos = poly->getPosition().x;
			ypos = poly->getPosition().y;
		}

		if(progress >= 1){
			xpos = destX;
			ypos = destY;
			progress = 0;
			if(isSprite){
				sprite->setPosition(destX, destY);
			}
			if(isText){
				text->setPosition(destX, destY);
			}
			if(isPoly){
				poly->setPosition(destX, destY);
			}
			interpolate = false;
		}
	}
}