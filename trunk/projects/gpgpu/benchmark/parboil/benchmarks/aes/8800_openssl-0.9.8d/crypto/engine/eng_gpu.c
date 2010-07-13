/*
 * Master's thesis "Using Graphic Processing Unit in Block Cipher Calculations"
 * by Urmas Rosenberg
 *
 * 2007
 *
 * GPU 8800GTS implementation, ENGINE
 */

#include <openssl/opensslconf.h>

#ifndef OPENSSL_NO_HW

//#include <stdio.h>
#include <openssl/engine.h>

// GPU stuff
#define GLEW_STATIC 1
#include <GL/glew.h>
#include <GL/glut.h>
#include <Cg/cgGL.h>

static ENGINE *ENGINE_gpu (void);

void
ENGINE_load_gpu (void)
{
	ENGINE *toadd = ENGINE_gpu ();
	if (!toadd) return;
	ENGINE_add (toadd);
	ENGINE_free (toadd);
	ERR_clear_error ();
}

static int gpu_init(ENGINE *e);
static int gpu_finish(ENGINE *e);
static int gpu_ciphers(ENGINE *e, const EVP_CIPHER **cipher, const int **nids, int nid);

static const char *gpu_id = "gpu";
static char gpu_name[100];


static int
gpu_bind_helper(ENGINE *e)
{
	BIO_snprintf(gpu_name, sizeof(gpu_name),"GPU (8800GTS) accelerated encrypting/decrypting");
	if (!ENGINE_set_id(e, gpu_id) ||
	    !ENGINE_set_name(e, gpu_name) ||
	    !ENGINE_set_init_function(e, gpu_init) ||
	    !ENGINE_set_finish_function(e, gpu_finish) ||
	    !ENGINE_set_ciphers (e, gpu_ciphers)) {
		return 0;
	}
	return 1;
}

static ENGINE *
ENGINE_gpu(void)
{
	ENGINE *eng = ENGINE_new();

	if (!eng) {
		return NULL;
	}

	if (!gpu_bind_helper(eng)) {
		ENGINE_free(eng);
		return NULL;
	}

	return eng;
}

static int
gpu_init(ENGINE *e)
{
	init_8800();
	return 1;
}

static int
gpu_finish(ENGINE *e)
{
	finish_8800();
	return 1;
}

#define AES_BLOCK_SIZE		16
#define AES_KEY_SIZE_128	16


static int gpu_cipher_nids[] = {
	NID_aes_128_ecb,
};
static int gpu_cipher_nids_num = (sizeof(gpu_cipher_nids)/
				      sizeof(gpu_cipher_nids[0]));

static int gpu_aes_init_key(EVP_CIPHER_CTX *ctx, const unsigned char *key,
				const unsigned char *iv, int enc);
static int gpu_aes_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out,
			      const unsigned char *in, size_t nbytes);

#define EVP_CIPHER_block_size_ECB	AES_BLOCK_SIZE

#define	DECLARE_AES_EVP(ksize,lmode,umode)	\
static const EVP_CIPHER gpu_aes_##ksize##_##lmode = {	\
	NID_aes_##ksize##_##lmode,		\
	EVP_CIPHER_block_size_##umode,	\
	AES_KEY_SIZE_##ksize,		\
	AES_BLOCK_SIZE,			\
	0 | EVP_CIPH_##umode##_MODE,	\
	gpu_aes_init_key,		\
	gpu_aes_cipher,		\
	NULL,				\
	0,	\
	EVP_CIPHER_set_asn1_iv,		\
	EVP_CIPHER_get_asn1_iv,		\
	NULL,				\
	NULL				\
}

DECLARE_AES_EVP(128,ecb,ECB);

static int
gpu_ciphers (ENGINE *e, const EVP_CIPHER **cipher, const int **nids, int nid)
{
	if (!cipher) {
		*nids = gpu_cipher_nids;
		return gpu_cipher_nids_num;
	}
	switch (nid) {
	  case NID_aes_128_ecb:
	    *cipher = &gpu_aes_128_ecb;
	    break;
	  default:
	    *cipher = NULL;
	    return 0;
	}
	return 1;
}

static int
gpu_aes_init_key (EVP_CIPHER_CTX *ctx, const unsigned char *key,
		      const unsigned char *iv, int enc)
{
	// decrypt is not implemented on gpu
	if (!ctx->encrypt)return 0;

	int key_len = EVP_CIPHER_CTX_key_length(ctx) * 8;

	int i, j;
	unsigned char _key[256];
	memset(_key, 0, sizeof(_key));

	switch(key_len) {
		case 128:
			init_key_8800(key);

			break;
		default:
			return 0;
	}

	return 1;
}

static int
gpu_aes_cipher(EVP_CIPHER_CTX *ctx, unsigned char *out_arg,
		   const unsigned char *in_arg, size_t nbytes)
{
	cipher_8800(in_arg, out_arg);
	return 1;
}

#endif /* !OPENSSL_NO_HW */
