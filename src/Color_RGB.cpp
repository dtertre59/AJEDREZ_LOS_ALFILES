#include "Color_RGB.h"

Color_RGB::Color_RGB()
{
	rojo = 255;
	verde = 255;
	azul = 255;
}
void Color_RGB::Set_color(unsigned char  c)
{

	if (c == 'b')
	{
		rojo = 255;
		verde = 245;
		azul = 157;
	}else if (c == 'n')
	{
		rojo = 55;
		verde = 34;
		azul = 8;
	}else
	{
		rojo = 255;
		verde = 255;
		azul = 255;
	}
}