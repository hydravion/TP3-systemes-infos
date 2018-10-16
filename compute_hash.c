#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include "compute_hash.h"


int get_hash(char *digest_type, char *data_to_hash, int data_type) // inspired by the example
/* get_hash
  INPUT:
  OUTPUT:
*/
{
  if (data_type == "file"){
    FILE *fp;
    int i = 0;
    char *p = strtok(data_to_hash,);

    for (file in data_to_hash){

    }
  }


  EVP_MD_CTX *mdctx;
  const EVP_MD *md;

//  char mess3[] = "Le manuel disait: Nécessite Windows 7 ou mieux. J’ai donc installé Linux\n";
  unsigned char md_value[EVP_MAX_MD_SIZE];
  int md_len, i;

  md = EVP_get_digestbyname(digest_type);

  if(!md) {
    printf("Unknown message digest %s\n", argv[1]);
    exit(1);
  }

  mdctx = EVP_MD_CTX_new();
  EVP_DigestInit_ex(mdctx, md, NULL);
  EVP_DigestUpdate(mdctx, mess3, strlen(mess3));
  //EVP_DigestUpdate(mdctx, mess1, strlen(mess1));
  //EVP_DigestUpdate(mdctx, mess2, strlen(mess2));
  EVP_DigestFinal_ex(mdctx, md_value, &md_len);
  EVP_MD_CTX_free(mdctx);

  printf("Digest is: ");
  for (i = 0; i < md_len; i++)
  printf("%02x", md_value[i]);
  printf("\n");

  return 0;
}
