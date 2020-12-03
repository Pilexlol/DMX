//---------------------------------------------------------------------------
#ifndef dmxH
#define dmxH
class DMX
{
	private:
		unsigned char dmxBlock[];

	public:
		dmx();
		void ouvrir();
		void fermer();
		void redColor();
		void greenColor();
		void blueColor();
		void whiteColor();
};
//---------------------------------------------------------------------------
#endif
