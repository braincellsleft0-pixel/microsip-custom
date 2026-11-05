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

#include "StdAfx.h"   
#include "StatusBar.h"   
#include "global.h"
#include "settings.h"

// StatusBar   
IMPLEMENT_DYNAMIC(StatusBar, CStatusBar)
StatusBar::StatusBar()   
{   
}
   
StatusBar::~StatusBar()   
{   
}

BEGIN_MESSAGE_MAP(StatusBar, CStatusBar)
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
END_MESSAGE_MAP()

void StatusBar::OnLButtonUp(UINT nFlags, CPoint point)
{
}

void StatusBar::OnMouseMove(UINT nFlags, CPoint point)
{
}

BOOL StatusBar::OnEraseBkgnd(CDC* pDC)
{
	if (accountSettings.darkMode) {
		CRect rc;
		GetClientRect(&rc);
		pDC->FillSolidRect(&rc, RGB(32, 32, 32));
		return TRUE;
	}
	return CStatusBar::OnEraseBkgnd(pDC);
}

void StatusBar::OnPaint()
{
	if (!accountSettings.darkMode) {
		CStatusBar::OnPaint();
		return;
	}
	CPaintDC dc(this);
	CRect rcClient;
	GetClientRect(&rcClient);
	dc.FillSolidRect(&rcClient, RGB(32, 32, 32));
	dc.SetBkMode(TRANSPARENT);
	dc.SetTextColor(RGB(220, 220, 220));

	CFont* pFont = GetFont();
	CFont* pOldFont = pFont ? dc.SelectObject(pFont) : NULL;

	int count = GetStatusBarCtrl().GetParts(0, NULL);
	for (int i = 0; i < count; i++) {
		CRect rcPane;
		GetItemRect(i, &rcPane);
		HICON hIcon = (HICON)GetStatusBarCtrl().GetIcon(i);
		if (hIcon) {
			DrawIconEx(dc.m_hDC, rcPane.left + 2, rcPane.top + (rcPane.Height() - 16) / 2, hIcon, 16, 16, 0, NULL, DI_NORMAL);
			rcPane.left += 20;
		}
		CString text = GetPaneText(i);
		if (!text.IsEmpty()) {
			dc.DrawText(text, &rcPane, DT_LEFT | DT_VCENTER | DT_SINGLELINE);
		}
	}
	if (pOldFont) dc.SelectObject(pOldFont);
}
