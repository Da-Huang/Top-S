// #redo
class Solution {
 public:
  char *m_pData;
  Solution() {
    this->m_pData = NULL;
  }
  Solution(char *pData) {
    this->m_pData = pData;
  }

  // Implement an assignment operator
  Solution operator=(const Solution &object) {
    if (&object == this) return *this;
    
    if (m_pData) delete m_pData;
    if (object.m_pData == nullptr) m_pData = nullptr;
    else {
      m_pData = new char[strlen(object.m_pData) + 1];
      strcpy(m_pData, object.m_pData);
    }
    return *this;
  }
};
