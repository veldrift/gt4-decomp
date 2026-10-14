struct Object{char prefix[56];void*resource;};
extern "C" void func_00503630(Object*);
extern "C" void func_00578908(void*);
extern "C" void func_00578AF0(void*);
extern "C" void func_00503560(Object*self){void*resource=self->resource;self->resource=0;if(resource){func_00503630(self);func_00578908(resource);func_00578AF0(resource);}}
