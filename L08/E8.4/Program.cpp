#include <stdio.h>
#include "Weather.h"

int main(int argc, char const *argv[])
{
    struct dataset entry1 = { 10, 20, 30, 40 };
    struct dataset entry2 = { 1, 2, 3, 4 };

    printf_s("Printing dataset with p-by-v\n");
    printDataset(entry1);
    printf_s("\nPrinting dataset with p-by-r\n");
    printDatasetPtr(&entry2);

    return 0;
}
