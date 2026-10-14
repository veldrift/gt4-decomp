typedef unsigned char u8;
typedef unsigned short u16;
typedef long s64;
struct D32 { char c[32]; };
struct Rec { unsigned key; u16 a; u8 b; u8 c; u8 d; D32 data; };
struct Tmp { u16 a; u8 b; u8 c; };
extern "C" void func_00431E88(void *t, Rec *src, int pos);
extern "C" int func_00432040(void *e, unsigned key);
extern "C" s64 func_00548918(void);
extern "C" void func_00579BD8(void *, s64);

extern "C" int func_004320B8(void *t, unsigned key, u8 d, D32 *data) {
    int pos = func_00432040(t, key);
    if (pos < 0) return 0;
    Rec r;
    Tmp tmp;
    r.key = key;
    Tmp *pt = &tmp;
    s64 v = func_00548918();
    func_00579BD8(pt, v);
    r.a = tmp.a;
    r.b = tmp.b;
    r.c = tmp.c;
    r.d = d;
    r.data = *data;
    func_00431E88(t, &r, pos);
    return 1;
}
