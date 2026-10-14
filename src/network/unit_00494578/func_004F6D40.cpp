/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Blob32 { int w[8]; };
struct Record { int first; Blob32 data; };
struct Queue { int index, other, count; Record items[16]; };
struct Conn { char pad[0x39a4]; Queue queue; };
struct Arg { char pad[0x18]; int first; Blob32 data; };
extern Conn D_00645570;
extern "C" void func_0060ECD8(Queue *, int);
extern "C" void func_004F6D40(Arg *arg, Conn *conn) {
    if (!conn) conn = &D_00645570;
    Queue *q = &conn->queue;
    int remaining = 16;
    remaining -= q->count;
    if (remaining != 0) {
        Record rec;
        rec.first = arg->first;
        rec.data = arg->data;
        Record *entry = q->items + q->index;
        *entry = rec;
        func_0060ECD8(q, 1);
    }
}
