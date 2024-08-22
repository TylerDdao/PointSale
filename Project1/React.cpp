#include "React.h"

bool IsButtonClicked(Rectangle rec, int key) {
	if (CheckCollisionPointRec(GetMousePosition(), rec)) {
		if (IsMouseButtonPressed(key)) {
			return true;
		}
	}
}