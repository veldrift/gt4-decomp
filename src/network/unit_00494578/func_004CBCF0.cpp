/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node;
struct Fs { char pad[0x68]; unsigned count; char pad6c[12]; char *vt; };
struct VEntry { short delta, index; int (*fn)(void *, int); };
struct VSearch { short delta, index; int (*fn)(void *, char *, Node **, char **); };
extern "C" void func_004CB1F0(char *, const char *) throw();
extern "C" int func_004CB8E8(Fs *, int) throw();
extern "C" int func_004CBA58(Fs *, int, unsigned, char *, Node **, char **) throw();
static inline int check(Fs *fs, int index) {
    VEntry *e = (VEntry *)(fs->vt + 8);
    return e->fn((char *)fs + e->delta, index);
}
extern "C" int func_004CBCF0(Fs *fs, int index, const char *name, Node **out1, char **out2) {
    char buf[16];
    func_004CB1F0(buf, name);
    char *p = buf;
    *out1 = 0;
    if (index == 0) {
        VSearch *e = (VSearch *)(fs->vt + 0x28);
        return e->fn((char *)fs + e->delta, buf, out1, out2);
    }
    while (check(fs, index) == 0) {
        int r = func_004CBA58(fs, func_004CB8E8(fs, index), fs->count, p, out1, out2);
        if (r < 0 || *out1 != 0) return r;
        VEntry *next = (VEntry *)(fs->vt + 0x18);
        index = next->fn((char *)fs + next->delta, index);
        if (index < 0) return index;
    }
    return -2;
}
