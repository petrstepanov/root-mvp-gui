/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Model.h
 * Author: petrstepanov
 *
 * Created on October 6, 2017, 2:35 AM
 */

#ifndef MODEL_H
#define MODEL_H

#include <RtypesCore.h>
#include <iostream>
#include <TQObject.h>
#include "Database.h"

class Model : public TQObject {
public:
	static Model* getInstance();

	// Data setters and getters
	void setMyNumber(Double_t num);
	Double_t getMyNumber();

	// Save and load data methods
	void saveData();
	void loadData();

	// Signals to Presenter
	void myNumberSet(Double_t num); // *SIGNAL*
	void dataLoaded();              // *SIGNAL*

private:
	Model();
	static Model* instance;

	Database* data;
	TString* dataFileName;

	ClassDef(Model, 0)
};

#endif /* MODEL_H */

