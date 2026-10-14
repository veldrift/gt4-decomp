struct IOV { char *p; int len; };
struct IOVec { IOV v[8]; unsigned int total; int count; };
struct Dev { int h; char pad4[0x48 - 4]; char *buf; char pad4c[0x5C - 0x4C]; unsigned int cap; };
struct Iface {
    char pad0[0x20];
    int (*f20)(int, long, int, char *, unsigned int, int *);
    char pad24[0x70 - 0x24];
    int (*f70)(long);
};
struct Pair { unsigned char c[2]; };
struct L { long a1; Pair pr; unsigned short n; int spc; };
extern Iface *D_0064B4B0;
extern "C" void *func_005A4724(char *, const char *, unsigned);

extern "C" int func_00529E30(Dev *dev, long a1, int a2, IOVec *iov) {
    L l;
    l.a1 = a1;
    l.spc = 0;
    if (dev == 0) return 0xD2F2;
    if (D_0064B4B0->f70(*(volatile long *)&l.a1) != 0) return 2;
    if (a2 == 0) return 2;
    if (iov == 0 || iov->total == 0 || dev->cap < iov->total) return 2;
    char *buf = dev->buf;
    unsigned short *hdr = (unsigned short *)buf;
    char *a0 = buf + 2;
    hdr[0] = 0x81C3;
    *(unsigned short *)a0 = iov->total & 0x7FF;
    l.pr.c[0] = ((unsigned char *)a0)[0];
    l.pr.c[1] = ((unsigned char *)a0)[1];
    unsigned short v = *(unsigned short *)&l.pr & 0xF800;
    *(unsigned short *)&l.pr = v;
    l.n = (v & 0x6000) ? 4 : 2;
    *(unsigned short *)(a0 + 2) = 0;
    char *dst = buf + l.n + 2;
    for (int i = iov->count - 1; i >= 0; i--) {
        if (iov->v[i].p != 0 && iov->v[i].len != 0) {
            func_005A4724(dst, iov->v[i].p, iov->v[i].len);
            dst += iov->v[i].len;
        }
    }
    return D_0064B4B0->f20(dev->h, l.a1, a2, dev->buf, l.n + iov->total + 2, &l.spc);
}
