// CatchScreenDlg.h : header file
//

#if !defined(AFX_CATCHSCREENDLG_H__536FDBC8_7DB2_4BEF_8943_70DBE8AD845F__INCLUDED_)
#define AFX_CATCHSCREENDLG_H__536FDBC8_7DB2_4BEF_8943_70DBE8AD845F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Resource.h"
#include "EditEx.h"
#ifndef TRACKEREX_
#include "TrackerEx.h"
#endif
/////////////////////////////////////////////////////////////////////////////
// CCatchScreenDlg dialog


class CCatchScreenDlg : public CDialog
{

//**********************************************************************
public:

	int m_xScreen;
	int m_yScreen;

	BOOL m_bShowMsg;                //��ʾ��ȡ���δ�С��Ϣ
	BOOL m_bDraw;                   //�Ƿ�Ϊ��ȡ״̬
	BOOL m_bFirstDraw;              //�Ƿ�Ϊ�״ν�ȡ
	BOOL m_bQuit;                   //�Ƿ�Ϊ�˳�
	CPoint m_startPt;				//��ȡ�������Ͻ�
	CTrackerEx m_rectTracker;     //��Ƥ����
	CBrush m_brush;					//
    HCURSOR m_hCursor;              //���
	CBitmap* m_pBitmap;            //����λͼ

	CRgn m_rgn;						//������������
public:
	HBITMAP CopyScreenToBitmap(LPRECT lpRect,BOOL bSave=FALSE);   //�������浽λͼ
	void DrawTip();                            //��ʾ������ʾ��Ϣ
	void DrawMessage(CRect &inRect,CDC* pDC);       //��ʾ��ȡ������Ϣ
	void PaintWindow();               //�ػ�����
//**********************************************************************
// Construction
public:
	void ChangeRGB();
	
	
	CCatchScreenDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCatchScreenDlg)
	enum { IDD = IDD_CATCHSCREEN_DIALOG };
	CEditEx	m_tipEdit;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCatchScreenDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCatchScreenDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CATCHSCREENDLG_H__536FDBC8_7DB2_4BEF_8943_70DBE8AD845F__INCLUDED_)