/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "spr.h"
struct SPR { unsigned char pad[7]; unsigned char mode; };
struct S { char pad[0xC]; int src, sw, sh; char pad18[8]; int handle, width, height; };
extern "C" void func_004971A0(int,int,int) throw();
extern "C" void func_00497200(int,int,int) throw();
extern "C" void func_004AB040(int);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004A4550(int,int);
extern "C" int func_004A6498(int,int,int,int,int,int,int,int);
extern "C" int func_00497298(S *p, int x0, int y0, int x1, int y1) {
    volatile SPR *spr = (volatile SPR *)spr_base();
    int w = x1 - x0;
    int h = y1 - y0;
    int pw = p->width;
    int ph = p->height;
    if (pw < w) w = pw;
    if (ph < h) h = ph;
    if (spr->mode) { y0 /= 2; y1 /= 2; }
    func_004971A0(p->handle,pw,ph);
    func_00497200(p->src,p->sw,p->sh);
    func_004AB040(5);
    func_004AA1D8(1.0f,1.0f,1.0f,1.0f);
    func_004A4550(3,0);
    func_004A4550(2,0);
    return func_004A6498(0,0,w,h,x0,y0,x1,y1);
}
