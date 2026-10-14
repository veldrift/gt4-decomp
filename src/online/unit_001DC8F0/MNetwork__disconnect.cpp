typedef int s32;

struct RefCounter;

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_001DC5F8(void *arg0, int arg1);
extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" s32 func_001F16A8(s32 arg0);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(struct RefCounter *p);
extern "C" void func_003285F8(struct RefCounter *p);

static inline void assign(void **dst, Handle *ph) {
    if ((void *)dst != (void *)ph) {
        void *p = ph->p;
        if (p != 0) {
            func_003285A8((struct RefCounter *)p);
        }
        if (*dst != 0) {
            func_003285F8((struct RefCounter *)*dst);
        }
        *dst = p;
    }
}

extern "C" void MNetwork__disconnect(s32 *arg0, void *arg1) {
    Handle h0;
    Handle h1;
    s32 flag;
    func_001DC650(&h0, arg1);
    flag = func_001F16A8(*(s32 *)&h0) ^ 1;
    func_001DC5F8(&h0, 2);
    if (flag != 0) {
        Handle *ph = &h1;
        func_002FE278(ph, (void *)0);
        assign((void **)arg0, ph);
        func_002FC870(ph, 2);
    } else {
        Handle *ph = &h0;
        func_002FE278(ph, (void *)1);
        assign((void **)arg0, ph);
        func_002FC870(ph, 2);
    }
}
