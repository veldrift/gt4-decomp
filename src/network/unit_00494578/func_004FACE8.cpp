/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char pad[0xC]; signed char flag; };
struct Obj { char pad0[0x888]; int x; char pad88C[0xA30-0x88C]; int y; int z; char padA38[0xF64-0xA38]; Sub sub; };
extern "C" int func_004F68C8(Obj *);
extern "C" void func_004FACE8(Obj *self, int flag) {
    if (func_004F68C8(self) != 0) {
        Sub *p = &self->sub;
        if (p->flag != flag) {
            int value = flag ? 3 : 2;
            p->flag = flag;
            self->z = 0;
            self->y = value;
            self->x = value;
        }
    }
}
