struct Obj{int a,mode;char data[96];int count;};
extern "C" int AutomobileControlRecord__Recorder__size(void*);
extern "C" void func_00346890(Obj*,int);
extern "C" int AutomobileControlRecord__Manager__size(Obj* self){int size=4;switch(self->mode){case 0:size+=AutomobileControlRecord__Recorder__size(self->data);break;case 1:for(int i=0;i<self->count;i++){func_00346890(self,i);size+=5364;size+=AutomobileControlRecord__Recorder__size(self->data);}break;case 2:size+=5364+AutomobileControlRecord__Recorder__size(self->data);break;}return size;}
