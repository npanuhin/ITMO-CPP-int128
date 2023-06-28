def decimal_to_binary(number: str):
    number = number.replace(' ', '')
    if number[0] == '-':
        return bin(int(number[1:]) - 1)[2:].zfill(128).replace('1', '2').replace('0', '1').replace('2', '0')
    else:
        return bin(int(number))[2:].zfill(128)


def binary_to_decimal(number: str):
    number = number.replace(' ', '')
    if number[0] == '1':
        return '-' + str(int(number[1:].replace('1', '2').replace('0', '1').replace('2', '0'), 2) + 1)
    else:
        return int(number, 2)


a = "-29256914613596052498173063890724085253"
b = "-137230788039330516817402106788765031062"

print(int(a))
print(int(b))
print(int(a) < int(b))

a = int(decimal_to_binary(a))
b = int(decimal_to_binary(b))

print(a)
print(b)
