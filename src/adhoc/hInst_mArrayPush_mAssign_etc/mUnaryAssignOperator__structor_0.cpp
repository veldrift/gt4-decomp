extern int func_00328420(void *arg0);
void *memcpy(void *, const void *, unsigned int);

// Address-only global; only the lui/addiu pattern matters for grading.
extern char mUnaryAssignOperator__vtable[];

struct S003205D8_Obj {
    int unk00;                      // 0x00
    int unk04;                      // 0x04 - vtable pointer
    int unk08;                      // 0x08 - copied from *arg1
    unsigned char unk0C[8];         // 0x0C - 8 bytes copied from arg2
};

int func_003205D8(struct S003205D8_Obj *arg0, int *arg1, void *arg2)
{
    func_00328420(arg0);
    arg0->unk04 = (int)mUnaryAssignOperator__vtable;
    arg0->unk08 = *arg1;
    memcpy(arg0->unk0C, arg2, 8);
}
