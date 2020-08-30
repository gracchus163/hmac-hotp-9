#include <u.h>
#include <libc.h>
#include <mp.h>
#include <libsec.h>

#define KEYLEN 20
void
print_bytes(uchar* bytes, int len)
{
	for(int i =0; i < len; i++)
	{
		print("%x", bytes[i]);
	}
	print("\n");
}
void
main() 
{
	
	ulong counter = 1;
	char *keystr = "3132333435363738393031323334353637383930";
	uchar key[KEYLEN];
	char byte[3];
	byte[2] = '\0';
	for(int i = 0; i < KEYLEN; i++)
	{
		byte[0] = keystr[i*2]; byte[1] = keystr[(i*2)+1];
		key[i] = (uchar)strtoul(byte, nil, 16);
	}
	print_bytes(key, KEYLEN);
	ulong dlen = sizeof(ulong);
	uchar *data = malloc(dlen);
	memset(data, 0, dlen);
	memcpy(data, (void*)&counter, dlen);
	uchar digest[SHA1dlen];
	hmac_sha1(data, dlen, key, KEYLEN, digest, nil);
	print_bytes(digest, SHA1dlen);
}