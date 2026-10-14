/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;

extern char D_006235A8[];
extern "C" int SPEC_DATABASE__DatabaseStorage__getRow(void *storage, long id, void *row);
extern "C" void func_00441950(void *, void *, void *);
extern "C" void func_00441970(void *, void *, void *);
extern "C" void func_004419E0(void *, void *, void *);
extern "C" void func_00441B20(void *, void *, void *);
extern "C" void func_00441C58(void *, void *, void *);
extern "C" void func_00441E28(void *, void *, void *);
extern "C" void func_00441E78(void *, void *, void *);
extern "C" void func_00441EE0(void *, void *, void *);
extern "C" void func_004421D0(void *, void *, void *);
extern "C" void func_00442218(void *, void *, void *);
extern "C" void func_00442358(void *, void *, void *);
extern "C" void func_004427B8(void *, void *, void *);
extern "C" void func_00442800(void *, void *, void *);
extern "C" void func_004428B8(void *, void *, void *);
extern "C" void func_00442900(void *, void *, void *);
extern "C" void func_00442A58(void *, void *, void *);
extern "C" void func_00442AA0(void *, void *, void *);
extern "C" void func_00442AE8(void *, void *, void *);
extern "C" void func_00442C40(void *, void *, void *);
extern "C" void func_00442CE0(void *, void *, void *);
extern "C" void func_00442D60(void *, void *, void *);
extern "C" void func_00442DE8(void *, void *, void *);
extern "C" void func_00442E80(void *, void *, void *);
extern "C" void func_00442EC8(void *, void *, void *);
extern "C" void func_00442F10(void *, void *, void *);
extern "C" void func_00443040(void *, void *, void *);
extern "C" void func_004430B8(void *, void *);
extern "C" void func_004430D0(void *, void *, void *);
extern "C" void func_004430D8(void *, void *, void *);
extern "C" void func_004430F0(void *, void *, void *);
extern "C" void func_004431F8(void *, void *, void *);
extern "C" void func_004458D0(void *, signed char, void *);
extern "C" u8 func_004461F8(void *);

struct Src {
    long f0;
    char pad8[0x10];
    signed char f18;
    char pad19[7];
    long f20, f28, f30, f38, f40, f48, f50, f58, f60, f68, f70, f78, f80, f88, f90, f98;
    long fA0, fA8, fB0, fB8, fC0, fC8, fD0, fD8, fE0, fE8, fF0, fF8, f100, f108;
    char pad110[0x4E];
    u16 f15E;
    char pad160[2];
    u8 f162;
    u8 f163;
};

struct Dst {
    char pad0;
    u8 f1;
    char pad2[2];
    u8 f4;
    char pad5[2];
    u8 f7;
    u8 f8;
    char pad9[0x1B];
    u8 f24;
    u8 f25;
    u8 f26;
    char pad27[0x98];
    u8 nBF;
    signed char bC0[0x18];
    s16 hD8[0x18];
    s16 f108;
    s16 f10A;
    u8 f10C;
    char pad10D[6];
    u8 f113;
    char pad114[0xC];
    u8 f120;
    char pad121[0x17];
    s16 h138[0xE];
    char pad154;
    u8 n155;
};

struct Rows {
    char r0[0x10];
    char r10[0x10];
    char r20[0x30];
    char r50[0x80];
};

extern "C" void func_004413C8(Src *a, Dst *d) {
    Rows rows;
    int i;
    char *st;

    st = D_006235A8;
    d->f10A = 1000;
    d->f10C = 100;
    d->f113 = 0;
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f20, rows.r0);
    func_00441950(a, d, rows.r0);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f28, rows.r10);
    func_00441970(a, d, rows.r10);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f70, rows.r20);
    func_004419E0(a, d, rows.r20);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f30, rows.r0);
    func_00441B20(a, d, rows.r0);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f38, rows.r50);
    func_00441C58(a, d, rows.r50);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f40, rows.r0);
    func_00441E28(a, d, rows.r0);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f48, rows.r0);
    func_00441E78(a, d, rows.r0);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f50, rows.r0);
    func_00441EE0(a, d, rows.r0);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f58, rows.r0);
    func_004421D0(a, d, rows.r0);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f60, rows.r0);
    func_00442218(a, d, rows.r0);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f68, rows.r0);
    func_00442358(a, d, rows.r0);
    if (a->f78 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->f78, rows.r0);
        func_004427B8(a, d, rows.r0);
    }
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f80, rows.r0);
    func_00442800(a, d, rows.r0);
    if (a->f88 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->f88, rows.r0);
        func_004428B8(a, d, rows.r0);
    }
    if (a->f90 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->f90, rows.r0);
        func_00442900(a, d, rows.r0);
    }
    if (a->f98 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->f98, rows.r0);
        func_00442A58(a, d, rows.r0);
    }
    if (a->fA0 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->fA0, rows.r0);
        func_00442AA0(a, d, rows.r0);
    }
    if (a->fA8 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->fA8, rows.r0);
        func_00442AE8(a, d, rows.r0);
    }
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->fB0, rows.r0);
    func_00442C40(a, d, rows.r0);
    if (a->fB8 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->fB8, rows.r0);
        func_00442CE0(a, d, rows.r0);
    }
    if (a->fC0 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->fC0, rows.r0);
        func_00442D60(a, d, rows.r0);
    }
    if (a->fC8 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->fC8, rows.r0);
        func_00442DE8(a, d, rows.r0);
    }
    if (a->fD0 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->fD0, rows.r0);
        func_00442E80(a, d, rows.r0);
    }
    if (a->fD8 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->fD8, rows.r0);
        func_00442EC8(a, d, rows.r0);
    }
    if (a->f108 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->f108, rows.r0);
        func_004431F8(a, d, rows.r0);
    }
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->fE0, rows.r0);
    func_00442F10(a, d, rows.r0);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->fE8, rows.r0);
    func_00443040(a, d, rows.r0);
    func_004430B8(a, d);
    if (a->f100 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->f100, rows.r0);
        func_004430D0(a, d, rows.r0);
    }
    if (a->fF8 != -1) {
        SPEC_DATABASE__DatabaseStorage__getRow(st, a->fF8, rows.r0);
        func_004430D8(a, d, rows.r0);
    }
    if (a->f18 == -1) a->f18 = 0;
    func_004458D0(a, a->f18, rows.r0);
    func_004430F0(a, d, rows.r0);
    {
        u8 v = d->f24;
        d->f25 = v;
        d->f26 = v >> 1;
    }
    d->f120 = func_004461F8(a);
    SPEC_DATABASE__DatabaseStorage__getRow(st, a->f0, rows.r0);
    d->f1 = ((u8 *)&rows)[0x13];
    d->f4 = ((u8 *)&rows)[0x14];
    for (i = d->n155 + 1; i < 12; i++) d->h138[i] = -1;
    for (i = d->nBF; i < 16; i++) {
        d->bC0[i] = -1;
        d->hD8[i] = 0;
    }
    d->f7 = a->f163;
    d->f8 = a->f162;
    if (a->f15E != 0) d->f108 = a->f15E;
}
