// crossnil.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "crossnil.h"

#include "HGEApplication.h"
#include "exceptions\exception.h"

#include <iostream>


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	try 
	{
		using namespace Application;

		HGEApplication hgeApplication;

		hgeApplication.Execute();

	}
	catch ( exceptions::HGEApplicationException& hgeApplicationException )
	{
		std::cout << hgeApplicationException.what();
	}
	catch ( std::exception& stdException ) 
	{
		std::cout << "std::exception" << stdException.what();
	}
	catch (...)
	{
		std::cout << "Unknown exception";
	}

	return (int)0;
}
