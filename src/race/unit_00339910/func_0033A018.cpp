typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef float f32;

struct VEnt { s16 off; s16 pad; void *(*fn)(void *, s32); };
struct VTab { char pad[0xD0]; VEnt e; };
struct List { u32 count; s32 unk4; char **items; };
struct B { char pad[0x60]; List *unk60; };
struct A {
    char pad[0x64 - 0];
    char *unk64;
    char pad2[4];
    B *unk6C;
};

extern char D_0069F2F8[];
extern "C" void func_0045B4D8(void *, void *, void *);
extern "C" void func_00339FE0(void *, void *, f32) throw();
extern "C" void func_00339F38(void *, char *, f32, void *, s32) throw();
extern "C" void func_003E5408(void *, void *);
extern "C" void func_003C2990(void *, void *);
extern "C" void func_0045B548(void *, void *);

extern "C" void func_0033A018(void *arg0, A *arg1, s32 arg2, s32 arg3, s32 arg4, f32 fp) {
    s32 buf0[4];
    u32 i = 0;
    func_0045B4D8(buf0, arg0, D_0069F2F8);
    VEnt *ve = (VEnt *)(arg1->unk64 + 0xD0);
    B *b = arg1->unk6C;
    func_00339FE0(arg0, ve->fn((char *)arg1 + ve->off, 0), fp);
    if (b->unk60->count != 0) {
        do {
            func_00339F38(arg0, b->unk60->items[i], fp, arg1, arg2);
            i++;
        } while (i < b->unk60->count);
    }
    if (arg3 != 0) {
        func_003E5408((char *)arg1 + 0x35E8, arg0);
    }
    if (arg4 != 0) {
        func_003C2990((char *)arg1 + 0x3238, arg0);
    }
    func_0045B548(buf0, arg0);
}
