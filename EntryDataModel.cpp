#include "EntryDataModel.h"

EntryDataModel::EntryDataModel()
{
	m_root = new EntryDataModelNode(NULL, "Entries");

	m_income = new EntryDataModelNode(m_root, "Income");
	m_root->m_insert(m_income);
	m_expense = new EntryDataModelNode(m_root, "Expenses");
	m_root->m_insert(m_expense);
}
void EntryDataModel::GetValue(wxVariant &variant, const wxDataViewItem &item, unsigned int col) const
{
	wxASSERT(item.IsOk());

	EntryDataModelNode* node = (EntryDataModelNode*)item.GetID();
	if (col == 0)
		variant = node->m_name;
	else if (col == 1)
		variant = node->m_value_text;
}
bool EntryDataModel::SetValue(const wxVariant &variant, const wxDataViewItem &item, unsigned int col)
{
	wxASSERT(item.IsOk());

	EntryDataModelNode* node = (EntryDataModelNode*)item.GetID();
	if (col == 0)
	{
		node->m_name = variant.GetString();
		return true;
	}
	else if (col == 1)
	{
		node->m_value_text = variant.GetString();
		return true;
	}
	return false;
}
wxDataViewItem EntryDataModel::GetParent(const wxDataViewItem &item) const
{
	if (!item.IsOk())
		return wxDataViewItem(0);

	EntryDataModelNode* node = (EntryDataModelNode*)item.GetID();
	if (node == m_root)
		return wxDataViewItem(0);
	return wxDataViewItem((void*) node->m_get_parent());
}
bool EntryDataModel::IsContainer(const wxDataViewItem &item) const
{
	if (!item.IsOk())
		return true;

	EntryDataModelNode* node = (EntryDataModelNode*)item.GetID();
	return node->m_is_container();
}
unsigned int EntryDataModel::GetChildren(const wxDataViewItem &parent, wxDataViewItemArray &array) const
{
	EntryDataModelNode* node = (EntryDataModelNode*)parent.GetID();
	if (!node)
	{
		array.Add(wxDataViewItem((void*)m_root));
		return 1;
	}
	if (node->m_get_child_count() == 0)
		return 0;

	unsigned int count = node->m_get_child_count();
	for (unsigned int pos = 0; pos < count; pos++)
	{
		EntryDataModelNode* child = node->m_get_nth_child(pos);
		array.Add(wxDataViewItem((void*)child));
	}

	return count;
}
void EntryDataModel::InsertIncome(wxString &str, wxString &val)
{
	EntryDataModelNode* child_node = new EntryDataModelNode(m_income, str, val);
	m_income->m_insert(child_node);
}
void EntryDataModel::InsertExpense(wxString &str, wxString &val)
{
	EntryDataModelNode* child_node = new EntryDataModelNode(m_expense, str, val);
	m_expense->m_insert(child_node);
}
