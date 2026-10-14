extern int RefCounter__structor_0(struct RefCounter *arg0);
extern "C" void *memcpy(void *dst, const void *src, unsigned int n);
extern char mUnaryOperator__vtable[];

struct mUnaryOperator {
    int unk0;                      /* 0x00 */
    int unk4;                      /* 0x04 - vtable pointer */
    int unk8;                      /* 0x08 */
    unsigned char unk0C[8];        /* 0x0C - 8 bytes copied from arg2 */
};

void mUnaryOperator__structor_0(struct mUnaryOperator *arg0, int *arg1, void *arg2)
{
    RefCounter__structor_0((struct RefCounter *)arg0);
    arg0->unk4 = (int)mUnaryOperator__vtable;
    arg0->unk8 = *arg1;
    memcpy(arg0->unk0C, arg2, 8);
}
