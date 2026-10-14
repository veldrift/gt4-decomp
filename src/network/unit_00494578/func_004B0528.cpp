/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Sub { char pad[0x14]; int flag; };
struct Obj { char pad[0x3298]; Sub *sub; char pad329c[0x14]; int value; };
extern "C" void func_00574EB0(void *);
extern "C" int func_005A5930(void *,int) __attribute__((noreturn));
extern "C" void func_004B0528(Obj *self,int flag) {
    func_00574EB0((char *)self + 0x3200);
    if (flag != 0) return;
    if (self->value >= 0) return;
    func_00574EB0((char *)self + 0x3260);
    self->sub->flag = 1;
    func_005A5930((char *)self + 0x30A0,1);
}
