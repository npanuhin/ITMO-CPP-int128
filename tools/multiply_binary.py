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


number1 = '11100000001001110010101101011000101101111101011001011100110001001011010010100000001010101110100000111001101011100111101010111011'
number2 = '00001001100100111101010100101001000001001000000111010110000101010101101110000101101101111000001010111001000111000010100010010110'

number1 = int(binary_to_decimal(number1))
number2 = int(binary_to_decimal(number2))

print(decimal_to_binary(str(number1 * number2))[-128:])
