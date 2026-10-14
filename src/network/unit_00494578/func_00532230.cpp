struct Obj { char pad[0x104]; int id; };
struct Buffer { unsigned char type,subtype; char data[510]; };
extern Buffer D_00868390;
extern "C" int func_00531EB0(signed char, Obj *, int, int, Buffer *) throw();
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" int func_00532230(signed char a, Obj *p, int id, unsigned int type, unsigned int subtype, int size, const void *src) {
    if (type >= 6) return 0x17;
    if (subtype >= 0x100) return 0x17;
    if (size <= 0) return 0x17;
    if (size >= 0x1ff) return 0x1f;
    if (!src) return 0x17;
    if (id == p->id) return 0;
    Buffer *b = &D_00868390;
    b->type = type;
    b->subtype = subtype;
    func_005A4724(b->data, src, size);
    return func_00531EB0(a, p, id, size+2, b);
}
