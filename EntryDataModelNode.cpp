#include "EntryDataModelNode.h"

EntryDataModelNode::~EntryDataModelNode()
{
	for (unsigned int i = 0; i < m_children.size(); i++)
		delete m_children[i];
}
