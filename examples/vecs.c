#include <stdio.h>
#include <ocml_vecs.h>

int fn(int b)
{
	return b * 5;
}

int main(int argc, char *argv[])
{
	vec2f f = {0.0f, 1.0f};
	vec2i i = {10, 20};

	printf("%.2f %.2f\n", f.x, f.y);
	printf("%d %d\n", i.x, i.y);

	f = vec2f_add(f, (vec2f){5.0f, 4.0f});
	printf("add %.2f %.2f\n", f.x, f.y);

	f = vec2f_sub(f, (vec2f){10.0f, 10.0f});
	printf("sub %.2f %.2f\n", f.x, f.y);

	f = vec2f_mul(f, (vec2f){4.0f, 4.0f});
	printf("mul %.2f %.2f\n", f.x, f.y);

	f = vec2f_div(f, (vec2f){2.0f, 2.0f});
	printf("div %.2f %.2f\n", f.x, f.y);

	i = vec2i_add(i, (vec2i){10,30});
	printf("i %d %d\n", i.x, i.y);

	vec3d d = {100.0, 500.0, 600.0};
	printf("d %.2f %.2f %.2f\n", d.x, d.y, d.z);

	d = vec3d_div(d, (vec3d){100.0, 100.0, 100.0});
	printf("d %.2f %.2f %.2f\n", d.x, d.y, d.z);

	vec3d fwd = {0.0, 0.0, 1.0};
	vec3d right = {1.0, 0.0, 0.0};
	vec3d up = vec3d_cross(fwd,right);
	printf("up %.2f %.2f %.2f\n", up.x, up.y, up.z);

	vec3i a = {1, 2, 3};
	vec3i b = {5, 5, 5};
	printf("dotAB %d\n", vec3i_dot(a,b));

	vec2u32 ua = {7, 8};
	vec2u32 ub = {100, 4};
	printf("dotUAB %u\n", vec2u32_dot(ua,ub));

	printf("%d\n", fn(11));

	return 0;
}
