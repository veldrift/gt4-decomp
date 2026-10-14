/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct RefCounter;

struct VEntry { s16 delta; s16 index; void *(*fn)(void *, s32, void *, void *); };
struct VObj { char pad0[4]; VEntry *vtbl; };

extern "C" void func_00312370(void *arg0, void *arg1) throw();
extern "C" void func_00221B28(void *arg0, void *arg1) throw();
extern "C" u8 *func_00314920(u8 *arg0);
extern "C" s32 func_002FE250(void *arg0);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(RefCounter *p);
extern "C" void func_003285F8(RefCounter *p);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_00221AD0(void *arg0, int arg1) throw();
extern "C" void func_00312318(void *arg0, int arg1);

extern "C" void MNetConf__LoadFile(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    if (arg2 >= 3) {
        s32 buf0[4];
        s32 buf1[4];
        s32 buf2[4];
        s32 buf3[4];
        s32 buf4[4];
        s32 *p_s7;
        s32 *p_s6;
        s32 *p_s5;
        s32 *p_s1;
        char *obj;
        VEntry *e;
        s32 r0;
        u8 *r1;
        u8 *r2;
        void *t1;
        s32 newVal;
        s32 oldVal;

        func_00221B28(buf0, arg1);
        p_s7 = buf1;
        func_002FC8C8(p_s7, arg3);
        p_s6 = buf2;
        func_00312370(p_s6, (char *)arg3 + 4);
        p_s5 = buf3;
        func_00312370(p_s5, (char *)arg3 + 8);
        obj = (char *)buf0[0];
        e = (VEntry *)((char *)((VObj *)obj)->vtbl + 0x2F0);
        obj = obj + e->delta;
        r0 = func_002FE250((void *)p_s7[0]);
        r1 = func_00314920((u8 *)p_s6[0]);
        r2 = func_00314920((u8 *)p_s5[0]);
        t1 = e->fn(obj, r0, r1, r2);
        p_s1 = buf4;
        func_002FE278(p_s1, t1);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8((RefCounter *)newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8((RefCounter *)oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s1, 2);
        func_00312318(p_s5, 2);
        func_00312318(p_s6, 2);
        func_002FC870(p_s7, 2);
        func_00221AD0(buf0, 2);
    }
}
