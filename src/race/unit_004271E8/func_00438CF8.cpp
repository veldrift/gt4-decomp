extern "C" int func_0057F238(const char *, const char *);
extern const char *D_00622E78[];
struct O { char pad[0x44]; int idx; };
extern "C" void func_00438CF8(O *self, const char *name) {
    int i = 0;
    do {
        if (func_0057F238(D_00622E78[i], name) == 0) {
            self->idx = i;
            break;
        }
        i++;
    } while (i < 5);
}
