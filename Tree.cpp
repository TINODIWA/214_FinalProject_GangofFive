#include "Tree.h"

Tree::Tree() : Plant() {
}

Tree::Tree(const Plant& other) : Plant(other) {
}

Tree::~Tree() {
}

Plant* Tree::clone() {
	return new Tree(*this);
}
