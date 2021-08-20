#include <stdio.h>
#include <ocml_mats.h>


int main(int argc, char *argv[])
{
	matf4x4 identity = matf4x4_identity();
	matf4x4 no = matf4x4_identity();
	no.values[0][0] = 2.0f;
	identity = matf4x4_mult((float*)identity.values,(float*)no.values);

	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			printf("%.2f ", identity.values[j][i]);
		}
		printf("\n");
	}

	return 0;
}
