extern "C" int func_0057F238(const char *, const char *);
extern const char *D_00622DF0[];
struct O { char pad[0x16B0]; int idx; };
extern "C" void func_00437380(O *self, const char *name) {
    int i = 0;
    do {
        if (func_0057F238(name, D_00622DF0[i]) == 0) {
            self->idx = i;
        }
        i++;
    } while (i < 3);
}
