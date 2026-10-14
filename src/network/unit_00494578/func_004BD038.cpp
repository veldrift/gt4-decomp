/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
struct Entry {
    int w0;
    int w4;
    char pad8[8];
};
struct TblA {
    char pad0[0x40];
    Entry e[16];
};
struct TblB {
    char pad0[0x50];
    Entry e[16];
};
struct Obj {
    char pad[0x24];
    char *t;
};
struct Req {
    short id;
    char pad[0x12];
    u16 h14;
    char pad16[0xA];
};
extern "C" u32 func_004C0508(char *, int, u32);
extern "C" int func_004BC978(char *, int, void *, int) throw();
extern "C" u32 func_004BC758(char *, int, void *) throw();

extern "C" u32 func_004BD038(Obj *obj, unsigned short id, int a2, int a3, u32 s4) {
    Req sp;
    Req sp20;
    Req *p = &sp;
    Req *q = &sp20;
    u32 sp40;
    u32 s1;
    u32 a0;
    sp40 = func_004C0508(obj->t, id, 0);
    u32 s3;
    if ((id & 0xFF00) == 0x200) {
        s3 = ((TblA *)obj->t)->e[id & 0xFF].w0 + ((TblA *)obj->t)->e[id & 0xFF].w4 - 1;
    } else {
        s3 = ((TblB *)obj->t)->e[id & 0xFF].w0 + ((TblB *)obj->t)->e[id & 0xFF].w4 - 1;
    }
    s1 = sp40;
    if (a2 != 0) {
        p->id = a2;
        if (func_004BC978(obj->t, id, p, 0) <= 0) return 0x80001E70;
        u32 r = func_004BC758(obj->t, id, p);
        if (r == 0) return r;
        s1 = func_004C0508(obj->t, id, r);
        if (s1 == 0) return s1;
    }
    a0 = s3;
    if (a3 != 0) {
        q->id = a3;
        if (func_004BC978(obj->t, id, q, 0) < 0) return 0x80001E70;
        a0 = func_004C0508(obj->t, id, q->h14);
        if (a0 == 0) return a0;
    }
    if (a0 < sp40 + s4 || s3 - s4 < s1 || a0 < s1 + s4) return 0;
    return 1;
}
