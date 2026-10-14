extern "C" int func_0057F238(const char *, const char *);
extern const char *D_00618890[];
struct O { char pad[0x2A0]; int idx; };
extern "C" void func_0013AC48(O *self, const char *name) {
    int i = 0;
    do {
        if (func_0057F238(name, D_00618890[i]) == 0) {
            self->idx = i;
            break;
        }
        i++;
    } while (i < 2);
}
