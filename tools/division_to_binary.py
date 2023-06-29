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


a = int(binary_to_decimal("01010010000010100011111001101000101000010001001010111011000111000100100110100111001000011100100110000001111010100000111111010100"))
b = int(binary_to_decimal("00001001100100111101010100101001000001001000000111010110000101010101101110000101101101111000001010111001000111000010100010010110"))

print(int(a / b))
print(decimal_to_binary(str(int(a / b))))
