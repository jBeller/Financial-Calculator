#include "MainFrame.h"

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxFlexGridSizer* mf_fg_sizer;
	mf_fg_sizer = new wxFlexGridSizer(0, 2, 0, 0);
	mf_fg_sizer->SetFlexibleDirection(wxBOTH);
	mf_fg_sizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);


	this->SetSizer(mf_fg_sizer);
	this->Layout();
	mf_menubar = new wxMenuBar(0);
	mf_mb_file_menu = new wxMenu();
	wxMenuItem* mf_fm_new;
	mf_fm_new = new wxMenuItem(mf_mb_file_menu, wxID_ANY, wxString(wxT("New")), wxEmptyString, wxITEM_NORMAL);
	mf_mb_file_menu->Append(mf_fm_new);

	wxMenuItem* mf_fm_open;
	mf_fm_open = new wxMenuItem(mf_mb_file_menu, wxID_ANY, wxString(wxT("Open...")), wxEmptyString, wxITEM_NORMAL);
	mf_mb_file_menu->Append(mf_fm_open);

	wxMenuItem* mf_fm_save;
	mf_fm_save = new wxMenuItem(mf_mb_file_menu, wxID_ANY, wxString(wxT("Save")), wxEmptyString, wxITEM_NORMAL);
	mf_mb_file_menu->Append(mf_fm_save);

	mf_menubar->Append(mf_mb_file_menu, wxT("File"));

	this->SetMenuBar(mf_menubar);

	this->Centre(wxBOTH);
}

MainFrame::~MainFrame()
{
}