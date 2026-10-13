struct Str { char *p; int length() const { return ((int *)p)[-4]; } };
struct Data { char pad[0x10]; int id; };
struct VEntry { short delta, index; int (*fn)(void *); };
struct VObj { char pad[4]; void *vtable; };
extern "C" void func_00132DB8(void *, void *);
extern "C" void func_00132D60(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" void func_00312318(void *, int);
extern "C" Str *func_00314920(void *);
extern "C" void func_0042F1B8(int, const char *, int, int);
extern "C" char D_0068EAD8[];
static inline const char *get_name(Str *s) {
  if (s->length() == 0) return D_0068EAD8;
  s->p[s->length()] = 0;
  return s->p;
}
static inline int get_value(void *argv) {
  VObj *obj = *(VObj **)((char *)argv + 4);
  VEntry *e = (VEntry *)((char *)obj->vtable + 0x58);
  return e->fn((char *)obj + e->delta);
}
extern "C" void MCalendar__putPresentCarEvent(void *ret, void *self, int argc, void *argv) {
  if (argc > 0) {
    int buf[4];
    int id;
    func_00132DB8(buf, self);
    id = ((Data *)buf[0])->id;
    func_00132D60(buf, 2);
    func_00312370(buf, argv);
    func_0042F1B8(id, get_name(func_00314920((void *)buf[0])), argc < 2 ? 0 : get_value(argv), 4);
    func_00312318(buf, 2);
  }
}
