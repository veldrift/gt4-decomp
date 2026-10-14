/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Stamp {
    unsigned int a : 9;
    unsigned int b : 6;
    unsigned int c : 8;
    unsigned int x : 1;
    unsigned int d : 1;
};
extern "C" int func_00448368(long long key);
extern "C" int func_001CD5F8(void *, int, Stamp *) throw();
extern "C" void func_001CFD50(void *self, int arg1) {
    char *p = (char *)self + 0x68;
    Stamp bits;
    bits.a = func_00448368(*(long long *)(p + 8));
    bits.b = *(signed char *)(p + 0xD8);
    bits.c = *(unsigned char *)(p + 0xD9);
    bits.x = *(int *)(p + 0xE4) != 0;
    bits.d = *(int *)(p + 0xE0) != 0;
    func_001CD5F8(self, arg1, &bits);
}
