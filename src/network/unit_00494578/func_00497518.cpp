/* compiler: ee-gcc2.96-nogcse */
#include "spr.h"
struct S { char pad[0x20]; int handle, width, height; };
struct Spr { char pad[3]; char flag; char pad4[0x1d8-4]; unsigned long flags; char pad1e0[0x18]; int *cursor; };
extern "C" void func_004971A0(int,int,int) throw();
extern "C" void func_00497200(int,int,int) throw();
extern "C" void func_0049FE28();
extern "C" void func_004A4550(int,int);
extern "C" void func_004A4910();
extern "C" int *func_004A5B70(int);
extern "C" void func_004AA1D8(float,float,float,float);
extern "C" void func_004A6668(float,float,float,float,float,float,float,float);
static inline int *build_packet(S *p, int w, Spr *spr) {
    int *saved = spr->cursor;
    int pw = p->width;
    int ph = p->height;
    if (pw < w) w = pw;
    func_004971A0(p->handle, pw, ph);
    func_00497200(p->handle, pw, ph);
    func_0049FE28();
    int *start = spr->cursor;
    func_004AA1D8(1.0f,1.0f,1.0f,1.0f);
    func_004A4550(3,1);
    func_004A4550(2,1);
    while (w >= 2) {
        int nw = w >> 1;
        if (nw * 2 != w) nw *= 2;
        func_004A4910();
        func_004A6668(0.0f,0.0f,(float)nw,(float)nw,0.0f,0.0f,(float)w,(float)w);
        w = nw;
    }
    int *end = spr->cursor;
    end[0] = 0x60000000;
    end[1] = 0;
    end[2] = 0;
    end[3] = 0;
    end += 4;
    int count = end-start;
    int *out = func_004A5B70(count/4) + count;
    while (start < end) {
        --end;
        --out;
        *out = *end;
    }
    spr->cursor = saved;
    spr->flag = 0;
    spr->flags |= 0x30003;
    return out;
}

extern "C" int *func_00497518(S *p, int w) {
    return build_packet(p, w, (Spr *)spr_base());
}
