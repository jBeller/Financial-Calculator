#include "MainFrame.h"

MainFrame::MainFrame(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxFrame(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);
	this->SetBackgroundColour(wxSystemSettings::GetColour(wxSYS_COLOUR_MENU));

	wxFlexGridSizer* mf_fg_sizer;
	mf_fg_sizer = new wxFlexGridSizer(0, 2, 0, 0);
	mf_fg_sizer->SetFlexibleDirection(wxBOTH);
	mf_fg_sizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	mf_tree_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* mf_tree_bSizer;
	mf_tree_bSizer = new wxBoxSizer(wxVERTICAL);

	mf_data_tree = new wxDataViewCtrl(mf_tree_panel, wxID_ANY, wxDefaultPosition, wxSize(-1, -1), 0);
	mf_data_tree->SetMinSize(wxSize(300, 200));

	mf_tree_bSizer->Add(mf_data_tree, 1, wxALL | wxEXPAND, 5);

	wxBoxSizer* mf_tree_buttons_bSizer;
	mf_tree_buttons_bSizer = new wxBoxSizer(wxHORIZONTAL);

	mf_tree_add_button = new wxButton(mf_tree_panel, wxID_ANY, wxT("Add..."), wxDefaultPosition, wxDefaultSize, 0);
	mf_tree_buttons_bSizer->Add(mf_tree_add_button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	mf_tree_remove_button = new wxButton(mf_tree_panel, wxID_ANY, wxT("Remove"), wxDefaultPosition, wxDefaultSize, 0);
	mf_tree_buttons_bSizer->Add(mf_tree_remove_button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	mf_tree_bSizer->Add(mf_tree_buttons_bSizer, 0, wxALIGN_CENTER_HORIZONTAL, 5);


	mf_tree_panel->SetSizer(mf_tree_bSizer);
	mf_tree_panel->Layout();
	mf_tree_bSizer->Fit(mf_tree_panel);
	mf_fg_sizer->Add(mf_tree_panel, 1, wxALL | wxEXPAND, 5);

	mf_results_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* mf_results_bSizer;
	mf_results_bSizer = new wxBoxSizer(wxVERTICAL);

	wxStaticText* mf_time_period_text;
	mf_time_period_text = new wxStaticText(mf_results_panel, wxID_ANY, wxT("Time Period: N/A"), wxDefaultPosition, wxDefaultSize, 0);
	mf_time_period_text->Wrap(-1);
	mf_results_bSizer->Add(mf_time_period_text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	mf_total_income_text = new wxStaticText(mf_results_panel, wxID_ANY, wxT("Total Income: $-.--"), wxDefaultPosition, wxDefaultSize, 0);
	mf_total_income_text->Wrap(-1);
	mf_results_bSizer->Add(mf_total_income_text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	mf_total_expenses_text = new wxStaticText(mf_results_panel, wxID_ANY, wxT("Total Expenses: $-.--"), wxDefaultPosition, wxDefaultSize, 0);
	mf_total_expenses_text->Wrap(-1);
	mf_results_bSizer->Add(mf_total_expenses_text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	mf_outlook_text = new wxStaticText(mf_results_panel, wxID_ANY, wxT("Outlook: $-.--"), wxDefaultPosition, wxDefaultSize, 0);
	mf_outlook_text->Wrap(-1);
	mf_results_bSizer->Add(mf_outlook_text, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);

	mf_calculate_button = new wxButton(mf_results_panel, wxID_ANY, wxT("Calculate..."), wxDefaultPosition, wxDefaultSize, 0);
	mf_results_bSizer->Add(mf_calculate_button, 0, wxALL | wxALIGN_CENTER_HORIZONTAL, 5);


	mf_results_panel->SetSizer(mf_results_bSizer);
	mf_results_panel->Layout();
	mf_results_bSizer->Fit(mf_results_panel);
	mf_fg_sizer->Add(mf_results_panel, 1, wxALL | wxALIGN_CENTER_VERTICAL, 5);


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

	mf_mb_help_menu = new wxMenu();
	wxMenuItem* mf_hm_about;
	mf_hm_about = new wxMenuItem(mf_mb_help_menu, wxID_ANY, wxString(wxT("About")), wxEmptyString, wxITEM_NORMAL);
	mf_mb_help_menu->Append(mf_hm_about);

	mf_menubar->Append(mf_mb_help_menu, wxT("Help"));

	this->SetMenuBar(mf_menubar);


	this->Centre(wxBOTH);
}
MainFrame::~MainFrame()
{
}