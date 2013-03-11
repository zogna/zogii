// DLGannounce.cpp : implementation file
//

#include "stdafx.h"
#include "zogci.h"
#include "DLGannounce.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern char LanguageFlag;
/////////////////////////////////////////////////////////////////////////////
// CDLGannounce dialog

CDLGannounce::CDLGannounce(CWnd* pParent /*=NULL*/)
	: CDialog(CDLGannounce::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDLGannounce)
	m_a = _T("");
	//}}AFX_DATA_INIT
}


void CDLGannounce::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDLGannounce)
	DDX_Text(pDX, IDC_EDIT_A, m_a);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDLGannounce, CDialog)
	//{{AFX_MSG_MAP(CDLGannounce)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDLGannounce message handlers
BOOL CDLGannounce::OnInitDialog()
{
	Language_SetWndStaticText(this);
	CDialog::OnInitDialog();
	
	Info();

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDLGannounce::Info(void)
{

	switch(LanguageFlag)
	{
	case 1:
		m_a=_T("1.通用免责声明\r\n");
		m_a+=_T("\t您应该对使用程序的结果自行承担风险。\r\n");
		m_a+=_T("\t作者不做任何形式的保证：\r\n");
		m_a+=_T("\t不保证程序满足您的要求，不保证程序不会出错，不保证程序的安全性，不保证数据的正确性、及时性、合法性。\r\n");
		m_a+=_T("\t因使用程序而可能遭致的意外、疏忽、侵权及其造成的损失，作者对其概不负责，亦不承担任何法律责任。\r\n");
		m_a+=_T("\t任何单位或个人认为通过本程序提供的图片或数据可能涉嫌侵犯其信息网络传播权，应该及时联系作者，并提供身份证明、权属证明及详细侵权情况证明。作者在收到上述文件后，将会去除其图片或数据。\r\n");
		m_a+=_T("2.警告1\r\n");
		m_a+=_T("\t此电脑端程序为免费程序。\r\n");
		m_a+=_T("\t其数据，图片来自网络搜索。作者将尽可能的署名来源。\r\n");
		m_a+=_T("\t如有您的数据未被署名，请联系作者。\r\n");
		m_a+=_T("\t因数据被使用者盗用等个人行为，所导致的侵权，作者不负法律责任。\r\n");
		m_a+=_T("3.警告2\r\n");
		m_a+=_T("\t勿复制或使用图片和数据信息用于商业或盈利行为。\r\n");
		m_a+=_T("\t使用前请根据“图片来源”信息，进行相关联系。\r\n");
		m_a+=_T("\t如出现侵权，自行负责。\r\n");
		break;
	case 2:
		m_a=_T("1.通用免責聲明\r\n");
		m_a+=_T("\t您應該對使用程序的結果自行承擔風險。\r\n");
		m_a+=_T("\t作者不做任何形式的保證：\r\n");
		m_a+=_T("\t不保證程序滿足您的要求，不保證程序不會出錯，不保證程序的安全性，不保證數據的正確性、及時性、合法性。\r\n");
		m_a+=_T("\t因使用程序而可能遭致的意外、疏忽、侵權及其造成的損失，作者對其概不負責，亦不承擔任何法律責任。\r\n");
		m_a+=_T("\t任何單位或個人認爲通過本程序提供的圖片或數據可能涉嫌侵犯其信息網絡傳播權，應該及時聯系作者，並提供身份證明、權屬證明及詳細侵權情況證明。作者在收到上述文件後，將會去除其圖片或數據。\r\n");
		m_a+=_T("2.警告1\r\n");
		m_a+=_T("\t此電腦端程序爲免費程序。\r\n");
		m_a+=_T("\t其數據，圖片來自網絡搜索。作者將盡可能的署名來源。\r\n");
		m_a+=_T("\t如有您的數據未被署名，請聯系作者。\r\n");
		m_a+=_T("\t因數據被使用者盜用等個人行爲，所導致的侵權，作者不負法律責任。\r\n");
		m_a+=_T("3.警告2\r\n");
		m_a+=_T("\t勿複制或使用圖片和數據信息用于商業或盈利行爲。\r\n");
		m_a+=_T("\t使用前請根據“圖片來源”信息，進行相關聯系。\r\n");
		m_a+=_T("\t如出現侵權，自行負責。\r\n");
		break;
	default:
		m_a=_T("1------------------------------------------------------------------------Google Translate\r\n");
		m_a+=_T("General Disclaimer\r\n");
		m_a+=_T("\tYou should use the results of the program at their own risk.\r\n");
		m_a+=_T("\tThe authors do not do any form of guarantee:\r\n");
		m_a+=_T("\tAssurance program to meet your requirements, does not guarantee that the program can not go wrong, does not guarantee the security of the program, does not guarantee the accuracy of the data, timeliness and legality.\r\n");
		m_a+=_T("\tUse the program and may result in the imposition of an accident, negligence, tort, and the resulting loss of their takes no responsibility for, nor accept any liability.\r\n");
		m_a+=_T("\tAny unit or individual that images or data provided through this program may be suspected of infringing its Information Network Transmission Right, should contact the author, and provide proof of identity, proof of ownership and detailed proof of infringement. Of the receipt of the above documents, will remove the pictures or data.\r\n");
		m_a+=_T("2------------------------------------------------------------------------Google Translate\r\n");
		m_a+=_T("Warning\r\n");
		m_a+=_T("\tThis PC program for the free program.\r\n");
		m_a+=_T("\tIts data, images from a Web search. Signature of possible sources.\r\n");
		m_a+=_T("\tIf your data is not signed, please contact the author.\r\n");
		m_a+=_T("\tDue to the theft of data by users such as personal behavior, the result of the infringement, without legal responsibility.\r\n");
		m_a+=_T("3------------------------------------------------------------------------Google Translate\r\n");
		m_a+=_T("Warning 2\r\n");
		m_a+=_T("\tDo not copy or use images and data information to be used for commercial or profitable behavior.\r\n");
		m_a+=_T("\tBefore use according to \"Image source\" information and related links.\r\n");
		m_a+=_T("\tIn case of infringement, and responsible for themselves.\r\n");
		break;
	}

	UpdateData(FALSE);
}