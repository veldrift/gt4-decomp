/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    char pad0[0x260];
    int x260, x264, x268;
    char pad26c[0x74];
    char lock[0x34];
    int active, done;
};
extern "C" void func_001C1FB0(int, int, int) throw();
extern "C" void func_001C3AA0(void *, int) throw();
extern "C" void func_00574EB0(void *);
extern "C" void func_00576788(int);
extern "C" void func_005767C0(int);
extern "C" void func_001C41C8(Obj *self) {
    for (;;) {
        self->active = 0;
        func_00574EB0(self->lock);
        int done = self->done;
        self->active = 1;
        if (done) break;
        func_00576788((int)self->lock);
        func_001C1FB0(self->x268, self->x264, self->x260);
        func_005767C0((int)self->lock);
        func_001C3AA0(self, self->x268);
    }
}
