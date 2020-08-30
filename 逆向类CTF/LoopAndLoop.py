# coding:utf-8
def check1(input, loop):
    a = input
    for i in range(1, 100):
        a = a - i
    return a

def check2(input, loop):
    a = input
    if loop % 2 == 0:
        for i in range(1, 1000):
            a = a - i
    else:
        for i in range(1, 1000):
            a = a + i
    return a

def check3(input, loop):
    a = input
    for i in range(1, 10000):
        a = a - i
    return a

key = 1835996258
target = key
# 控制1到99的循环
for i in range(2, 100):
    if 2 * i % 3 == 0:
        target = check1(target, i - 1)
    elif 2 * i % 3 == 1:
        target = check2(target, i - 1)
    else:
        target = check3(target, i - 1)
print(target)
