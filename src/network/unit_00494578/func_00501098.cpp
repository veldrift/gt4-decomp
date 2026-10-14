/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00500ED8(void *, void *, int, int) throw();
extern "C" int func_00504348(void *);
extern "C" void func_00578B10(int);
extern "C" void func_00501098(char *self, void *a1, int a2, int a3) {
    char *q = self + 0x4C;
    int i = 0;
    func_00500ED8(self, a1, a2, a3);
    self += 0xCC;
    do {
        while (func_00504348(q) == 0) func_00578B10(1000);
        i++;
        *(int *)self = -1;
        q += 8;
        self += 4;
    } while (i < 16);
}
