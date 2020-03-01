#ifndef MYVIEW_H
#define MYVIEW_H

#include "AbstractView.h"
#include "MyPresenter.h"
#include <TGNumberEntry.h>
#include <Rtypes.h>

class MyPresenter;

class MyView : public AbstractView<MyPresenter> {
public:
	// Constructor & destructor
	MyView(const TGWindow *w = 0);
	virtual ~MyView();

	// Calls from Presenter
	void setMyNumber(Double_t);
	Double_t getMyNumber();

protected:
	// Override base class virtual functions
	MyPresenter* instantinatePresenter() override;
	void connectPresenterSignals() override;
	void initializeUI() override;

	// Declaration of UI objects
	TGNumberEntry* myNumberEntry;
	TGTextButton* saveDataButton;
	TGTextButton* loadDataButton;

	ClassDefOverride(MyView,0)
};

#endif /* MYVIEW_H */
