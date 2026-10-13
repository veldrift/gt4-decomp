/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct hObject {
    s32 m0;
    hObject() __asm__("func_0030A678");
    virtual ~hObject();
};

struct Vec3_00228660 {
    f32 x, y, z;
};

struct mProgress : hObject {
    char pad8[8];
    s32 m10;
    f32 m14;
    f32 m18;
    Vec3_00228660 m1C;
    f32 m28;
    mProgress();
    virtual ~mProgress();
};

mProgress::mProgress() {
    m10 = 0;
    f32 t = *(f32 *)&m10;
    Vec3_00228660 *v = &m1C;
    m14 = 1.0f;
    m18 = t;
    v->x = t;
    v->y = t;
    v->z = t;
    m28 = t;
}
