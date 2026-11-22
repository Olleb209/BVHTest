
#pragma once

#include <stdbool.h>
#include <math.h>

// ==========================================================
// Compiler attributes
// ==========================================================

#define CCMATH_INLINE static inline

// ==========================================================
// Structs
// ==========================================================

// Vec 4 ----------------------------------------------------

typedef union ccmath_vec4f32 {
	float data[4];

	struct { float x, y, z, w; };
	struct { float r, g, b, a; };
	struct { float s, t, p, q; };
} ccmath_vec4f32;

typedef union ccmath_vec4f64 {
	double data[4];

	struct { double x, y, z, w; };
	struct { double r, g, b, a; };
	struct { double s, t, p, q; };
} ccmath_vec4f64;

// Vec 3 ----------------------------------------------------

typedef union ccmath_vec3f32 {
	float data[3];

	struct { float x, y, z; };
	struct { float r, g, b; };
	struct { float s, t, p; };
} ccmath_vec3f32;

typedef union ccmath_vec3f64 {
	double data[3];

	struct { double x, y, z; };
	struct { double r, g, b; };
	struct { double s, t, p; };
} ccmath_vec3f64;

// Vec 2 ----------------------------------------------------

typedef union ccmath_vec2f32 {
	float data[2];

	struct { float x, y; };
	struct { float u, v; };
	struct { float s, t; };
} ccmath_vec2f32;

typedef union ccmath_vec2f64 {
	double data[2];

	struct { double x, y; };
	struct { double u, v; };
	struct { double s, t; };
} ccmath_vec2f64;

// ==========================================================
// Declarations
// ==========================================================

// ----------------------------------------------------------
// Vec4f32 --------------------------------------------------
// ----------------------------------------------------------

// Computes -v
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_neg(ccmath_vec4f32 v);

// Computes abs(v)
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_abs(ccmath_vec4f32 v);

// Computes the minimum of each component
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_min(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Computes the maximum of each component
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_max(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Clamps all components between two floats
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_clampf(
	ccmath_vec4f32 v,
	float min,
	float max
);

// Clamps all components between two vectors
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_clampv(
	ccmath_vec4f32 v,
	ccmath_vec4f32 min,
	ccmath_vec4f32 max
);

// Interpolates between v1 and v2 with scalar t
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_lerp(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2,
	float t
);

// Interpolates between v1 and v2 with scalar t clamped between 1 and 0
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_lerp_clamped(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2,
	float t
);

// Interpolates between v1 and v2 with component-wise t
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_lerpv(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2,
	ccmath_vec4f32 t
);

// Computes v1 + v2
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_add(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Computes v1 - v2
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_sub(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Computes v1 * v2 component-wise
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_mul(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Multiplies every component by a scalar
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_scale(
	ccmath_vec4f32 v,
	float s
);

// Computes v1 / v2 component-wise
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_div(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Computes the dot product of the given vectors
CCMATH_INLINE 
float ccmath_vec4f32_dot(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Computes the squared length of the given vector
CCMATH_INLINE 
float ccmath_vec4f32_length_squared(
	ccmath_vec4f32 v
);

// Computes the squared distance between the given vectors
CCMATH_INLINE 
float ccmath_vec4f32_distance_squared(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Computes the length of the given vector
CCMATH_INLINE 
float ccmath_vec4f32_length(
	ccmath_vec4f32 v
);

// Computes the distance between the given vectors
CCMATH_INLINE 
float ccmath_vec4f32_distance(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
);

// Makes the given vector have length 1
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_normalize(
	ccmath_vec4f32 v
);

// Makes the given vector have length 1
// Makes it so that if vector is length 0 it stays length 0
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_normalize_safe(
	ccmath_vec4f32 v
);

// ----------------------------------------------------------
// Vec4f64 --------------------------------------------------
// ----------------------------------------------------------

// Computes -v
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_neg(ccmath_vec4f64 v);

// Computes abs(v)
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_abs(ccmath_vec4f64 v);

// Computes the minimum of each component
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_min(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Computes the maximum of each component
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_max(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Clamps all components between two floats
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_clamp(
	ccmath_vec4f64 v,
	double min,
	double max
);

// Clamps all components between two vectors
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_clampv(
	ccmath_vec4f64 v,
	ccmath_vec4f64 min,
	ccmath_vec4f64 max
);

// Interpolates between v1 and v2 with scalar t
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_lerp(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2,
	double t
);

// Interpolates between v1 and v2 with t clamped between 0 and 1
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_lerp_clamped(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2,
	double t
);

// Interpolates between v1 and v2 with component-wise t
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_lerpv(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2,
	ccmath_vec4f64 t
);

// Computes v1 + v2
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_add(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Computes v1 - v2
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_sub(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Computes v1 * v2 component-wise
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_mul(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Multiplies every component by a scalar
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_scale(
	ccmath_vec4f64 v,
	double s
);

// Computes v1 / v2 component-wise
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_div(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Computes the dot product of the given vectors
CCMATH_INLINE 
double ccmath_vec4f64_dot(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Computes the squared length of the given vector
CCMATH_INLINE 
double ccmath_vec4f64_length_squared(
	ccmath_vec4f64 v
);

// Computes the squared distance between the given vectors
CCMATH_INLINE 
double ccmath_vec4f64_distance_squared(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Computes the length of the given vector
CCMATH_INLINE 
double ccmath_vec4f64_length(
	ccmath_vec4f64 v
);

// Computes the distance between the given vectors
CCMATH_INLINE 
double ccmath_vec4f64_distance(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
);

// Makes the given vector have length 1
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_normalize(
	ccmath_vec4f64 v
);

// Makes the given vector have length 1
// Makes it so that if vector is length 0 it stays length 0
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_normalize_safe(
	ccmath_vec4f64 v
);

// ==========================================================
// Definitions
// ==========================================================

// ----------------------------------------------------------
// Vec4f32 --------------------------------------------------
// ----------------------------------------------------------

// Computes -v
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_neg(ccmath_vec4f32 v) {
	return (ccmath_vec4f32){{
		-v.x, -v.y, -v.z, -v.w
	}};
}

// Computes abs(v)
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_abs(ccmath_vec4f32 v) {
	return (ccmath_vec4f32){{
		fabsf(v.x), fabsf(v.y), fabsf(v.z), fabsf(v.w)
	}};
}

// Computes the minimum of each component
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_min(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
	return (ccmath_vec4f32){{
		fminf(v1.x, v2.x),
		fminf(v1.y, v2.y),
		fminf(v1.z, v2.z),
		fminf(v1.w, v2.w)
	}};
}

// Computes the maximum of each component
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_max(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
	return (ccmath_vec4f32){{
		fmaxf(v1.x, v2.x),
		fmaxf(v1.y, v2.y),
		fmaxf(v1.z, v2.z),
		fmaxf(v1.w, v2.w)
	}};
}

// Clamps all components between two floats
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_clampf(
	ccmath_vec4f32 v,
	float min,
	float max
) {
	return (ccmath_vec4f32){{
		fminf(max, fmaxf(min, v.x)),
		fminf(max, fmaxf(min, v.y)),
		fminf(max, fmaxf(min, v.z)),
		fminf(max, fmaxf(min, v.w))
	}};
}

// Clamps all components between two vectors
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_clampv(
	ccmath_vec4f32 v,
	ccmath_vec4f32 min,
	ccmath_vec4f32 max
) {
	return (ccmath_vec4f32){{
		fminf(max.x, fmaxf(min.x, v.x)),
		fminf(max.y, fmaxf(min.y, v.y)),
		fminf(max.z, fmaxf(min.z, v.z)),
		fminf(max.w, fmaxf(min.w, v.w))
	}};
}

// Interpolates between v1 and v2 with scalar t
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_lerp(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2,
	float t
) {
	return ccmath_vec4f32_add(
		v1,
		ccmath_vec4f32_scale(
			ccmath_vec4f32_sub(v2, v1),
			t
		)
	);
}

// Interpolates between v1 and v2 with t clamped between 0 and 1
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_lerp_clamped(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2,
	float t
) {
	return ccmath_vec4f32_add(
		v1,
		ccmath_vec4f32_scale(
			ccmath_vec4f32_sub(v2, v1),
			fminf(1.0f, fmaxf(0.0f, t))
		)
	);
}

// Interpolates between v1 and v2 with component-wise t
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_lerpv(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2,
	ccmath_vec4f32 t
) {
	return ccmath_vec4f32_add(
		v1,
		ccmath_vec4f32_mul(
			ccmath_vec4f32_sub(v2, v1),
			t
		)
	);
}

// Computes v1 + v2
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_add(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
	return (ccmath_vec4f32){{
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z,
		v1.w + v2.w
	}};
}

// Computes v1 - v2
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_sub(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
	return (ccmath_vec4f32){{
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z,
		v1.w - v2.w
	}};
}

// Computes v1 * v2 component-wise
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_mul(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
	return (ccmath_vec4f32){{
		v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z,
		v1.w * v2.w
	}};
}

// Multiplies every component by a scalar
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_scale(
	ccmath_vec4f32 v,
	float s
) {
	return (ccmath_vec4f32){{
		v.x * s,
		v.y * s,
		v.z * s,
		v.w * s
	}};
}

// Computes v1 / v2 component-wise
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_div(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
	return (ccmath_vec4f32){{
		v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z,
		v1.w / v2.w
	}};
}

// Computes the dot product of the given vectors
CCMATH_INLINE 
float ccmath_vec4f32_dot(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
	return v1.x * v2.x +
		   v1.y * v2.y +
		   v1.z * v2.z +
		   v1.w * v2.w;
}

// Computes the squared length of the given vector
CCMATH_INLINE 
float ccmath_vec4f32_length_squared(
	ccmath_vec4f32 v
) {
	return ccmath_vec4f32_dot(v, v);
}

// Computes the squared distance between the given vectors
CCMATH_INLINE 
float ccmath_vec4f32_distance_squared(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
    return ccmath_vec4f32_length_squared(ccmath_vec4f32_sub(v1, v2));
}

// Computes the length of the given vector
CCMATH_INLINE 
float ccmath_vec4f32_length(
	ccmath_vec4f32 v
) {
	return sqrtf(ccmath_vec4f32_length_squared(v));
}

// Computes the distance between the given vectors
CCMATH_INLINE 
float ccmath_vec4f32_distance(
	ccmath_vec4f32 v1,
	ccmath_vec4f32 v2
) {
    return ccmath_vec4f32_length(ccmath_vec4f32_sub(v1, v2));
}

// Makes the given vector have length 1
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_normalize(
	ccmath_vec4f32 v
) {
	float inv_length = 1.0f / sqrtf(ccmath_vec4f32_length_squared(v));

	return ccmath_vec4f32_scale(v, inv_length);
}

// Makes the given vector have length 1
// Makes it so that if vector is length 0 it stays length 0
CCMATH_INLINE 
ccmath_vec4f32 ccmath_vec4f32_normalize_safe(
	ccmath_vec4f32 v
) {
	float squared_length = ccmath_vec4f32_length_squared(v);

	if (squared_length == 0.0f) {
		return (ccmath_vec4f32){{0.0f, 0.0f, 0.0f, 0.0f}};
	}

	float inv_length = 1.0f / sqrtf(squared_length);

	return ccmath_vec4f32_scale(v, inv_length);
}

// ----------------------------------------------------------
// Vec4f64 --------------------------------------------------
// ----------------------------------------------------------

// Computes -v 
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_neg(ccmath_vec4f64 v) {
	return (ccmath_vec4f64){{
		-v.x, -v.y, -v.z, -v.w
	}};
}

// Computes abs(v)
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_abs(ccmath_vec4f64 v) {
	return (ccmath_vec4f64){{
		fabs(v.x), fabs(v.y), fabs(v.z), fabs(v.w)
	}};
}

// Computes the minimum of each component
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_min(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
	return (ccmath_vec4f64){{
		fmin(v1.x, v2.x),
		fmin(v1.y, v2.y),
		fmin(v1.z, v2.z),
		fmin(v1.w, v2.w)
	}};
}

// Computes the maximum of each component
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_max(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
	return (ccmath_vec4f64){{
		fmax(v1.x, v2.x),
		fmax(v1.y, v2.y),
		fmax(v1.z, v2.z),
		fmax(v1.w, v2.w)
	}};
}

// Clamps all components between two doubles
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_clamp(
	ccmath_vec4f64 v,
	double min,
	double max
) {
	return (ccmath_vec4f64){{
		fmin(max, fmax(min, v.x)),
		fmin(max, fmax(min, v.y)),
		fmin(max, fmax(min, v.z)),
		fmin(max, fmax(min, v.w))
	}};
}

// Clamps all components between two vectors
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_clampv(
	ccmath_vec4f64 v,
	ccmath_vec4f64 min,
	ccmath_vec4f64 max
) {
	return (ccmath_vec4f64){{
		fmin(max.x, fmax(min.x, v.x)),
		fmin(max.y, fmax(min.y, v.y)),
		fmin(max.z, fmax(min.z, v.z)),
		fmin(max.w, fmax(min.w, v.w))
	}};
}

// Interpolates between v1 and v2 with scalar t
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_lerp(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2,
	double t
) {
	return ccmath_vec4f64_add(
		v1,
		ccmath_vec4f64_scale(
			ccmath_vec4f64_sub(v2, v1),
			t
		)
	);
}

// Interpolates between v1 and v2 with t clamped between 0 and 1
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_lerp_clamped(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2,
	double t
) {
	return ccmath_vec4f64_add(
		v1,
		ccmath_vec4f64_scale(
			ccmath_vec4f64_sub(v2, v1),
			fmin(1.0, fmax(0.0, t))
		)
	);
}

// Interpolates between v1 and v2 with component-wise t
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_lerpv(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2,
	ccmath_vec4f64 t
) {
	return ccmath_vec4f64_add(
		v1,
		ccmath_vec4f64_mul(
			ccmath_vec4f64_sub(v2, v1),
			t
		)
	);
}

// Computes v1 + v2
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_add(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
	return (ccmath_vec4f64){{
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z,
		v1.w + v2.w
	}};
}

// Computes v1 - v2
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_sub(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
	return (ccmath_vec4f64){{
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z,
		v1.w - v2.w
	}};
}

// Computes v1 * v2 component-wise
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_mul(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
	return (ccmath_vec4f64){{
		v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z,
		v1.w * v2.w
	}};
}

// Multiplies every component by a scalar
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_scale(
	ccmath_vec4f64 v,
	double s
) {
	return (ccmath_vec4f64){{
		v.x * s,
		v.y * s,
		v.z * s,
		v.w * s
	}};
}

// Computes v1 / v2 component-wise
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_div(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
	return (ccmath_vec4f64){{
		v1.x / v2.x,
		v1.y / v2.y,
		v1.z / v2.z,
		v1.w / v2.w
	}};
}

// Computes the dot product of the given vectors
CCMATH_INLINE 
double ccmath_vec4f64_dot(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
	return v1.x * v2.x +
		   v1.y * v2.y +
		   v1.z * v2.z +
		   v1.w * v2.w;
}

// Computes the squared length of the given vector
CCMATH_INLINE 
double ccmath_vec4f64_length_squared(
	ccmath_vec4f64 v
) {
	return ccmath_vec4f64_dot(v, v);
}

// Computes the squared distance between the given vectors
CCMATH_INLINE 
double ccmath_vec4f64_distance_squared(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
    return ccmath_vec4f64_length_squared(ccmath_vec4f64_sub(v1, v2));
}

// Computes the length of the given vector
CCMATH_INLINE 
double ccmath_vec4f64_length(
	ccmath_vec4f64 v
) {
	return sqrt(ccmath_vec4f64_length_squared(v));
}

// Computes the distance between the given vectors
CCMATH_INLINE 
double ccmath_vec4f64_distance(
	ccmath_vec4f64 v1,
	ccmath_vec4f64 v2
) {
    return ccmath_vec4f64_length(ccmath_vec4f64_sub(v1, v2));
}

// Makes the given vector have length 1
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_normalize(
	ccmath_vec4f64 v
) {
	double inv_length = 1.0 / sqrt(ccmath_vec4f64_length_squared(v));

	return ccmath_vec4f64_scale(v, inv_length);
}

// Makes the given vector have length 1
// Makes it so that if vector is length 0 it stays length 0
CCMATH_INLINE 
ccmath_vec4f64 ccmath_vec4f64_normalize_safe(
	ccmath_vec4f64 v
) {
	double squared_length = ccmath_vec4f64_length_squared(v);

	if (squared_length == 0.0) {
		return (ccmath_vec4f64){{0.0, 0.0, 0.0, 0.0}};
	}

	double inv_length = 1.0f / sqrt(squared_length);

	return ccmath_vec4f64_scale(v, inv_length);
}
