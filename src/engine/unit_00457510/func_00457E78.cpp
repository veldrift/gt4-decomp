struct S { int a; int link; int pad[3]; int tbl[4]; };
extern "C" void func_00457CD0(int *s, int n);

extern "C" void func_00457E78(S *arg0) {
    int *s0 = arg0->tbl;
    int n = 4;
    int *old = (int *)arg0->link;
    arg0->link = (int)arg0;
    int d = (int)arg0 - (int)old;
    int *s1 = s0;
    do {
        n--;
        int v = *s0;
        v += d;
        *s0 = v;
        s0++;
        func_00457CD0((int *)*s1, d);
        s1++;
    } while (n >= 0);
}
