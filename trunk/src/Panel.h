#ifndef __PANEL_H__
#define __PANEL_H__


class Panel
{
	public:
		int textureId;
		Panel( int );
		~Panel( );
		void Render( );
		void drawBot( );
		void drawTips( char *, char * );
};

#endif // __PANEL_H__