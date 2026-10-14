struct Wheel {float angle;char gap[44];float otherAngle;char gap2[18];unsigned char active;char gap3[33];float drag,drag2,force,resistance;char gap4[101];unsigned char mode;char gap5[14];};
struct Body {char gap[96];Wheel wheels[4];char gap2[56];float step,damping;char gap3[132];float mass;char gap4[100];float velocity;char gap5[16];float acceleration;char gap6[16];float force;char gap7[60];float extraForce;char gap8[8];float forceStep;};
struct MassData {char gap[0x2f0];float masses[0];};
struct Config {char gap[16];MassData data;};
struct Info {unsigned char word,count;char gap[18];unsigned char indices[0];int index(int i){return i<count?indices[i]:0;}};
struct Obj {char gap[16];Config*config;char gap2[0x104-20];Body body;};
extern "C" Info*func_00359510(Config*);
extern "C" float func_0057D1F0(float),func_0057D2B8(float);
extern "C" void func_00351FA8(Obj*self){
 int i=0;Body*body=&self->body;float sum=0;
 Config*config=self->config;Info*info=func_00359510(config);float step=*(float*)((char*)self+0x54c);
 Wheel*wheel;
 if(info->count){wheel=(Wheel*)((char*)self+0x164);do{sum+=func_0057D1F0(wheel->angle)*wheel->force;++i;++wheel;}while(i<info->count);}
 body->force=(body->force+sum)+body->forceStep;
 float mass=0;
 int j=0;for(;j<info->count;++j){MassData*data=&config->data;if(!((Wheel*)((char*)self+0x164))[j].active)mass+=data->masses[info->index(j)];}
 float inverse=1.0f/(mass+body->mass);
 body->acceleration=body->acceleration+(body->force+body->extraForce)*inverse;
 body->velocity=body->velocity+body->acceleration*step;
 if(body->velocity!=0){
 float correction=0;i=0;
 if(info->count){wheel=(Wheel*)((char*)self+0x164);do{
 correction+=func_0057D1F0(wheel->angle)*wheel->resistance;
 if(wheel->mode==1)correction-=func_0057D2B8(wheel->angle)*wheel->drag;
 else {float angle=wheel->otherAngle;correction-=func_0057D2B8(angle)*wheel->drag;correction-=func_0057D1F0(angle)*wheel->drag2;}
 ++i;++wheel;}while(i<info->count);}
 float change=correction*inverse;
 float velocity=body->velocity+change*step;
 if(body->velocity*velocity>0){body->force+=correction;body->acceleration+=change;}
 else {body->acceleration+=body->damping*(-body->velocity);velocity=0;}
 body->velocity=velocity;
 }
}
