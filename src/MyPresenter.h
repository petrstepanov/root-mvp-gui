#ifndef MYPRESENTER_H
#define MYPRESENTER_H

#include "AbstractPresenter.h"
#include "MyView.h"
#include "Model.h"

class MyView;

class MyPresenter : public AbstractPresenter<Model, MyView> {
public:
	MyPresenter(MyView* view);

	// Slots for View Signals
	void onViewMyNumberSet();
	void onViewSaveDataButtonClick();
	void onViewLoadDataButtonClick();

	// Slots for Model Signals
	void onModelMyNumberSet(Double_t);
	void onModelDataLoaded();

protected:
	// Override base class virtual methods
	Model* instantinateModel() override;
	void connectModelSignals() override;
	void updateViewState() override;

	ClassDefOverride(MyPresenter, 0)
};

#endif /* MyPRESENTER_H */
