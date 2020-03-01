#ifdef __CINT__
#pragma link off all globals;
#pragma link off all classes;
#pragma link off all functions;
#pragma link C++ nestedclasses;

// For signals and slots
#pragma link C++ class Model;
#pragma link C++ class Database;
#pragma link C++ class MyMainFrame;

#pragma link C++ class AbstractView<MyPresenter>+;
#pragma link C++ class MyView;

#pragma link C++ class AbstractPresenter<Model, MyView>+;
#pragma link C++ class MyPresenter;

#endif
