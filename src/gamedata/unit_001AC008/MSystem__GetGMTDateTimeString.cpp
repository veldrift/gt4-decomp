/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef long s64;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct D4 { short year; unsigned char month, day; };
struct T4 { unsigned char hour, min, sec, spare; };
struct DT { D4 d; T4 t; };

extern Rep D_00659FA8;
extern "C" void func_00312318(void *, int);
extern "C" void func_00314B20(void *, void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" s64 func_005488F8(void);
extern "C" void func_00579BD8(DT *, long);
extern "C" s32 func_0057DA20(char *, const char *, ...);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);
extern "C" void *func_005C2630(Str *, u32, u32, const char *, u32);
extern char D_00692E28[];

extern "C" void MSystem__GetGMTDateTimeString(s32 *arg0) {
    DT now;
    D4 d;
    T4 t;
    char buf[16];
    s32 h[8];
    Str s;
    func_00579BD8(&now, func_005488F8());
    d = now.d;
    t = now.t;
    char *pb = buf;
    func_0057DA20(pb, D_00692E28, d.year, d.month, d.day, t.hour, t.min, t.sec);
    pb[14] = 0;
    Str *ps = &s;
    {
        Rep *r = &D_00659FA8;
        char *p;
        if (r->sel != 0) {
            p = func_005C2560(r);
        } else {
            p = (char *)(r + 1);
            r->ref++;
        }
        ps->p = p;
    }
    func_005C2630(ps, 0, -1, pb, func_0057F260(pb));
    s32 *ph = h;
    func_00314B20(ph, ps);
    if (arg0 != ph) {
        s32 nv = *ph;
        if (nv != 0) func_003285A8(nv);
        if (*arg0 != 0) func_003285F8(*arg0);
        *arg0 = nv;
    }
    func_00312318(ph, 2);
    {
        Rep *q = (Rep *)(ps->p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
}
