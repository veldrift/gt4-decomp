/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Body { float u, pos[2], angle, vel[2], angvel, accel[2], angacc, u2; };
struct State { int t; Body b; };
struct Car { float pos[2]; float u; float x[2]; float pad14; float y[2]; char pad20[0x550]; float angle; };
extern "C" unsigned char D_00621FF8[2];
extern "C" float func_0057D2B8(float) throw();
extern "C" float func_0057D1F0(float);
static inline void advance(State *out, float dt) {
    for (int j=0; j<2; j++) out->b.pos[j] += out->b.vel[j]*dt;
    out->b.angle += out->b.angvel*dt;
}
extern "C" void func_003F0A48(Car *car, State *out, State *in, int ticks) {
    float dt = (float)ticks * 0x1.5d867ap-12f;
    *out = *in;
    if(ticks != 0) {
        if ((unsigned char)(D_00621FF8[0]-2) < 2u) {
            int steps=(ticks*60+1500)/3000;
            if(steps<=0) steps=1;
            float subdt=dt/(float)steps;
            for(int i=0;i<steps;i++) {
                for(int j=0;j<2;j++) out->b.pos[j]+=out->b.vel[j]*subdt;
                float a=out->b.accel[0]*subdt;
                float b=out->b.accel[1]*subdt;
                out->b.angle += out->b.angvel*subdt;
                float s=func_0057D2B8(out->b.angle);
                float c=func_0057D1F0(out->b.angle);
                float ns=-s;
                float vx=out->b.vel[0]+(ns*a+c*b);
                float vy=out->b.vel[1]+(c*a+s*b);
                out->b.angvel+=out->b.angacc*subdt;
                out->b.vel[1]=vy;
                out->b.vel[0]=vx;
            }
        } else {
            if(D_00621FF8[0]==1) {
                float a=out->b.accel[0]*dt;
                float b=out->b.accel[1]*dt;
                for(int j=0;j<2;j++) {
                    out->b.vel[j]+=car->x[j]*a;
                    out->b.vel[j]+=car->y[j]*b;
                }
            }
            advance(out,dt);
        }
        if(D_00621FF8[1]==1) {
            for(int j=0;j<2;j++) out->b.pos[j]=(out->b.pos[j]+car->pos[j])*0.5f;
            float diff=car->angle-out->b.angle;
            if(diff>3.14159265f) out->b.angle+=6.2831853f;
            else if(diff < -3.14159265f) out->b.angle-=6.2831853f;
            out->b.angle=(out->b.angle+car->angle)*0.5f;
        }
    }
}
