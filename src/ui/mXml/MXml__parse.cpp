/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void func_0026C458(void *, int) throw();
extern "C" void func_0026C4B0(void *, void *) throw();
extern "C" int func_0026D320(void *, char *, int, int);
extern "C" void func_002FC870(void *, int);
extern "C" void func_002FC8C8(void *, void *);
extern "C" int func_002FE250(void *);
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" char *func_00314AD8(void *);
extern "C" int func_00314B10(void *);
struct Value {
    void *obj; char pad[12];
    Value(void *src) { func_002FC8C8(this, src); }
    ~Value() { func_002FC870(this, 2); }
    void *get() const { return obj; }
};
struct Holder {
    void *obj; char pad[12];
    Holder(void *src) { func_0026C4B0(this, src); }
    ~Holder() { func_0026C458(this, 2); }
    void *get() const { return obj; }
};
extern "C" void MXml__parse(void *arg0, void *arg1, int count, char *args) {
    void *buf0[4];
    int flag;
    if (count > 0) {
        flag = 1;
        func_00312370(buf0, args);
        if (count >= 2) {
            Value value(args + 4);
            flag = func_002FE250(value.get()) == 1;
        }
        {
            Holder holder(arg1);
            void *obj = holder.get();
            char *text = func_00314AD8(buf0[0]);
            func_0026D320(obj, text, func_00314B10(buf0[0]), flag);
        }
        func_00312318(buf0, 2);
    }
}
