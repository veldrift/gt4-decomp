typedef int s32;

/* Object layout: vtable word at 0x48, fields at 0x24..0x44; sub-object at 0xC. */
struct Obj00500DD8 {
    char pad0[0x24];
    s32 m24;
    s32 m28;
    s32 m2C;
    s32 m30;
    s32 m34;
    s32 m38;
    s32 m3C;
    s32 m40;
    s32 m44;
    s32 m48;
};

extern char D_00689770[];

extern "C" s32 func_00500EB0(Obj00500DD8 *arg0);
extern "C" void func_005041A0(void *arg0);
extern "C" void func_0060F150(void *a0, void *a1);

extern "C" s32 func_00500DD8(Obj00500DD8 *arg0) {
    arg0->m48 = (s32)D_00689770;
    func_0060F150(arg0, arg0);
    func_005041A0((char *)arg0 + 0xC);
    arg0->m24 = 0x272E;
    arg0->m28 = -1;
    arg0->m2C = -1;
    arg0->m30 = -1;
    arg0->m34 = -1;
    arg0->m38 = -1;
    arg0->m3C = -1;
    arg0->m40 = -1;
    arg0->m44 = 0;
    return func_00500EB0(arg0);
}
