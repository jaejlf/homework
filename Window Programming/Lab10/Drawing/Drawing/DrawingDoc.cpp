﻿
// DrawingDoc.cpp: CDrawingDoc 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Drawing.h"
#endif

#include "DrawingDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CDrawingDoc

IMPLEMENT_DYNCREATE(CDrawingDoc, CDocument)

BEGIN_MESSAGE_MAP(CDrawingDoc, CDocument)
END_MESSAGE_MAP()


// CDrawingDoc 생성/소멸

CDrawingDoc::CDrawingDoc() noexcept
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CDrawingDoc::~CDrawingDoc()
{
}

BOOL CDrawingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CDrawingDoc serialization

void CDrawingDoc::Serialize(CArchive& ar)
{
	x.Serialize(ar);
	y.Serialize(ar);
}

void CDrawingDoc::Add(CPoint point)
{
	x.Add(point.x);
	y.Add(point.y);
}
int CDrawingDoc::Size()
{
	return x.GetSize();
}
CPoint CDrawingDoc::GetPoint(int i)
{
	return CPoint(x[i], y[i]);
}
#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CDrawingDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CDrawingDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CDrawingDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CDrawingDoc 진단

#ifdef _DEBUG
void CDrawingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDrawingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CDrawingDoc 명령
