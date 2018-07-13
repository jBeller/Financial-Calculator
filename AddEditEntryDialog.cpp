#include "AddEditEntryDialog.h"

AddEditEntryDialog::AddEditEntryDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxFlexGridSizer* d_fg_sizer;
	d_fg_sizer = new wxFlexGridSizer(7, 1, 0, 0);
	d_fg_sizer->SetFlexibleDirection(wxBOTH);
	d_fg_sizer->SetNonFlexibleGrowMode(wxFLEX_GROWMODE_SPECIFIED);

	d_name_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* d_name_bSizer;
	d_name_bSizer = new wxBoxSizer(wxHORIZONTAL);

	d_name_text = new wxStaticText(d_name_panel, wxID_ANY, wxT("Name:"), wxDefaultPosition, wxDefaultSize, 0);
	d_name_text->Wrap(-1);
	d_name_bSizer->Add(d_name_text, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	d_name_ctrl = new wxTextCtrl(d_name_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	d_name_bSizer->Add(d_name_ctrl, 1, wxALL, 5);


	d_name_panel->SetSizer(d_name_bSizer);
	d_name_panel->Layout();
	d_name_bSizer->Fit(d_name_panel);
	d_fg_sizer->Add(d_name_panel, 1, wxEXPAND | wxALL, 5);

	d_type_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* d_type_bSizer;
	d_type_bSizer = new wxBoxSizer(wxHORIZONTAL);

	d_type_text = new wxStaticText(d_type_panel, wxID_ANY, wxT("Type: "), wxDefaultPosition, wxDefaultSize, 0);
	d_type_text->Wrap(-1);
	d_type_bSizer->Add(d_type_text, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	wxString d_type_choiceChoices[] = { wxT("INCOME"), wxT("EXPENSE") };
	int d_type_choiceNChoices = sizeof(d_type_choiceChoices) / sizeof(wxString);
	d_type_choice = new wxChoice(d_type_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, d_type_choiceNChoices, d_type_choiceChoices, 0);
	d_type_choice->SetSelection(0);
	d_type_bSizer->Add(d_type_choice, 0, wxALL | wxEXPAND, 5);


	d_type_panel->SetSizer(d_type_bSizer);
	d_type_panel->Layout();
	d_type_bSizer->Fit(d_type_panel);
	d_fg_sizer->Add(d_type_panel, 1, wxEXPAND | wxALL, 5);

	d_period_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* d_period_bSizer;
	d_period_bSizer = new wxBoxSizer(wxHORIZONTAL);

	d_period_text = new wxStaticText(d_period_panel, wxID_ANY, wxT("Period:  "), wxDefaultPosition, wxDefaultSize, 0);
	d_period_text->Wrap(-1);
	d_period_bSizer->Add(d_period_text, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	wxString d_period_choiceChoices[] = { wxT("WEEKLY"), wxT("MONTHLY"), wxT("BIANNUALLY"), wxT("ANNUALLY") };
	int d_period_choiceNChoices = sizeof(d_period_choiceChoices) / sizeof(wxString);
	d_period_choice = new wxChoice(d_period_panel, wxID_ANY, wxDefaultPosition, wxDefaultSize, d_period_choiceNChoices, d_period_choiceChoices, 0);
	d_period_choice->SetSelection(0);
	d_period_bSizer->Add(d_period_choice, 0, wxALL, 5);


	d_period_panel->SetSizer(d_period_bSizer);
	d_period_panel->Layout();
	d_period_bSizer->Fit(d_period_panel);
	d_fg_sizer->Add(d_period_panel, 1, wxEXPAND | wxALL, 5);

	d_value_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* d_value_bSizer;
	d_value_bSizer = new wxBoxSizer(wxHORIZONTAL);

	d_value_text = new wxStaticText(d_value_panel, wxID_ANY, wxT("$"), wxDefaultPosition, wxDefaultSize, 0);
	d_value_text->Wrap(-1);
	d_value_bSizer->Add(d_value_text, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	d_value_ctrl = new wxTextCtrl(d_value_panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0);
	d_value_bSizer->Add(d_value_ctrl, 1, wxALL, 5);


	d_value_panel->SetSizer(d_value_bSizer);
	d_value_panel->Layout();
	d_value_bSizer->Fit(d_value_panel);
	d_fg_sizer->Add(d_value_panel, 1, wxEXPAND | wxALL, 5);

	d_start_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* d_start_bSizer;
	d_start_bSizer = new wxBoxSizer(wxHORIZONTAL);

	d_start_text = new wxStaticText(d_start_panel, wxID_ANY, wxT("Start Date:"), wxDefaultPosition, wxDefaultSize, 0);
	d_start_text->Wrap(-1);
	d_start_bSizer->Add(d_start_text, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	d_start_date_picker = new wxDatePickerCtrl(d_start_panel, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DROPDOWN);
	d_start_bSizer->Add(d_start_date_picker, 0, wxALL, 5);


	d_start_panel->SetSizer(d_start_bSizer);
	d_start_panel->Layout();
	d_start_bSizer->Fit(d_start_panel);
	d_fg_sizer->Add(d_start_panel, 1, wxEXPAND | wxALL, 5);

	d_end_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* d_end_bSizer;
	d_end_bSizer = new wxBoxSizer(wxHORIZONTAL);

	d_end_text = new wxStaticText(d_end_panel, wxID_ANY, wxT("End Date: "), wxDefaultPosition, wxDefaultSize, 0);
	d_end_text->Wrap(-1);
	d_end_bSizer->Add(d_end_text, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);

	d_end_date_picker = new wxDatePickerCtrl(d_end_panel, wxID_ANY, wxDefaultDateTime, wxPoint(-1, -1), wxDefaultSize, wxDP_DROPDOWN);
	d_end_bSizer->Add(d_end_date_picker, 0, wxALL, 5);

	d_indefinite_check_box = new wxCheckBox(d_end_panel, wxID_ANY, wxT("Indefinite"), wxDefaultPosition, wxDefaultSize, 0);
	d_end_bSizer->Add(d_indefinite_check_box, 0, wxALL | wxALIGN_CENTER_VERTICAL, 5);


	d_end_panel->SetSizer(d_end_bSizer);
	d_end_panel->Layout();
	d_end_bSizer->Fit(d_end_panel);
	d_fg_sizer->Add(d_end_panel, 1, wxEXPAND | wxALL, 5);

	d_buttons_panel = new wxPanel(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL);
	wxBoxSizer* d_buttons_bSizer;
	d_buttons_bSizer = new wxBoxSizer(wxHORIZONTAL);

	d_ok_button = new wxButton(d_buttons_panel, wxID_ANY, wxT("OK"), wxDefaultPosition, wxDefaultSize, 0);
	d_buttons_bSizer->Add(d_ok_button, 1, wxALL, 5);

	d_cancel_button = new wxButton(d_buttons_panel, wxID_ANY, wxT("Cancel"), wxDefaultPosition, wxDefaultSize, 0);
	d_buttons_bSizer->Add(d_cancel_button, 1, wxALL, 5);


	d_buttons_panel->SetSizer(d_buttons_bSizer);
	d_buttons_panel->Layout();
	d_buttons_bSizer->Fit(d_buttons_panel);
	d_fg_sizer->Add(d_buttons_panel, 1, wxEXPAND | wxALL, 5);


	this->SetSizer(d_fg_sizer);
	this->Layout();
	d_fg_sizer->Fit(this);

	this->Centre(wxBOTH);

	// Connect Events
	d_ok_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddEditEntryDialog::d_clicked_ok), NULL, this);
	d_cancel_button->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddEditEntryDialog::d_clicked_cancel), NULL, this);
}
AddEditEntryDialog::~AddEditEntryDialog()
{
	// Disconnect Events
	d_ok_button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddEditEntryDialog::d_clicked_ok), NULL, this);
	d_cancel_button->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(AddEditEntryDialog::d_clicked_cancel), NULL, this);
}
void AddEditEntryDialog::d_clicked_ok(wxCommandEvent& event)
{
	wxString str;
	wxDateTime date;

	d_entry_name = d_name_ctrl->GetLineText(0);

	if (d_type_choice->GetSelection() == 0)       // INCOME
		d_entry_type = EntryType::INCOME;
	else if (d_type_choice->GetSelection() == 1)  // EXPENSE
		d_entry_type = EntryType::EXPENSE;

	switch (d_period_choice->GetSelection())
	{
	case 0:   // WEEKLY
		d_entry_time = EntryTime::WEEKLY;
		break;
	case 1:   // MONTHLY
		d_entry_time = EntryTime::MONTHLY;
		break;
	case 2:   // BIANNUALLY
		d_entry_time = EntryTime::BIANNUALLY;
		break;
	case 3:   // ANNUALLY
		d_entry_time = EntryTime::ANNUALLY;
		break;
	default:  // Error
		break;
	}

	str = d_value_ctrl->GetLineText(0);
	str.ToDouble(&d_entry_value);

	date = d_start_date_picker->GetValue();
	d_entry_start = date.GetTicks();

	if (d_indefinite_check_box->GetValue())
		d_entry_end = 0;
	else
	{
		date = d_end_date_picker->GetValue();
		d_entry_end = date.GetTicks();
	}

	///TODO: Add error checking

	EndModal(wxOK);
}
void AddEditEntryDialog::d_clicked_cancel(wxCommandEvent& event)
{
	EndModal(wxCANCEL);
}