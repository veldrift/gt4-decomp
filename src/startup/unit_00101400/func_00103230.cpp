typedef int s32;
struct O { char p0[4]; s32 u4; char p1[0x30]; char u38[0x30]; s32 u68; };
extern "C" void func_00103A40(void *);
extern "C" void func_00104D18(void);
extern "C" void func_00574EB0(void *);
extern "C" void func_00574EE8(void *);
extern "C" void free(int);
extern "C" void func_00103230(O *a) {
    while (a->u4) {
        func_00574EB0((char *)a + 8);
        if (!a->u4) break;
        func_00103A40(a);
        free(a->u68);
        a->u68 = 0;
        func_00104D18();
        func_00574EE8(a->u38);
    }
    func_00574EE8(a->u38);
}
