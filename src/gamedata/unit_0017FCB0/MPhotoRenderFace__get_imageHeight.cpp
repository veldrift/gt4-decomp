typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

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

extern "C" void func_001978D0(void *);
extern "C" void func_00197878(void *, s32);
extern "C" void func_002F9360(void *, f32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002F7B68(void *, s32);

struct MPhotoRenderFace__get_imageHeight_v_s0 {
    char pad0[0x14];
    s32 unk14;
    char pad1[0x4];
    s32 unk1C;
};

extern "C" void MPhotoRenderFace__get_imageHeight(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    f32 f;

    func_001978D0(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0xEC);
    func_00197878(buf0, 0x2);
    f = 0.0f;
    if (v_s0 != 0) {
        f = (f32)(((struct MPhotoRenderFace__get_imageHeight_v_s0 *)v_s0)->unk14 *
                  ((struct MPhotoRenderFace__get_imageHeight_v_s0 *)v_s0)->unk1C);
    }
    func_002F9360(buf0, f);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_002F7B68(buf0, 0x2);
}
