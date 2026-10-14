/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad0[8]; char *f8; };
struct Fs { char pad0[4]; int f4; char pad8[0x50 - 8]; unsigned int f50; };
extern "C" Node *func_004CA820(int, int) throw();
extern "C" void func_004CA938(int, Node *) throw();
extern "C" int func_004CB1D8(char *) throw();
extern "C" int func_004CBBC8(Fs *fs, int base, unsigned int count, Node **out1, char **out2) {
    unsigned int i = 0;
    if (count != 0) {
        do {
            Node *n = func_004CA820(fs->f4, base + i);
            if (n == 0) return -5;
            char *e = n->f8;
            if ((unsigned int)e < (unsigned int)(e + fs->f50)) {
                do {
                    if (*e == 0 || (func_004CB1D8(e) == 0 && *e == -0x1B)) {
                        *out1 = n;
                        *out2 = e;
                        return 1;
                    }
                    e += 0x20;
                } while ((unsigned int)e < (unsigned int)(n->f8 + fs->f50));
            }
            func_004CA938(fs->f4, n);
            i++;
        } while (i < count);
    }
    return 0;
}
