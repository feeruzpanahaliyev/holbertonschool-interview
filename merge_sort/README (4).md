<img src="https://github.com/Qcarvalhooliveira/holbertonschool-interview/blob/main/merge_sort/image/Merge-Sort.png" width="1000" height="400">

# **Merge Sort** :computer:

## **Description:** :speech_balloon:

* This exercise involves implementing a merge sort algorithm in C to sort an array of integers in ascending order. The task requires the development of the merge_sort function using a top-down approach, adhering to specific constraints such as sorting the left subarray before the right and ensuring only one memory allocation is used for the temporary array. The implementation should also include the print_array function for output, and the code must follow the Betty coding style guidelines. The merge sort algorithm's time complexities for best, average, and worst cases should be documented as O(nlog(n)). 

## **More Info**

For this project you are given the following print_array function:

```
alexa@ubuntu-xenial:merge_sort$ cat print_array.c
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
alexa@ubuntu-xenial:merge_sort$
```

* Our file print_array.c (containing the print_array function) will be compiled with your functions during the correction.
* Please declare the prototype of the function print_array in your sort.h header file
* Please, note this format is used for Big O notation:
    * O(1)
    * O(n)
    * O(n!)
    * n square -> O(n^2)
    * log(n) -> O(log(n))
    * n * log(n) -> O(nlog(n))


## **Task** :books:

#### **0. Merge sort**

Write a function that sorts an array of integers in ascending order using the Merge Sort algorithm:

* Prototype: void merge_sort(int *array, size_t size);
* You must implement the top-down merge sort algorithm
    * When you divide an array into two sub-arrays, the size of the left array should always be <= the size of the right array. i.e. {1, 2, 3, 4, 5} -> {1, 2}, {3, 4, 5}
    * Sort the left array before the right array
* You are allowed to use printf
* You are allowed to use malloc and free only once (only one call)
* Output: see example

In the file 0-O, write the Big O notations of the time complexity of the Merge Sort algorithm, with 1 notation per line:

* in the best case
* in the average case
* in the worst case

```
alexa@ubuntu-xenial:merge_sort$ cat 0-main.c
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    merge_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}
alexa@ubuntu-xenial:merge_sort$ gcc -Wall -Wextra -Werror -pedantic 0-main.c 0-merge_sort.c print_array.c -o merge
alexa@ubuntu-xenial:merge_sort$ ./merge
19, 48, 99, 71, 13, 52, 96, 73, 86, 7

Merging...
[left]: 19
[right]: 48
[Done]: 19, 48
Merging...
[left]: 71
[right]: 13
[Done]: 13, 71
Merging...
[left]: 99
[right]: 13, 71
[Done]: 13, 71, 99
Merging...
[left]: 19, 48
[right]: 13, 71, 99
[Done]: 13, 19, 48, 71, 99
Merging...
[left]: 52
[right]: 96
[Done]: 52, 96
Merging...
[left]: 86
[right]: 7
[Done]: 7, 86
Merging...
[left]: 73
[right]: 7, 86
[Done]: 7, 73, 86
Merging...
[left]: 52, 96
[right]: 7, 73, 86
[Done]: 7, 52, 73, 86, 96
Merging...
[left]: 13, 19, 48, 71, 99
[right]: 7, 52, 73, 86, 96
[Done]: 7, 13, 19, 48, 52, 71, 73, 86, 96, 99

7, 13, 19, 48, 52, 71, 73, 86, 96, 99
alexa@ubuntu-xenial:merge_sort$
```

## **Author** :black_nib:

* **Queise Carvalho de Oliveira** - [Linkedin](https://www.linkedin.com/in/queise-carvalho-de-oliveira-50359749/)


## License :page_with_curl:
This project is licensed under the [MIT License](https://opensource.org/license/mit/).
