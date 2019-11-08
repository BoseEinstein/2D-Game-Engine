#pragma once

class Collider {

public:
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Construct an empty collider with zero for x,y,w, and h
	*/
	Collider();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Construct a collider with the values provided
	*/
	Collider( float x, float y, float width, float height);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Change the size of the collider to the values provided*/
	void setColliderSize(float x, float y, float width, float height);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get relative x position of collider
	*/
	float getX();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get relative y position of collider
	*/
	float getY();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get width of collider
	*/
	float getWidth();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get height of collider
	*/
	float getHeight();




private:

	float _x;
	float _y;
	float _width;
	float _height;

};
