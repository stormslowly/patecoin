
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

char const a_work_string[] = "{\"error\": null, \"id\": 0, \"result\": {"
		"\"hash1\": \"00000000000000000000000000000000000000000000000000000000000000000000008000000000000000000000000000000000000000000000000000010000\", "
		"\"data\": \"00000002b5f9f8b1b55f202c2cfc63bd560de6e53ab744d194df7a870000000400000000ce85db2a5865d561f5413930cf35b908b68d3abfb7d8ef6f6491b38ad6d52dc5523a9a961926222200000000000000800000000000000000000000000000000000000000000000000000000000000000000000000000000080020000\", "
		"\"target\": \"0000000000000000000000000000000000000000000000000000ffff00000000\", "
		"\"midstate\": \"d0e26d152a835bfd854e9a1acdddc48c9a59ebb35aa98df63fcb0ad299c12e6d\"}}";

TEST(WorkJSON, basiccase)
{
	json_t *json;
	json_t *a_object;
	json_error_t error = { };
	const char *str;
	int a;

	json = json_loads("{\"a\" : 123 }",&error);

	a_object = json_object_get(json, "a");
	a = json_integer_value(a_object);
	json_decref(json);
	json_decref(a_object);

	CHECK_EQUAL(123,a);
}

TEST(WorkJSON,workjsoncase){
	json_t *json,*work_json,*midstate;
	json_error_t error;

	char work_data[32];
	char const *str;

	json = json_loads(a_work_string,&error);

	work_json = json_object_get(json,"result");

	midstate = json_object_get(work_json,"midstate");

	str = json_string_value(midstate);

//	printf("\n %s \n", str);

	STRCMP_EQUAL("d0e26d152a835bfd854e9a1acdddc48c9a59ebb35aa98df63fcb0ad299c12e6d",str);

	json_decref(json);
	json_decref(work_json);
	json_decref(midstate);


}
