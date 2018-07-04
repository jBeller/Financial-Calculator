#ifndef __ADDEDITENTRYDIALOG__
#define __ADDEDITENTRYDIALOG__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/checkbox.h>
#include <wx/button.h>
#include <wx/dialog.h>

class AddEditEntryDialog : public wxDialog
{
private:
	wxPanel* d_name_panel;
	wxStaticText* d_name_text;
	wxTextCtrl* d_name_ctrl;
	wxPanel* d_type_panel;
	wxStaticText* d_type_text;
	wxChoice* d_type_choice;
	wxPanel* d_period_panel;
	wxStaticText* d_period_text;
	wxChoice* d_period_choice;
	wxPanel* d_value_panel;
	wxStaticText* d_value_text;
	wxTextCtrl* d_value_ctrl;
	wxPanel* d_start_panel;
	wxStaticText* d_start_text;
	wxDatePickerCtrl* d_start_date_picker;
	wxPanel* d_end_panel;
	wxStaticText* d_end_text;
	wxDatePickerCtrl* d_end_date_picker;
	wxCheckBox* d_indefinite_check_box;
	wxPanel* d_buttons_panel;
	wxButton* d_ok_button;
	wxButton* d_cancel_button;
protected:
	void d_clicked_ok(wxCommandEvent& event);
	void d_clicked_cancel(wxCommandEvent& event);
public:
	AddEditEntryDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Add/Edit Entry"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(-1, -1), long style = wxDEFAULT_DIALOG_STYLE);
	~AddEditEntryDialog();
};

#endif  // __ADDEDITENTRYDIALOG__