/* compiler: ee-gcc2.96-no-strict-aliasing */
struct ItemBase {
    char pad0[0xC];
    float value;
    char pad10[4];
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void update();
};
struct Item : ItemBase { char pad18[0x30 - 0x18]; };
struct Panel {
    char pad0;
    unsigned char b1, b2;
    char pad3;
    short h4, h6, h8, hA;
    float value;
    int handle;
    char pad14[0xC];
    Item items[2];
};
extern "C" void func_003A5740(void *);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004AA1D8(float, float, float, float);
extern "C" void func_003AF108(int, unsigned char, unsigned char, float, float, float, float);
extern "C" void RaceABMonitor__render_main(Panel *p) {
    if (p->handle == 0) func_003A5740(p);
    func_004A1638(6);
    func_004A2808(0x44, 1.0f);
    func_004AA1D8(1.0f, 1.0f, 1.0f, p->value);
    func_003AF108(p->handle, p->b1, p->b2, (float)p->h4, (float)p->h6, (float)p->h8, (float)p->hA);
    Item *item = p->items;
    for (int i = 0; i < 2; i++) {
        item->value = p->value;
        item->update();
        item++;
    }
}
