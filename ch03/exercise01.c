//Programming Exercise 3.11.1
#include <stdio.h>
int main(void)
{
//***************************************************************************
//The length of long and int is the same, change %d/%u -> %ld/%lu will be ok
//                  No need to declare following 2 lines
//***************************************************************************
//	long max_long = 2147483647;		//2^31 - 1
//	unsigned long max_ulong = 4294967295;	//2^32 - 1

	short max_int16 = 32767;	//2^15 - 1
	unsigned short max_uint16 = 65535;	//2^16 - 1
	int max_int32 = 2147483647;	//2^31 - 1
	unsigned int max_uint32 = 4294967295;	//2^32 - 1
	long long max_int64 = 9223372036854775807;	//2^63 - 1
	unsigned long long max_uint64 = 18446744073709551615;	//2^64 - 1

	float of_float = 2.51232123e38f;
	double of_double = 2.51232123e307;
	long double of_ldouble = 2.51232123e307;

	float uf_float = 9.876543210987654321e-40f;
	double uf_double = 9.876543210987654321e-314;
	long double uf_ldouble = 9.876543210987654321e-314;



//------------
//integer part
//------------

	//test short
	printf("The size of short is %zd\n", sizeof(short));
	printf("The max of short is %hd\n", max_int16);
	printf("short overflow is %hd.\n\n", max_int16 + 1);

	//test unsigned short
	printf("The size of unsigned short is %zd\n", sizeof(unsigned short));
	printf("The max of unsigned short is %hu\n", max_uint16);
	printf("unsigned short overflow is %hu.\n\n", max_uint16 + 1);

	//test int
	printf("The size of int is %zd\n", sizeof(int));
	printf("The max of int is %d\n", max_int32);
	printf("int overflow is %d.\n\n", max_int32 + 1);

	//test unsigned int
	printf("The size of unsigned int is %zd\n", sizeof(unsigned int));
	printf("The max of int is %u\n", max_uint32);
	printf("unsigned int overflow is %u.\n\n", max_uint32 + 1);

	//test long
	printf("The size of long is %zd\n", sizeof(long));
	printf("The max of long is %ld\n", max_int32);
	printf("long overflow is %ld.\n\n", max_int32+ 1);

	//test unsigned long
	printf("The size of unsigned long is %zd\n",sizeof(unsigned long));
	printf("The max of unsigned long is %lu\n", max_uint32);
	printf("unsigned long overflow is %lu.\n\n", max_uint32 + 1);

	//test long long
	printf("and the size of long long is %zd\n", sizeof(long long));
	printf("The max of long long is %lld\n", max_int64);
	printf("unsigned int overflow is %lld.\n\n", max_int64 + 1);

	//test unsigned long long
	printf("and the size of unsigned long long is %zd\n", sizeof(unsigned long long));
	printf("The max of long long is %llu\n", max_uint64);
	printf("unsigned int overflow is %llu.\n\n", max_uint64 + 1);

//-------------
//decemal part
//-------------
	printf("The size of float is %zd\n", sizeof(float));
	printf("The size of double is %zd\n", sizeof(double));
	printf("The size of long double is %zd\n\n", sizeof(long double));

	printf("Decemal Overflow(Mutipled by 10.0f):\n");
	printf("float = %e, float * 10.0f = %e\n", of_float, of_float * 10);
	printf("double = %e, double * 10.0f = %e\n", of_double, of_double * 10);
	printf("long double = %Le, long double * 10.0f = %Le\n\n", of_ldouble, of_ldouble * 10);

	printf("Decemal Underflow(Divided by 1.0e5f):\n");
	printf("float = %e, float / 1.0e5f = %e\n", uf_float, uf_float / 1e5f);
	printf("double = %e, double / 1.0e5f = %e\n", uf_double, uf_double / 1e5f);
	printf("long double = %Le, long double / 1.0e5f = %Le\n", uf_ldouble, uf_ldouble / 1e5f);

	return 0;
}
