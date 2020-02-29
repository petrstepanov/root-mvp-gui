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

	// Override base class virtual functions
	MyPresenter* instantinatePresenter();
	void connectSignals();

	// Calls from Presenter
	void setMyNumber(Double_t);
	Double_t getMyNumber();

	// Declaration of UI objects
	TGNumberEntry* myNumberEntry;
	TGTextButton* saveDataButton;
	TGTextButton* loadDataButton;

protected:
	// Initialize the UI
	void initUI();

	// ROOT's inline methods
	ClassDef(MyView, 0);
};

#endif /* MYVIEW_H */
