typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct T {
    u32 f0, f4, f8, fC;
    s32 f10, f14, f18;
    s32 pad1C;
    s32 f20;
};

extern u8 D_0064C10E;
extern T D_0086B418;

extern "C" {
s32 func_0053AE58() throw();
s32 func_0053A7D0(s32 *) throw();
}

extern "C" s32 func_0053B120(T *out)
{
    T sp;
    s32 now;

    if (out == 0) {
        return 2;
    }
    if (D_0064C10E == 0) {
        if (func_0053AE58() != 0) {
            return 0x640;
        }
        D_0064C10E = 1;
    }
    sp = D_0086B418;
    if (func_0053A7D0(&now) != 0) {
        return 0x640;
    }
    sp.f0 = sp.f0 + (now - D_0086B418.f20);
    sp.f4 = sp.f4 + sp.f0 / 1000;
    sp.f0 = sp.f0 % 1000;
    sp.f8 = sp.f8 + sp.f4 / 60;
    sp.f4 = sp.f4 % 60;
    sp.fC = sp.fC + sp.f8 / 60;
    sp.f8 = sp.f8 % 60;
    if (sp.fC >= 24) {
        if (func_0053AE58() != 0) {
            return 0x640;
        }
        sp = D_0086B418;
    }
    out->f18 = sp.f18;
    out->f14 = sp.f14;
    out->f10 = sp.f10;
    out->fC = sp.fC;
    out->f8 = sp.f8;
    out->f4 = sp.f4;
    out->f0 = sp.f0;
    out->f20 = sp.f20;
    return 0;
}
