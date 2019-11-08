#pragma once
class Component {
public:
	Component(int parentID);
	int getParentID();
private:
	int _parentID;
};