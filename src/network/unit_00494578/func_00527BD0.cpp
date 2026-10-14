typedef int s32;
typedef unsigned short u16;
struct Ent { s32 type; char pad[0x40]; };
struct Obj { char pad[0x84]; Ent *ents; };
extern "C" void func_00527A70(Obj *, s32, s32) throw();
extern "C" void func_00527B28(Obj *, s32) throw();
extern "C" s32 func_00527BD0(s32 mode, Obj *obj, s32 kind, u16 a3, u16 idx) {
    if (mode == 3 || mode == 1) {
        func_00527B28(obj, idx);
    } else if (mode == 2) {
        Ent *e = &obj->ents[idx];
        if (kind == 7 || e->type == 4) {
            func_00527B28(obj, idx);
        } else {
            func_00527A70(obj, a3, idx);
        }
    }
    return 0;
}
