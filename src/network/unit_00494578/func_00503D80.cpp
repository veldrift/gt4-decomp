/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Node { char pad[0x10]; void *value; };
struct List { char data[12]; };
struct Obj { char pad[0x30]; List free, active; char pad48[0x910]; void *handle; };
struct Request { int a,b,timeout,c,d; void (*cb1)(); void (*cb2)(); Obj *self; };
extern "C" void func_00503FD0();
extern "C" void func_00503F48();
extern "C" int func_00522408(Request *, int);
extern "C" int func_005293D0(void *, const Request *, void **);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_0057CB00(List *, Node *);
extern "C" Node **func_0057CC10(List *);
extern "C" void *func_005A48D8(void *, int, unsigned);
struct Lock {
    Obj *self;
    char pad[12];
    Lock(Obj *o) : self(o) { func_00576788(o); }
    ~Lock() { func_005767C0(self); }
};
extern "C" Node *func_00503D80(Obj *self, int arg1) {
    List *free = &self->free;
    Node *result = 0;
    Lock lock(self);
    Node **p = func_0057CC10(free);
    Request request;
    void *out;
    if (p) {
        result = *p;
        func_005A48D8(&request, 0, 32);
        func_00522408(&request, arg1);
        request.timeout = 5000;
        request.cb1 = func_00503FD0;
        request.cb2 = func_00503F48;
        request.self = self;
        if (func_005293D0(self->handle, &request, &out)) {
            func_0057CB00(free, result);
            result = 0;
        } else {
            result->value = out;
            func_0057CB00(&self->active, result);
        }
    }
    return result;
}
