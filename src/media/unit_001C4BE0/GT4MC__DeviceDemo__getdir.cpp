/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;

struct Entry {
    char pad0[0x10];
    s32 f10;
    char pad14[8];
    char name[0x24];
};
struct VE1 { short delta; short idx; s32 (*fn)(void *, void *); };
struct VE2 { short delta; short idx; void *(*fn)(void *, s32); };
struct Self {
    void **vtbl;
    char pad4[0x40];
    s32 f44;
};
extern "C" void func_002EFBF0(void *);
struct Arr { char pad[4]; char *vtbl; };
struct Handle {
    Arr *p;
    char pad[0xC];
};

extern "C" void func_002EFBF0(void *);
extern "C" void func_002ED5C0(void *, s32);
extern "C" s32 hArray__size(void *);
extern "C" void func_00312318(void *, s32);
extern "C" void func_00312370(void *, void *);
extern "C" char *func_00314AD8(void *);
extern "C" s32 func_0032A570(void *, s32);
extern "C" s32 func_0057F260(const char *) throw();
extern "C" void *func_005A48D8(void *, s32, u32);
extern "C" char *func_005A609C(char *, const char *);
extern "C" char *func_005A6AB0(void *, const void *, s32) throw();

struct Str {
    void *p;
    char pad[12];
};

extern "C" s32 GT4MC__DeviceDemo__getdir(Self *self, const char *path, Entry *out, s32 start, s32 cnt) {
    s32 len = func_0057F260(path);
    if (path[len - 2] == '/') {
        char buf[0x80];
        func_005A48D8(out, 0, 0x80);
        func_005A6AB0(out->name, path + 1, len - 3);
        out->name[len - 3] = 0;
        if (cnt >= 4) {
            __builtin_strcpy((char *)out + 0x5C, "thumbnail");
            __builtin_strcpy((char *)out + 0x9C, "icon0.ico");
            __builtin_strcpy((char *)out + 0xDC, "icon.sys");
            cnt = 4;
        } else {
            cnt = 1;
        }
        for (s32 k = 0; k < cnt; k++) {
                Entry *e = out + k;
                func_005A6AB0(buf, path, len - 1);
                func_005A609C(buf + len - 1, e->name);
                VE1 *v = (VE1 *)((char *)self->vtbl + 0x98);
                e->f10 = v->fn((char *)self + v->delta, buf);
        }
        return cnt;
    }
    {
    s32 n = 0;
    Handle h;
    func_002EFBF0(&h);
    func_0032A570(&h, self->f44);
    if (h.p == 0) {
        func_002ED5C0(&h, 2);
        return 0;
    }
    s32 i = start;
    s32 end = i + cnt;
    goto test;
    body: {
        n++;
        VE2 *v = (VE2 *)(h.p->vtbl + 0x70);
        Str s;
        void *item = v->fn((char *)h.p + v->delta, i++);
        Str *ps = &s;
        func_00312370(ps, item);
        char *nm = func_00314AD8(ps->p);
        func_005A48D8(out, 0, 0x40);
        func_005A6AB0(out->name, nm, 0x20);
        func_00312318(ps, 2);
        out++;
    }
    test:
    if (i < end && (u32)i < (u32)hArray__size(h.p)) goto body;
    func_002ED5C0(&h, 2);
    return n;
    }
}
