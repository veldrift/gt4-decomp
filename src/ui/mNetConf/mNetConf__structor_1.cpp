/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Blob { char b[0x258]; };

struct NetConf {
    s32 pad0;
    void *vt;
    char pad8[8];
    Blob data;
    NetConf(const Blob &src);
};

extern char mNetConf__vtable[];
extern "C" void hObject__structor_0(void *);

extern "C" int mNetConf__structor_1(NetConf *self, const Blob &src) {
    hObject__structor_0(self);
    self->vt = mNetConf__vtable;
    self->data = src;
}
