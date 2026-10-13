typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct File {
    char p0[0xC];
    s16 flags;              /* 0x0C */
    s16 file;               /* 0x0E */
    char p1[0xC];           /* 0x10-0x1B */
    struct File *cookie;    /* 0x1C */
    void (*f_read)(void);   /* 0x20 */
    void (*f_write)(void);  /* 0x24 */
    void (*f_seek)(void);   /* 0x28 */
    void (*f_close)(void);  /* 0x2C */
    char p2[0x24];          /* 0x30-0x53 */
    void *data;             /* 0x54 */
};

extern "C" s32 func_005AC2A0(void *ptr, const char *mode, s32 *optr);
extern "C" struct File *func_005A3530(void *ptr);
extern "C" s32 func_005A4998(void *ptr, const char *file, s32 oflags, s32 mode);
extern "C" void func_005A5B80(void);
extern "C" void func_005A5BE8(void);
extern "C" void func_005A5C68(void);
extern "C" void func_005A5CD0(void);
extern "C" void func_005A3AB8(struct File *fp, s32 buf, s32 mode);

extern "C" struct File *func_005A3750(void *ptr, const char *file, const char *mode) {
    s32 buf[4];
    s32 flags;
    struct File *fp;
    s32 r;
    s32 a4;

    flags = func_005AC2A0(ptr, mode, buf);
    if (flags == 0) {
        return 0;
    }
    fp = func_005A3530(ptr);
    if (fp == 0) {
        return 0;
    }
    r = func_005A4998(fp->data, file, buf[0], 0x1B6);
    a4 = flags & 0x100;
    if (r < 0) {
        fp->flags = 0;
        return 0;
    }
    fp->file = r;
    fp->f_read = func_005A5B80;
    fp->f_write = func_005A5BE8;
    fp->f_seek = func_005A5C68;
    fp->f_close = func_005A5CD0;
    fp->flags = flags;
    fp->cookie = fp;
    if (a4 != 0) {
        func_005A3AB8(fp, 0, 2);
    }
    return fp;
}
