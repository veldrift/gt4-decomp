struct Car;struct Record;struct World;struct RaceEntry;
struct VEntry {short adjust,index;void *function;};
struct RaceEntry {int count;char unknown4[4];Car **cars;char unknownC[20];virtual void slot0();virtual Car *take();virtual void slot2();virtual void slot3();virtual int append(Car*);};
struct World {char unknown[0x64];VEntry *table;char unknown68[8];void *data;char unknown74[0xC54];int mode;};
struct Car {char unknown[0x1A0];char state[0xFC0];char unknown1160[0x1728];int active;char unknown288C[0xBB0];Record *record;};
struct Record {char unknown[0xD4];char control[0xFC];int flag;};
struct Owner {char unknown[0x60];RaceEntry *entry;char unknown64[0x20];World *world;char unknown88[12];int flag;};
extern "C" {extern char *D_00622F4C;void RaceEntryCar__toGhost(Car*,Car*,int);void func_00346708(int,int);void *func_003466D8(int,int);void *func_0034C190(void*,int);void func_003B6AE8(Car*,void*);void func_003BBA30(void*,int);void AutomobileControlRecord__Manager__reset(void*);}
extern "C" void func_003C08C0(Owner*self,int mode,int transfer){
 if(transfer){if((unsigned)(self->world->mode-2)<2)return;if(!*(int*)(D_00622F4C+0x39D7C))return;}
 switch(self->entry->count){case 0:return;case 1:{Car *car=self->entry->take();self->entry->append(car);break;}case 2:default:break;}
 self->flag=0;
 if(mode!=2){Car **cars=self->entry->cars;RaceEntryCar__toGhost(cars[1],cars[0],transfer);}
 switch(mode){case 0:func_00346708(1,0);break;case 1:{void *destination=func_003466D8(1,0);void *source=func_003466D8(1,2);__builtin_memcpy(destination,source,0x10000);break;}}
 World *world=self->world;VEntry *call=world->table+72;Record *record=((Record*(*)(World*,int))call->function)((World*)((char*)world+call->adjust),1);record->flag=0;
 if(transfer){void *data=world->data;Car *car=self->entry->cars[1];car->active=0;func_003B6AE8(car,func_0034C190(data,1));func_003BBA30(car->state,1);car->record=record;AutomobileControlRecord__Manager__reset(record->control);}
}
