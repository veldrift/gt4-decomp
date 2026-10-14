typedef unsigned char u8;
extern "C" void func_003FA980(void *, int);
extern "C" void func_003FA9C0(u8 *, u8 *);
extern "C" void func_003FAA10(char *a)
{
    char *p = a;
    char *q = a + 0x140;
    int n = 3;
    do {
        func_003FA980(p, 1);
        func_003FA980(p + 0xA0, 0);
        u8 v = (u8)p[0xC0];
        if (v < 0x32) p[0xC0] = 0x32;
        else if (v >= 0xC9) p[0xC0] = -0x38;
        n -= 1;
        func_003FA980(q, 0);
        q += 0x28;
        p += 0x28;
    } while (n >= 0);
    func_003FA9C0((u8 *)a + 0x1E9, (u8 *)a + 0x1EA);
    u8 *s = (u8 *)a + 0x1E0;
    func_003FA9C0((u8 *)a + 0x1F0, (u8 *)a + 0x1F1);
    func_003FA9C0((u8 *)a + 0x1F7, (u8 *)a + 0x1F8);
    func_003FA9C0((u8 *)a + 0x201, (u8 *)a + 0x203);
    if (s[2] == 0) s[2] = 1;
}
