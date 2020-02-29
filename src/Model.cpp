/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Model.cpp
 * Author: petrstepanov
 * 
 * Created on October 6, 2017, 2:35 AM
 */

#include "Model.h"
#include <TFile.h>
#include <TTree.h>

// Singleton
Model* Model::instance = NULL;

Model* Model::getInstance(){
	if (!instance){
		instance = new Model();
	}
	return instance;
}

// Constructor
Model::Model(){
	// Initialize the database
	data = new Database();
	data->myNumber = 50;
	// Set database filename
	dataFileName = new TString("database.root");
};

// Write database to file
void Model::saveData(){
	TFile *file = new TFile(dataFileName->Data(), "RECREATE");
	TTree *tree = new TTree("tree", "ROOT Tree");
	tree->Branch("DatabaseBranch", "Database", &data, 16000, 0);
	tree->Fill();
	file->Write();
}

// Read database from file
void Model::loadData(){
	TFile *file = new TFile(dataFileName->Data());
	TTree *tree = (TTree*)file->Get("tree");
	tree->SetBranchAddress("DatabaseBranch",&data);
	tree->GetEntry(0);
	dataLoaded(); // Emit signal
}


void Model::setMyNumber(Double_t number){
	data->myNumber = number;
	myNumberSet(data->myNumber); // Emit signal
}

Double_t Model::getMyNumber(){
	return data->myNumber;
}

// Modal Signals
void Model::myNumberSet(Double_t i){
	Emit("myNumberSet(Double_t)", i);
}

void Model::dataLoaded(){
	Emit("dataLoaded()");
}
