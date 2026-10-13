// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mCourseRecordUnit:hObject {void* const data;mCourseRecordUnit(void*) __asm__("func_0015AC48");virtual ~mCourseRecordUnit();};
mCourseRecordUnit::mCourseRecordUnit(void* value):data(value){}
