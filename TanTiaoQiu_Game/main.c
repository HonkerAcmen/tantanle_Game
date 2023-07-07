#include "Game_H.h"

int main(void) {
	startup();
	
	while (1) {
		show();
		upDateWithoutInput();
		upDateWithInput();
	}
	return 0;
}