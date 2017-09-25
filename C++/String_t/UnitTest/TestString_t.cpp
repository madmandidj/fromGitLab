#include "String_t.h"
#include "../../inc/mu_test.h"
#include <stdio.h>
#include <string.h>





UNIT(TestDefaultConstructor)
	
	String_t str_t1;
	
	ASSERT_THAT(0 == str_t1.Length());
	
END_UNIT



UNIT(TestConstructorWithConstCharPointer)
	
	String_t str_t1("100% No bugs here\n");
	
	ASSERT_THAT(18 == str_t1.Length());
	
END_UNIT



UNIT(TestConstructorWithConstStringTRef)
	
	String_t str_t1("100% No bugs here\n");
	String_t& str_t1r = str_t1;
	String_t str_t2(str_t1r);
	
	ASSERT_THAT(18 == str_t2.Length());
	
END_UNIT



UNIT(TestGetString)
	
	String_t str_t1("100% No bugs here\n");
	char* str;
	
	str = (char*)str_t1.GetString();
	
	ASSERT_THAT(0 == strcmp(str, "100% No bugs here\n"));
	
END_UNIT



UNIT(TestSetString)
	
	String_t str_t1;
	str_t1.SetString("Yo Yo Yo\n");
	char* str;
	
	str = (char*)str_t1.GetString();
	ASSERT_THAT(0 == strcmp(str, "Yo Yo Yo\n"));
	
END_UNIT




UNIT(TestCompare)
	
	String_t str_t1("yam");
	String_t str_t2("yam");
	
	ASSERT_THAT(0 == str_t1.Compare(str_t2));
	
	str_t2.SetString("yan");
	
	ASSERT_THAT(1 == str_t1.Compare(str_t2));
	
	str_t2.SetString("yal");
	
	ASSERT_THAT(2 == str_t1.Compare(str_t2));
	
END_UNIT



UNIT(TestEqualsOperator)
	
	String_t str_t1("yam");
	String_t str_t2;
	
	str_t2 = str_t1;
	
	ASSERT_THAT(0 == str_t1.Compare(str_t2));
	
END_UNIT



UNIT(TestConvertToLower)
	
	String_t str_t1("YAMAHA");
	String_t str_t2("yamaha");
	
	str_t1.ConvertToLowerCase();
	
	ASSERT_THAT(0 == str_t1.Compare(str_t2));
	
END_UNIT




UNIT(TestConvertToUpper)
	
	String_t str_t1("yamaha");
	String_t str_t2("YAMAHA");
	
	str_t1.ConvertToUpperCase();
	
	ASSERT_THAT(0 == str_t1.Compare(str_t2));
	
END_UNIT



UNIT(TestPrependFromChar)
	
	String_t str_t1("Alon");
	String_t str_t2("EyalAlon");
	
	str_t1.Prepend("Eyal");
	
	ASSERT_THAT(0 == str_t1.Compare(str_t2));
	
END_UNIT



UNIT(TestPrependFromStringT)
	
	String_t str_t1("Alon");
	String_t str_t2("Eyal");
	String_t str_t3("EyalAlon");
	
	str_t1.Prepend(str_t2);

	ASSERT_THAT(0 == str_t1.Compare(str_t3));
	
END_UNIT



UNIT(TestPlusEqualsOperatorConstChar)
	
	String_t str_t1("Alon");
	String_t str_t2("Eyal");
	String_t str_t3("EyalAlon");
	
	str_t2 += "Alon";
	
	ASSERT_THAT(0 == str_t2.Compare(str_t3));
	
END_UNIT



UNIT(TestPlusEqualsOperatorConstStringT)
	
	String_t str_t1("Alon");
	String_t& str_t1r = str_t1;
	String_t str_t2("Eyal");
	String_t str_t3("EyalAlon");
	
	str_t2 += str_t1r;
	
	ASSERT_THAT(0 == str_t2.Compare(str_t3));
	
END_UNIT



UNIT(TestGetIthChar)

	String_t str_t1("EyalAlon");
	char c;
	
	c = str_t1.GetIthChar(4);
	
	ASSERT_THAT('A' == c);
	
END_UNIT



UNIT(TestGetIthCharOperator)

	String_t str_t1("EyalAlon");
	char c;
	
	c = str_t1[4];
	
	ASSERT_THAT('A' == c);
	
END_UNIT



UNIT(TestContainsConstChar)

	String_t str_t1("Alon");
	int result;
	
	result = str_t1.Contains("lo");
	
	ASSERT_THAT(1 == result);
	
END_UNIT



UNIT(TestContainsConstStringT)

	String_t str_t1("Alon");
	String_t str_t2("Alo");
	int result;
	
	result = str_t1.Contains(str_t2);
	
	ASSERT_THAT(1 == result);
	
END_UNIT




UNIT(TestLargerThan)

	String_t str_t1("Alon");
	char str[] = "123";
	
	ASSERT_THAT(str_t1 > str);
	
END_UNIT




UNIT(TestCout)

	String_t str_t1("Alon");
	
	cout << str_t1;
	ASSERT_THAT(1);
	
END_UNIT



UNIT(TestCin)

	String_t str_t1;
	
	cin >> str_t1;
	
	cout << str_t1;
	
	ASSERT_THAT(1);
	
END_UNIT




TEST_SUITE(String_t)

	TEST(TestDefaultConstructor)
	TEST(TestConstructorWithConstCharPointer)
	TEST(TestConstructorWithConstStringTRef)
	TEST(TestGetString)
	TEST(TestSetString)
	TEST(TestCompare)
	TEST(TestEqualsOperator)
	TEST(TestConvertToLower)
	TEST(TestConvertToUpper)
	TEST(TestPrependFromChar)
	TEST(TestPrependFromStringT)
	TEST(TestPlusEqualsOperatorConstChar)
	TEST(TestPlusEqualsOperatorConstStringT)
	TEST(TestGetIthChar)
	TEST(TestContainsConstChar)
	TEST(TestContainsConstStringT)
	TEST(TestLargerThan)
	TEST(TestCout)
	TEST(TestCin)
	TEST(TestGetIthCharOperator)
	
END_SUITE







