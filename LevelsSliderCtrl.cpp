#include "settings.h"
#include "LevelsSliderCtrl.h"
#include "const.h"

BEGIN_MESSAGE_MAP(CLevelsSliderCtrl, CSliderCtrl)
	ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
END_MESSAGE_MAP()

void CLevelsSliderCtrl::OnCustomDraw(NMHDR *pNotifyStruct, LRESULT *result)
{
	NMCUSTOMDRAW *pNmcd = (NMCUSTOMDRAW *)pNotifyStruct;

	switch (pNmcd->dwDrawStage) {
	case CDDS_PREPAINT:
		if (GetStyle() & TBS_ENABLESELRANGE) {
			*result = CDRF_NOTIFYITEMDRAW;
		}
		break;
	case CDDS_ITEMPREPAINT:
		switch (pNmcd->dwItemSpec) {
		case TBCD_THUMB: {
			CDC *pDC = CDC::FromHandle(pNmcd->hdc);
			CRect rect = pNmcd->rc;
			int dpiX = GetDeviceCaps(pDC->m_hDC, LOGPIXELSX);
			int dpiY = GetDeviceCaps(pDC->m_hDC, LOGPIXELSY);
			if (GetStyle()&TBS_VERT) {
				rect.DeflateRect(MulDiv(6, dpiX, 96), MulDiv(3, dpiX, 96));
			}
			else {
				rect.DeflateRect(MulDiv(3, dpiX, 96), MulDiv(6, dpiX, 96));
			}
			COLORREF thumbCol = accountSettings.darkMode ? RGB(110, 110, 110) : RGB(170, 170, 170);
			pDC->FillSolidRect(&rect, thumbCol);
			*result = CDRF_SKIPDEFAULT;
			break;
		}
		case TBCD_CHANNEL: {
			CDC *pDC = CDC::FromHandle(pNmcd->hdc);
			int min, max, selmin, selmax;
			bool hot;
			GetRange(min, max);
			GetSelection(selmin, selmax);
			max -= min;
			CRect rect;
			GetChannelRect(&rect);
			if (GetStyle()&TBS_VERT) {
				hot = selmin <= 0;
				// fix windows bug
				if (rect.right > rect.bottom) {
					rect.left ^= rect.top ^= rect.left ^= rect.top; // swap left and top values
					rect.right ^= rect.bottom ^= rect.right ^= rect.bottom; // swap right and bottom values
				}
				rect.DeflateRect(2, 2);
				selmin = (int)(((double)(selmin - min) / max * rect.Height()) + 0.5) + rect.top;
				selmax = (int)(((double)(selmax - min) / max * rect.Height()) + 0.5) + rect.top;
				COLORREF chBgV = accountSettings.darkMode ? RGB(45, 45, 45) : (IsActive ? GetSysColor(COLOR_WINDOW) : pDC->GetBkColor());
				COLORREF chHlV = hot ? RGB(255, 0, 0) : (accountSettings.darkMode ? RGB(11, 110, 230) : GetSysColor(COLOR_HIGHLIGHT));
				pDC->FillSolidRect(CRect(rect.left, rect.top, rect.right, rect.bottom), chBgV);
				pDC->FillSolidRect(CRect(rect.left, selmin, rect.right, selmax), chHlV);
				pDC->ExcludeClipRect(rect);
			}
			else {
				hot = selmax >= GetRangeMax();
				// fix windows bug
				if (rect.bottom > rect.right) {
					rect.left ^= rect.top ^= rect.left ^= rect.top; // swap left and top values
					rect.right ^= rect.bottom ^= rect.right ^= rect.bottom; // swap right and bottom values
				}
				rect.DeflateRect(2, 2);
				selmin = (int)(((double)(selmin - min) / max * rect.Width()) + 0.5) + rect.left;
				selmax = (int)(((double)(selmax - min) / max * rect.Width()) + 0.5) + rect.left;
				COLORREF chBgH = accountSettings.darkMode ? RGB(45, 45, 45) : (IsActive ? GetSysColor(COLOR_WINDOW) : pDC->GetBkColor());
				COLORREF chHlH = hot ? RGB(255, 0, 0) : (accountSettings.darkMode ? RGB(11, 110, 230) : GetSysColor(COLOR_HIGHLIGHT));
				pDC->FillSolidRect(CRect(rect.left, rect.top, rect.right, rect.bottom), chBgH);
				pDC->FillSolidRect(CRect(selmin, rect.top, selmax, rect.bottom), chHlH);
				pDC->ExcludeClipRect(rect);
			}
			*result = CDRF_DODEFAULT | CDRF_NOTIFYPOSTPAINT;
			break;
		}
		}
		break;
	case CDDS_ITEMPOSTPAINT:
		switch (pNmcd->dwItemSpec) {
		case TBCD_CHANNEL: {
			CDC *pDC = CDC::FromHandle(pNmcd->hdc);
			pDC->SelectClipRgn(NULL);
			break;
		}
		}
		break;
	}
}
