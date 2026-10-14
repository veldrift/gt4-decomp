/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

extern "C" void func_00105250(char *);
extern "C" void func_00105280(void *, int);
extern "C" void func_00107AE8(void *);
extern "C" void func_00107B00(void *, int);
extern "C" s32 *func_00451020(void *) throw();
extern "C" s32 *func_00451078(void *, int) throw();
extern "C" void func_004519A8(void *) throw();
extern "C" void func_004519D8(void *) throw();
extern "C" void func_00453A28(void *, s32, void *, void *, void *);
extern "C" void func_00453A48(void *);
extern "C" void func_00455598(int, int, s32 *);
extern "C" void ModelSet2__registerExternalTexSet(s32, s32);
extern "C" void func_0049B448(s32);
extern "C" s32 func_0049B478(int, float);
extern "C" void func_004A1638(s32);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void func_004A7844(float, float, float);
extern "C" void func_004A7900(float, float, float);
extern "C" void func_004A79B0(float);
extern "C" void func_004AB040(s32);

extern "C" void func_00453028(char *arg0, s32 arg1)
{
    char sp0[0x40];
    char sp40[0x40];
    char sp80[0x30];

    if (*(s32 *)arg0 != 0) {
        char *s3 = arg0 + 0xC;
        func_004A53F8();
        func_00105250(sp0);
        s32 s4 = arg1 & 1;
        func_00107AE8(sp40);
        func_00453A28(s3, 0, sp0, sp40, sp80);
        func_004519A8(arg0);
        func_0049B448(1);
        func_0049B478(2, 1.0f);
        func_0049B478(4, 1.0f);
        func_0049B478(3, *(float *)(arg0 + 0x3C));
        float v;
        if (s4 != 0) {
            func_004A79B0(180.0f);
            v = 0.5f * *(float *)(s3 + arg1 * 0x38 + 0xA0);
        } else {
            v = *(float *)(s3 + arg1 * 0x38 + 0xA0) * -0.5f;
        }
        func_004A7844(v, 0.0f, 0.0f);
        func_004A1638(0xE);
        func_004A1638(0x13);
        float c = *(float *)(arg0 + arg1 * 0x38 + 0xB0);
        func_004A7900(c, c, c);
        if (s4 != 0) {
            func_004A79B0(180.0f);
        }
        s32 *p = func_00451078(arg0, ((arg1 >> 1) ^ 1) & 1);
        if (p != 0) {
            func_00455598(*p, s4, p);
            ModelSet2__registerExternalTexSet(3, 0);
        }
        s32 *q = func_00451020(arg0);
        if (q != 0) {
            *(s32 *)(s3 + 0x24) = arg1;
            func_00455598(*q, arg1, q);
            ModelSet2__registerExternalTexSet(2, 0);
        }
        func_004AB040(0x13);
        func_004AB040(0xE);
        func_0049B448(0);
        func_004519D8(arg0);
        func_00453A48(s3);
        func_004A5400();
        func_00107B00(sp40, 2);
        func_00105280(sp0, 2);
    }
}
