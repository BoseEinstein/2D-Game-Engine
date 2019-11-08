#include "../include/Transform.h"

Transform::Transform()  {
	_x = 0.0f;
	_y = 0.0f;
	_rotate = 0.0f;
	_active = true;
}

Transform::Transform( float x, float y, float rotate)  {
	_x = x;
	_y = y;
	_rotate = rotate;
	_active = true;
}

Transform::~Transform() {

}

float Transform::getX() {
	return _x;
}

float Transform::getY() {
	return _y;
}

float Transform::getRotate() {
	return _rotate;
}

void Transform::setX(float x) {
	_x = x;
}

void Transform::setY(float y) {
	_y = y;
}

void Transform::setRotate(float rotate) {
	_rotate = rotate;
}

bool Transform::isActive() {
	return _active;
}

void Transform::setActive(bool active) {
	_active = active;
}