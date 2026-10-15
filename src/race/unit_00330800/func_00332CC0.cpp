/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
void *memset(void *, int, unsigned int);

struct N6 { s32 a; u16 b; };
extern N6 D_0069F118;

struct SgiHeader {
    u16 magic;
    u8 storage;
    u8 bpc;
    u16 dimension;
    u16 xsize;
    u16 ysize;
    u16 zsize;
    u32 pixmin;
    u32 pixmax;
    char dummy[4];
    s32 imagename0; /* imagename: "dummy" */
    u16 imagename4;
    char pad1E[2];
    char rest[0x200 - 0x20];
};

extern "C" void func_00332740(s32, char *, s32) throw();
extern "C" s32 func_005B2DF0(const char *, s32);
extern "C" void func_005B3080(s32);
extern "C" s32 func_005B36A8(s32, void *, s32);

static inline s32 swap16(s32 x) {
    return ((x >> 8) & 0xFF) | ((x & 0xFF) << 8);
}

extern "C" s32 func_00332CC0(s32 arg0, char *arg1, s32 w, s32 h, s32 arg4, char *arg5) {
    SgiHeader hdr;
    memset(&hdr, 0, 0x200);
    hdr.magic = swap16(474);
    hdr.storage = 0;
    hdr.bpc = 1;
    hdr.dimension = swap16(3);
    hdr.xsize = swap16(w);
    hdr.ysize = swap16(h);
    hdr.zsize = swap16(arg4 + (arg5 != 0));
    hdr.pixmin = 0;
    hdr.pixmax = 0xFF000000;
    hdr.imagename0 = D_0069F118.a;
    hdr.imagename4 = D_0069F118.b;
    arg0 = func_005B2DF0((const char *)arg0, 0x602);
    if (arg0 < 0) {
        return 0;
    }
    s32 area = w * h;
    func_005B36A8(arg0, &hdr, 0x200);
    func_00332740(arg0, arg1, area * arg4);
    if (arg5 != 0) {
        func_00332740(arg0, arg5, area);
    }
    func_005B3080(arg0);
    return 1;
}
