struct Stats{char unknown0[0xFE0];float value;};
struct Data{char unknown0[0x10];Stats*stats;};
struct Vehicle{char unknown0[0x18];Data*data;char unknown1C[4];char state[0];};
struct Pool{int count,unknown4;Vehicle**vehicles;};
struct Entry{short adjust;short unknown;int(*fn)(void*);};
struct Manager{char unknown0[0x64];Entry*vt;};
struct Controller;
struct Self{char unknown0[0x60];Pool*pool;char unknown64[0xC];Controller*controller;char unknown74[0x10];Manager*manager;};
extern "C" int SPEC_DATABASE__RaceSpec__getCourseType(Controller*);
extern "C" unsigned char SPEC_DATABASE__CarEquipments__getDriveTrainType(char*);
extern "C" unsigned char RaceOrganization__getPreScore(Self*self,int index){int count=self->pool->count;float value=self->pool->vehicles[index]->data->stats->value;if(count==1)return 0;Manager*m=self->manager;Entry*e=&m->vt[95];if(e->fn((char*)m+e->adjust)==10)return 250;float bias=0.03f;int mode=SPEC_DATABASE__RaceSpec__getCourseType(self->controller);if(mode==2){if(SPEC_DATABASE__CarEquipments__getDriveTrainType((char*)self->pool->vehicles[index]+0x20)!=mode)bias=0x1.1eb850p-4f;}float sum=0.0f;for(int i=0;i<count;++i){if(i!=index)sum+=self->pool->vehicles[i]->data->stats->value;}float diff=sum/float(count-1)+bias-value;float factor;if(diff<0.0f){factor=diff*10.0f+1.0f;if(factor<0x1.999998p-4f)factor=0x1.999998p-4f;}else{factor=diff*200.0f;if(factor<1.0f)factor=1.0f;}factor*=10.0f;if(factor>200.0f)factor=200.0f;return (unsigned char)(unsigned)(factor+0.5f);}
