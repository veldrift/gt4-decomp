typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

struct Dest {
    s32 w[20];
};

extern "C" void func_0013BD68(void *arg0, int arg1);
extern "C" void func_0013BDC0(void *arg0, void *arg1);
extern "C" void *func_00147D80(void *arg0);
extern "C" void *func_00441248(void *arg0);
extern "C" void *func_004454C0(void *arg0);
extern "C" int func_00448B48(void *arg0, Dest *dest);
extern "C" s32 func_00448948(Dest *arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, int arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline void assign(void **dst, Handle *ph) {
    if ((void *)dst != (void *)ph) {
        void *p = ph->p;
        if (p != 0) {
            func_003285A8(p);
        }
        if (*dst != 0) {
            func_003285F8(*dst);
        }
        *dst = p;
    }
}

extern "C" void func_0013EDF8(void **arg0, void *arg1) {
    Dest d;
    Handle h0;
    Handle h;
    Handle *garage=&h0;func_0013BDC0(garage, arg1);
    if (func_00448B48(func_004454C0(func_00441248(func_00147D80(garage->p))), &d) != 0) {
        s32 v = *(unsigned char *)((char *)&d+0x30);
        Handle *ph = &h;
        func_002FE278(ph, v != 0);
        assign(arg0, ph);
        func_002FC870(ph, 2);
    } else {
        Handle *ph = &h;
        func_002FE278(ph, 0);
        assign(arg0, ph);
        func_002FC870(ph, 2);
    }
    func_0013BD68(garage, 2);
}
