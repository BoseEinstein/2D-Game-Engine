#ifndef TRANSFORM_H
#define TRANSFORM_H


class Transform {
public:
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Create transform at 0,0,0
	*/
	Transform();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Create transform at provided x,y and rotate
	*/
	Transform( float x, float y, float rotate);
	~Transform();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get x position of this transform
	*/
	float getX();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get y position of this transform
	*/
	float getY();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Get rotate position of this transform
	*/
	float getRotate();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set x position of this transform
	*/

	void setX(float x);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Set y position of this transform
	*/
	void setY(float y);
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	set rotate position of this transform
	*/
	void setRotate(float rotate);

	/*
	CAN ACCESS THROUGH GAME ENGINE API
	Return true if this transform is currently active
	*/
	bool isActive();
	/*
	CAN ACCESS THROUGH GAME ENGINE API
	set if this transform is currently active
	*/
	void setActive(bool active);

private:
	float _x;
	float _y;
	float _rotate;
	bool _active;
};

#endif