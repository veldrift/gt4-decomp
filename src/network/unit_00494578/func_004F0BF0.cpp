/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Ring { int index, other, count; int items[256]; };
struct Conn { char pad[0x198]; Ring queue; };
extern "C" void func_0060EBC8(Ring *, int);
static inline unsigned remaining(unsigned capacity, unsigned used) { return capacity - used; }
static inline void push(Ring *q, const int &value, int capacity) {
    if (remaining(capacity, q->count) != 0) {
        int *entry = q->items + q->index;
        *entry = value;
        func_0060EBC8(q, 1);
    }
}
extern "C" void func_004F0BF0(Conn *conn, int value) {
    push(&conn->queue, value, 256);
}
