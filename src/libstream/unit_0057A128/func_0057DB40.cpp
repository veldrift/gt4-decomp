struct func_0057DB40_arg0 {
    char pad0[0x4];
    char *unk4;
    int unk8;
    int unkC;
};

void func_0057DBA0(struct func_0057DB40_arg0 *s);   /* extern */

int func_0057DB40(struct func_0057DB40_arg0 *arg0, int arg1) {
    int *cnt;
    int n;

    if (arg0->unkC == arg0->unk8) {
        func_0057DBA0(arg0);
    }
    cnt = &arg0->unkC;
    n = *cnt;
    *(arg0->unk4 + n) = arg1;
    *cnt = n + 1;
    return 0;
}
