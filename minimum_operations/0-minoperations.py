#!/usr/bin/python3

"""
Module to calc. the minimum number of operations to reach n characters of 'H'
"""


def minOperations(n):
    """
    Calc. the minimum number of operations needed to reach n characters of 'H'.
    Args:
        n (int): The target number of 'H' characters.
    Returns:
        int: The minimum number of operations required.
    Raises:
        None
    """
    if n <= 1:
        return 0
        
    operations = 0
    divisor = 2

    while n > 1:
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
