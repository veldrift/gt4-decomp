/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[8]; void *head; };
extern "C" int func_003E4CA8(void *) throw();
extern "C" int func_003E4F60(Obj *s) {
    void *p = s->head;
    if (!p) return 0;
    return func_003E4CA8(p);
}
