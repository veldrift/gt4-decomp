/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_00576100(void *);
extern "C" void func_00576140(void *);
extern "C" void func_0060F3A0(void *, int);
struct Guard {
    void *p;
    Guard(void *v) : p(v) { func_00576100(p); }
    ~Guard() { func_00576140(p); }
};
struct Queue {
    int index, other, count;
    int values[16];
    void push(const int &value, void *lock) {
        Guard g(lock);
        values[index] = value;
        func_0060F3A0(this, 1);
    }
};
static inline int remaining(int n) { return 16 - n; }
extern "C" void func_00501BF0(int self, int value) {
    Queue *q = (Queue *)(0x8800 + self);
    void *lock = (void *)(0x8850 + self);
    if (remaining(q->count)) {
        volatile struct { int value; void *lock; } local;
        local.value = value;
        local.lock = lock;
        func_00576100(lock);
        int *dest = (int *)q + q->index;
        dest[3] = local.value;
        func_0060F3A0(q, 1);
        func_00576140(lock);
    }
}
