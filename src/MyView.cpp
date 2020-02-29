#include "MyView.h"
#include "MyPresenter.h"
#include <TGFrame.h>

MyView::MyView(const TGWindow* w) : AbstractView<MyPresenter>(w) {
	initUI();
	presenter = instantinatePresenter();
	connectSignals();
}

MyView::~MyView() {
	Cleanup();
}

// Initialize UI widgets
void MyView::initUI(){
	SetLayoutManager(new TGVerticalLayout(this));
	// Number textbox
	myNumberEntry = new TGNumberEntry(this, 0, 6, -1, TGNumberFormat::kNESRealTwo, TGNumberFormat::kNEAAnyNumber, TGNumberFormat::kNELLimitMinMax, 0, 100);
	AddFrame(myNumberEntry, new TGLayoutHints(kLHintsCenterX | kLHintsTop, 100, 100, 50, 10));
	// Save database button
	saveDataButton = new TGTextButton(this, "Save data");
	AddFrame(saveDataButton, new TGLayoutHints(kLHintsCenterX | kLHintsTop, 0, 0, 0, 10));
	// Load database button
    loadDataButton = new TGTextButton(this, "Load data");
	AddFrame(loadDataButton, new TGLayoutHints(kLHintsCenterX | kLHintsTop, 0, 0, 0, 50));
}

// Setters and getters
void MyView::setMyNumber(Double_t number) {
	myNumberEntry->SetNumber(number);
}

Double_t MyView::getMyNumber(){
	return myNumberEntry->GetNumberEntry()->GetNumber();
}

// Instantinate the Presenter
MyPresenter* MyView::instantinatePresenter() {
	return new MyPresenter(this);
}

// Connect View signals to Presenter slots
void MyView::connectSignals(){
	myNumberEntry->Connect("ValueSet(Long_t)", "MyPresenter", presenter, "onViewMyNumberSet()");
	saveDataButton->Connect("Clicked()", "MyPresenter", presenter, "onViewSaveDataButtonClick()");
	loadDataButton->Connect("Clicked()", "MyPresenter", presenter, "onViewLoadDataButtonClick()");
}
