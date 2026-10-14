typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Obj { s32 unk0; };
void func_00525660(u8 *, u32 *, u16 *);
s32 func_005262B0(struct Obj *, u16, u32, u8 *, s32);
void func_00529650(s32, s32);
void func_005257B0(s32 a0, s32 a1, u8 *data, s32 size, s32 code, struct Obj *obj) {
    u16 v;
    u32 t;
    if (obj->unk0 == a0 || (func_00529650(a0, a1), obj->unk0 == a0)) {
        do {
            func_00525660(data, &t, &v);
            func_005262B0(obj, (u16)code, t, data, v);
            size -= v;
            data += v;
        } while (v != 0 && size != 0);
    }
}
