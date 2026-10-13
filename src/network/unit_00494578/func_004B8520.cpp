struct func_004B8520_arg0 {
    char pad0[0x858];
    int unk858;
    int unk85C;
};

extern "C" short func_004B8520(void *arg0) {
    struct func_004B8520_arg0 *s = (struct func_004B8520_arg0 *)arg0;
    int idx = s->unk858;
    char *e = (char *)arg0 + idx * 0x41C;
    e = e + s->unk85C * 8;
    return *(short *)(e + 0x23A);
}
