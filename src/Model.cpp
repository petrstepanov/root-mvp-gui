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

Model::Model(){
	// Initialize the database
	data = new Database();
	// Set default database values
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
	file->Close();
}

// Read database from file
void Model::loadData(){
	TFile *file = new TFile(dataFileName->Data());
	TTree *tree = (TTree*)file->Get("tree");
	tree->SetBranchAddress("DatabaseBranch",&data);
	tree->GetEntry(0);
	file->Close();
	dataLoaded();                // Emit signal
}

// Data setters and getters
void Model::setMyNumber(Double_t number){
	data->myNumber = number;
	myNumberSet(data->myNumber); // Emit signal
}

Double_t Model::getMyNumber(){
	return data->myNumber;
}

// Model Signals
void Model::myNumberSet(Double_t n){
	Emit("myNumberSet(Double_t)", n);
}

void Model::dataLoaded(){
	Emit("dataLoaded()");
}
