/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;
typedef unsigned short u16;
extern "C" void func_0013BD68(void *, int) throw();
extern "C" void func_0013BDC0(void *) throw();
extern "C" s32 func_00147D80(void *);
extern "C" void func_00354FF8(void *, s32, void *, s32);
extern "C" void func_0043E2F0(void *, s32, s16);
extern "C" void func_0043E370(void *, s32);
extern "C" u16 func_0043EB90(void *);
extern "C" u8 func_0043EBB8(void *);
extern "C" void *func_00441248(void *);
extern "C" void func_004413C8(void *, char *);
extern "C" s32 func_00445780(void *);

extern "C" void MCarGarage__setGearAuto(void) {
    s16 arr[16];
    char buf[0x600];
    s32 holderbuf[4];
    s32 *holder=holderbuf;
    s32 s3;
    void *obj;
    s32 n;
    s16 *p;
    func_0013BDC0(holder);
    obj = (void *)func_00147D80((void *)holder[0]);
    func_0013BD68(holder, 2);
    func_004413C8(func_00441248(obj), buf);
    func_0043E370(obj, func_0043EB90(obj));
    buf[0x156] = 1;
    func_00354FF8(buf, func_0043EBB8(obj) * 10, arr, 0);
    s3 = 1;
    n = func_00445780(func_00441248(obj));
    if (n > 0) {
        p = &arr[1];
        do {
            s16 a = *p;
            p++;
            func_0043E2F0(obj, s3, a);
            s3++;
        } while (n >= s3);
    }
}
