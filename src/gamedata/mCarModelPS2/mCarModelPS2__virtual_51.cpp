typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Rep { s32 len, cap, ref, sel; };
struct Str { char *p; char pad[0xC]; };
struct S00659988 { const char *name; };
struct StateBlock_00156340 { u32 words[50]; };
struct VEntry { short delta, index; void *fn; };
struct Object { char pad[4]; char *vtable; };

extern char D_0068FD90[];
extern char D_0068FD88[];
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" const char *func_00450BF0(void *);
extern "C" s32 func_00594470(const char *, const char *, s32);
extern "C" s32 func_0057F238(const char *, const char *);
extern "C" void GT4Model__CarModel__getWingFileName(const char *, void *, s32);
extern "C" void func_00576788(void *);
extern "C" void func_005768D8(void *);
extern "C" void func_005767C0(void *);

static inline const char *str_data(Str *str) {
    Rep *rep = (Rep *)(str->p - 0x10);
    if (rep->len == 0) return D_0068FD90;
    str->p[rep->len] = 0;
    return str->p;
}

extern "C" s32 mCarModelPS2__virtual_51(void *arg0, Str *arg1) {
    StateBlock_00156340 state;
    const char *name = str_data(arg1);
    const char *key = (const char *)func_00450BF0((char *)arg0 + 0x2A4);
    if (func_00594470(name, key, 8) == 0) return 0;

    if (func_0057F238(name, D_0068FD88) == 0) {
        state.words[0] = 7;
    } else {
        state.words[0] = 5;
        GT4Model__CarModel__getWingFileName(name, &state.words[1], 1);
    }

    void *render = (char *)arg0 + 0x11C;
    func_00576788(render);
    if (*(s32 *)((char *)arg0 + 0x15C) == 0) {
        *(StateBlock_00156340 *)((char *)arg0 + 0x1DC) = state;
        *(s32 *)((char *)arg0 + 0x15C) = 1;
        func_005768D8(render);
    } else {
        *(s32 *)((char *)arg0 + 0x1D8) = 0;
    }
    func_005767C0(render);
    return 1;
}
