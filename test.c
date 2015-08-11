#include <stdio.h>
#include <othm_base.h>

int main(void)
{
	printf("%s\n", othm_load_file("test.ilk"));
	return 0;
}
