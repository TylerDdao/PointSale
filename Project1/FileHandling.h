#pragma once
#include <iostream>
#include <sstream>
#include <string.h>
#include <fstream>
#include "Core.h"

using namespace std;

bool SaveMenus(string fileName, Core system);
bool LoadMenus(string fileName, Core& system);

bool SaveOrders(ofstream& fp, Sale sale);
bool LoadOrders(istringstream& line, Sale& sale);

bool SaveSales(string fileName, Core system);
bool LoadSales(string fileName, Core& system);

bool SaveEmployees(string fileName, Core system);
bool LoadEmployees(string fileName, Core& system);