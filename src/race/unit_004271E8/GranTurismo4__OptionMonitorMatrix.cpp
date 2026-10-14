extern "C" {
struct V { char pad[0x8C]; int a; int b; };
extern char *D_00622F4C;
int GranTurismo4__OptionMonitorMatrix_2(void *self, char *p, int a, int b, int c, int d);
int GranTurismo4__OptionMonitorMatrix(void *self) {
    char *base = D_00622F4C;
    char *p = base + 0x38CD4;
    V *v = (V *)(base + 0x39FF4);
    int f = *(int *)p;
    int c = (f >> 1) & 1;
    int d = f & 1;
    int a = v->a - 1;
    int b = 1 - v->b;
    return GranTurismo4__OptionMonitorMatrix_2(self, p, a, b, c, d);
}
}
