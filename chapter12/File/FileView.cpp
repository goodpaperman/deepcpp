// FileView.cpp : implementation of the CFileView class
//

#include "stdafx.h"
#include "File.h"

#include "FileDoc.h"
#include "FileView.h"

#include <fstream.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFileView

IMPLEMENT_DYNCREATE(CFileView, CView)

BEGIN_MESSAGE_MAP(CFileView, CView)
	//{{AFX_MSG_MAP(CFileView)
	ON_COMMAND(IDM_FILE_WRITE, OnFileWrite)
	ON_COMMAND(IDM_FILE_READ, OnFileRead)
	ON_COMMAND(IDM_REG_WRITE, OnRegWrite)
	ON_COMMAND(IDM_REG_READ, OnRegRead)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFileView construction/destruction

CFileView::CFileView()
{
	// TODO: add construction code here

}

CFileView::~CFileView()
{
}

BOOL CFileView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CFileView drawing

void CFileView::OnDraw(CDC* pDC)
{
	CFileDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CFileView printing

BOOL CFileView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFileView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFileView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CFileView diagnostics

#ifdef _DEBUG
void CFileView::AssertValid() const
{
	CView::AssertValid();
}

void CFileView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFileDoc* CFileView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFileDoc)));
	return (CFileDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFileView message handlers

void CFileView::OnFileWrite() 
{
	// TODO: Add your command handler code here
    //FILE* pFile = fopen("1.txt", "w"); 
    //char* string = "http://www.sunxin.org"; 
    //fwrite(string, 1, strlen(string), pFile); 

    //fseek(pFile, 0, SEEK_SET); 
    //string = "欢迎访问"; 
    //fwrite(string, 1, strlen(string), pFile); 
    ////fclose(pFile); 
    //fflush(pFile); 

    //FILE* file = fopen("1.txt", "w"); 
    //char buf[22] = "http://www.sunxin.org"; 
    //buf[21] = '\0'; 
    //fwrite(buf, 1, 22, file); 
    //fclose(file); 

    //FILE* file = fopen("2.txt", "w"); 
    ////FILE* file = fopen("2.txt", "wb"); 
    //char ch[3]; 
    //ch[0] = 'a'; 
    ////ch[1] = 10; 
    //ch[1] = 13; 
    //ch[2] = 'b'; 
    //fwrite(ch, 1, 3, file); 
    //fclose(file); 

    //FILE* file = fopen("3.txt", "w"); 
    ////int i=98341; 
    //char ch[6] = "98341"; 
    ////itoa(i, ch, 10); 
    //////fwrite(&i, 4, 1, file); 
    //fwrite(ch, 1, 5, file); 
    //fclose(file); 

    //ofstream ofs("4.txt"); 
    //char* buf = "http://www.sunxin.org";  
    //ofs.write(buf, strlen(buf)); 
    //ofs.close(); 

    //HANDLE hFile; 
    //hFile = ::CreateFile("5.txt", GENERIC_WRITE, 0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL, NULL); 
    //LPTSTR lpszText = "http://www.sunxin.org"; 
    //DWORD dwWrites; 
    //WriteFile(hFile, lpszText, strlen(lpszText), &dwWrites, NULL); 
    //CloseHandle(hFile); 

    //CFile file("6.txt", CFile::modeCreate | CFile::modeWrite); 
    //CString str("http://www.sunxin.org"); 
    //file.Write(str, str.GetLength()); 
    //file.Close(); 

	CFileDialog dlg(FALSE); 
	dlg.m_ofn.lpstrTitle = "我的文件保存对话框"; 
	dlg.m_ofn.lpstrFilter = "Text Files(*.txt; *.nmd)\0*.txt;*.nmd\0All Files(*.*)\0*.*\0\0"; 
	dlg.m_ofn.lpstrDefExt = "*.txt"; 
	if(dlg.DoModal() == IDOK)
	{
		CFile file(dlg.GetFileName(), CFile::modeCreate | CFile::modeWrite); 
		file.Write("ni ma de", 5); 
		file.Close(); 
	}
}

void CFileView::OnFileRead() 
{
	// TODO: Add your command handler code here
    //FILE* file = fopen("1.txt", "r"); 
    //char ch[100]; 
    //memset(ch, 0, 100); 
    //fread(ch, 1, 100, file); 
    //fclose(file); 
    //MessageBox(ch); 

    //FILE* file = fopen("1.txt", "r"); 
    //fseek(file, 0, SEEK_END); 
    //int len = ftell(file); 
    //rewind(file); 
    //char* buf = new char[len + 1]; 
    //fread(buf, 1, len+1, file); 
    //buf[len] = '\0'; 
    //fclose(file); 
    //MessageBox(buf); 
    //delete buf; 

    //FILE* file = fopen("2.txt", "r"); 
    ////FILE* file = fopen("2.txt", "rb"); 
    //char ch[100]; 
    //fread(ch, 1, 3, file); 
    //ch[3] = '\0'; 
    //fclose(file); 
    //MessageBox(ch); 

    //ifstream ifs("4.txt"); 
    //char ch[100]; 
    //memset(ch, 0, 100); 
    //ifs.read(ch, 100); 
    //ifs.close(); 
    //MessageBox(ch); 

    //HANDLE hFile; 
    //hFile = CreateFile("5.txt", GENERIC_READ, 0, NULL,OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL); 
    //char ch[100]; 
    //DWORD dwReads; 
    //ReadFile(hFile, ch, 100, &dwReads, NULL); 
    //ch[dwReads] = '\0'; 
    //CloseHandle(hFile); 
    //MessageBox(ch); 

    //CFile file("6.txt", CFile::modeRead); 
    //DWORD dwFileLen = file.GetLength();     
    //char* buf = new char[dwFileLen + 1]; 
    //buf[dwFileLen] = 0; 
    //file.Read(buf, dwFileLen); 
    //file.Close(); 
    //MessageBox(buf); 
    //delete buf; 

	CFileDialog dlg(TRUE); 
	dlg.m_ofn.lpstrTitle = "我的文件打开对话框"; 
	dlg.m_ofn.lpstrFilter = "Text Files(*.txt)\0*.txt\0All Files(*.*)\0*.*\0"; 
	if(dlg.DoModal() == IDOK)
	{
		CFile file(dlg.GetFileName(), CFile::modeRead); 
		char buf[100]; 
		int nRead = file.Read(buf, 99); 
		buf[nRead] = 0; 
		file.Close(); 
		MessageBox(buf); 
	}
}

void CFileView::OnRegWrite() 
{
	// TODO: Add your command handler code here
	HKEY hKey; 
	RegCreateKey(HKEY_LOCAL_MACHINE, "Software\\http://wwww.sunxin.org\\admin", &hKey); 
	RegSetValue(hKey, NULL, REG_SZ, "zhangshan", 10); 
	DWORD age = 30; 
	RegSetValueEx(hKey, "age", 0, REG_DWORD, (CONST BYTE*)&age, 4); 
	RegCloseKey(hKey); 
}

void CFileView::OnRegRead() 
{
	// TODO: Add your command handler code here
    //LONG lValue; 
    //RegQueryValue(HKEY_LOCAL_MACHINE, "Software\\http://wwww.sunxin.org\\admin", NULL, &lValue); 
    //char* buf = new char[lValue]; 
    ////char buf[100]; 
    //RegQueryValue(HKEY_LOCAL_MACHINE, "Software\\http://wwww.sunxin.org\\admin", buf, &lValue); 
    //MessageBox(buf); 
    //delete buf; 

	HKEY hKey; 
	RegOpenKey(HKEY_LOCAL_MACHINE, "Software\\http://wwww.sunxin.org\\admin", &hKey); 
	DWORD dwType, dwValue, dwAge; 
	RegQueryValueEx(hKey, "age", 0, &dwType, (LPBYTE)&dwAge, &dwValue); 
	CString str; 
	str.Format("age = %d", dwAge); 
	MessageBox(str); 
}
