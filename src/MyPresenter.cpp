/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyPresenter.cpp
 * Author: petrstepanov
 * 
 * Created on October 6, 2017, 6:31 PM
 */

#include "MyPresenter.h"
#include "MyView.h"
#include "Model.h"

MyPresenter::MyPresenter(MyView* view) : AbstractPresenter<Model, MyView>(view) {
	model = instantinateModel();
	connectModelSignals();
	updateViewState();
}

Model* MyPresenter::instantinateModel() {
	return Model::getInstance();
}

void MyPresenter::connectModelSignals() {
	model->Connect("myNumberSet(Double_t)", "MyPresenter", this, "onModelMyNumberSet(Double_t)");
	model->Connect("dataLoaded()", "MyPresenter", this, "onModelDataLoaded()");
}

void MyPresenter::updateViewState(){
	view->setMyNumber(model->getMyNumber());
}

// Slots for View Signals
void MyPresenter::onViewMyNumberSet(){
	Double_t number = view->getMyNumber();
	model->setMyNumber(number);
}

void MyPresenter::onViewSaveDataButtonClick(){
	model->saveData();
}

void MyPresenter::onViewLoadDataButtonClick(){
	model->loadData();
}

// Slots for Model Signals
void MyPresenter::onModelMyNumberSet(Double_t number){
	view->setMyNumber(number);
}

void MyPresenter::onModelDataLoaded(){
	updateViewState();
}
