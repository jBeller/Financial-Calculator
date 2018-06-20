#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainFrame.h"

class Financial_Calculator : public wxApp
{
public:
	virtual bool OnInit();
};

wxIMPLEMENT_APP(Financial_Calculator);

bool Financial_Calculator::OnInit()
{
	MainFrame *frame = new MainFrame(NULL);
	frame->Show(true);
	return true;
}