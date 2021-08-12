#include <ocml_mats.h>

int main(int argc, char *argv[])
{
	matf4x4 identity = {0};
	(*matf4x4_ite(identity,0,0)) = 1;
	return 0;
}
