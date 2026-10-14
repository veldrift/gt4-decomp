struct Task { int active; void (*cb)(void *); int kind; };
struct Result { int status, error; };
struct State { int kind; char data[16]; unsigned short size; char pad[2]; };
struct Fast { int active, busy; };
struct Request { int data[2]; int size; void (*cb)(); int zero; };
struct Manager { char pad[0x80]; int (*copy)(void *, void *); };
struct Sender { char pad[0x20]; int (*send)(int, void *); };
extern int D_0064B4F0, D_0064B4F4;
extern State D_008687C8;
extern Fast D_008687E0;
extern void (*D_00868818)(void *);
extern Manager *D_0064B4B0;
extern Sender *D_0064B4BC;
extern "C" int func_005344F8(void *) throw();
extern "C" void func_005367E0();
extern "C" int func_00534570(Task *t, Result *r) {
 Request q; State *s;
 if (!r) return 23;
 r->error=30; r->status=1;
 if (!t) goto invalid;
 if (!t->active) {r->error=38;return 38;}
 if (!t->cb) goto invalid;
 if (D_0064B4F0 && D_008687E0.active && !D_008687E0.busy) {
  t->cb(&D_008687E0); r->error=0; goto success;
 }
 if(t->kind==3) func_005344F8(&t->kind);
 {
 s=&D_008687C8;
 if(s->kind!=3) {
invalid:
  r->error=23;return 23;
 }
 D_00868818=t->cb;
 D_0064B4B0->copy(&q,&s->data);
 q.size=s->size; q.cb=func_005367E0; q.zero=0;
 if(D_0064B4BC->send(D_0064B4F4,&q)) {r->error=37;return 37;}
 }
 r->error=0;
success:
 return 0;
}
