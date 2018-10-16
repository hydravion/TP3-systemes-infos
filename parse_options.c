#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "parse_options.h"

#define DATA_LEN 255
#define DIGEST_LEN 10

int compute_and_print_hashes(int argc, char *argv[]) // inspired by the example
/* compute_and_print_hashes
  INPUT: arguments to the program
  OUTPUT:
*/
{
  int opt, flag_is_file;
  opt = 0;
  char data_to_hash[DATA_LEN], digest_type[DIGEST_LEN];

  optind = 1;
  while ((opt = getopt(argc, argv, "f:t:")) != -1) {
     switch (opt) {
     case 'f':
        int flag_is_file = 1;
        printf("f %s\n", argv[optind]);
        printf("f %s\n", optarg);
        strncpy(data_to_hash, optarg, DATA_LEN);
        break;
     case 't':
         printf("t %s\n", argv[optind]);
         strncpy(digest_type, optarg, DIGEST_LEN);
         break;
     default: /* '?' */
         fprintf(stderr, "Usage: %s [-t nsecs] [-n] name\n",
                 argv[0]);
         exit(EXIT_FAILURE);
     }
  }

  if (optind >= argc) {
     fprintf(stderr, "Expected argument after options\n");


  }

  if (!flag_is_file){
    data_to_hash[0] = '\0';
    while (argv[optind]) {
      strcat(data_to_hash,argv[optind]);
      strcat(data_to_hash," ");
      optind++;
    }
    data_to_hash[strlen(data_to_hash)-1] = '\0'; // remove the last character (a whitespace)
  }


  printf("data = %s, digest = %s, name argument = %s\n", data_to_hash, digest_type, argv[optind]);


  return 0;
}
