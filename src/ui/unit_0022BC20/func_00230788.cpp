typedef int s32;
typedef unsigned int u32;
struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct Str { char *p; };
struct Obj {
    char pad0[0x1D08];
    s32 unk1D08;
    void *unk1D0C;
    char pad1[0x28];
    s32 unk1D38;
    s32 unk1D3C;
    char pad2[8];
    s32 unk1D48;
};
extern Rep D_00659FA8;
extern char D_006987A8[];
extern char D_006987B0[];
extern char D_006987B8[];
extern char D_006987C8[];
extern char D_006987D0[];
extern "C" void func_002A39D8(void *, s32 *, s32 *);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" char *func_005C2560(Rep *);
extern "C" void func_005C2630(Str *, s32, s32, const char *, s32);

extern "C" Str *func_00230788(Str *out, Obj *o) {
    s32 sp[2];
    const char *name;
    Rep *r;
    if (o->unk1D08 != 0 && o->unk1D48 != 0) {
        func_002A39D8(o->unk1D0C, &sp[0], &sp[1]);
        if (o->unk1D38 == 0) {
            if (o->unk1D3C == 0) { r = &D_00659FA8; name = D_006987A8; }
            else { r = &D_00659FA8; name = D_006987B0; }
        } else {
            if (o->unk1D3C == 0) { r = &D_00659FA8; name = D_006987B8; }
            else { r = &D_00659FA8; name = D_006987C8; }
        }
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        out->p = d;
        func_005C2630(out, 0, -1, name, func_0057F260(name));
    } else {
        name = D_006987D0;
        r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        out->p = d;
        func_005C2630(out, 0, -1, name, func_0057F260(name));
    }
    return out;
}
