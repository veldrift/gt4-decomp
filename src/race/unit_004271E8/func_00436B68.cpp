extern "C" int func_0057F238(const char *, const char *);
extern const char *D_00622DE0[];
struct O { char pad[0x1158]; int idx; };
extern "C" void func_00436B68(O *self, const char *name) {
    int i = 0;
    do {
        if (func_0057F238(name, D_00622DE0[i]) == 0) {
            self->idx = i;
            break;
        }
        i++;
    } while (i < 3);
}
