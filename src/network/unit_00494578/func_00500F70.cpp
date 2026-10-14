/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Obj {
    char pad0[0x44];
    s32 u44;
    s32 u48;
    char arr[16 * 8];
};
extern char D_00689740[];
extern "C" s32 func_00500DD8(void *) throw();
extern "C" void func_005041A0(void *);
extern "C" int func_00500F70(Obj *self) {
    s32 i = 15;
    func_00500DD8(self);
    char *p = self->arr;
    self->u48 = (s32)D_00689740;
    char *a0 = p;
    do {
        i -= 1;
        func_005041A0(a0);
        p += 8;
        a0 = p;
    } while (i != -1);
    self->u44 = 1;
}
