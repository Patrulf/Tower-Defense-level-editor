// TowerDefense.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Engine.h"
#include <iostream>

int main(int argc, char* argv[])
{
	try {
		Engine _engine;
	}
	catch (const std::runtime_error& error)
	{
		std::cerr << error.what() << std::endl;
	}
	catch (...) {
		std::cerr << "An error occured";
	}

    return 0;
}

