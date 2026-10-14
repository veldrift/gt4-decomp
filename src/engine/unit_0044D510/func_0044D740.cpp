typedef int s32;
typedef long long s64;

struct P2 { s32 a; s32 b; };
struct Obj { char p0[0x28]; s64 p28; struct P2 p30; char p38[8]; };
struct Hdl { char p0[0x4C]; void *p4C; char p50[0x74 - 0x50]; s32 p74; char p78[0x94 - 0x78]; s32 p94; };

extern "C" {
void FileInstrumentStream__structor_0(void *o);
void FileInstrumentStream__structor_1(void *o, int flags);
struct Hdl *func_004AE1F8(void *ws, const char *path);
void func_004AEFF0(void *ws);
void func_004AF0A0(void *ws, int flags);
void func_004AF3E8(struct Hdl *h);
void func_004AF568(struct Hdl *h);
}

extern "C" s32 func_0044D740(const char *arg0, s64 arg1, s32 arg2, s32 arg3)
{
    char ws[0xB0];
    struct Obj o;
    struct P2 t;
    s32 ret = 0;
    struct Hdl *h;

    func_004AEFF0(ws);
    h = func_004AE1F8(ws, arg0);
    if (h != 0) {
        struct P2 *pt;
        FileInstrumentStream__structor_0(&o);
        pt = &t;
        pt->a = arg2;
        t.b = arg3;
        o.p28 = arg1;
        o.p30 = *pt;
        h->p74 = 0;
        h->p4C = &o;
        func_004AF3E8(h);
        ret = h->p94;
        func_004AF568(h);
        FileInstrumentStream__structor_1(&o, 2);
    }
    func_004AF0A0(ws, 2);
    return ret;
}
