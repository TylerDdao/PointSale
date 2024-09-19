#include <iostream>
#include "Screens.h"
#include "RegisterScreens.h"
#include "ManagerScreens.h"
#include "Core.h"
#include "Randomizer.h"
#include "FileHandling.h"

#define _NO_CRT_STDIO_INLINE

using namespace std;

int main() {
    srand(time(NULL));
    const int screenWidth = 1366;
    const int screenHeight = 768;
    int screen = Login_Site;
    Initialize(screenWidth, screenHeight, "PointSale", 60);
    bool running = true;
    Core system;
    LoadMenus("Menu.txt", system);
    LoadSales("Sale.txt", system);
    LoadEmployees("Employee.txt", system);
    //system.SetTax(13);
    //Menu menu1("M1");
    //Menu menu2("M2");
    //Menu menu3("M3");
    //Menu menu4("M4");
    //system.AddMenu(menu1);
    //system.AddMenu(menu2);
    //system.AddMenu(menu3);
    //system.AddMenu(menu4);
    //Item item1("Item 1", "I1", 10);
    //system.GetMenu(0)->AddItem(item1);
    //Item item2("Item 2", "I2", 10);
    //system.GetMenu(0)->AddItem(item2);
    //Item item3("Item 3", "I3", 10);
    //system.GetMenu(0)->AddItem(item3);
    //Item item4("Item 4", "I4", 10);
    //system.GetMenu(0)->AddItem(item4);
    //Item item5("Item 5", "I5", 10);
    //system.GetMenu(0)->AddItem(item5);
    //Item item6("Item 6", "I6", 10);
    //system.GetMenu(0)->AddItem(item6);
    //Item item7("Item 7", "I7", 10);
    //system.GetMenu(0)->AddItem(item7);
    //Item item8("Item 8", "I8", 10);
    //system.GetMenu(0)->AddItem(item8);
    //system.SetCurrentWorking("M161105");

    //Order newOrder2(item2, 2);
    //saleTemp.AddOrder(newOrder2);
    //Order newOrder3(item3, 2);
    //saleTemp.AddOrder(newOrder3);
    //Order newOrder4(item4, 2);
    //saleTemp.AddOrder(newOrder4);
    while (running) {
        switch (screen)
        {
        case Home: {
            /*HomeScreen(screen);*/
            /*TestScreen(screen, system);*/
            break;
        }
        case Login_Site: {
            Login(screen, system);
            break;
        }
        case R_Home: {
            RHome(screen, system);
            break;
        }
        case R_Menu: {
            RMenu(screen, system);
            break;
        }
        case R_NewOrder: {
            NewOrder(screen, system);
            break;
        }
        case R_Current_Order: {
            EditOrder(screen, system);
            break;
        }
        case R_Confirm: {
            RConfirm(screen, system);
            break;
        }
        case M_Home: {
            MHome(screen, system);
            break;
        }
        case M_Menu_List: {
            MMenuList(screen, system);
            break;
        }
        case M_Menu_Edit: {
            MMenuEdit(screen, system);
            break;
        }
        case M_Edit_Menu_Id: {
            MEditMenuId(screen, system);
            break;
        }
        case M_Item_Edit: {
            MItemEdit(screen, system);
            break;
        }
        case M_Search_Sale: {
            MSearchSale(screen, system);
            break;
        }
        case M_Sale_List: {
            MSaleList(screen, system);
            break;
        }
        case M_Order_List: {
            MOrderList(screen, system);
            break;
        }
        case M_Employee_List: {
            MEmployeeList(screen, system);
            break;
        }
        case M_Add_Employee: {
            MAddEmployee(screen, system);
            break;
        }
        case M_New_Employee: {
            MNewEmployee(screen, system);
            break;
        }
        case M_Edit_Employee: {
            MEditEmployee(screen, system);
            break;
        }
        case M_Employee_Edited_Info:{
            MEmployeeEditedInfo(screen, system);
            break;
        }
        case M_R_SearchSale: {
            MRSearchSale(screen, system);
            break;
        }
        case M_Report_List: {
            MReportList(screen, system);
            break;
        }
        case M_Finance_Report: {
            MFinanceReport(screen, system);
            break;
        }
        case M_Report_Day_List: {
            MReportDayList(screen, system);
            break;
        }
        case Not_Found_404: {
            NotFound404(screen);
            break;
        }
        case Quit: {
            SaveMenus("Menu.txt", system);
            SaveSales("Sale.txt", system);
            SaveEmployees("Employee.txt", system);
            system.DeleteAll();
            running = false;
            break;
        }
        default:
            //404
            break;
        }
    }

    DeInitialize();
    return 0;
}