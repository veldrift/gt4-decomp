/* compiler: ee-gcc2.96-nogcse */
struct Range { int index; int low; int high; };
struct Obj { char pad[0xBC]; Range r; char padC8[0x28]; signed char *disabled; };
extern "C" void func_002D73C8(Obj *, int, int) throw();
extern "C" void func_0057CE40(Range *, int);
extern "C" int func_0057CF10(Range *, int);
extern "C" int func_002D7468(Obj *self, int step) {
    Range *r = &self->r;
    int old = r->index;
    int result = func_0057CF10(r, step);
    signed char *disabled = self->disabled;
    if (disabled) {
        int index = r->index;
        while (disabled[index]) {
            ++index;
            if (index >= r->high) {
                func_0057CE40(r, old);
                return 0;
            }
        }
        func_0057CE40(r, index);
    }
    func_002D73C8(self, old, r->index);
    return result;
}
