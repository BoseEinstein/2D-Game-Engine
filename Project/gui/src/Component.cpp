#include "../include/Component.h"

Component::Component(int parentID) {
	_parentID = parentID;
}

int Component::getParentID() {
	return _parentID;
}