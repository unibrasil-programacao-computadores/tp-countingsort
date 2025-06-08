#include "sort.h"
#include "input.h"

int main()
{

    sort_base_array(countingsort, "countingsort");
    sort_ordered_arrays(countingsort, "countingsort");
    sort_reverse_ordered_arrays(countingsort, "countingsort");
    sort_uniform_arrays(countingsort, "countingsort");

    return 0;
}
