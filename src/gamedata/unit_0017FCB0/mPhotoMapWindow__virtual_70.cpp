/* compiler: ee-gcc2.96-no-strict-aliasing */
struct V { short d, i; void (*fn)(void *, void *, void *); };
struct Node { char pad[4]; char *vtbl; };
struct Vec4 { float x, y, z, w; Vec4(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {} };
struct View { char b[0x3C]; };
struct G { View v[2]; int cur; };

extern G D_0061850C;

extern "C" void func_00105280(void *, int);
extern "C" void func_00105338(void *, void *, int);
extern "C" void func_00105708(void *);
extern "C" void *func_00192E20(void *);
extern "C" void func_00194DB0(void *, void *);
extern "C" float func_002313E0(void *);
extern "C" float func_00231400(void *);
extern "C" float func_00231420(void *);
extern "C" float func_00231440(void *);
extern "C" void mWidget__virtual_70(void *, void *, int);
extern "C" void func_004A1638(int);
extern "C" void func_004A2808(int, float);
extern "C" void func_004A29A8(int);
extern "C" void func_004A2D20(int, int, int, int);
extern "C" void RaceEntryCar__update(int);
extern "C" void func_004A53F8(void);
extern "C" void func_004A5400(void);
extern "C" void pglPushAttrib(int);
extern "C" void func_004A5688(void);
extern "C" void func_004A7454(void);
extern "C" void func_004AB040(int);

extern "C" void mPhotoMapWindow__virtual_70(void *self, Node *w, int flag)
{
    void *h;
    mWidget__virtual_70(self, w, 0);
    if (flag != 0) {
        h = func_00192E20(w);
        if (h != 0) {
            pglPushAttrib(0xC1);
            float fx = func_002313E0(w);
            float fy = func_00231400(w);
            float fz = func_00231420(w);
            float fw = func_00231440(w);
            Vec4 in(0.0f, 0.0f, 0.0f, 0.0f);
            in.x = fx;
            in.y = fy;
            in.z = fz;
            in.w = fw;
            Vec4 out(0.0f, 0.0f, 0.0f, 0.0f);
            char buf[0x40];
            V *v = (V *)(w->vtbl + 0x1F8);
            v->fn((char *)w + v->d, &out, &in);
            func_004A2D20((int)out.x, (int)out.y, (int)out.z, (int)out.w);
            func_00105338(buf, &D_0061850C.v[D_0061850C.cur], 0x3A);
            func_00105708(buf);
            RaceEntryCar__update(1);
            func_004A53F8();
            func_004A7454();
            RaceEntryCar__update(0);
            func_004A53F8();
            func_004A7454();
            func_00194DB0(self, h);
            func_004A5400();
            RaceEntryCar__update(1);
            func_004A5400();
            RaceEntryCar__update(0);
            func_004AB040(5);
            func_004A29A8(0);
            func_004AB040(0xF);
            func_004A1638(0x11);
            func_004A1638(6);
            func_004A2808(0x44, 1.0f);
            func_004A5688();
            func_00105280(buf, 2);
        }
    }
}
