/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned char u8;
extern char *D_00622F4C;
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" u16 *func_004683A8() throw();
extern "C" int func_00468418(float) throw() __attribute__((const));
extern "C" void *func_00468690(void *, void *) throw();
extern "C" char *func_00433C10(void *, void *);
static inline void copy_row(u16 *out, u16 *src, int k, int i) {
    for (int j = 0; j < 8; j++) {
        if (k != 0 || j != 7) out[i * 8 + j] = src[k + i * 64 + j * 8];
    }
}
static inline void copy_tail_row(u16 *out, u8 *src2, int i) {
    for (int j = 0; j < 4; j++) {
        out[24 + i * 4 + j] = src2[i * 4 + j] << 8;
    }
}
extern "C" void func_00468710(u16 *out, void *arg1, float f) {
    char tmp[16];
    func_005A48D8(out, 0, 0x40);
    u16 *src = func_004683A8();
    int k = func_00468418(f);
    int i = 0;
    do {
        copy_row(out, src, k, i);
        i++;
    } while (i < 3);
    char *obj = func_00433C10(D_00622F4C + 0x14a30, func_00468690(tmp, arg1));
    if (obj) {
        u8 *src2 = (u8 *)obj + 0x228;
        for (i = 0; i < 2; i++) {
            copy_tail_row(out, src2, i);
        }
    }
}
