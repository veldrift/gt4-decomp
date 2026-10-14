/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Bound { char pad[8]; float size; };
struct Obj { char pad[0x38]; Bound *bound; };
extern "C" void func_00455598(void *,int,int);
extern "C" void func_004A40B0(float,float);
extern "C" void RaceEntryCar__update(int);
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void pglPushAttrib(int);
extern "C" void func_004A5688();
extern "C" void func_004A74A0();
extern "C" void func_004A74B4(float *);
extern "C" void func_004A7550(float *);
extern "C" void func_004A7890(float,float,float);
static inline void render_scaled(Obj *obj,int n,float size) {
    float far;
            if(size>0.0f) far=1000.0f/size;
            else far=1.0f;
            RaceEntryCar__update(0);
            func_004A53F8();
            func_004A74A0();
            func_004A7890(far,far,far);
            func_00455598(obj,n,0);
            func_004A5400();
}
extern "C" void func_00396B80(void *self,Obj *obj,int n,float near,float far) {
    float mat[16];
    if(obj) {
        pglPushAttrib(0x40);
        func_004A40B0(0.0f,1.0f);
        RaceEntryCar__update(1);
        func_004A53F8();
        func_004A7550(mat);
        if(mat[2]==0.0f && mat[6]==0.0f) {
            float d=far-near;
            mat[10]=-(far+near)/d;
            mat[14]=(far * -2.0f * near)/d;
            func_004A74B4(mat);
            RaceEntryCar__update(0);
            func_004A53F8();
            func_004A74A0();
            func_00455598(obj,n,0);
            func_004A5400();
        } else {
            render_scaled(obj,n,obj->bound->size);
        }
        RaceEntryCar__update(1);
        func_004A5400();
        func_004A5688();
        RaceEntryCar__update(0);
    }
}
