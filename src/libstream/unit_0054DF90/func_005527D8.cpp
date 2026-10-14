/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_0086FDC0[];
extern "C" void func_00552970();
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void *exception__structor_0(int);
extern "C" void rbuf__structor_0(void *, int);
extern "C" void func_005547E8(void *);
extern "C" void func_00552AC8(void *, int, int);
extern "C" void func_00552AD8(int);
extern "C" void func_00565A78(void *);
extern "C" void func_00565798(void *, int);
extern "C" void func_00565AD0(void *);
struct S { int pad[2]; void *buffer; int padc; void *table; char pad14[0x40]; int magic; int size; int pad5c; void *queue; void (*callback)(); int pad68; char data[8]; char pad74[0x9c]; int state; };
extern "C" void func_005527D8(S *self) {
    void **buffer = &self->buffer;
    self->table = D_0086FDC0;
    self->magic = 0x424b5550;
    self->size = 5;
    self->callback = func_00552970;
    func_005A48D8(self->data, 0, 8);
    void *p = exception__structor_0(0x44);
    rbuf__structor_0(p, 0x80);
    *buffer = p;
    func_005547E8(p);
    func_00552AC8(self, 0x14, 5);
    self->state = 0;
    func_00552AD8(2);
    func_00565A78(self);
    func_00565798(self->queue, 0);
    func_00565AD0(self);
}
