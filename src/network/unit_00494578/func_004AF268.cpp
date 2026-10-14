/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VEntry { short delta, index; void (*fn)(void *); };
struct Conn { char pad[0x38]; int owner; char p2[0x44]; int state, status; char p3[0x10]; int timer, busy; char p4[8]; char *vtbl; };
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_004AD368(int, void *);
extern "C" void func_004AD438(int, void *);
extern "C" void func_004AD5E0(int, void *);
extern "C" int func_004AF520(void *);
static inline void notify(Conn *c, int off) { VEntry *e = (VEntry *)(c->vtbl + off); e->fn((char *)c + e->delta); }
extern "C" void func_004AF268(Conn *c) {
 int changed = 0;
 func_00576788(c);
 int state = c->state;
 c->busy = 1;
 switch (state) {
 case 0:
 func_004AD368(c->owner, c); c->status = 1; changed = 1; notify(c, 0x40); break;
 case 1:
 if (func_004AF520(c)) { func_004AD438(c->owner, c); c->status = 1; changed = 1; notify(c, 0x40); c->timer = 0; } break;
 case 2:
 if (func_004AF520(c)) { func_004AD5E0(c->owner, c); c->status = 1; changed = 1; notify(c, 0x40); c->timer = 0; } break;
 }
 func_005767C0(c);
 if (changed) notify(c, 0x48);
}
