#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/sizer.h>
#include <wx/gdicmn.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/frame.h>

class MainFrame : public wxFrame
{
private:
	wxMenuBar* mf_menubar;
	wxMenu* mf_mb_file_menu;

public:
	MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Financial Calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(500, 300), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	~MainFrame();
};

#endif  // __MAINFRAME_H__