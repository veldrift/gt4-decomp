typedef signed char s8;
typedef unsigned char u8;
extern "C" void func_004389F8(void *, void *, const s8 *, const u8 *, int);
extern "C" void func_0043C260(int, void *, void *, void *);
extern "C" void *func_0055F1F0(void *);
extern char D_006A6588[];

extern "C" void func_0043C4D0(char *self, void *a, char *b) {
    func_004389F8(a, func_0055F1F0(b), (const s8 *)(self + 0x14), (const u8 *)D_006A6588, 6);
    func_0043C260(4, a, b + 4, self + 0x11);
}
