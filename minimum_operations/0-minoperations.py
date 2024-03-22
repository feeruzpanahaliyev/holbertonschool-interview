#!/usr/bin/python3


def minOperations(n):
    if n <= 1:
        return 0
    
    operations = 0
    div = 2

    while n > 1:
        while n % div == 0:
            operations += div
            n //= div
        div += 1

    return operations

