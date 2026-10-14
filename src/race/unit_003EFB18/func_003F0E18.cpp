/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Body { float u, pos[2], angle, vel[2], angvel, accel[2], angacc, u2; };
struct State { int t; Body b; };
struct Car { char pad[0x440]; unsigned char idx; };
struct Object { char pad[0x104]; Car car; };
struct Vec3 { float v[3]; };
extern "C" State D_008456C0[6], D_008457F8[6];
extern "C" int D_008457E0[6], D_00845918[6];
extern "C" unsigned char D_00845930[6], D_00621FF8[6];
extern "C" Vec3 D_00622020[6];
extern "C" void func_003F0230(Object*, State*, int) throw();
extern "C" void func_003F0A48(Car*, State*, State*, int) throw();
extern "C" void func_003F05E0(Object*, State*, int) throw();
extern "C" float func_0036CCD8(float,float,float,float);
extern "C" void func_003F0E18(Object *self, int time) {
    State a,b;
    Car *car=&self->car;
    int index=car->idx;
    State *current=D_008456C0+index;
    State *previous=D_008457F8+index;
    if(current->t==-1) {
        if(!D_00845930[index]) return;
        func_003F0230(self,current,time);
        D_00845930[car->idx]=0;
    }
    func_003F0A48(car,&a,current,time-current->t);
    D_00622020[car->idx].v[0]=a.b.pos[0];
    D_00622020[car->idx].v[1]=a.b.pos[1];
    int elapsed=time-D_008457E0[car->idx];
    if(D_00621FF8[4]!=0 && D_00845918[car->idx]!=-1 && elapsed<=D_00621FF8[5]*50) {
        func_003F0A48(car,&b,previous,time-previous->t);
        float weight=(float)elapsed/(float)(D_00621FF8[5]*50);
        switch(D_00621FF8[4]) {
        case 2: weight+=0.5f; break;
        case 3: weight+=1.0f; break;
        }
        float other=1.0f-weight;
        for(int j=0;j<2;j++) a.b.pos[j]=a.b.pos[j]*weight+b.b.pos[j]*other;
        a.b.vel[0]=a.b.vel[0]*weight+b.b.vel[0]*other;
        a.b.vel[1]=a.b.vel[1]*weight+b.b.vel[1]*other;
        a.b.angle=func_0036CCD8(weight,a.b.angle,other,b.b.angle);
        a.b.angvel=a.b.angvel*weight+b.b.angvel*other;
    }
    func_003F05E0(self,&a,elapsed);
}
