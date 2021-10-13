#include <string.h>
#include "temp_functions.h"

int main(int argc, char **argv) {

    int memory_check, current_month, selected_month, current_year, plug[3];
    int current_size = 22;

    const char *opts = "m:f:h";

    int ret;

    char user_file[50] = { 0 };
    FILE *data_file;

    struct measures_t *my_measures;
    my_measures = (struct measures_t *)malloc(sizeof(struct measures_t) * current_size);

    get_current_time(&current_month, &current_year);

    while ((ret = getopt(argc, argv, opts)) != -1) {
        switch (ret) {
            case 'f' :
                strcpy(user_file, optarg);
                data_file = fopen(user_file, "r");
                if (data_file == NULL) {
                    printf("Can't open %s file.\n", user_file);
                    return 0;
                }
                else{
                    memory_check = scan_file(my_measures, data_file, &current_size);

                }

                if (memory_check == 1) {
                    do {
                        my_measures = (struct measures_t *)realloc(my_measures, (sizeof(struct measures_t) * current_size));
                        memory_check = scan_file(my_measures, data_file, &current_size);

                    } while (memory_check == 1);
                }
            case 'm' :
                selected_month = atoi(optarg);
                break;
            case 'h' :
                help_function(argv[0]);
                break;
            case '?' :
                help_function(argv[0]);
                break;
        }
    }
    printf ("===============================================\n");
    print_all(my_measures, current_year, 0);
    printf ("===============================================\n");

    if (selected_month == 0) print_month_data(my_measures, current_month, current_year, plug, 0);
    else print_month_data(my_measures, selected_month, current_year, plug, 0);

    print_all(my_measures, current_year, current_year);
    printf ("===============================================\n");

    free (my_measures);
    if (data_file != NULL) fclose(data_file);

    return 0;
}
