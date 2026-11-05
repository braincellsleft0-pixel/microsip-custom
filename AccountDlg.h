#include <afxbutton.h>
#include <vector>

/*
 * Copyright (C) 2011-2024 MicroSIP (http://www.microsip.org)
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#pragma once

#include "define.h"

#include "resource.h"
#include "const.h"
#include "settings.h"

class AccountDlg :
	public CDialog
{
public:
	//CFont m_font;
	AccountDlg(CWnd* pParent = NULL);	// standard constructor
	~AccountDlg();
	enum { IDD = IDD_ACCOUNT };

	void Load(int id);

private:
	int accountId;
	Account m_Account;
protected:
	virtual BOOL OnInitDialog();
	afx_msg void OnDestroy();
	virtual void PostNcDestroy();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClose();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnChangePassword();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void UpdateControlPositions();
	CMFCButton m_btnSave;
	CMFCButton m_btnCancel;
	CMFCButton m_btnRemove;

private:
	CSize m_szMin;
	CSize m_szInitial;
	struct CtrlInfo {
		HWND hWnd;
		CRect rc;
		bool moveX;
		bool moveY;
		bool sizeX;
	};
	std::vector<CtrlInfo> m_ctrls;
	CBrush m_brDarkBg;
	CBrush m_brDarkEdit;
	int m_nScrollPos;
	int m_nContentHeight;
	afx_msg void OnNMClickSyslinkSipServer(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkSipProxy(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkUsername(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkDomain(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkAuthID(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkPassword(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkName(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkDialingPrefix(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkDialPlan(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkHideCID(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkVoicemail(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkEncryption(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkTransport(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkPublicAddress(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkPublishPresence(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkIce(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkRewrite(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkSessionTimer(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMClickSyslinkDisplayPasswod(NMHDR *pNMHDR, LRESULT *pResult);
};
