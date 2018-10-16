#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "compute_hash.h"
#include "parse_options.h"


int main(int argc, char *argv[])
{
    /*
    1. process the options (-f for files, one hash per file, else string, -t to choose digest type, default sha1)
      1.1
    2. hash the data
      2.1 if file,
      2.2 if string
    */
    
    compute_and_print_hashes(argc, argv);

    exit(EXIT_SUCCESS);
}
