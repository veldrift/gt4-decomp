typedef int s32;
struct V { short d, i; void (*fn)(void *, void *); };
struct VT { char p[0x1C8]; V v1C8; };
struct Obj { char p[0x64]; VT *vt; char q[4]; void *u6C; };
struct Frame {
    char a[0x80];
    s32 r80; char b[0xC]; s32 *p90; char c[0xC];
    s32 u0A0, u0A4; char d[8];
    s32 uB0; char e[4]; char uB8[0x188];
};
extern "C" void func_001CB870(void *);
extern "C" void func_003C0C40(void *, s32, s32);
extern "C" void func_003C0D58(void *, s32, s32);
extern "C" void func_003C0D78(void *, s32, s32);
extern "C" void func_003C0D98(void *, s32, s32);
extern "C" void func_003C0DB8(void *, s32, s32);
extern "C" void func_00444190(void *);
extern "C" void SPEC_DATABASE__CarEquipments__setVariationOrder(void *, s32);
extern "C" void func_0044CF80(void *);
extern "C" void func_0044CF90(void *, s32);
extern "C" void func_0044D278(void *);
extern "C" void func_004AE370(void *, void *, void *, s32);
extern "C" void free(void *);
extern char SettingSerialize__vtable[];
extern "C" s32 SettingSerialize__structor_1(Obj *o) {
    Frame f;
    func_001CB870(&f);
    s32 *pA0 = &f.u0A0;
    s32 *p80 = &f.r80;
    *pA0 = 0;
    f.u0A4 = 0x61AC0;
    func_004AE370(p80, &f, pA0, 1);
    if (*p80 == 0) {
        s32 *s1;
        s32 *pB0 = &f.uB0;
        s1 = f.p90;
        func_0044CF80(pB0);
        *pB0 = (s32)SettingSerialize__vtable;
        func_00444190(f.uB8);
        func_0044D278(s1);
        char *s0 = (char *)s1 + *s1;
        func_003C0D58(o->u6C, s0[0xB01], 0);
        func_003C0C40(o->u6C, s0[0xB00] != 0, 0);
        func_003C0D78(o->u6C, s0[0xB02] != 0, 0);
        func_003C0D98(o->u6C, s0[0xB03], 0);
        func_003C0DB8(o->u6C, s0[0xB04] != 0, 0);
        V *v = &o->vt->v1C8;
        v->fn((char *)o + v->d, s0);
        free(s1);
        *pB0 = (s32)SettingSerialize__vtable;
        SPEC_DATABASE__CarEquipments__setVariationOrder(f.uB8, 2);
        func_0044CF90(pB0, 0);
        return 1;
    }
    return 0;
}
