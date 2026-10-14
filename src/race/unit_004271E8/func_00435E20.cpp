extern "C" int func_0057F238(const char *, const char *);
extern const char *D_00622DA8[];
struct O { int a; int idx; };
extern "C" void func_00435E20(O *self, const char *name) {
    int i = 0;
    do {
        if (func_0057F238(name, D_00622DA8[i]) == 0) {
            self->idx = i;
            break;
        }
        i++;
    } while (i < 6);
}
