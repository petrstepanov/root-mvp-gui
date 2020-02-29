/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MyMainFrame.cpp
 * Author: petrstepanov
 *
 * Created on October 15, 2017, 1:47 AM
 */

#include "TImage.h"
#include "MyMainFrame.h"
#include <TApplication.h>
#include <iostream>

MyMainFrame::MyMainFrame() : TGMainFrame(gClient->GetRoot()) {
	SetCleanup(kDeepCleanup);
	SetWindowName("ROOT MVP GUI");

	// Exit this application via the Exit button or Window Manager.
	Connect("CloseWindow()", "MyMainFrame", this, "exit()");
	DontCallClose();
}

MyMainFrame::~MyMainFrame(){
	Cleanup();
}

void MyMainFrame::mapAndResize(){
	MapSubwindows();
	Layout();
	Resize(GetDefaultSize());
	MapWindow();
}

void MyMainFrame::exit(){
	// Exit and close the ROOT session
	gApplication->Terminate();
}
