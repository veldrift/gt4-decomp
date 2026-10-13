/* GT4 func_00454038: callers' Buf/Tex and the record-lookup helper are declared
 * here with the signatures the solved callees use. */
struct Tex;

struct func_00454EF8_arg0 {
    char pad0[0x1C];
    unsigned short unk1C;
};

struct Obj {
    char pad0[0x20];
    func_00454EF8_arg0 *r20;
};

struct Inner {
    Obj *o0;
    char pad4[0x5B4];
    func_00454EF8_arg0 *r5B8;
};

struct Buf {
    char pad0[8];
    int unk8;
};

struct Outer {
    char pad0[4];
    Inner *inner;
    char pad8[8];
    Buf *buf;
};

extern "C" int func_00454EF8(func_00454EF8_arg0 *arg0, int arg1, int arg2);
extern "C" void func_00107BE8(Buf *b, Tex *t);
extern "C" void ModelSet2__registerExternalTexSet(int arg0, int arg1);

extern "C" void func_00454038(Outer *arg0)
{
    func_00454EF8_arg0 *a = 0;
    Inner *in = arg0->inner;
    Obj *o = in->o0;

    if (o != 0) {
        func_00454EF8_arg0 *t = in->r5B8;
        if (t != 0) {
            a = t;
        } else {
            a = o->r20;
        }
    }
    int n = (int)a->unk1C - 1;
    int v = func_00454EF8(a, n, 0);
    func_00107BE8(arg0->buf, (Tex *)v);
    ModelSet2__registerExternalTexSet(2, arg0->buf->unk8);
}
