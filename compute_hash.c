#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>
#include "compute_hash.h"


char get_hash(char *digest_type, char *data_to_hash, char *data_type) // inspired by the example
/* get_hash
  INPUT:
  OUTPUT:
*/
{
  /* Split data_to_hash into different strings */
  if(data_type == "file"){
    // following snippet found on stackoverflow
    FILE *fp;
    int i, nb_files;
    i = 0;
    nb_files = 0;
    char *p = strtok(data_to_hash, " ");
    char *filenames[30];

    while(p != NULL){
      filenames[i++] = p;
      p = strtok(NULL, " "); // split the string containing the filenames
      nb_files++;
    }
  }


  EVP_MD_CTX *mdctx;
  const EVP_MD *md;

//  char mess3[] = "Le manuel disait: Nécessite Windows 7 ou mieux. J’ai donc installé Linux\n";
  unsigned char md_value[EVP_MAX_MD_SIZE];
  int md_len, i;

  md = EVP_get_digestbyname(digest_type);

  if(!md) { // if digest type unknown
    printf("Unknown message digest %s\n", argv[1]);
    exit(1);
  }

  int nb;
  switch(data_type){
    case "file":
      nb = nb_files;
      data = filesnames;
    case "string":
      nb = 1;
      data = ;
  }

  int i;
  for(i = 0; i < nb; ++i){
    mdctx = EVP_MD_CTX_new();
    EVP_DigestInit_ex(mdctx, md, NULL);
    EVP_DigestUpdate(mdctx, data[i], strlen(data[i]));
    //EVP_DigestUpdate(mdctx, mess1, strlen(mess1));
    EVP_DigestFinal_ex(mdctx, md_value, &md_len);
    EVP_MD_CTX_free(mdctx);
  }


  printf("Digest is: ");
  for (i = 0; i < md_len; i++)
  printf("%02x", md_value[i]);
  printf("\n");

  return data_to_hash;
}
