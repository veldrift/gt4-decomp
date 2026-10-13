extern int func_00328420(void *arg0);
extern char D_00676030[];

struct P8 {
    int a;
    int b;
};

struct S0031A988 {
    int unk0;                      /* 0x00 */
    int unk4;                      /* 0x04 - vtable pointer */
    int unk8;                      /* 0x08 */
    struct P8 unkC;                /* 0x0C, 8 bytes copied from arg2 */
};

int func_0031A988(struct S0031A988 *arg0, int *arg1, struct P8 *arg2) {
    func_00328420(arg0);
    arg0->unk4 = (int)D_00676030;
    arg0->unk8 = *arg1;
    arg0->unkC = *arg2;
}
