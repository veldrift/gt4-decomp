/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ring { int stride; int f4; int read; char *data; int index; int write; bool empty() const { return write == read; } };
extern "C" {
void func_0054F420(void *, int);
void func_00574EB0(void *);
void func_00574EE8(void *);
void func_00576788(void *);
void func_005767C0(void *);
void func_0057B410(Ring *, int);
}
struct Guard {
    void *p;
    Guard(void *q) : p(q) { func_00576788(q); }
    ~Guard() { func_005767C0(p); }
};
static inline bool empty(const Ring *r) { return r->write == r->read; }
struct Obj { char pad[0x380]; Ring ring; char pad398[0x48]; int active; };
extern "C" void func_0054E948(Obj *obj) {
    char *self = (char *)obj;
    if (obj->active) {
      Ring *ring = &obj->ring;
      void *mutex = self + 0x39C;
      do {
        if (obj->ring.empty()) {
            func_00574EB0(self + 0x350);
        } else {
            int index = ring->index;
            func_0054F420(ring->data + ring->stride * index, 0xA000);
            {
                Guard lock(mutex);
                func_0057B410(ring, 1);
            }
            func_00574EE8(self + 0x2F0);
        }
      } while (obj->active);
    }
}
