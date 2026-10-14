/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Item { volatile unsigned char id; char pad1; signed char kind; char pad3[0x11]; float value; };
struct Range { void *data; int count; char pad[8]; };
struct Root { char pad0[0x10]; char *other; };
struct Self { char pad0[0x1c]; unsigned char id, pos, previous, current; char pad20[4]; float oldValue, value; char pad2c[0xbc]; Root *root; void *source; };
extern "C" void func_00469F08(Range *, void *, int);
extern "C" int func_00469FC8(Range *, int);
extern "C" unsigned int func_00463960(Self *) throw();
extern "C" float func_004674F0(Self *, int) throw();
extern "C" void func_004679C0(Self *self) {
    Range range;
    char *other = self->root->other;
    func_00469F08(&range, self->source, self->id);
    int count = range.count;
    func_00463960(self);
    self->previous = self->current;
    int index = self->pos;
    if ((index ^ count) == 0) index = 0;
    self->oldValue = self->value;
    if (((Item *)func_00469FC8(&range, index))->kind == -128) {
        ++index;
        if (index >= count) index -= count;
    }
    switch (self->current = ((Item *)func_00469FC8(&range, index))->id) {
    case 0:
        self->value = *(float *)(other + 0xfd8);
        break;
    case 1:
    case 2:
        self->value = func_004674F0(self, index);
        break;
    }
}
