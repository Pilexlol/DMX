#include <vcl.h>
#pragma hdrstop
#include "include/DasHard.h.h"
#include <winsock2.h>
#include "main.h"
#include "dmx.h"
#include "windows.h"
typedef int socklen_t;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Web.Win.Sockets"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
	#if defined (WIN32)
		WSADATA WSAData;
		int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
	#else
		int erreur = 0;
	#endif

	SOCKADDR_IN sin;

	if(!erreur)
	{
		Textco->Visible = false;
		g_dasusbdll=LoadLibrary(L"DasHard2006.dll");

		if(g_dasusbdll)
		{
			DasUsbCommand = (DASHARDCOMMAND)::GetProcAddress((HMODULE)g_dasusbdll,"DasUsbCommand");
		}
		interface_open=DasUsbCommand(DHC_INIT,0,NULL);
		DasUsbCommand(DHC_OPEN,0,0);

		for (int i = 0; i < DMX_MAXCHANNEL + 1; i++)
		{
			dmxBlock[i]=0;
		}
		dmxBlock[0]=0xFF;
		dmxBlock[1]=0xFF;
		dmxBlock[2]=0xFF;
		dmxBlock[3]=0xFF;
		dmxBlock[4]=0xFF;
		dmxBlock[5]=0xFF;
	}
	dmx dmx(dmxBlock);
}
//---------------------------------------------------------------------------
 void __fastcall TForm1::SendTrame()
 {
	if(interface_open > 0)
	{
		try
		{
            //methode d'envoi de trames
			DasUsbCommand(DHC_DMXOUT,DMX_MAXCHANNEL,dmxBlock);
		}
		catch(int x)
		{
		}
	}
 }
 void __fastcall TForm1::FormClose(TObject*Sender,TCloseAction&Action)
 {
	if(interface_open > 0)
	{
		DasUsbCommand(DHC_CLOSE,0,0);
		DasUsbCommand(DHC_EXIT,0,NULL);
	}
	if(g_dasusbdll!=NULL)
	FreeLibrary(g_dasusbdll);
 }
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	SendTrame();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BleuClick(TObject *Sender)
{
	dmx->blueColor();//appel fonction bleu
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BlancClick(TObject *Sender)
{
	dmx->whiteColor(); //appel fonction blanc
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RougeClick(TObject *Sender)
{
	dmx->redColor();//appel fonction rouge
}
//---------------------------------------------------------------------------
void __fastcall TForm1::VertClick(TObject *Sender)
{
	dmx->greenColor(); //appel fonction Vert
}
//----------------------------------------------------------------------------
void __fastcall TForm1::ouvrirClick(TObject *Sender)
{
	dmx->ouvrir();//appel fonction Allumage
}
//---------------------------------------------------------------------------
void __fastcall TForm1::fermerClick(TObject *Sender)
{
	dmx->fermer();//appel fonction Fermeture
	delete dmx;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::quitterClick(TObject *Sender)
{
    exit(1);
}
//---------------------------------------------------------------------------

