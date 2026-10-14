struct B2 {
    signed char c[2];
};
struct B4 {
    signed char c[4];
};
struct Blob {
    char d[0x64];
};
extern void (*D_0064A304)(int, int, int, void *);
extern "C" void *func_005A48D8(void *, int, unsigned);

extern "C" short func_00515318(int a0, int a1, int a2, const signed char *p) {
    signed char sp[0x80];
    func_005A48D8(sp, 0, 0x80);
    *(B2 *)sp = *(const B2 *)p;
    p += 2;
    short id = *(short *)sp;
    *(B4 *)(sp + 2) = *(const B4 *)p;
    p += 4;
    *(B4 *)(sp + 8) = *(const B4 *)p;
    p += 4;
    *(B4 *)(sp + 0xC) = *(const B4 *)p;
    p += 4;
    *(B4 *)(sp + 0x10) = *(const B4 *)p;
    p += 4;
    *(B4 *)(sp + 0x14) = *(const B4 *)p;
    p += 4;
    if (*(int *)(sp + 0x14) & 1) {
        *(Blob *)(sp + 0x18) = *(const Blob *)p;
        p += 0x64;
    }
    if (*(int *)(sp + 0x14) & 2) {
        *(B4 *)(sp + 0x7C) = *(const B4 *)p;
    }
    if (D_0064A304) D_0064A304(a0, a1, a2, sp);
    return id;
}
