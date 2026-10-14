struct Record{unsigned char prefix[2],type,state;int counter,unused;float value;char rest[0x14e4];};
extern "C" void func_0035AB08(void*,Record*,unsigned char);
extern "C" int func_00358468(void*,int);
extern "C" void Automobile__isDataLoggerActive(unsigned char* self,int index,int type,float value){
 unsigned char* owner=*(unsigned char**)(self+12);
 Record* records=*(Record**)(owner+0x14c);
 Record* record=records+index;
 void* object=*(void**)(self+4);
 int count=*(int*)(owner+0x11c);
 if(*(int*)(owner+0xd8)==2&&index)count-=records->counter;
 func_0035AB08(object,record,self[0x544]);
 record->value=value;
 record->type=type;
 record->counter=count;
 record->state=func_00358468(object,50);
}
