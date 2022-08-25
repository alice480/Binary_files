#include "state_search.h"

int main() {
    char path[256];
    int year, month, day;
    input(path, &year, &month, &day);
    int code = search(path, day, month, year);
    if (code)
        printf("%d", code);
    else
        printf("n/a");
    return 0;
}

int search(char *path, int day, int month, int year) {
    int code = 0;
    struct data ptr[1];
    FILE *file = fopen(path, "rb");
    if (file) {
        while (!feof(file) && !code) {
            while (fscanf(file, "%d %d %d %d %d %d %d %d", &ptr[0].year, &ptr[0].month, &ptr[0].day,
                    &ptr[0].hour, &ptr[0].minute, &ptr[0].second, &ptr[0].status, &ptr[0].code) == 8) {
                if (ptr[0].day == day && ptr[0].month == month && ptr[0].year == year)
                    code = ptr[0].code;
            }
        }
    }
    return code;
}


void input(char *path, int *year, int *month, int *day) {
    char str[11];
    scanf("%s", path);
    scanf("%s", str);
    char *ptr = strtok(str, ".");
    *day = atoi(ptr);
    ptr = strtok(NULL, ".");
    *month = atoi(ptr);
    ptr = strtok(NULL, "\0");
    *year = atoi(ptr);
}
