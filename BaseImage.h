// BaseImage.h: interface for the CBaseImage class.
//
//////////////////////////////////////////////////////////////////////

#define PALVERSION 0x300
#define DIB_HEADER_MARKER ((WORD)('M'<<8) | 'B')

class CBaseImage  : public CObject
{
protected:
	BITMAPFILEHEADER bmpHeader;
	LPBITMAPINFO pBitmapInfo;
	LPSTR m_pDib;
	LPSTR tDib;
	int m_ndumy;
	int m_nColor;
	LPLOGPALETTE lpLogPalette;
	CPalette *cPalette;
	char m_strFileName[512];
public:
	CBitmap *m_pBitmap;
	CBaseImage();
	virtual ~CBaseImage();

public:
	virtual BOOL LoadJpg(LPCSTR) = 0;	// 가상 함수화 된 이유를 생각해보라..
	void MakeBitmap();
	BOOL SaveImage(LPCSTR *file=NULL);
	/*
	Create
	size 크기의 영상을 colornum의 색으로 배경을 backcolor로 만든다.
	*/
	BOOL Create(SIZE size, int colornum,COLORREF backcolor);
	void Create(int Width, int Height, COLORREF * pPal);
	/* 
	GetSize:
	이미지의 크기를 안다.
	*/
	SIZE GetSize();
	/*
	PaintImage
	화면에 이미지를 출력한다.
	*/
	BOOL  PaintImage(int x, int y, HDC hDC);
	/*
	LoadBmp
	filename으로 bmp를 로드한다.
	*/
	BOOL LoadBmp(LPCSTR filename);
	/*
	SaveImage
	bmp 파일을 저장한다.
	*/
	BOOL SaveImage(LPCSTR file);
	//파일명 얻기
	LPCSTR GetFileName(){return m_strFileName;}
	//파일 칼라수 얻기
	int GetColorNum(){	return m_nColor;}
	//팔레트 얻기
	CPalette * GetPalette(){return cPalette;}
	LPBITMAPINFO GetBitmapInfo(){return pBitmapInfo;};


protected:
	/*
	SetBmpInfo:
		szBitmapInfo에 값을 설정하는 함수
		버전업: 16칼라 2칼라 각각 가로 4와 8보다 작은 이미지 설정안됨
	*/
	BOOL SetBmpInfo(SIZE size, int colornum);
	/*
	AllocBmpInfo
	pBitmapInfo를 메모리에 설정하는 함수
	*/
	BOOL AllocBmpInfo(int colornum);
	/*
	CreatePalette
	mode가 1이면 pBitmapInfo 에서
	그렇지 않으면 만듬
	*/

	BOOL CreatePalette(BOOL mode);
	/*
	FindColorInPalette
	팔레트 안에서 fi 의 색이 있는가를 찾는다.
	version up: 비슷한 색으로 가기
	*/
	int FindColorInPalette(COLORREF fi);
	/*
	SetSystemPalette
	윈도우에 설정되어있는 팔레트를 사용한다.
	*/
	BOOL SetSystemPalette(HDC hDC);

};

