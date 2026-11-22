
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "ccmath.h"

#define COUNT 4096
#define ITERATIONS 256
#define ROUNDS 7

static volatile double benchmark_sink = 0.0;

static double get_time(void) {
	struct timespec ts;
	timespec_get(&ts, TIME_UTC);

	return (double)ts.tv_sec + (double)ts.tv_nsec * 1e-9;
}

static void initialize(
	ccmath_vec4f32* a,
	ccmath_vec4f32* b
) {
	for (int i = 0; i < COUNT; i++) {
		float x = (float)(i % 100 + 1) * 0.01f;

		a[i] = (ccmath_vec4f32) {
			.x = x,
			.y = x + 0.5f,
			.z = x + 1.0f,
			.w = x + 1.5f
		};

		b[i] = (ccmath_vec4f32) {
			.x = 1.01f,
			.y = 1.02f,
			.z = 1.03f,
			.w = 1.04f
		};
	}
}

static double checksum(ccmath_vec4f32* data) {
	double sum = 0.0;

	for (int i = 0; i < COUNT; i++) {
		sum += data[i].x;
		sum += data[i].y;
		sum += data[i].z;
		sum += data[i].w;
	}

	return sum;
}

static double benchmark_add(
	ccmath_vec4f32* a,
	ccmath_vec4f32* b
) {
	double start = get_time();

	for (int n = 0; n < ITERATIONS; n++) {
		for (int i = 0; i < COUNT; i++) {
			a[i] = ccmath_vec4f32_add(a[i], b[i]);
		}
	}

	double elapsed = get_time() - start;
	benchmark_sink += checksum(a);

	return elapsed;
}

static double benchmark_mul(
	ccmath_vec4f32* a,
	ccmath_vec4f32* b
) {
	double start = get_time();

	for (int n = 0; n < ITERATIONS; n++) {
		for (int i = 0; i < COUNT; i++) {
			a[i] = ccmath_vec4f32_mul(a[i], b[i]);
		}
	}

	double elapsed = get_time() - start;
	benchmark_sink += checksum(a);

	return elapsed;
}

static double benchmark_scale(ccmath_vec4f32* a) {
	double start = get_time();

	for (int n = 0; n < ITERATIONS; n++) {
		for (int i = 0; i < COUNT; i++) {
			a[i] = ccmath_vec4f32_scale(a[i], 1.001f);
		}
	}

	double elapsed = get_time() - start;
	benchmark_sink += checksum(a);

	return elapsed;
}

static double benchmark_dot(
	ccmath_vec4f32* a,
	ccmath_vec4f32* b
) {
	double start = get_time();
	double sum = 0.0;

	for (int n = 0; n < ITERATIONS; n++) {
		for (int i = 0; i < COUNT; i++) {
			a[i] = ccmath_vec4f32_add(a[i], b[i]);
			sum += ccmath_vec4f32_dot(a[i], b[i]);
		}
	}

	double elapsed = get_time() - start;
	benchmark_sink += sum;

	return elapsed;
}

static double benchmark_length(ccmath_vec4f32* a) {
	double start = get_time();
	double sum = 0.0;

	for (int n = 0; n < ITERATIONS; n++) {
		for (int i = 0; i < COUNT; i++) {
			a[i] = ccmath_vec4f32_scale(a[i], 1.0001f);
			sum += ccmath_vec4f32_length(a[i]);
		}
	}

	double elapsed = get_time() - start;
	benchmark_sink += sum;

	return elapsed;
}

static double benchmark_normalize(ccmath_vec4f32* a) {
	double start = get_time();

	for (int n = 0; n < ITERATIONS; n++) {
		for (int i = 0; i < COUNT; i++) {
			a[i] = ccmath_vec4f32_normalize(a[i]);
		}
	}

	double elapsed = get_time() - start;
	benchmark_sink += checksum(a);

	return elapsed;
}

typedef double (*benchmark_fn)(
	ccmath_vec4f32*,
	ccmath_vec4f32*
);

static double samples[ROUNDS];

static int compare_double(const void* a, const void* b) {
	double x = *(const double*)a;
	double y = *(const double*)b;

	return (x > y) - (x < y);
}

static void run_benchmark(
	const char* name,
	benchmark_fn fn,
	ccmath_vec4f32* a,
	ccmath_vec4f32* b
) {
	for (int r = 0; r < ROUNDS; r++) {
		initialize(a, b);

		// Warm up
		fn(a, b);

		initialize(a, b);

		samples[r] = fn(a, b) * 1000.0;
	}

	qsort(samples, ROUNDS, sizeof(double), compare_double);

	printf("%-16s %10.3f ms\n", name, samples[ROUNDS / 2]);
}

static void run_single_benchmark(
	const char* name,
	double (*fn)(ccmath_vec4f32*),
	ccmath_vec4f32* a,
	ccmath_vec4f32* b
) {
	for (int r = 0; r < ROUNDS; r++) {
		initialize(a, b);
		fn(a);

		initialize(a, b);
		samples[r] = fn(a) * 1000.0;
	}

	qsort(samples, ROUNDS, sizeof(double), compare_double);

	printf("%-16s %10.3f ms\n", name, samples[ROUNDS / 2]);
}

int main(void) {
	ccmath_vec4f32* a = malloc(sizeof(ccmath_vec4f32) * COUNT);
	ccmath_vec4f32* b = malloc(sizeof(ccmath_vec4f32) * COUNT);

	if (!a || !b) {
		fprintf(stderr, "Memory allocation failed\n");
		free(a);
		free(b);
		return 1;
	}

	printf("CCMath Benchmark\n");
	printf("Vectors: %d\n", COUNT);
	printf("Iterations: %d\n", ITERATIONS);
	printf("Rounds: %d (median)\n\n", ROUNDS);

	run_benchmark("Addition", benchmark_add, a, b);
	run_benchmark("Multiplication", benchmark_mul, a, b);

	run_single_benchmark("Scalar multiply", benchmark_scale, a, b);

	run_benchmark("Dot product", benchmark_dot, a, b);

	run_single_benchmark("Length", benchmark_length, a, b);
	run_single_benchmark("Normalize", benchmark_normalize, a, b);

	printf("\nSink: %.6f\n", benchmark_sink);

	free(a);
	free(b);

	return 0;
}
