#include "sort.h"
#include "input.h"

int main()
{

    sort_base_array(countingsort, "countingsort");
    sort_ordered_arrays(countingsort, "Countingsort");
    sort_reverse_ordered_arrays(countingsort, "Countingsort");
    sort_uniform_arrays(countingsort, "Countingsort");

    return 0;
}
