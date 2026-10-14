struct M { char pad[0xFC]; int cnt; char pad2[0xF8]; int tbl[1]; };
extern M *D_0064B4B4;
extern "C" int func_0051B720(int *out, int val) {
    if (out == 0) return 0x17;
    M *m = D_0064B4B4;
    int c = m->cnt;
    *out = c;
    M *m2 = D_0064B4B4;
    m->tbl[c] = val;
    m2->cnt++;
    return 0;
}
