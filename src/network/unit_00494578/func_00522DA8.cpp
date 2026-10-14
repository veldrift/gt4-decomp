struct Color { unsigned value; unsigned pad; } __attribute__((aligned(8)));
struct S { int value; unsigned char a,b,c,d; int unused[2]; };
extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" void func_00522428(S *, unsigned) throw();
extern "C" int func_00570B48(void *, void *, int, unsigned short, S *);
extern "C" int func_00522DA8(int a, int *out, long color, int arg3) {
    *out = 0;
    int state = D_0064B444;
    unsigned c = *(unsigned *)&color;
    if (state != 1) return 5;
    if (a < 0) return 2;
    if (!c) return 2;
    S s;
    S *ps = &s;
    func_00522428(ps, c);
    int r = func_00570B48(D_00863EC0, D_00863F00, a, arg3 & 0xffff, ps);
    if (r < 0) return 0xc350;
    if (r > 0) *out = state;
    return 0;
}
