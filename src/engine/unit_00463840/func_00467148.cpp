/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" char *func_00463BB8(char *) throw();
extern "C" unsigned char D_00620DE9;
extern "C" unsigned char D_00623E50[16];
extern "C" void func_00467148(char *self, int index) {
    char *base = *(char **)(self + 0xE4);
    unsigned char *bytes = (unsigned char *)base + 0xF818;
    char *out = func_00463BB8(self);
    int offset = index + 0x10;
    int a = *(unsigned char *)(base + index + 0xF824);
    int b = bytes[offset];
    if (a == 0) a = 100;
    int c = *(unsigned char *)(base + offset + 0xF81C);
    int delta = 0;
    if (b == 0) b = 100;
    if (a > 100) a = 100;
    if (c == 0) c = 100;
    if (D_00620DE9 != 0) {
        char *p = *(char **)(self + 0xE8) + 0x104;
        if (*(signed char *)(p + 0x466) == 2) {
            int k = *(unsigned char *)(p + 0x440);
            if (D_00623E50[11] == 0) b -= (k % 3) * 7;
            if (D_00623E50[10] == 0) {
                c -= (k * 4) & 4;
                delta = -((k * 7 % 5) * 2);
            }
            *(float *)(out + 0xC) *= (float)(((k + 1) % 3) * 3 + 97) * 0.01f;
        }
    }
    if (a != 100) *(float *)(out + 0x6C) = (float)a * 0.01f;
    if (b != 100) *(float *)(self + 0xBC) *= (float)b * 0.01f;
    if (c != 100) *(float *)(self + 0xB8) *= (float)c * 0.01f;
    if (delta != 0) *(float *)(out + 8) += (float)delta * 0x1.1c71c6p-2f;
}
