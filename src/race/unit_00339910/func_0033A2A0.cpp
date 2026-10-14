typedef int s32;
typedef unsigned int u32;
typedef short s16;
typedef long s64;

struct VEnt { s16 off; s16 pad; u32 (*fn)(void *); };
struct Mdl { char *vt; };
struct Item {
    char pad0[0x20];
    char unk20[0x2860];
    Mdl *unk2880;
};
struct List { u32 count; s32 unk4; Item **items; };
struct E { char pad[0x80]; s32 unk80; };
struct D { s32 unk0; E *unk4; };
struct B {
    char pad0[0x60];
    List *unk60;
    s64 unk68;
    void *unk70;
    char pad74[0xC];
    D *unk80;
};
struct C { char pad[0x6C]; B *unk6C; };

extern char D_0069F310[];
extern "C" void func_0045B4D8(void *, void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8u(void *, u32);
extern "C" s64 SPEC_DATABASE__RaceSpec__getCourseCode(void *);
extern "C" s32 func_00447CA0(s64, char *);
extern "C" void func_0045B040(void *, void *);
extern "C" void *func_00445350(void *);
extern "C" s64 func_004454D0(void *);
extern "C" void *func_004541C0(s64);
extern "C" void func_0045AFF0(void *, s32);
extern "C" void func_0033A150(void *, s32) throw();
extern "C" void func_0033A1B0(void *, void *, void *) throw();
extern "C" void func_0045B548(void *, void *);

extern "C" void func_0033A2A0(void *arg0, C *arg1, s32 arg2, s32 arg3) {
    s32 buf0[4];
    char name[0x100];
    u32 i = 0;
    u32 j;
    func_0045B4D8(buf0, arg0, D_0069F310);
    GT4Model__BinStreamWriter__write8u(arg0, 2);
    B *b = arg1->unk6C;
    func_00447CA0(SPEC_DATABASE__RaceSpec__getCourseCode(b->unk70), name);
    func_0045B040(arg0, name);
    func_00447CA0(b->unk68, name);
    func_0045B040(arg0, name);
    u32 n = b->unk60->count;
    GT4Model__BinStreamWriter__write8u(arg0, n);
    if (n != 0) {
        do {
            Item *it = b->unk60->items[i];
            i++;
            void *r3 = func_00445350((char *)it + 0x20);
            void *r2 = func_004541C0(func_004454D0((char *)it + 0x20));
            Mdl *m = it->unk2880;
            VEnt *ve = (VEnt *)(*(char **)((char *)m + 8) + 0x38);
            u32 r0 = ve->fn((char *)m + ve->off);
            func_0045B040(arg0, r3);
            func_0045B040(arg0, r2);
            GT4Model__BinStreamWriter__write8u(arg0, r0);
        } while (i < n);
    }
    func_0045AFF0(arg0, arg2);
    if (arg3 != 0) {
        E *e = arg1->unk6C->unk80->unk4;
        func_0033A150(arg0, e->unk80);
    }
    j = 0;
    if (n != 0) {
        do {
            Item *it = b->unk60->items[j];
            j++;
            func_0033A1B0(arg0, it, b);
        } while (j < n);
    }
    func_0045B548(buf0, arg0);
}
