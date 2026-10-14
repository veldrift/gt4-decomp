typedef int s32;
typedef short s16;
typedef unsigned short u16;
struct Ent { char pad[0x2C]; u16 unk2C; char pad2E[0x16]; };
struct Obj { char pad0[0x84]; Ent *unk84; };
struct D { s16 a; s16 b; u16 c; };
struct Entry { void *p; s32 size; };
struct Buf { Entry entries[8]; s32 total, count; char pad[8]; D d; void init() { count = 0; total = 0; } void push(void *p) { entries[count].p = p; entries[count].size = 6; total += 6; ++count; } };
extern "C" s32 func_00525648(s32, s32) throw() __attribute__((const));
extern "C" int func_00527510(Obj *, s32, s32, s32, Buf *) throw();
extern "C" s32 func_00527B28(Obj *self, u16 idx) {
    Buf b;
    b.d.a = func_00525648(3, 6);
    b.d.b = idx;
    b.d.c = self->unk84[idx].unk2C;
    b.init();
    b.push(&b.d);
    func_00527510(self, 0, 0, 0xF000, &b);
    return 0;
}
