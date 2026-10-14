extern "C" void func_004479C8(void);
extern "C" void func_00447A00(void);
extern "C" void func_00447A50(void);
extern "C" void func_0048FA10(void);
extern "C" void func_0048F988(void);
extern "C" int func_00108D80(int a);
extern "C" void func_0048F9B8(int a);

extern int D_006186F0;

extern "C" void func_00107FD8(void) {
    if (D_006186F0 != 0) {
        func_004479C8();
        func_00447A00();
        func_00447A50();
        func_0048FA10();
        func_0048F988();
        func_0048F9B8(func_00108D80(0));
        D_006186F0 = 0;
    }
}
