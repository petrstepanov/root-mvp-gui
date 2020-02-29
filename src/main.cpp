//#include <TROOT.h>
#include <TApplication.h>
//#include <TGFrame.h>
#include "MyView.h"
#include "MyMainFrame.h"

int main(int argc, char **argv) {
	TApplication* app = new TApplication("MyApplication", &argc, argv);

	MyMainFrame* myMainFrame = new MyMainFrame();
	MyView* myView = new MyView(myMainFrame);
	myMainFrame->AddFrame(myView, new TGLayoutHints(kLHintsExpandX | kLHintsExpandY));
	myMainFrame->mapAndResize();

	app->Run();
    return 0;
}
