/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Raw { void *set; void *obj; };
struct Pred { void *set; void *obj;
    Pred(void *s, void *o) : set(s), obj(o) {}
    Pred(const Pred &p) { *(Raw *)this = *(const Raw *)&p; }
};
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005DD518(void *, Pred);
static inline void remove_if(void *list, Pred pr) { func_005DD518(list, pr); }
extern "C" void func_00250C58(char *self, void *obj) {
    void *lock = self + 0xE8;
    func_00576788(lock);
    Pred pr(self, obj);
    remove_if(self + 0x10, pr);
    func_005767C0(lock);
}
