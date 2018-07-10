#ifndef __ENTRYDATAMODEL_H__
#define __ENTRYDATAMODEL_H__

#include <wx/dataview.h>
#include "EntryDataModelNode.h"

class EntryDataModel : public wxDataViewModel
{
private:
	EntryDataModelNode* m_root;
	EntryDataModelNode* m_income;
	EntryDataModelNode* m_expense;
public:
	EntryDataModel();
	~EntryDataModel() { delete m_root; }
	wxString GetColumnType(unsigned int col) const override { return wxT("string"); }
	unsigned int GetColumnCount() const override { return 2; }
	void GetValue(wxVariant &variant, const wxDataViewItem &item, unsigned int col) const override;
	bool SetValue(const wxVariant &variant, const wxDataViewItem &item, unsigned int col) override;
	wxDataViewItem GetParent(const wxDataViewItem &item) const override;
	bool IsContainer(const wxDataViewItem &item) const override;
	unsigned int GetChildren(const wxDataViewItem &parent, wxDataViewItemArray &array) const override;
	void InsertIncome(wxString &str, wxString &val);
	void InsertExpense(wxString &str, wxString &val);
};

#endif // __ENTRYDATAMODEL_H__

