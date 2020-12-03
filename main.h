//---------------------------------------------------------------------------

#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include<System.Classes.hpp>
#include<Vcl.Controls.hpp>
#include<Vcl.StdCtrls.hpp>
#include<Vcl.Forms.hpp>
#include<Vcl.ComCtrls.hpp>
#include<Vcl.ExtCtrls.hpp>
#include"include/DasHard.h.h"
#include <IdBaseComponent.hpp>
#include <IdComponent.hpp>
#include <IdTCPClient.hpp>
#include <IdTCPConnection.hpp>
#include "Web.Win.Sockets.hpp"
#include <IdCustomTCPServer.hpp>
#include <IdTCPServer.hpp>
#include <IdContext.hpp>
#include "dmx.h"
#define DMX_MAXCHANNEL 512
//---------------------------------------------------------------------------
class TForm1 : public TForm
{

__published:	// Composants gérés par l'EDI
	TTimer *Timer1;
	TButton *Bleu;
	TLabel *Textco;
	TButton *Rouge;
	TButton *Vert;
	TButton *Blanc;
	TButton *ouvrir;
	TButton *fermer;
	TTrackBar *TrackBar1;
	TButton *quitter;
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormClose(TObject*Sender,TCloseAction&Action);
	void __fastcall BleuClick(TObject *Sender);
	void __fastcall BlancClick(TObject *Sender);
	void __fastcall RougeClick(TObject *Sender);
	void __fastcall ouvrirClick(TObject *Sender);
	void __fastcall fermerClick(TObject *Sender);
	void __fastcall VertClick(TObject *Sender);
	void __fastcall quitterClick(TObject *Sender);

private:	// Déclarations utilisateur

	HINSTANCE g_dasusbdll;
	typedef int(*DASHARDCOMMAND)(int,int,unsigned char*);
	DASHARDCOMMAND DasUsbCommand;
	int interface_open;
	unsigned char dmxBlock[512];

	UnicodeString text;
	DMX * dmx;//attribut classe

public:		// Déclarations utilisateur
      SOCKET sock;
	__fastcall TForm1(TComponent* Owner);
	void __fastcall SendTrame();//declaration de fonction d'envoi de trames


};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
