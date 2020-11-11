#include "sort_ascending.h"

void sort_ascending(double data_set[], int qty_elements)
{
  if (qty_elements < 10000)
  {
    std::vector <double> to_sort(data_set, data_set+qty_elements);

    std::sort(to_sort.begin(), to_sort.end());

    for (int transfer_index = 0; transfer_index < qty_elements; transfer_index++)
    {
      data_set[transfer_index] = to_sort[transfer_index];
    }
  }
}
