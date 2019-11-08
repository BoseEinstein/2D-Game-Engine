#include "../include/Collider.h"

Collider::Collider() {
	setColliderSize(0,0,0,0);
}

Collider::Collider(float x, float y, float width, float height)  {

	setColliderSize(x, y, width, height);

}

void Collider::setColliderSize(float x, float y, float width, float height) {

	_x = x;
	_y = y;
	_width = width;
	_height = height;

}



float Collider::getX() {
	return _x;
}

float Collider::getY() {
	return _y;
}

float Collider::getWidth() {
	return _width;
}

float Collider::getHeight() {
	return _height;
}



