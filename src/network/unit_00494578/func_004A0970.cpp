#include "spr.h"
struct Obj { char pad[0x8c]; short x,y; unsigned short w,h,dw,dh; char pad2; unsigned char interlace,mode,field; };
struct Spr { char pad[0x10]; unsigned char mode; char pad2[2]; unsigned char n; char pad3[0xa8-0x14]; long addr; char pad4[0xc0-0xb0]; long display; long zero; };
extern "C" void func_004A0970(Obj *o) {
    int mx=0;
    int x=o->x, y=o->y, w=o->w, h=o->h;
    int height, dy, dx;
    switch(o->mode) {
    case 3: height=512; dy=36; dx=675; break;
    case 0x50: {
        int total=1280;
        dx=total/o->dw;
        mx=dx;
        height=448;
        dy=(448-h)/2+48;
        x-=320/mx;
        dx=(total-w*mx)/2+640;
        break;
    }
    case 0x51: {
        int total=1920;
        dx=total/o->dw;
        mx=dx;
        height=1080;
        dy=(512-h)/2+36;
        x=x+(-416/mx)+3;
        dx=(total-w*mx)/2+640;
        break;
    }
    default: height=448; dy=24; dx=640; break;
    }
    if(mx==0) mx=(o->dw+2559)/o->dw;
    int my=height/o->dh;
    if(my==0) my=1;
    if(o->interlace==1) { dy*=2; h*=2; }
    Spr *s=(Spr *)spr_base();
    if(o->field==0) h>>=1;
    if(s->mode==1) s->addr=(s->n<<8)|0x63; else s->addr=0x62;
    s->zero=0;
    long xbits=((x*mx+dx)&0xfff) | ((long)(my*h-1)<<44);
    long mbits=((long)(my-1)<<27)|((long)(mx-1)<<23);
    long ybits=((long)((dy+y)&0xfff)<<12)|((long)(mx*w-1)<<32);
    s->display=xbits|mbits|ybits;
}
