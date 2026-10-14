typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Big { void *first; char pad[0x3040]; };

extern "C" void func_002106F8(void *, void *);
extern "C" void func_00273570(void *, int);
extern "C" void func_00273728(void *, void *, int);
extern "C" void func_00273830(void *);
extern "C" void func_00574B18(void *, void *, void *, int);
extern "C" void func_00574BA0(void *, int);
extern "C" void *malloc(s32) throw();
extern "C" void func_005A4724(void *, void *, s32);

extern "C" void *func_00218AD0(void *arg0, signed char *src, s32 size) {
    Big obj;
    s32 magic = src[0] | (src[1] << 8) | (src[2] << 16) | (src[3] << 24);
    s32 isMagic = magic == (s32)0xFFF7EEC5;
    void *buf;
    if (isMagic) {
        u8 *u = (u8 *)src;
        s32 w = u[4];
        w |= u[5] << 8;
        w |= u[6] << 16;
        w |= u[7] << 24;
        size = -w;
    }
    buf = malloc(size);
    if (isMagic) {
        func_00574B18(&obj, buf, src, 1);
        func_00574BA0(&obj, 2);
    } else {
        func_005A4724(buf, src, size);
    }
    func_00273830(&obj);
    func_00273728(obj.first, buf, 1);
    func_002106F8(arg0, &obj);
    func_00273570(&obj, 2);
    return arg0;
}
