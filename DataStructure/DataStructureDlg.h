// DataStructureDlg.h : header file
//

#if !defined(AFX_DATASTRUCTUREDLG_H__02AC9E9E_88E9_4CA4_A6EF_9C0215AB818C__INCLUDED_)
#define AFX_DATASTRUCTUREDLG_H__02AC9E9E_88E9_4CA4_A6EF_9C0215AB818C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDataStructureDlg dialog

class CDataStructureDlg : public CDialog
{
// Construction
public:
	CString GetPath();
	CDataStructureDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDataStructureDlg)
	enum { IDD = IDD_DATASTRUCTURE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDataStructureDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDataStructureDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtonHuffman();
	afx_msg void OnButtonGraph();
	afx_msg void OnButtonJosephus();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DATASTRUCTUREDLG_H__02AC9E9E_88E9_4CA4_A6EF_9C0215AB818C__INCLUDED_)
