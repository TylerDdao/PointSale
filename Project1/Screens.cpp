#include "Screens.h"
#include "Components.h"
#include "React.h"
//void HomeScreen(int& screen)
//{
//	while (screen == Home) {
//		BeginDrawing();
//		ClearBackground(LIGHTGRAY);
//		DrawCurrentTime(5, 5, 50, BLACK);
//		DrawText("Offline", 5, 741, 30, RED);
//		Rectangle registerButton = { 483, 224, 400, 100 };
//		Rectangle managerButton = { 483, 334, 400, 100 };
//		Rectangle quitButton = { 483, 444, 400, 100 };
//
//		DrawRec(registerButton, WHITE, BLACK);
//		DrawTextOnRec(registerButton, "Register", 50, BLACK, CENTER);
//
//		DrawRec(managerButton, WHITE, BLACK);
//		DrawTextOnRec(managerButton, "Manager", 50, BLACK, CENTER);
//
//		DrawRec(quitButton, WHITE, BLACK);
//		DrawTextOnRec(quitButton, "Quit", 50, BLACK, CENTER);
//
//		if (IsButtonClicked(registerButton, MOUSE_BUTTON_LEFT)) {
//			screen = Login_Site;
//		}
//		if (IsButtonClicked(managerButton, MOUSE_BUTTON_LEFT)) {
//			screen = Login_Site;
//		}
//		if (IsButtonClicked(quitButton, MOUSE_BUTTON_LEFT)) {
//			screen = Quit;
//		}
//
//		EndDrawing();
//	}
//}

void Login(int& screen, Core& system)
{
	InputField staffNumberField;
	string employeeId = "\0";
	while (screen == Login_Site) {
		BeginDrawing();
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(5, 5, 50, BLACK);
		Rectangle idInputField = { 433,310,500,100 };
		DrawInputField(idInputField, employeeId, WHITE, BLACK, BLACK, 50, MAX_EMPLOYEE_ID, staffNumberField);
		DrawText("Staff ID", 433, 243, 50, BLACK);
		system.SetCurrentWorking(employeeId);
		Rectangle quitButton = { 433, 425, 200,100 };
		Rectangle loginButton = { 733, 425, 200,100 };
		DrawRec(quitButton, RED, BLACK);
		DrawRec(loginButton, WHITE, BLACK);
		DrawTextOnRec(quitButton, "Quit", 40, BLACK, CENTER);
		DrawTextOnRec(loginButton, "Login", 40, BLACK, CENTER);
		if (IsButtonClicked(quitButton, MOUSE_BUTTON_LEFT)) {
			screen = Quit;
		}
		if (IsButtonClicked(loginButton, MOUSE_BUTTON_LEFT)) {
			if (system.EmployeeIdVerify(employeeId)) {
				Employee* ptr = system.SearchEmployee(employeeId);
				if (ptr->GetDepartment() == MANAGER) {
					screen = M_Home;
				}
				else
				{
					screen = R_Home;
				}
			}
			else {
				screen = Not_Found_404;
			}
		}
		EndDrawing();
	}
}

void Initialize(int screenWidth, int screenHeight, string name, int fps)
{
	InitWindow(screenWidth, screenHeight, name.c_str());
	SetTargetFPS(fps);
}

void DeInitialize()
{
	CloseWindow();
}

void NotFound404(int& screen)
{

	while (screen == Not_Found_404) {
		BeginDrawing();
		
		ClearBackground(LIGHTGRAY);
		DrawCurrentTime(0, 0, 50, BLACK);
		DrawText("404 Error: Not Found", 359, 290, 70, RED);
		Rectangle rec = { 583,384,200,100 };
		DrawRec(rec, WHITE, BLACK);
		DrawTextOnRec(rec, "Return", 40, BLACK, CENTER);
		if (IsButtonClicked(rec, MOUSE_BUTTON_LEFT)) {
			screen = Login_Site;
		}
		EndDrawing();
	}
}
