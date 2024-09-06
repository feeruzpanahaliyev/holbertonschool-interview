<img src="https://github.com/Qcarvalhooliveira/holbertonschool-interview/blob/main/making_change/image/Making-Change.png" width="1000" height="300">

# **Making Change** :computer:

## **Description:** :speech_balloon:

* This exercise involves creating a function, makeChange(coins, total), which determines the minimum number of coins needed to achieve a given total using a set of coin denominations. The function employs dynamic programming to iteratively calculate the fewest coins required for each amount from 0 up to the specified total. If the total is zero or less, the function returns 0, as no coins are needed. If the total cannot be met with the available coins, it returns -1. The approach ensures an efficient solution, capable of handling large inputs within a reasonable runtime.

## **Task** :books:

#### **0. Change comes from within**

Given a pile of coins of different values, determine the fewest number of coins needed to meet a given amount total.

* Prototype: def makeChange(coins, total)
* Return: fewest number of coins needed to meet total
    * If total is 0 or less, return 0
    * If total cannot be met by any number of coins you have, return -1
* coins is a list of the values of the coins in your possession
* The value of a coin will always be an integer greater than 0
* You can assume you have an infinite number of each denomination of coin in the list
* Your solution’s runtime will be evaluated in this task

```
carrie@ubuntu:~/making_change$ cat 0-main.py
#!/usr/bin/python3
"""
Main file for testing
"""

makeChange = __import__('0-making_change').makeChange

print(makeChange([1, 2, 25], 37))

print(makeChange([1256, 54, 48, 16, 102], 1453))

carrie@ubuntu:~/making_change$
```
```
carrie@ubuntu:~/making_change$ ./0-main.py
7
-1
carrie@ubuntu:~/making_change$
```

## **Author** :black_nib:

* **Queise Carvalho de Oliveira** - [Linkedin](https://www.linkedin.com/in/queise-carvalho-de-oliveira-50359749/)


## License :page_with_curl:
This project is licensed under the [MIT License](https://opensource.org/license/mit/).
