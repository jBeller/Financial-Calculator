#ifndef __MAINFRAME_H__
#define __MAINFRAME_H__

#include <wx/msgdlg.h>
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/dataview.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/panel.h>
#include <wx/stattext.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>

#include "AddEditEntryDialog.h"
#include "EntryDataModel.h"
#include "User.h"

class MainFrame : public wxFrame
{
private:
	wxPanel* mf_tree_panel;
	wxDataViewCtrl* mf_data_tree;
	wxButton* mf_tree_add_button;
	wxButton* mf_tree_remove_button;
	wxPanel* mf_results_panel;
	wxStaticText* mf_total_income_text;
	wxStaticText* mf_total_expenses_text;
	wxStaticText* mf_outlook_text;
	wxButton* mf_calculate_button;
	wxMenuBar* mf_menubar;
	wxMenu* mf_mb_file_menu;
	wxMenu* mf_mb_help_menu;

	User* mf_current_user;
	wxDataViewModel* mf_data_model;
protected:
	void mf_add_entry_dialog(wxCommandEvent& event);
	void mf_add_samples(wxCommandEvent& event);
public:
	MainFrame(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Financial Calculator"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(477, 314), long style = wxDEFAULT_FRAME_STYLE | wxTAB_TRAVERSAL);
	~MainFrame();
};

#endif  // __MAINFRAME_H__