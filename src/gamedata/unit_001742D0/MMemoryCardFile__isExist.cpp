/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Flags { char pad[0x48]; unsigned short unused : 2; unsigned short flag : 1; };

static inline u16 get_flag(Flags *p) { return p->flag; }

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void * func_00174148(void *) throw();
extern "C" void * func_001792D8(void *, void *);
extern "C" s32 func_001CC528(s32, s32);
extern "C" void * func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_00179280(void *, s32);
extern "C" void func_001740F0(void *, s32) throw();

extern "C" void MMemoryCardFile__isExist(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 buf2[4];
    s32 *p_s3;
    s32 *p_s1;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_00174148(buf0);
        p_s3 = buf1;
        func_001792D8(p_s3, arg3);
        t1 = func_001CC528(*(s32 *)((char *)buf0[0] + 0x10), *(s32 *)((char *)*p_s3 + 0x1c));
        s32 result = -1;
        if (t1 != 0) {
            s16 flag = get_flag((Flags *)*(s32 *)((char *)buf0[0] + 0x10));
            result = flag != 0;
        }
        p_s1 = buf2;
        func_002FE278(p_s1, result);
        if (arg0 != p_s1) {
            newVal = *p_s1;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s1, 0x2);
        func_00179280(p_s3, 0x2);
        func_001740F0(buf0, 0x2);
    }
}
