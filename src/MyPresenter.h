/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MyPresenter.h
 * Author: petrstepanov
 *
 * Created on October 6, 2017, 6:31 PM
 */

#ifndef MYPRESENTER_H
#define MYPRESENTER_H

#include "AbstractPresenter.h"
#include "MyView.h"
#include "Model.h"

class MyView;

class MyPresenter : public AbstractPresenter<Model, MyView> {
public:
	MyPresenter(MyView* view);

	// Override base class virtual methods
	Model* instantinateModel() override;
	void connectModelSignals() override;
	void updateViewState() override;

	// Slots for View Signals
	void onViewMyNumberSet();
	void onViewSaveDataButtonClick();
	void onViewLoadDataButtonClick();

	// Slots for Model Signals
	void onModelMyNumberSet(Double_t);
	void onModelDataLoaded();

};

#endif /* MyPRESENTER_H */

