typedef int s32;
inline void *operator new(unsigned int, void *p) { return p; }
inline void *operator new[](unsigned int, void *p) { return p; }
struct Elem {
    Elem() __asm__("func_004274D0");
    char d[0x44];
};
extern char D_006A4B60[];
extern char D_006A4B80[];
extern char D_006A4B98[];
extern s32 D_006186E8;
extern s32 *D_006186EC;
extern "C" void func_0057DA20(char *, const char *, ...);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" char *strcpy(char *, const char *);
struct Obj {
    Elem e[6];
    s32 f198;
    char b19C[0x80];
    char b21C[0x20];
    char b23C[0x20];
    char b25C[0x80];
    char b2DC[0x80];
    char b35C[0x80];
};
extern "C" void *func_004274E0(Obj *p) {
    new (p->e) Elem[6];
    p->f198 = 1;
    func_005A48D8(p->b19C, 0, 0x80);
    func_005A48D8(p->b21C, 0, 0x20);
    func_005A48D8(p->b23C, 0, 0x20);
    if (D_006186E8 >= 2) {
        s32 s = D_006186EC[1];
        func_0057DA20(p->b25C, D_006A4B60, s);
        func_0057DA20(p->b2DC, D_006A4B80, s);
    } else {
        strcpy(p->b25C, "snap/");
        func_0057DA20(p->b2DC, D_006A4B98);
    }
    return func_005A48D8(p->b35C, 0, 0x80);
}
