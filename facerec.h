#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	IMAGE_LOAD_ERROR,
	SERIALIZATION_ERROR,
	UNKNOWN_ERROR,
} err_code;

typedef struct facerec {
	void* cls;
	const char* err_str;
	err_code err_code;
} facerec;

typedef struct faceret {
	int num_faces;
	long* rectangles;
	float* descriptors;
	const char* err_str;
	err_code err_code;
} faceret;

facerec* facerec_init(const char* model_dir, const double threshold, const unsigned int jitter);
faceret* facerec_recognize(facerec* rec, const uint8_t* img_data, int len, int max_faces);
faceret* facerec_recognize_mat(facerec* rec, const uint8_t* img_data, int rows, int columns, int max_faces);
void facerec_set_samples(facerec* rec, const float* descriptors, int len);
int facerec_classify(facerec* rec, const float* descriptor);
void facerec_free(facerec* rec);

#ifdef __cplusplus
}
#endif
