/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Block32 { int w[8]; };
struct Block40 { int a,b; Block32 tail; };
struct Input { char pad[0x18]; int a,b; Block32 tail; };
struct Queue { int index, unk4, count; Block40 entries[16]; };
struct Owner { char pad[0x3bf4]; Queue queue; };
extern Owner D_00645570;
extern "C" void func_004F87E8(void *, int);
extern "C" void func_0060EC60(void *, int);
extern "C" void func_004F44E0(Input *in, Owner *o) {
    if (!o) o = &D_00645570;
    Queue *q = &o->queue;
    int remaining = 16;
    remaining -= q->count;
    if (remaining != 0) {
        Block40 temp;
        temp.a = in->a;
        temp.b = in->b;
        temp.tail = in->tail;
        char *e = (char *)q + q->index * 40;
        *(Block40 *)(e + 12) = temp;
        func_0060EC60(q, 1);
    }
    func_004F87E8(o, in->a);
}
