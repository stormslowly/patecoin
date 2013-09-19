
#include <stdio.h>
#include <stdlib.h>
#include "CppUTest/TestHarness.h"

extern "C"{
#include "jansson/jansson.h"
}

TEST_GROUP(WorkJSON)
{ 
	void setup()
	{
	}
	void teardown()
	{
	}
};

char a_work_string[] = "{\"error\": null, \"id\": 0, \"result\": {\"hash1\": \"00000000000000000000000000000000000000000000000000000000000000000000008000000000000000000000000000000000000000000000000000010000\", \"data\": \"00000002b5f9f8b1b55f202c2cfc63bd560de6e53ab744d194df7a870000000400000000ce85db2a5865d561f5413930cf35b908b68d3abfb7d8ef6f6491b38ad6d52dc5523a9a961926222200000000000000800000000000000000000000000000000000000000000000000000000000000000000000000000000080020000\", \"target\": \"0000000000000000000000000000000000000000000000000000ffff00000000\", \"midstate\": \"d0e26d152a835bfd854e9a1acdddc48c9a59ebb35aa98df63fcb0ad299c12e6d\"}}";

TEST(WorkJSON, workload)
{

	json_t *json;
	json_t *a_object;
	json_error_t error = { };
	const char *str;
	int a;

	json = json_loads("{\"a\" : 123 }",&error);

	printf("=====%s.....",error.text);


	a_object = json_object_get(json, "a");

	a = json_integer_value(a_object);

	CHECK_EQUAL(123,a);

	// ASSERT_NULL(str);

	// STRCMP_EQUAL("Hello World!\n", str);

	json_decref(json);
	json_decref(a_object);


}
