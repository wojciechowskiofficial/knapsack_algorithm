#include <cstdlib>
#include <ctime>

#include "Item.h"
#include "Generator.h"

Generator::~Generator() {
	if (this->gen_arr != NULL) {
		delete [] this->gen_arr;
	}
}
bool Generator::gen(int quantity, int max_value, int max_weight) {
	if (this->gen_arr != NULL) {
		return false;
	}
	this->gen_arr = new Item [quantity];
	srand(time(NULL));
	for (int i = 0; i < quantity; i++) {
		this->gen_arr[i].weight = rand() % max_weight + 1;
		this->gen_arr[i].value = rand() % max_value + 1;
		this->gen_arr[i].id = i;
	}
	return true;
}