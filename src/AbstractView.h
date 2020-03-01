#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

#include <TGFrame.h>

template<class P> class AbstractView: public TGCompositeFrame {
public:
	AbstractView(const TGWindow *w = 0) : TGCompositeFrame(w) {
		presenter = nullptr;
	}

	~AbstractView() {
		delete presenter;
	}

protected:
	P* presenter;

	virtual P* instantinatePresenter()=0;
	virtual void connectPresenterSignals()=0;
	virtual void initializeUI()=0;

	ClassDef(AbstractView,0)
};

#endif /* ABSTRACTVIEW_H */
