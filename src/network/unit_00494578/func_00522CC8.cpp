struct Color { long raw; };
struct S { int value; unsigned char a,b,c,d; int unused[2]; };
extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" void func_00522428(S *, unsigned int) throw();
extern "C" int func_00570AB8(void *, void *, int, int, int *, S *, int, int);
extern "C" int func_00522CC8(int a, Color color, unsigned int size, int data, int *out) {
    S s __attribute__((aligned(16)));
    int local = 0;
    unsigned c = *(unsigned int *)&color;
    if (!D_0064B444) return 5;
    if (a < 0) return 2;
    if (!c) return 2;
    if (size & 0xffff0000) return 2;
    *out = 0;
    func_00522428(&s, c);
    int r = func_00570AB8(D_00863EC0, D_00863F00, a, data, &local, &s, size, 0);
    if (r < 0) return 0xc350;
    *out += r;
    return 0;
}
