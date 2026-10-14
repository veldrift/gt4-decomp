/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Color { unsigned int value, unused; };
struct S { int value; unsigned char a,b,c,d; int unused[2]; };
extern int D_0064B444;
extern char D_00863EC0[], D_00863F00[];
extern "C" void func_00522428(S *, unsigned int) throw();
extern "C" int func_00570840(void *, void *, int, int, int, int *, S *, unsigned int, int);
extern "C" int func_00522B60(int a, Color color, unsigned int size, int b, int c, int *out) {
    S s;
    int local = 0;
    int state = D_0064B444;
    unsigned int cv = color.value;
    if (!state) return 5;
    if (a < 0) return 2;
    if (!cv) return 2;
    if (size & 0xFFFF0000) return 2;
    *out = 0;
    func_00522428(&s, cv);
    int r = func_00570840(D_00863EC0, D_00863F00, a, b, c, &local, &s, size, 0);
    if (r < 0) return 0xC350;
    *out = r;
    return 0;
}
