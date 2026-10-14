/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Car {
 float pos[2]; char p8[0x438]; unsigned char index; char p441[0x27];
 float steer; char p46c[0x28]; float factor; char p498[0x88];
 unsigned char mode; char p521[0x23]; float vel[2]; char p54c[0x24];
 float angle; char p574[8]; float angvel;
};
struct Object { char p0[0x10]; void *data; char p14[0xf0]; Car car; };
struct State { int time; unsigned char flags, factor, steer, pad; float pos[2], angle, vel[2], angvel, accel[2], angacc; short force[2]; };
struct Vec3 { float v[3]; };
struct Info { unsigned char unk, count; char pad[0x2a]; unsigned char group[1]; };
extern "C" Vec3 D_00845970[6];
extern "C" int func_003446B8(Object*);
extern "C" int func_00343BE0(Object*);
extern "C" Info *func_00359510(void*);
static inline void zero(float *f, float v) { f[1]=v; f[0]=v; }
extern "C" void func_003F0230(Object *self, State *out, int time) {
    float force[2];
    int j;
    Car *car=&self->car;
    out->flags=0;
    out->time=time;
    int mode=car->mode;
    if(mode>=8) mode=7;
    out->flags=mode;
    if(func_003446B8(self)) out->flags|=8;
    if(func_00343BE0(self)) out->flags|=16;
    out->factor=(int)(car->factor*64.0f);
    out->steer=(int)(car->steer/0x1.1df468p-7f);
    for(j=0;j<2;j++) {
        out->pos[j]=car->pos[j];
        out->vel[j]=car->vel[j];
    }
    out->angle=car->angle;
    out->angvel=car->angvel;
    out->accel[0]=D_00845970[car->index].v[0];
    out->accel[1]=D_00845970[car->index].v[1];
    out->angacc=D_00845970[car->index].v[2];
    Info *info=func_00359510(self->data);
    zero(force,0.0f);
    for(j=0;j<info->count;j++) {
        char *part=(char*)self+0x164+j*0xec;
        force[info->group[j]]+=*(float*)(part+0x70)+*(float*)(part+0x74);
    }
    for(j=0;j<2;j++) {
        float f=force[j]*0x1.a1f58ep-4f;
        if(f>16000.0f) f=16000.0f;
        else if(f<-16000.0f) f=-16000.0f;
        out->force[j]=(int)f;
    }
}
