#include "Screens.h"

void HomeScreen(int& screen)
{
	while (screen == Home) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(5, 5, 50, BLACK);
		Rectangle registerButton = { 483, 224, 400, 100 };
		Rectangle managerButton = { 483, 334, 400, 100 };
		Rectangle quitButton = { 483, 444, 400, 100 };
		
		DrawRec(registerButton, WHITE, BLACK);
		DrawTextOnRec(registerButton, "Register", 50, BLACK, CENTER);

		DrawRec(managerButton, WHITE, BLACK);
		DrawTextOnRec(managerButton, "Manager", 50, BLACK, CENTER);

		DrawRec(quitButton, WHITE, BLACK);
		DrawTextOnRec(quitButton, "Quit", 50, BLACK, CENTER);

		if (IsButtonClicked(registerButton, MOUSE_BUTTON_LEFT)) {
			screen = R_Login;
		}
		if (IsButtonClicked(registerButton, MOUSE_BUTTON_LEFT)) {
			//Maneger site
		}
		if (IsButtonClicked(quitButton, MOUSE_BUTTON_LEFT)) {
			screen = Quit;
		}

		EndDrawing();
	}
}

void RLogin(int& screen)
{
	InputField staffNumberField;
	int employeeId = 0;
	while (screen == R_Login) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(5, 5, 50, BLACK);
		Rectangle idInputField = { 433,310,500,100 };
		DrawInputField(idInputField,"Staff ID", employeeId, WHITE, BLACK,BLACK,BLACK, 50,50, MAX_EMPLOYEE_ID,staffNumberField);
		Rectangle returnButton = { 433, 425, 200,100 };
		Rectangle loginButton = { 733, 425, 200,100 };
		DrawRec(returnButton, WHITE, BLACK);
		DrawRec(loginButton, WHITE, BLACK);
		DrawTextOnRec(returnButton, "Return", 40, BLACK, CENTER);
		DrawTextOnRec(loginButton, "Login", 40, BLACK, CENTER);
		if (IsButtonClicked(returnButton, MOUSE_BUTTON_LEFT)) {
			screen = Home;
		}
		if (IsButtonClicked(loginButton, MOUSE_BUTTON_LEFT)) {
			screen = R_Home;
		}
		EndDrawing();
	}
}
