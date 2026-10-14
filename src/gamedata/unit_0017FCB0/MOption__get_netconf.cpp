typedef int s32;

struct Big {
    s32 d[0x96];
};

struct Inner {
    char pad[0x10];
    s32 p10;
};

struct Handle {
    Inner *p;
    char pad[0xC];
};

struct Src {
    char pad[0x10];
    Big b;
};

struct SrcHandle {
    Src *p;
    char pad[0xC];
};

static inline Inner *get(Handle *h) {
    return h->p;
}

extern "C" void func_0017FAD0(void *arg0, int arg1);
extern "C" void *func_0017FB28(void *arg0, void *arg1);
extern "C" void func_00221AD0(void *arg0, int arg1);
extern "C" void func_00221B28(void *arg0, void *arg1);
extern "C" void func_00221ED0(void *arg0, s32 arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

extern "C" void MOption__get_netconf(void **arg0, void *arg1, s32 arg2, void *arg3) {
    Handle buf;
    if (arg2 > 0) {
        SrcHandle h;
        SrcHandle *ph;
        func_0017FB28(&buf, arg1);
        ph = &h;
        func_00221B28(ph, arg3);
        *(Big *)(buf.p->p10 + 0x13F8) = ph->p->b;
        func_00221AD0(ph, 2);
        func_0017FAD0(&buf, 2);
    } else {
        Handle h;
        Handle *ph;
        func_0017FB28(&buf, arg1);
        ph = &h;
        func_00221ED0(ph, get(&buf)->p10 + 0x13F8);
        if ((void *)arg0 != (void *)ph) {
            void *p = ph->p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_00221AD0(ph, 2);
        func_0017FAD0(&buf, 2);
    }
}
