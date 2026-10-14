struct First{unsigned long words[47];int changed,preserved;};
struct Second{char unknown0[0xFB4];int preserved;};
struct Tail{int words[8];};
struct Asset;
struct Embedded;
struct Car{char unknown0[0x20];First first;Second second;char unknown1158[0x1728];Asset* asset;Asset* linked;char unknown2888[0x74];int changed;char unknown2900[0xB40];int a,b,c,d,e,f,g,h;char unknown3460[8];Tail tail;};
extern "C" void RaceEntryCar__copyVehicleModel(Car*,const Asset*);
extern "C" Embedded* func_003930D8(Embedded*,const Embedded*);
inline void restore(int* d,const int& keep){*d=keep;}
inline void assignFirst(Car* d,const Car* s,int keep){d->first=s->first;restore(&d->first.preserved,keep);}
inline void assignSecond(Car* d,const Car* s,int keep){d->second=s->second;restore(&d->second.preserved,keep);}
extern "C" void RaceEntryCar__toGhost(Car* self,const Car* source,int linked){
 First* first=&self->first;
 assignFirst(self,source,self->first.preserved);
 assignSecond(self,source,self->second.preserved);
 first->changed=1;
 self->a=source->a;self->b=source->b;self->c=source->c;self->d=source->d;self->e=source->e;self->f=source->f;self->g=source->g;self->h=source->h;
 self->tail=source->tail;
 if(!linked)RaceEntryCar__copyVehicleModel(self,source->asset);else self->linked=source->asset;
 func_003930D8((Embedded*)self->unknown2900,(const Embedded*)source->unknown2900);
 self->changed=1;
}
