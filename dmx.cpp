//---------------------------------------------------------------------------

#pragma hdrstop
#include "main.h"
#include "dmx.h"
#include <iostream>
#include <conio.h>
using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)

dmx::dmx(){
	 dmxBlock[512]; //constructeur
}
void DMX::redColor(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=0;
	dmxBlock[5]=0;
}
void DMX::greenColor(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=0;
	dmxBlock[1]=255;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=0;
	dmxBlock[5]=0;
}
void DMX::blueColor(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=0;
	dmxBlock[1]=0;
	dmxBlock[2]=255;
	dmxBlock[3]=0;
	dmxBlock[4]=0;
	dmxBlock[5]=0;
}
void DMX::whiteColor(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=255;
	dmxBlock[2]=255;
	dmxBlock[3]=255;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}
void DMX::ouvrir(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=255;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=255;
	dmxBlock[5]=255;
}
void DMX::fermer(){
	for (int i = 0; i < 512; i++) {
		dmxBlock[i]=0;
	}
	dmxBlock[0]=0;
	dmxBlock[1]=0;
	dmxBlock[2]=0;
	dmxBlock[3]=0;
	dmxBlock[4]=0;
	dmxBlock[5]=0;
}





