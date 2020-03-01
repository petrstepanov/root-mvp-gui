#ifndef ABSTRACTPRESENTER_H
#define ABSTRACTPRESENTER_H

#include <TQObject.h>

template<class M, class V> class AbstractPresenter: public TQObject {
public:
	AbstractPresenter(V* v){
		view = v;
	}

	~AbstractPresenter(){
		delete model;
		delete view;
	}

protected:
	M* model = nullptr;
	V* view = nullptr;

	virtual M* instantinateModel()=0;
	virtual void connectModelSignals()=0;
	virtual void updateViewState()=0;

	ClassDef(AbstractPresenter,0)
};

#endif /* ABSTRACTPRESENTER_H */
