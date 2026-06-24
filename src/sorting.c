#include "struktur.h"

int lebihBesar(Hadiah a, Hadiah b)
{
    if (a.y > b.y)
    {
    return 1;
    }
    if (a.y == b.y && a.x > b.x)
    {
        return 1;
    }
    return 0;
}

void sortHadiah(Hadiah data[], int jumlah)
{
    int i, j;
    Hadiah temp;
    for (i = 1; i < jumlah; i++)
    {
        temp = data[i];
        j = i - 1;
        while (j >= 0 && lebihBesar(data[j], temp))
        {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = temp;
    }
}