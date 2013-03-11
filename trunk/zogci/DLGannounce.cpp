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
		m_a=_T("1.ͨ����������\r\n");
		m_a+=_T("\t��Ӧ�ö�ʹ�ó���Ľ�����ге����ա�\r\n");
		m_a+=_T("\t���߲����κ���ʽ�ı�֤��\r\n");
		m_a+=_T("\t����֤������������Ҫ�󣬲���֤���򲻻��������֤����İ�ȫ�ԣ�����֤���ݵ���ȷ�ԡ���ʱ�ԡ��Ϸ��ԡ�\r\n");
		m_a+=_T("\t��ʹ�ó�����������µ����⡢�������Ȩ������ɵ���ʧ�����߶���Ų������಻�е��κη������Ρ�\r\n");
		m_a+=_T("\t�κε�λ�������Ϊͨ���������ṩ��ͼƬ�����ݿ��������ַ�����Ϣ���紫��Ȩ��Ӧ�ü�ʱ��ϵ���ߣ����ṩ���֤����Ȩ��֤������ϸ��Ȩ���֤�����������յ������ļ��󣬽���ȥ����ͼƬ�����ݡ�\r\n");
		m_a+=_T("2.����1\r\n");
		m_a+=_T("\t�˵��Զ˳���Ϊ��ѳ���\r\n");
		m_a+=_T("\t�����ݣ�ͼƬ�����������������߽������ܵ�������Դ��\r\n");
		m_a+=_T("\t������������δ������������ϵ���ߡ�\r\n");
		m_a+=_T("\t�����ݱ�ʹ���ߵ��õȸ�����Ϊ�������µ���Ȩ�����߲����������Ρ�\r\n");
		m_a+=_T("3.����2\r\n");
		m_a+=_T("\t���ƻ�ʹ��ͼƬ��������Ϣ������ҵ��ӯ����Ϊ��\r\n");
		m_a+=_T("\tʹ��ǰ����ݡ�ͼƬ��Դ����Ϣ�����������ϵ��\r\n");
		m_a+=_T("\t�������Ȩ�����и���\r\n");
		break;
	case 2:
		m_a=_T("1.ͨ����؟��\r\n");
		m_a+=_T("\t����ԓ��ʹ�ó���ĽY�����гГ��L�U��\r\n");
		m_a+=_T("\t���߲����κ���ʽ�ı��C��\r\n");
		m_a+=_T("\t�����C����M������Ҫ�󣬲����C���򲻕����e�������C����İ�ȫ�ԣ������C���������_�ԡ����r�ԡ��Ϸ��ԡ�\r\n");
		m_a+=_T("\t��ʹ�ó�����������µ����⡢������֙༰����ɵēpʧ�����ߌ���Ų�ؓ؟���಻�Г��κη���؟�Ρ�\r\n");
		m_a+=_T("\t�κΆ�λ�����J��ͨ�^�������ṩ�ĈDƬ�򔵓����������ַ�����Ϣ�W�j�����࣬��ԓ���rϵ���ߣ��K�ṩ����C���������C����Ԕ���֙���r�C�����������յ������ļ��ᣬ����ȥ����DƬ�򔵓���\r\n");
		m_a+=_T("2.����1\r\n");
		m_a+=_T("\t����X�˳������M����\r\n");
		m_a+=_T("\t�䔵�����DƬ���ԾW�j���������ߌ��M���ܵ�������Դ��\r\n");
		m_a+=_T("\t�������Ĕ���δ��������Ոϵ���ߡ�\r\n");
		m_a+=_T("\t�򔵓���ʹ���߱I�õȂ����Р��������µ��֙࣬���߲�ؓ����؟�Ρ�\r\n");
		m_a+=_T("3.����2\r\n");
		m_a+=_T("\t���}�ƻ�ʹ�ÈDƬ�͔�����Ϣ�����̘I��ӯ���Р���\r\n");
		m_a+=_T("\tʹ��ǰՈ�������DƬ��Դ����Ϣ���M�����Pϵ��\r\n");
		m_a+=_T("\t����F�֙࣬����ؓ؟��\r\n");
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