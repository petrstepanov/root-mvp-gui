/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   AbstractPresenter.h
 * Author: petrstepanov
 *
 * Created on October 10, 2017, 7:37 PM
 */

#ifndef ABSTRACTPRESENTER_H
#define ABSTRACTPRESENTER_H

#include <TQObject.h>
#include <iostream>

template<class M, class V> class AbstractPresenter: public TQObject {
protected:
	M* model = nullptr;
	V* view = nullptr;

	virtual M* instantinateModel()=0;
	virtual void connectModelSignals()=0;
	virtual void updateViewState()=0;

public:
	AbstractPresenter(V* v){
		view = v;
	}

	~AbstractPresenter(){}

	ClassDef(AbstractPresenter,0)
};

#endif /* ABSTRACTPRESENTER_H */
