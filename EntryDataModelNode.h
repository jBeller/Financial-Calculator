#ifndef __ENTRYDATAMODELNODE_H__
#define __ENTRYDATAMODELNODE_H__

#include <wx/string.h>
#include <vector>

class EntryDataModelNode
{
private:
	EntryDataModelNode* m_parent;
	std::vector<EntryDataModelNode*> m_children;
public:
	wxString m_name;
	wxString m_value_text;
	bool m_container;
public:
	EntryDataModelNode(EntryDataModelNode* parent, const wxString &name, const wxString &value)
		: m_parent(parent), m_name(name), m_value_text(value), m_container(false) {}
	EntryDataModelNode(EntryDataModelNode* parent, const wxString &branch)
		: m_parent(parent), m_name(branch), m_value_text(""), m_container(true) {}
	~EntryDataModelNode();
	bool m_is_container() const { return m_container; }
	EntryDataModelNode* m_get_parent() { return m_parent; }
	std::vector<EntryDataModelNode*> m_get_children() { return m_children; }
	EntryDataModelNode* m_get_nth_child(unsigned int n) 
		{ return (n >= m_children.size() ? NULL : m_children[n]); }
	void m_insert(EntryDataModelNode* child) { m_children.push_back(child); }
	unsigned int m_get_child_count() const { return m_children.size(); }
};

#endif // __ENTRYDATAMODELNODE_H__