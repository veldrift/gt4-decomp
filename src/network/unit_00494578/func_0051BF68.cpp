typedef unsigned int u32;
struct Api { char pad[0xc]; void (*close)(); };
struct Api2 { char pad[0x60]; int (*close)(int); };
extern int D_0064AE0C,D_0064AE14,D_0064AE18,D_0064AE1C,D_0064AE20;
extern u32 D_0064AE10;
extern Api *D_0064B4B0;
extern Api2 *D_0064B710;
extern unsigned char D_008637A8[];
extern "C" int func_0051BE28() throw();
extern "C" void func_0051BE60() throw();
extern "C" int func_0051CCD0();
extern "C" void func_0051DB90(u32);
extern "C" int func_00538C68(int *);
extern "C" int func_005397D0(unsigned char *);
extern "C" int func_0051BF68() {
    u32 i=0;
    int r=func_0051BE28();
    if (r) return r;
    if (D_0064AE0C==1) {
        for (;i<D_0064AE10;i++) func_0051DB90(i);
        func_0051CCD0();
        D_0064B4B0->close();
        int *p=&D_0064AE14;
        if (*p) func_00538C68(p);
        *p=0;
        D_0064AE10=0;
        if (D_0064AE18) {
            func_00538C68(&D_0064AE18);
            D_0064AE1C=0;
        }
        if (D_0064B710) D_0064B710->close(0);
    }
    int *ref=&D_0064AE0C;
    --*ref;
    func_0051BE60();
    if (*ref==0) {
        D_0064AE20=0;
        int result=func_005397D0(D_008637A8);
        if (result) return result;
    }
    return 0;
}
