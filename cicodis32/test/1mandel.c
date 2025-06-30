#include <stdio.h>
#include <conio.h>
#include <dos.h>
#include <math.h>

#define W 320
#define H 200

int main()
{
        double  r  = 1.0,
                cx = -0.5,
                cy = 0.0,
                minx = cx - r,
                maxx = cx + r,
                miny = cy - r,
                maxy = cy + r,
                dx = maxx-minx,
                dy = maxy-miny;

        char *vgamem=(char*)0xa0000;
        
        const unsigned maxiter=256;


        union REGS reg;
        reg.w.ax = 0x13;
        int386(0x10,&reg,&reg);

        _asm {
                xor eax, eax
        }
        for (int i=0;i<256;++i)
        {
                outp(0x3c8,i);
                outp(0x3c9,32-31*(cos(i*0.017*1)));
                outp(0x3c9,32-31*(cos(i*0.017*3)));
                outp(0x3c9,32-31*(cos(i*0.017*5)));
        }

        for (int y=0;y<H;++y)
        {
                cy = miny + dy*y/H;
                for (int x=0;x<W;++x)
                {
                        cx = minx + dx*x/W;
                        double z1=0,z2=0;

                        int i=0;
                        while (i<=maxiter)
                        {
                                double n1=z1*z1-z2*z2+cx;
                                double n2=2*z1*z2+cy;
                                z1=n1;
                                z2=n2;
                                if ((z1*z1+z2*z2) >= 4.0) break;
                                i++;
                        }
                        if (i < maxiter)
                        {
                                *(vgamem+y*W+x) = 255*((double)i/maxiter);
                        }
                }

        }
        getch();
        reg.w.ax=3;
        int386(0x10,&reg,&reg);
        return 1;
}